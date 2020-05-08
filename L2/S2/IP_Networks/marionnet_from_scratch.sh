#!/bin/bash

# This file is part of marionnet
# Copyright (C) 2010 2011 2012 2013 2014 2015 2016  Jean-Vincent Loddo
# Copyright (C) 2010 2011 2012 2013 2014 2015 2016  Université Paris 13
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Script version: 0.94.0
# 2018.02.04

# Thanks:
# - Lucas Nussbaum for the idea of option "--download-only/-O",
#   and for his patch proposal (July 2013)

set -e
shopt -s nullglob
shopt -s expand_aliases

# Prevent problems compiling `ocamlbricks' (the command `cd' prints
# the target directory when CDPATH is set, in the style of `pushd',
# and this unexpected behaviour get the make process confused):
unset CDPATH

# Prevent problems installing files as root (sudo) with a more
# restrictive umask (like for instance 027):
umask 022

# By default SUDO_OR_EVAL and SUDO_OR_NOTHING are set to 'sudo' for normal users:
if [[ $USER = root ]]; then
  export SUDO_OR_EVAL=eval
  export SUDO_OR_NOTHING=
else
  export SUDO_OR_EVAL=sudo
  export SUDO_OR_NOTHING=sudo
fi

function exiting_because_error {
 # global KEEP_DEBRIS TWDIR
 echo -e "Exiting because of an unexpected error in line $BASH_LINENO"
 if [[ $KEEP_DEBRIS = no ]]; then
  rm -rf $TWDIR
 fi
 exit 3
}
#
trap exiting_because_error ERR

# =============================================================
#                     SELF DEPENDENCIES
# =============================================================

function abspath {
 local B=$(basename $1)
 local D=$(dirname $1)
 (builtin cd $D; echo $PWD/$B)
}

# If realpath is not installed, use the poor man version:
type -t realpath 2>/dev/null 1>/dev/null || {
 function realpath { abspath "$@"; }
 export -f realpath
}

# Backup of the command line:
COMMAND_LINE="$(type -p $0 || realpath $0) "
COMMAND_LINE="$(realpath $COMMAND_LINE) "$@""

# =============================================================
#                  PARSING COMMAND LINE
# =============================================================

# Getopt's format used to parse the command line:
OPTSTRING="hp:s:m:b:o:t:kl:d:v:y:NVDKFTAOc:"

function parse_cmdline {
local i j flag
# Transform long format options into the short one:
for i in "$@"; do
  if [[ double_dash_found = 1 ]]; then
    ARGS+=("$i")
  else case "$i" in
    --help)
      ARGS+=("-h");
      ;;
    --marionnet-series|--series)
     ARGS+=("-s");
     ;;
    --marionnet-version|--marionnet)
     ARGS+=("-m");
     ;;
    --ocamlbricks-version|--ocamlbricks)
     ARGS+=("-b");
     ;;
    --ocaml-version|--ocaml)
     ARGS+=("-o");
     ;;
    --no-native|--bytecode)
     ARGS+=("-N");
     ;;
    --lablgtk-version|--lablgtk)
     ARGS+=("-l");
     ;;
    --vde-version|--vde)
     ARGS+=("-v");
     ;;
    --dot-version|--dot|--graphviz)
     ARGS+=("-d");
     ;;
    --debris|--keep-debris)
     ARGS+=("-k");
     ;;
    --no-vde|--ignore-vde)
     ARGS+=("-V");
     ;;
    --no-dot|--ignore-dot)
     ARGS+=("-D");
     ;;
    --no-kernels|--ignore-kernels)
     ARGS+=("-K");
     ;;
    --no-tiny|--ignore-tiny|--ignore-tiny-filesystems)
     ARGS+=("-T");
     ;;
    --no-filesystems|--ignore-filesystems)
     ARGS+=("-F");
     ;;
    --download-only)
     ARGS+=("-O");
     ;;
    --no-all|--ignore-all)
     ARGS+=("-A");
     ;;
    --continue)
     ARGS+=("-c");
     ;;
    --prefix)
     ARGS+=("-p");
     ;;
    --proxy|--http-proxy)
     ARGS+=("-y");
     ;;
    --tmpdir)
     ARGS+=("-t");
     ;;
    --)
      ARGS+=("--");
      double_dash_found=1;
      ;;
    --[a-zA-Z0-9]*)
      echo "*** Illegal long option $i.";
      exit 1;
      ;;
    -[a-zA-Z0-9]*)
      j="${i:1}";
      while [[ $j != "" ]]; do ARGS+=("-${j:0:1}"); j="${j:1}"; done;
      ;;
    *)
      ARGS+=("$i")
      ;;
  esac
  fi
done
set - "${ARGS[@]}"
unset ARGS

# Interpret short format options:
while [[ $# -gt 0 ]]; do
  OPTIND=1
  while getopts ":$OPTSTRING" flag; do
    if [[ $flag = '?' ]]; then
      echo "ERROR: illegal option -$OPTARG.";
      exit 1;
    fi
    eval "option_${flag}=$OPTIND"
    eval "option_${flag}_arg='$OPTARG'"
  done
  for ((j=1; j<OPTIND; j++)) do
    if [[ $1 = "--" ]]; then
      shift;
      for i in "$@"; do ARGS+=("$i"); shift; done
      break 2;
    else
      shift;
    fi
  done
  # Get just the first argument and reloop:
  for i in "$@"; do ARGS+=("$i"); shift; break; done
done
} # end of parse_cmdline()

declare -a ARGS
parse_cmdline "$@" # read OPTSTRING and set ARGS
# Warning: the following two branches could not be grouped
# into the single command (`else' branch):
# set - "${ARGS[@]}";
# The behaviour is not the same when the array is empty!
if [[ ${#ARGS[@]} -eq 0 ]]; then
  set - "";
else
  set - "${ARGS[@]}";
fi
unset ARGS

function print_usage_and_exit {
 echo -e "Usage: ${0##*/} [OPTIONS]
Download, compile and install marionnet and its principal dependencies.
In addition to compile-time dependencies, when a run-time dependency
like 'vde' or 'dot' seems not installed, the script automatically
downloads, compiles and installs it from the appropriate project homepage
or from our mirror (i.e. https://www.marionnet.org/download/mirror/).
Options:
  -p, --prefix PATH		Set the installation prefix
  -t, --tmpdir PATH		Set the temporary working directory
  -c, --continue PATH		Continue execution started in PATH
  -k, --keep-debris		Don't clean temporary files when exiting
  -h				Print this message and exit
  -s, --series VERSION		Set marionnet's series (may be '0.90.x', '0.94.x' or 'trunk')
  -m, --marionnet VERSION	Set marionnet's version
  -b, --ocamlbricks VERSION	Set ocamlbricks' version
  -o, --ocaml VERSION		Set ocaml's version
  -l, --lablgtk VERSION         Set lablgtk's version
  -v, --vde VERSION             Set vde2's version
  -d, --dot VERSION 		Set dot's (graphviz) version
  -y, --proxy IP:PORT	        Set an (http/https) proxy for downloading (wget)
  -N, --bytecode		Generate bytecode only (no native executables)
  -V, --no-vde			Do nothing about vde
  -D, --no-dot			Do nothing about dot (graphviz)
  -K, --no-kernels 		Don't download kernels
  -T, --no-tiny			Don't download tiny filesystems (guignol, pinocchio, ..)
  -F, --no-filesystems		Don't download (large) filesystems (debian, mandriva, ..)
  -O, --download-only           Skip everything except downloads of kernels and filesystems
  -A, --no-all		        Equivalent to --no-{vde,dot,kernels,tiny,filesystems}
Defaults:
  - the installation prefix is ${PREFIX}
  - the temporary working directory is $TMPDIR
  - continue execution: ${CONTINUE:-none}
  - marionnet's series is ${MARIONNET_SERIES:-latest}
  - marionnet's version is ${MARIONNET_VERSION:-latest}
  - ocamlbricks' version is ${OCAMLBRICKS_VERSION:-latest}
  - ocaml's version is ${OCAML_VERSION:-latest}
  - lablgtk's version is ${LABLGTK_VERSION:-latest}
  - vde's version is ${VDE2_VERSION:-latest}
  - dot's (graphviz') version is ${GRAPHVIZ_VERSION:-latest}
  - keep debris: $KEEP_DEBRIS
  - http proxy: $http_proxy
  - generate bytecode only: $GENERATE_BYTECODE
  - ignore vde: $IGNORE_VDE
  - ignore dot: $IGNORE_DOT
  - ignore kernels: $IGNORE_KERNELS
  - ignore tiny filesystems: $IGNORE_TINY_FILESYSTEMS
  - ignore large filesystems: $IGNORE_LARGE_FILESYSTEMS
  - ignore trunk stuff: $IGNORE_TRUNK_STUFF"
 exit $1
}

# =============================================================
#                         TUNING
# =============================================================

# Option -p, --prefix
if [[ -n ${option_p} ]]; then
 PREFIX=$(realpath "${option_p_arg}")
else
 PREFIX=$(realpath /usr/local)
fi

# Option -t, --tmpdir
if [[ -n ${option_t} ]]; then
 TMPDIR=$(realpath "${option_t_arg}")
else
 # We initialize the system variable TMPDIR if necessary:
 TMPDIR=${TMPDIR:-/tmp}
 TMPDIR=$(realpath $TMPDIR)
fi

# Option -s, --marionnet-series
if [[ -n ${option_s} ]]; then
 MARIONNET_SERIES="${option_s_arg}"
else
 MARIONNET_SERIES="0.94.x"  # default
fi

# Option -m, --marionnet-version
if [[ -n ${option_m} ]]; then
 MARIONNET_VERSION="${option_m_arg}"
elif [[ $MARIONNET_SERIES = "trunk" ]]; then
 MARIONNET_VERSION="trunk"
fi

# Accept the setting "-m trunk" as it was "-s trunk":
if [[ $MARIONNET_VERSION = "trunk" ]]; then
 MARIONNET_SERIES="trunk"
fi

# Option -b, --ocamlbricks-version
if [[ -n ${option_b} ]]; then
 OCAMLBRICKS_VERSION="${option_b_arg}"
elif [[ $MARIONNET_VERSION = "trunk" ]]; then
 OCAMLBRICKS_VERSION="trunk"
fi

# Option -o, --ocaml-version
if [[ -n ${option_o} ]]; then
 OCAML_VERSION="${option_o_arg}"
elif [[ $MARIONNET_VERSION = "trunk" || $MARIONNET_SERIES = "0.94.x" ]]; then
 # This value must be updated each time the trunk
 # will require a new OCaml version:
 OCAML_VERSION="3[.]12[.]1"
else
 # Fixed for marionnet 0.90.6:
 OCAML_VERSION="3[.]11[.]2"
fi

# Option -l, --lablgtk-version
if [[ -n ${option_l} ]]; then
 LABLGTK_VERSION="${option_l_arg}"
else
 # Fixed for marionnet 0.90.6:
 LABLGTK_VERSION="2[.]14[.]2"
fi

# Option -v, --vde-version
if [[ -n ${option_v} ]]; then
 VDE2_VERSION="${option_v_arg}"
fi

# Option -d, --dot-version
if [[ -n ${option_d} ]]; then
 GRAPHVIZ_VERSION="${option_d_arg}"
fi

# Option -N, --no-native, --bytecode
if [[ -n ${option_N} ]]; then
 GENERATE_BYTECODE=yes
else
 GENERATE_BYTECODE=no
fi

# Option -k, --keep-debris
if [[ -n ${option_k} ]]; then
 KEEP_DEBRIS=yes
else
 KEEP_DEBRIS=no
fi

# Option -y, --proxy
if [[ -n ${option_y} ]]; then
 HTTP_PROXY_IP_PORT="${option_y_arg#http://}"
 # ---
 # Environment variables used by `wget':
 export http_proxy="http://${HTTP_PROXY_IP_PORT}/"
 export https_proxy=$http_proxy
 export ftp_proxy=$http_proxy
 export dns_proxy=$http_proxy
 export rsync_proxy=$http_proxy
 export no_proxy="localhost,127.0.0.1"
fi

# Option -c, --continue
if [[ -n ${option_c} ]]; then
  if [[ -d "${option_c_arg}" ]]; then
   TMPDIR=$(realpath "${option_c_arg}")
   TWDIR="$TMPDIR"
   CONTINUE=yes
  else
   echo "Error: ${option_c_arg} doesn't exist or is not a directory."
   echo "Exiting."
   exit 1
  fi
fi

# Option -V, --no-vde
if [[ -n ${option_V} || -n ${option_A} ]]; then IGNORE_VDE=yes; else IGNORE_VDE=no; fi

# Option -D, --no-dot
if [[ -n ${option_D} || -n ${option_A} ]]; then IGNORE_DOT=yes; else IGNORE_DOT=no; fi

# Option -K, --no-kernels
if [[ -n ${option_K} || -n ${option_A} ]]; then IGNORE_KERNELS=yes; else IGNORE_KERNELS=no; fi

# Option -P, --no-tiny
if [[ -n ${option_P} || -n ${option_A} ]]; then IGNORE_TINY_FILESYSTEMS=yes; else IGNORE_TINY_FILESYSTEMS=no; fi

# Option -F, --no-filesystems
if [[ -n ${option_F} || -n ${option_A} ]]; then IGNORE_LARGE_FILESYSTEMS=yes; else IGNORE_LARGE_FILESYSTEMS=no; fi

# Option -T, --no-trunk-stuff
if [[ -n ${option_T} ]]; then IGNORE_TRUNK_STUFF=yes; else IGNORE_TRUNK_STUFF=no; fi

# Option -O, --download-only
if [[ -n ${option_O} ]]; then DOWNLOAD_ONLY=yes; else DOWNLOAD_ONLY=no; fi

# Option -h
if [[ -n ${option_h}  ]]; then
 print_usage_and_exit 0
fi

# =============================================================
#                     TEMPORARY STUFF
# =============================================================

function exiting_because_signal {
 # global KEEP_DEBRIS TWDIR COMMAND_LINE
 echo -e "Exiting because of signal."
 if [[ $KEEP_DEBRIS = no ]]; then
  rm -rf $TWDIR
 else
  echo -e "You can continue the execution launching the following command:
---
$COMMAND_LINE -c $TWDIR
---
Exiting."
 fi
 exit 2
}

# Temporary Working Directory TWDIR (global variable)
# Automatically cleaned when some events occur
function tmpfile {
 # global TMPDIR TWDIR
 if [[ -z $TWDIR ]]; then
   local FREE_MB=$(df -B 1M -P $TMPDIR | awk '{print $4}' | tail -n 1)
   if [[ $FREE_MB -lt $REQUIRED_MB ]]; then
     echo "Insufficient free disk space (${FREE_MB} Mb) in the directory $TMPDIR."
     echo "You can set a larger temporary working directory using the -t option."
     echo "Near to $REQUIRED_MB Mb are required for the script's execution."
     echo "Exiting."
     exit 1
   fi 1>&2
   TWDIR=$(mktemp -p ${TMPDIR:-/tmp} -d ${0##*/}.XXXXXXXX)
   local SIGINT=2
   local SIGQUIT=3
   local SIGABRT=6
   local SIGKILL=9
   local SIGTERM=15 # CTRL-C
   local TRAPPED_EVENTS="$SIGINT $SIGQUIT $SIGABRT $SIGKILL $SIGTERM"
   trap "exiting_because_signal" $TRAPPED_EVENTS
 fi
 if [[ $# = 0 ]]; then
   local TMPFILE=$(mktemp -p $TWDIR tmpfile.XXXXXXXX)
 else
   local TMPFILE=$(mktemp -p $TWDIR "$@")
 fi
 echo "$TMPFILE"
}

# =============================================================
#                           TOOLS
# =============================================================

function exit_and_continue_as_root {
# global TWDIR COMMAND_LINE
echo
if [[ -n "$1" ]]; then
  echo "Error using the program '$1' to become the super user."
else
  echo "No manner to become the super user."
fi
echo -e "In order to install marionnet, become super user and continue launching
the following command:
---
$COMMAND_LINE -c $TWDIR
---
Exiting."
exit 1
}

function ensure_sudo {
# global USER TWDIR COMMAND_LINE
[[ $USER = root ]] && return 0
sudo -v "$@" || exit_and_continue_as_root "sudo"
}

function ensure_sudo_or_continue_as_root {
# global USER TWDIR COMMAND_LINE
local MESSAGE_ABOUT_ACTION="$1"
if [[ $USER = root ]]; then
  echo "Fine, I'm root." 1>&2
elif type -t sudo 1>&2; then
  ensure_sudo -p "* Required the [sudo] password for %u:"
elif type -t su 1>&2; then
  echo "* $MESSAGE_ABOUT_ACTION"
  echo "  The script will be continued as root."
  echo -n "  Please provide root's password: "
  su -c "echo; $COMMAND_LINE -c $TWDIR" || exit_and_continue_as_root "su"
  exit 0
else
  exit_and_continue_as_root
fi
}


function append_line_if_needed {
# global SUDO_OR_NOTHING
local LINE="$1"
local FILE="$2"
{ test -f "$FILE" && grep -q "${LINE}" "$FILE"; } || $SUDO_OR_NOTHING echo "$LINE" >> "$FILE"
}

function wait_printing_dots {
 while sleep 2 && jobs %% 1>/dev/null 2>&1; do echo -n "."; done
}

function define_global_TAB {
local i COLS
if [[ -z $COLUMNS ]]; then
 if type tput 1>/dev/null 2>/dev/null; then
   COLUMNS=$(tput cols)
 else
   COLUMNS=80
 fi
fi
# COLS is the max between $COLUMNS and 104
if [[ $COLUMNS -gt 104 ]]; then COLS=104; else COLS=$COLUMNS; fi
global_TAB+='\r'
for ((i=1; i<=(COLS/8)-1; i++)); do global_TAB+='\t'; done
}

define_global_TAB;

function echo_at_right_side {
 local NEWLINE=""
 if [[ $1 = --newline ]]; then NEWLINE="\n"; shift; fi
 eval echo -en "'$global_TAB'"
 eval printf "'%4s$NEWLINE'" "$1"
}

function wait_printing_percent_progress {
 if [[ -z $1 ]];
 then wait_printing_dots
 else
   local SECTION_SIZE=$1 # or "weight"
   local LOGSIZE=$(wc -c <$LOGFILE)
   local OFFSET=$LOGSIZE
   local TAB=${2:-$global_TAB}
   local PERCENT
   while sleep 2 && jobs %% 1>/dev/null 2>&1; do
     LOGSIZE=$(wc -c <$LOGFILE)
     eval echo -en "'$TAB'"
     PERCENT=$((100*(LOGSIZE-OFFSET)/SECTION_SIZE))
     if [[ $PERCENT -gt 100 ]]; then PERCENT=100; fi
     printf "%3d%%" $PERCENT
   done
   eval echo -en "'$TAB'"
   printf "100%%"
 fi
}

function launch_and_log {
 # global COMMAND_RESULT ALREADY_DONE SUDO_OR_EVAL
 # The option --as-root implies --as-script if the user in not root (in order to
 # prevent sudo to re-ask the password)
 # The option --as-script implies that the command will be launched
 # as a standalone script
 local DO_NOT_REGISTER_AS_DONE
 if [[ $1 = --do-not-register-as-done ]]; then shift; DO_NOT_REGISTER_AS_DONE=y; fi
 local EVAL_OR_SUDO
 local AS_SCRIPT
 # By default EVAL_OR_SUDO is equal to eval
 EVAL_OR_SUDO=eval
 if [[ $1 = --as-root   || $1 = --sudo   ]]; then shift; EVAL_OR_SUDO=$SUDO_OR_EVAL; fi
 if [[ $1 = --as-script || $1 = --script ]]; then shift; AS_SCRIPT=yes; fi
 if [[ ${EVAL_OR_SUDO%% *} = sudo ]]; then
   AS_SCRIPT=yes
 fi
 local MSG="$1"
 echo -n "* $MSG ..."
 if grep <$ALREADY_DONE -q "^$MSG DONE$"; then
  echo_at_right_side "done";
  echo
  return 0
 fi
 local CMD="{ $2 2>&1 || echo 1 > $COMMAND_RESULT; } 1>&2"
 local SECTION_SIZE=$3
 echo -e "===\nCHECKPOINT: $MSG\n===\n" 1>&2
 echo 0 > $COMMAND_RESULT
 case $AS_SCRIPT in
   yes)
     local TMPSCRIPT=$(tmpfile script.XXXXXX)
     echo '#!/bin/bash' > $TMPSCRIPT
     echo "export PATH=$PATH" >> $TMPSCRIPT
     echo $CMD >> $TMPSCRIPT
     chmod +x $TMPSCRIPT
     $EVAL_OR_SUDO $TMPSCRIPT &
     ;;
     *)
     $EVAL_OR_SUDO $CMD &
     ;;
 esac
 wait_printing_percent_progress $SECTION_SIZE
 sync
 local RETURN_CODE=$(<$COMMAND_RESULT)
 if [[ $RETURN_CODE -eq 1 ]]; then
  echo "FAILED!"
  echo "Last 20 lines of log ($LOGFILE):"
  echo "======"
  tail -n 20 $LOGFILE
  echo "======"
  echo "Exiting."
 else
  echo
  if [[ -z $DO_NOT_REGISTER_AS_DONE ]]; then
    echo "$MSG DONE" >> $ALREADY_DONE
  fi
 fi
 return $RETURN_CODE
}

# Support https:
alias wget='wget --no-check-certificate'
export WGET='wget --no-check-certificate'

function download_tar_gz_from_definite_url {
local BASENAME="$1" # ex: vde2
local URL="$2" # ex: http://sourceforge.net/projects/vde/files/vde2/2.3.2/vde2-2.3.2.tar.gz
{ wget -O - "$URL" \
  | tar 1>&2 xvzf -
  } || return 1
ln -s ${BASENAME}-* ${BASENAME} || true
return 0
}


function download_latest_tar_gz_from_url {
local BASENAME="$1" # ex: vde2
local VERSION="${2:-[0-9][0-9]*[.][0-9][0-9]*[.][0-9][0-9]*}"
local URL="$3" # ex: http://sourceforge.net/projects/vde/
local TGZ="${4:-$(tmpfile)}"
{ wget -O - "$URL" \
  | grep -o "href=\".*${BASENAME}-${VERSION}[.]tar[.]gz[0-9A-Za-z/_-]*\"" \
  | cut -d\" -f2
  } > $TGZ || return 1
LATEST=$(grep <$TGZ -o "${VERSION}[.]tar[.]gz" | tr '.' ' '| sort -n | tr ' ' '.' | tail -n 1)
if [[ -z "$LATEST" ]]; then
  echo "No latest version of $BASENAME found looking into $URL."
  return 2
else
  echo "Ok, latest version $LATEST of $BASENAME found looking into $URL."
fi 1>&2
TGZ=$(grep <$TGZ -o ".*${BASENAME}-${LATEST}[0-9A-Za-z/_-]*")
# Adjust relative href:
if [[ ${TGZ#http://} = ${TGZ} ]] && [[ ${TGZ#https://} = ${TGZ} ]] && [[ ${TGZ#ftp://} = ${TGZ} ]]; then
TGZ="${URL%/*}/$TGZ"
fi
{ wget -O - $TGZ \
  | tar 1>&2 xvzf -
  } || return 1
ln -s ${BASENAME}-* ${BASENAME} || true
return 0
}

# Usage: download_latest_tar_gz [(-v|--version) REGEXPR] BASENAME URL...
function download_latest_tar_gz {
local VERSION
if [[ $1 = '-v' || $1 = '--version' ]]; then
 VERSION="$2"
 shift 2 || return 2
else
 VERSION="[0-9][0-9]*[.][0-9][0-9]*[.][0-9][0-9]*"
fi
# "-v latest" means the latest matching the default regexp:
if [[ $VERSION = latest || -z $VERSION ]]; then
  VERSION="[0-9][0-9]*[.][0-9][0-9]*[.][0-9][0-9]*"
fi
local BASENAME="$1" # ex: vde2
shift || return 2
local URL LATEST
local TGZ=$(tmpfile)
for URL in "$@"; do
 download_latest_tar_gz_from_url "$BASENAME" "$VERSION" "$URL" "$TGZ"  && {
   [[ $# -gt 1 ]] && echo "Downloaded from $URL"
   rm -f "$TGZ"
   return 0
   }
done
rm -f "$TGZ"
return 1
}

# =============================================================
#                        DOWNLOADS
# =============================================================

# Marionnet 0.90.2 has a problem with 3.12.0 (camlp4)
function download_latest_ocaml {
  local VERSION="${OCAML_VERSION:-[0-9][.][0-9][0-9][.][0-9]*}"
  download_latest_tar_gz -v "$VERSION" ocaml \
    "http://caml.inria.fr/pub/distrib/ocaml-3.11/" \
    $OUR_MIRROR \
    "http://caml.inria.fr/download.html"
}


# Obsolete url: "ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/olabl/"
function download_latest_lablgtk {
  local VERSION="${LABLGTK_VERSION:-[0-9][.][0-9][0-9]*[.][0-9][0-9]*}"
  download_latest_tar_gz -v "$VERSION" lablgtk \
    "http://wwwfun.kurims.kyoto-u.ac.jp/soft/lsl/lablgtk.html" \
    $OUR_MIRROR
}

function download_latest_vde {
  local VERSION=${VDE2_VERSION:-2.3.2}
  local URL="http://sourceforge.net/projects/vde/files/vde2/2.3.2/vde2-2.3.2.tar.gz"
  download_tar_gz_from_definite_url vde2 "$URL" || \
    download_latest_tar_gz -v "$VERSION" vde2 $OUR_MIRROR
}

function download_latest_marionnet {
  local VERSION=${MARIONNET_VERSION:-latest}
  download_latest_tar_gz -v "$VERSION" marionnet \
    "https://launchpad.net/marionnet" \
    $OUR_MIRROR
}

function download_latest_ocamlbricks  {
  local VERSION=${OCAMLBRICKS_VERSION:-latest}
  download_latest_tar_gz -v "$VERSION" ocamlbricks \
    "https://launchpad.net/ocamlbricks" \
    $OUR_MIRROR
}

function download_latest_graphviz {
  local VERSION=${GRAPHVIZ_VERSION:-latest}
  download_latest_tar_gz -v "$VERSION" graphviz \
    "http://www.graphviz.org/Download_source.php" \
    $OUR_MIRROR
}

# =============================================================
#                     DEBIAN or derived
# =============================================================

function are_we_in_debian_or_derived {
  $(which dpkg) -L bash 2>/dev/null | grep -q $(which bash) &&
  $(which dpkg) -L apt  2>/dev/null | grep -q $(which apt-get)
}

# Useless now (since 2011-11-07)
function are_we_in_ubuntu_11_or_greater {
 if [[ -f /etc/issue ]]; then
   local A=$(head -n 1 /etc/issue)
   local a b c
   read a b c <<<"$A"
   if [[ "$a" = "Ubuntu" ]]; then
     IFS="." read a c <<<"$b"
     [[ "$a" -ge 11 ]]
   else
     return 1
   fi
 else
  return 1
 fi
}

# (problems with the packaged version of vde2)
function are_we_in_ubuntu_12_04 {
 if [[ -f /etc/issue ]]; then
   local A=$(head -n 1 /etc/issue)
   local a b c
   read a b c <<<"$A"
   if [[ "$a" = "Ubuntu" ]]; then
     IFS="." read a c d <<<"$b"
     [[ "$a" = "12" && "$c" = "04" ]]
   else
     return 1
   fi
 else
  return 1
 fi
}

function echo_debian_package_for_binary_if_really_needed {
 local BINARY=$1
 local PACKAGE=$2
 if type -t $BINARY 1>&2; then
   return 0 # not needed
 else
   echo "$PACKAGE " # note the trailing blank
 fi
}

function is_aptitude_installed  {
 type 1>&2 aptitude
}


function is_package_installed {
 local L=en_US.UTF-8
 LANG=$L LC_ALL=$L LC_MESSAGES=$L LANGUAGE=$L dpkg -s $1 2>/dev/null | \grep -q 'Status: install ok installed';
}

function echo_required_debian_packages {
 local LIST i VDE2_VERSION

 # Then continue with aptitude
 for i in gcc g++ make flex bison grep tar xterm wget mktemp realpath sed gawk aptitude; do
   LIST+=$(echo_debian_package_for_binary_if_really_needed $i $i)
 done

 LIST+=$(echo_debian_package_for_binary_if_really_needed dot graphviz)
 LIST+=$(echo_debian_package_for_binary_if_really_needed uml_switch uml-utilities)

 for i in \
   libgtk2.0-dev libglade2-dev liblablgtksourceview2-ocaml-dev \
   libtool bridge-utils coreutils debianutils diffutils \
   net-tools uml-utilities util-linux x11-xserver-utils \
   coreutils findutils login procps gettext \
   rlfe; # alternatives are rlwrap and ledit
   do
   if ! is_package_installed $i; then
     LIST+="$i "
   fi
 done

 # vde2 only if is not already installed and the available version is >= 2.2.1
 if type 1>&2 aptitude; then
   type 1>&2 vde_switch || {
       VDE2_VERSION=$(aptitude show vde2 | awk '/^Version.*[2-9][.][0-9][.][0-9].*/ {print $2}' | awk -F '-' '{print $1}')
       VDE2_VERSION=$(echo $VDE2_VERSION | awk -F '.' '(($2 * 100 + $3 * 10 + $4) >= 221) {print}')
       if [[ -n "$VDE2_VERSION" ]]; then
	   LIST+="vde2 "
       fi
   }
 fi

 # x86_64 => libc6-i386
 if type uname && [[ $(uname -m) = "x86_64" ]] && ! is_package_installed libc6-i386; then
   LIST+="libc6-i386 "
 fi 1>&2

 # Return the list:
 echo "$LIST"
}

# =============================================================
#                  OUR KERNELS AND FILESYSTEMS
# =============================================================

function download_our_kernels {
  # global OUR_BASE_URL
  local KERNELS
  KERNELS=$(wget -O - "$OUR_BASE_URL" \
  | grep -o 'href="kernels_[^"]*"' \
  | grep -o "kernels_[^\"]*[.]tar[.]gz"\
  )
  local i WEIGHT
  for i in $KERNELS; do
    # Known weights:
    case "$i" in
      kernels_linux-*.tar.gz) 
          WEIGHT=7000 # approximatively
          launch_and_log --sudo --script "Installing $i" "{ $WGET -O - '$OUR_BASE_URL/$i' | tar 1>&2 xvzf -; }" $WEIGHT
          ;;
      *) unset WEIGHT ;;
    esac
  done
}

function download_our_large_filesystems {
  # global OUR_BASE_URL
  local FILESYSTEMS
  FILESYSTEMS=$(wget -O - "$OUR_BASE_URL" \
  | grep -o 'href="filesystems_[^"]*"' \
  | grep -o "filesystems_[^\"]*[.]tar[.]gz"\
  )
  local i WEIGHT
  for i in $FILESYSTEMS; do
    # Known weights:
    case "$i" in
      filesystems_machine-*.tar.gz) 
          WEIGHT=800000 # approximatively
          launch_and_log --sudo --script "Installing $i" "{ $WGET -O - '$OUR_BASE_URL/$i' | tar 1>&2 xvzf -; }" $WEIGHT
          ;;
      *) unset WEIGHT ;;
    esac
  done
}

function download_our_tiny_filesystems {
  # global OUR_BASE_URL
  local FILESYSTEMS
  FILESYSTEMS=$(wget -O - "$OUR_BASE_URL" \
  | grep -o 'href="filesystems_[^"]*"' \
  | grep -o "filesystems_[^\"]*[.]tar[.]gz"\
  )
  local i WEIGHT
  for i in $FILESYSTEMS; do
    # Known weights:
    case "$i" in
      "filesystems_pinocchio.tar.gz") 
          WEIGHT=77543 
          launch_and_log --sudo --script "Installing $i" "{ $WGET -O - '$OUR_BASE_URL/$i' | tar 1>&2 xvzf -; }"  $WEIGHT
          ;;
      "filesystems_guignol.tar.gz")   
          WEIGHT=27175 
          launch_and_log --sudo --script "Installing $i" "{ $WGET -O - '$OUR_BASE_URL/$i' | tar 1>&2 xvzf -; }"  $WEIGHT
          ;;
      *) unset WEIGHT ;;
    esac
  done
}

# Main function calling the previously defined functions (download_our_*):
function download_marionnet_kernels_and_filesystems {
  # global  OUR_BASE_URL  SUDO_OR_NOTHING  PREFIX
  # global  IGNORE_KERNELS  IGNORE_TINY_FILESYSTEMS  IGNORE_LARGE_FILESYSTEMS
  ensure_sudo -p "* Required the [sudo] password for %u:"
  $SUDO_OR_NOTHING mkdir -p $PREFIX/share/marionnet/
  pushd $PREFIX/share/marionnet/ 1>&2

  if [[ $IGNORE_KERNELS = yes ]]; then
  echo -n "* Installing kernels: dependency ignored (--no-kernels)"
  echo_at_right_side --newline "ok"
  else download_our_kernels; fi

  if [[ $IGNORE_TINY_FILESYSTEMS = yes ]]; then
  echo -n "* Installing tiny filesystems: dependency ignored (--no-tiny)"
  echo_at_right_side --newline "ok"
  else download_our_tiny_filesystems; fi

  if [[ $IGNORE_LARGE_FILESYSTEMS = yes ]]; then
  echo -n "* Installing large filesystems: dependency ignored (--no-filesystems)"
  echo_at_right_side --newline "ok"
  else download_our_large_filesystems; fi

  popd 1>&2
}

# =============================================================
#                            MAIN
# =============================================================

PATH_BACKUP=$PATH
cd "$TMPDIR"

if [[ $CONTINUE != yes ]]; then
tmpfile -u 1>/dev/null # just create the temporary working directory $TWDIR
fi

# We reassign the system variable TMPDIR used by mktemp (for children):
export TMPDIR=$TWDIR
export -f tmpfile

REPODIR="$TWDIR"
REPODIR=$(realpath $REPODIR)
# echo -e "Working directory \r\t\t\t: $REPODIR"
cd $REPODIR
LOGFILE=$REPODIR/log
echo -e "* The log file is $LOGFILE"

# Redirect stderr to the log file:
exec 2>>$LOGFILE

COMMAND_RESULT=$REPODIR/result
ALREADY_DONE=$REPODIR/already_done
touch $COMMAND_RESULT $ALREADY_DONE

OUR_BASE_URL="https://www.marionnet.org/download/marionnet_from_scratch/$MARIONNET_SERIES/"
OUR_MIRROR="$OUR_BASE_URL/mirror/"

if [[ $DOWNLOAD_ONLY = yes ]]; then
  download_marionnet_kernels_and_filesystems
  echo '---'
  echo "Success."
  exit 0
fi

if are_we_in_debian_or_derived; then
  echo "* This looks like a Debian or derived distribution. Oh, joy!"
  # It's a joy but we have to workaround some security choices:
  if [[ $SUDO_OR_EVAL    = sudo ]]; then SUDO_OR_EVAL="sudo -E"; fi
  if [[ $SUDO_OR_NOTHING = sudo ]]; then SUDO_OR_NOTHING="sudo -E"; fi
  # ---
  DEBIAN_PACKAGE_LIST=$(echo_required_debian_packages)
  echo "DEBIAN_PACKAGE_LIST=$DEBIAN_PACKAGE_LIST" 1>&2 # debugging
  if [[ -n ${DEBIAN_PACKAGE_LIST%% } ]]; then
    echo "  Required packages: $DEBIAN_PACKAGE_LIST"
    echo -n "  Shall I install required package(s) with aptitude ([y]/n)? "
    read z
    if [[ $z != n && $z != N ]]; then
      echo -n "  Shall I use the aptitude option --allow-untrusted ([y]/n)? "; read z
      if [[ $z != n && $z != N ]]; then
	APTITUDE_OPTIONS+="--allow-untrusted "
      fi
      MSG="Installing required packages with aptitude"
      ensure_sudo_or_continue_as_root "* $MSG"
      # First install aptitude if needed:
      if ! type 1>&2 aptitude; then
	launch_and_log --sudo "Installing aptitude" "apt-get -y install aptitude"
	APTITUDE_INSTALLED_NOW=yes
      fi
      # vde2 only if is not already installed and the available version is >= 2.2.1
      if [[ $APTITUDE_INSTALLED_NOW = yes ]] && ! type 1>&2 vde_switch; then
	VDE2_VERSION=$(aptitude $APTITUDE_OPTIONS show vde2 | awk '/^Version.*[2-9][.][0-9][.][0-9].*/ {print $2}' | awk -F '-' '{print $1}')
	VDE2_VERSION=$(echo $VDE2_VERSION | awk -F '.' '(($2 * 100 + $3 * 10 + $4) >= 221) {print}')
	if [[ -n "$VDE2_VERSION" ]]; then
	  DEBIAN_PACKAGE_LIST+="vde2 "
	  echo "  Note: I will also install vde2 with aptitude"
	fi
      fi
      # We set the option `--do-not-register-as-done' because sometimes a single call to aptitude is not sufficient to install all things...
      launch_and_log --do-not-register-as-done --sudo "$MSG" "aptitude $APTITUDE_OPTIONS -q -y install $DEBIAN_PACKAGE_LIST"
      DISABLE_libc6_i386_WARNING=yes
    fi # answered yes
  fi # package list not empty
fi # are_we_in_debian_or_derived

launch_and_log "Downloading marionnet" download_latest_marionnet 22400
launch_and_log "Downloading ocamlbricks" download_latest_ocamlbricks 7500

# =============================================================
#                       OCAML & LABLGTK
# =============================================================

function compile_ocaml {
cd ocaml
# Download and apply the patch bugfix-5237.diff for ocaml 3.11 on a 64 bits architecture
if type uname 1>&2 && [[ $(uname -m) = "x86_64" ]]; then
  local BUGFIX_FILE="bugfix-5237.diff"
  echo "Downloading the ocaml 3.11 patch ($BUGFIX_FILE) for x86_64"
  wget -O $BUGFIX_FILE "$OUR_MIRROR/$BUGFIX_FILE" || \
    wget -O $BUGFIX_FILE 'http://caml.inria.fr/mantis/file_download.php?file_id=415&type=bug' || \
      return 1
  echo "Applying the ocaml 3.11 patch ($BUGFIX_FILE) for x86_64"
  patch -p1 < $BUGFIX_FILE
# Download and apply the patch 0007-Fix-ocamlopt-w.r.t.-binutils-2.2[1-9].patch
# for ocaml 3.11 on a 32 bits architecture with binutils version=2.2[1-9].x
elif type ld 1>&2 && ld -v | \grep -q '[ ]2[.]2[1-9]'; then
  local BUGFIX_FILE="bugfix-5237-i386.diff"
  echo "Downloading the ocaml 3.11 patch ($BUGFIX_FILE) for i386"
  wget -O $BUGFIX_FILE "$OUR_MIRROR/$BUGFIX_FILE" || \
    wget -O $BUGFIX_FILE 'http://caml.inria.fr/mantis/file_download.php?file_id=418&type=bug' || \
      return 1
  echo "Applying the ocaml 3.11 patch ($BUGFIX_FILE) for i386"
  patch -p1 < $BUGFIX_FILE
fi
# Compile now:
{ ./configure -prefix $OCAML_PREFIX -no-curses -no-tk &&
  make world.opt &&
  make install &&
  make -C tools/ objinfo &&
  if [[ ! -e $OCAML_PREFIX/bin/ocamlobjinfo ]]; then
    cp tools/objinfo $OCAML_PREFIX/bin/ &&
    [[ -e $OCAML_PREFIX/bin/ocamlobjinfo ]] || ln -s objinfo $OCAML_PREFIX/bin/ocamlobjinfo
  fi
  } || return 1
cd ..
}

function compile_lablgtk {
cd lablgtk
{ ./configure --prefix $OCAML_PREFIX \
  --with-glade --without-gl --without-rsvg --without-gnomecanvas --without-gnomeui \
  --without-panel --without-gtkspell --without-gtksourceview --with-gtksourceview2 \
  --without-quartz &&
  make &&
  make opt &&
  make install
  } || return 1
cd ..
}

# Tuning:
export OCAML_PREFIX=$PWD/local
export PATH=$OCAML_PREFIX/bin:$PATH
LIB_OCAML=$OCAML_PREFIX/lib/ocaml/
export CAML_LD_LIBRARY_PATH=${LIB_OCAML}/stublibs
launch_and_log "Downloading ocaml" download_latest_ocaml 83000
launch_and_log "Downloading lablgtk" download_latest_lablgtk 17800
launch_and_log "Compiling ocaml" compile_ocaml 382000
launch_and_log "Compiling lablgtk" compile_lablgtk 56000

# =============================================================
#                       OCAMLBRICKS
# =============================================================

cd ocamlbricks
cat >CONFIGME <<EOF
ocaml_libraryprefix=$LIB_OCAML
libraryprefix=$LIB_OCAML
prefix=$PREFIX
prefix_install=$PREFIX
configurationprefix=\$prefix/etc
documentationprefix=\$prefix/share/doc
localeprefix=\$prefix/share/locale
ocaml_sources=$LIB_OCAML/caml
ocaml_version=$(ocamlc -version || echo ${OCAML_VERSION//[\[\]]/})
EOF

launch_and_log "Compiling ocamlbricks" 'make clean && make && make install' 4002673
cd ..

# =============================================================
#                        MARIONNET
# =============================================================

cd marionnet
cp ../ocamlbricks/CONFIGME .

# make

case $GENERATE_BYTECODE in
 yes)
  MARIONNET_MAKE_COMMAND='make clean byte'
  WEIGHT=2460914
  ;;
 no)
  MARIONNET_MAKE_COMMAND='make clean native'
  WEIGHT=2780316
  ;;
esac

launch_and_log \
  "Compiling marionnet" \
  "$MARIONNET_MAKE_COMMAND" \
  $WEIGHT

# make install

if [[ $USER = root ]]; then
  MAKE_INSTALL='make install'
  # Reset SUDO_OR_EVAL and SUDO_OR_NOTHING:
  SUDO_OR_EVAL=eval
  unset AS_ROOT SUDO_OR_NOTHING
elif [[ -w "$PREFIX" ]]; then
  MAKE_INSTALL='make install'
  unset AS_ROOT
elif type -t sudo 1>&2; then
  ensure_sudo -p "* Required the [sudo] password for %u:"
  MAKE_INSTALL="PATH=$PATH make install"
  SUDO_MAKE_INSTALL="sudo make install"
  AS_ROOT=--as-root
elif type -t su 1>&2; then
  echo "* Preparing to install in $PREFIX"
  echo "  The script will be continued as root."
  echo -n "  Please provide root's password: "
  su -c "echo; $COMMAND_LINE -c $TWDIR" || exit_and_continue_as_root "su"
  exit 0
else
  exit_and_continue_as_root
fi

# Set a default if not already set (when sudo is required and available):
SUDO_MAKE_INSTALL=${SUDO_MAKE_INSTALL:-$SUDO_OR_NOTHING $MAKE_INSTALL}

launch_and_log ${AS_ROOT} \
  "Installing marionnet" \
  "$MAKE_INSTALL" \
  3918924 # weight

# Alias for marionnet -> marionnet.native (or marionnet.byte)
if ! type marionnet 1>&2; then
 pushd $PREFIX/bin/
 for i in marionnet.{native,byte}; do
   if [[ -x $i ]]; then
     $SUDO_OR_NOTHING ln -sf $i marionnet
     break
   fi
 done
 popd
fi 1>&2

cd ..

# =============================================================
#                           VDE
# =============================================================

function download_compile_and_install_vde2 {
  download_latest_vde &&
  cd vde2
  { ./configure -prefix $PREFIX &&
    make &&
    $SUDO_MAKE_INSTALL
    } || return 1
  cd ..
}

if [[ $IGNORE_VDE = yes ]]; then
 echo -n "* Installing vde2: dependency ignored (--no-vde)"
 echo_at_right_side --newline "ok"
elif type vde_switch 1>&2; then
 echo -n "* Installing vde2: it seems to be already installed"
 echo_at_right_side --newline "ok"
else
 launch_and_log \
   "Downloading, compiling and installing vde2" \
   download_compile_and_install_vde2 \
   54276 # weight
fi

# =============================================================
#                       DOT (GRAPHVIZ)
# =============================================================

function download_compile_and_install_graphviz {
  download_latest_graphviz &&
  cd graphviz
  { ./configure -prefix=$PREFIX &&
    make &&
    $SUDO_MAKE_INSTALL
    } || return 1
  cd ..
}

if [[ $IGNORE_DOT = yes ]]; then
 echo -n "* Installing dot (graphviz): dependency ignored (--no-dot)"
 echo_at_right_side --newline "ok"
elif type dot 1>&2; then
 echo -n "* Installing dot (graphviz): it seems to be already installed"
 echo_at_right_side --newline "ok"
else
 launch_and_log \
   "Downloading, compiling and installing dot (graphviz)" \
   download_compile_and_install_graphviz \
   863227 # weight
fi

# =============================================================
#                     KERNELS AND FILESYSTEMS
# =============================================================

# The functions related to these features are located at the
# beginning of this script in order to manage the option
# download--only. So, at this point we have just to call the
# good function:
download_marionnet_kernels_and_filesystems

# =============================================================
#                     marionnet.conf
# =============================================================

if [[ -f $PREFIX/share/marionnet/marionnet.conf ]]; then
 MARIONNET_DOT_CONF=$PREFIX/share/marionnet/marionnet.conf
elif [[ -f $PREFIX/etc/marionnet/marionnet.conf ]]; then
 MARIONNET_DOT_CONF=$PREFIX/etc/marionnet/marionnet.conf
else
 echo "File \`marionnet.conf' not found. Exiting.";
 exit 3
fi

function first_installed_binary_of_list {
 local i
 for i in "$@"; do
   if type -t $i &>/dev/null; then
     echo $i
     return 0
   fi
 done
 # otherwise return the first:
 echo $1
}

MARIONNET_KEYBOARD_LAYOUT=$(echo $LANG | grep -o '^[a-z]*')
MARIONNET_KEYBOARD_LAYOUT=${MARIONNET_KEYBOARD_LAYOUT=:-us}
MARIONNET_PDF_READER=$(first_installed_binary_of_list evince okular kpdf xpdf gv)
MARIONNET_POSTSCRIPT_READER=$MARIONNET_PDF_READER
MARIONNET_DVI_READER=$MARIONNET_PDF_READER
MARIONNET_HTML_READER=$(first_installed_binary_of_list firefox epiphany galeon konqueror rekonq chromium opera)
MARIONNET_TEXT_EDITOR=$(first_installed_binary_of_list emacs gedit kate kwrite xemacs)

for i in MARIONNET_{PDF,POSTSCRIPT,DVI,HTML}_READER MARIONNET_TEXT_EDITOR MARIONNET_KEYBOARD_LAYOUT; do
 v=$(eval echo \$$i);
 $SUDO_OR_NOTHING sed -i -e "s/$i=\(.*\)/$i=$v/" $MARIONNET_DOT_CONF
done

if [[ ! -f /etc/marionnet/marionnet.conf ]]; then
  echo -n "* Installing /etc/marionnet/marionnet.conf ..."
  $SUDO_OR_NOTHING mkdir -p /etc/marionnet/
  $SUDO_OR_NOTHING cp $MARIONNET_DOT_CONF /etc/marionnet/
  echo_at_right_side --newline "ok"
fi

# =============================================================
#                     SysV-style INIT
# =============================================================

function generate_the_marionnet_daemon_script {
local TMPFILE=$(tmpfile)
cat >$TMPFILE <<EOF
#!/bin/bash

# This file was automatically generated by ${0##*/}

# This file is part of marionnet
# Copyright (C) 2010 Jean-Vincent Loddo
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Very basic init launcher for the marionnet-daemon

### BEGIN INIT INFO
# Provides: marionnet-daemon
# Required-Start: \$local_fs \$remote_fs \$network
# Required-Stop:
# Default-Start: 2 3 4 5
# Default-Stop: 0 1 6
# Short-Description: Support daemon for marionnet
# Description: Support daemon for marionnet
### END INIT INFO

set -e
PATH=$PREFIX/bin:$PREFIX/sbin:\$PATH

DAEMON=\$(type -p marionnet-daemon.native || type -p marionnet-daemon.byte) || {
  echo "Error: neither marionnet-daemon.native nor marionnet-daemon.byte found."
  exit 1
}

function killall_marionnet_daemon {
 ps -u 0 -o pid,cmd | awk '\$2 ~ /marionnet-daemon/ {print \$1}' | while read pid; do kill -9 \$pid; done
}

function is_marionnet_daemon_launched {
 ps -u 0 -o cmd | awk '\$1 ~ /marionnet-daemon/ {print \$1}' | grep -q 'marionnet-daemon'
}

function pid_of_marionnet_daemon {
 ps -u 0 -o pid,cmd | awk '\$2 ~ /marionnet-daemon/ {print \$1}' | while read pid; do echo \$pid; done
}

case "\$1" in
 start)
  if is_marionnet_daemon_launched; then
    echo "The marionnet daemon is already launched."
    exit 0
  else
    echo -n "Starting the marionnet daemon..."
    \$DAEMON >/dev/null 2>/dev/null &
  fi
  echo " Ok"
  ;;
 stop)
  echo -n "Stopping the marionnet daemon..."
  killall_marionnet_daemon || true
  echo " Ok"
  ;;
 status)
  if is_marionnet_daemon_launched; then
    PID=\$(pid_of_marionnet_daemon)
    echo "The marionnet daemon is running (PID=\$PID)."
  else
    echo "The marionnet daemon is stopped."
  fi
  exit 0
  ;;
 *)
  echo "Usage: $1 (start|stop|status)"
  echo "Start or stop the marionnet daemon."
  exit 1
esac
EOF
chmod +x $TMPFILE
$SUDO_OR_NOTHING mv -f $TMPFILE $1
}

function install_the_marionnet_daemon_script {
# global INIT_DIR
generate_the_marionnet_daemon_script $INIT_DIR/marionnet-daemon
local RC_DIRS i
RC_DIRS=$(for i in /etc/rc[2-5S].d /etc/*/rc[2-5S].d/ /etc/*/*/rc[2-5S].d ; do
  [[ -d $i ]] && B=$(basename $i) && echo "$B $i $B"
done | sort -u --key=1,1 | { while read _ b _; do echo $b; done })
# ---
for i in $RC_DIRS; do
  pushd $i
  if [[ "$(realpath ../init.d)" = "$INIT_DIR" ]]; then
    $SUDO_OR_NOTHING ln -sf ../init.d/marionnet-daemon S90marionnet-daemon
  elif [[ "$(realpath ../../init.d)" = "$INIT_DIR" ]]; then
    $SUDO_OR_NOTHING ln -sf ../../init.d/marionnet-daemon S90marionnet-daemon
  else
    $SUDO_OR_NOTHING ln -sf $INIT_DIR/marionnet-daemon S90marionnet-daemon
  fi
  popd
done 1>&2
# ---
if [[ $(ps --no-headers -o comm 1) = "systemd" ]]; then
  $SUDO_OR_NOTHING systemctl enable marionnet-daemon
fi
}

function launch_the_marionnet_daemon_script {
# global INIT_DIR SUDO_OR_NOTHING
if [[ $(ps --no-headers -o comm 1) = "systemd" ]]; then
  $SUDO_OR_NOTHING systemctl start marionnet-daemon 1>&2
else
  $SUDO_OR_NOTHING $INIT_DIR/marionnet-daemon start 1>&2
fi
}

function define_global_INIT_DIR {
# global INIT_DIR
local i j
if [[ -d /etc/init.d ]]; then
 INIT_DIR=/etc/init.d
else
 declare -i j
 j=0
 for i in /etc/*/init.d; do
   [[ -d $i ]] && INIT_DIR=$i && j+=1
 done
 if [[ j != 1 ]]; then unset INIT_DIR; fi
fi
}

define_global_INIT_DIR;

if [[ -z $INIT_DIR ]]; then
 echo -n "* Installing daemon: directory init.d not found in /etc"
 echo_at_right_side --newline "ko"
elif [[ -f $INIT_DIR/marionnet-daemon ]]; then
 echo -n "* Installing daemon: script already exists in $INIT_DIR"
 echo_at_right_side --newline "ok"
else
  echo "* Installing daemon:"
  echo -n "  Shall I install the marionnet daemon in your runlevels ([y]/n)? "
  read z
  if [[ $z != n && $z != N ]]; then
    ensure_sudo -p "  Required the [sudo] password for %u:"
    echo -n "  Installing the marionnet daemon ..."
    install_the_marionnet_daemon_script
    [[ -e /dev/net/tun ]] || $SUDO_OR_NOTHING mknod /dev/net/tun c 10 200
    $SUDO_OR_NOTHING chmod a+rw /dev/net/tun
    if [[ -f /etc/modules.conf ]]; then
      append_line_if_needed "alias char-major-10-200 tun" /etc/modules.conf
      $SUDO_OR_NOTHING depmod -a
    fi 1>&2
    echo_at_right_side --newline "ok"
    echo -n "  Launching the marionnet daemon ..."
    launch_the_marionnet_daemon_script
    echo_at_right_side --newline "ok"
    DAEMON_LAUNCHED=yes
  fi
fi

# =============================================================
#                     Adjust X -nolisten tcp
# =============================================================

function remove_nolisten_assignment_from {
# global SUDO_OR_NOTHING
local i=$1
$SUDO_OR_NOTHING sed -i -e 's/\(^[a-ZA-Z0-9]*[=].*[-]nolisten tcp.*\)$/#\1\n\1/g' $i
$SUDO_OR_NOTHING sed -i -e 's/\(^[a-ZA-Z0-9]*[=].*\)[-]nolisten tcp\(.*\)$/\1 \2/g' $i
}

function remove_nolisten_X_or_startx_actuals_from {
# global SUDO_OR_NOTHING
local i=$1
$SUDO_OR_NOTHING sed -i -e 's/\(^[a-ZA-Z0-9/: ]*X.*\)[-]nolisten tcp\(.*\)$/\1\2/g' $i
$SUDO_OR_NOTHING sed -i -e 's/\(^[a-ZA-Z0-9/: ]*startx.*\)[-]nolisten tcp\(.*\)$/\1\2/g' $i
}

function remove_DisallowTCP_from {
# global SUDO_OR_NOTHING
local i=$1
$SUDO_OR_NOTHING sed -i -e 's/\(^DisallowTCP=true.*\)$/#\1\nDisallowTCP=false/g' $i
}

# Sections in file have the form "[security]"
function ensure_section_and_binding {
[[ $# -ge 3 ]] || return 1
local SECTION=$1   # ex: security
local VARIABLE=$2  # ex: Enable
local VALUE=$3     # ex: true
local AWK_PROGRAM
shift 3
AWK_PROGRAM="
   BEGIN {x=0}
   /\[$SECTION\]/ {x=1;print;next}
   (x==1) && /$VARIABLE=.*/ {print \"$VARIABLE=$VALUE\"; x=2; next}
   (x==1) && /\[.*\]/       {print \"$VARIABLE=$VALUE\n\"; print; x=2; next}
   /\[.*\]/ {print;next}
   {print}
   END {if (x==0) print \"[$SECTION]\"; if (x==0 || x==1) print \"$VARIABLE=$VALUE\n\";}"
case $# in
 0) awk "$AWK_PROGRAM" ;;
 *)
  local i
  local TMPFILE=$(tmpfile)
  for i in "$@"; do
    awk 0<"$i" 1>$TMPFILE "$AWK_PROGRAM"
    cat $TMPFILE 1>"$i"
  done
  rm $TMPFILE
  ;;
esac
}

# This is needed, for instance, for ubuntu 10.10
function ensure_DisallowTCP_false_to_gdm_custom_dot_conf {
# global SUDO_OR_NOTHING CHANGED_FILES
local custom=${1:-/etc/gdm/custom.conf}
local TMPFILE=$(tmpfile)
cp $custom $TMPFILE
ensure_section_and_binding "security" "DisallowTCP" "false" $TMPFILE
ensure_section_and_binding "xdmcp" "Enable" "true" $TMPFILE
if ! diff -q $custom $TMPFILE >/dev/null; then
  CHANGED_FILES+="$custom "
  $SUDO_OR_NOTHING bash -c "cat $TMPFILE >$custom"
fi
}

# This is needed, for instance, for ubuntu 12.04
function ensure_xserver_allow_tcp_in_lightdm_dot_conf {
# global SUDO_OR_NOTHING CHANGED_FILES
local custom=${1:-/etc/lightdm/lightdm.conf}
local TMPFILE=$(tmpfile)
cp $custom $TMPFILE
ensure_section_and_binding "SeatDefaults" "xserver-allow-tcp" "true" $TMPFILE
if ! diff -q $custom $TMPFILE >/dev/null; then
  CHANGED_FILES+="$custom "
  $SUDO_OR_NOTHING bash -c "cat $TMPFILE >$custom"
fi
}


function apply_all_filters {
# global CHANGED_FILES
local i=$1
cat $i > $BACKUP
{ remove_nolisten_assignment_from $i;
  remove_DisallowTCP_from $i;
  remove_nolisten_X_or_startx_actuals_from $i;
  } || true
diff -q $BACKUP $i >/dev/null || {
  CHANGED_FILES+="$i "
  }
}

function adjust_X_display_manager {
# global SUDO_OR_NOTHING CHANGED_FILES
local BACKUP=$(tmpfile)
DIRS=$($SUDO_OR_NOTHING find /etc/ -type d -name "?dm")
if [[ -d /etc/X11/xinit ]]; then DIRS+=" /etc/X11/xinit/"; fi
FILES=$([[ -n $DIRS ]] && $SUDO_OR_NOTHING find $DIRS -name "*rc" -o -name "*.conf")
FILES=$(for i in $FILES; do grep -l "^[a-zA-Z0-9/_\-= ]*[-]nolisten tcp" $i; done)
for i in $FILES; do apply_all_filters $i; done
rm -f $BACKUP
# A special case: gdm/gdm3 :
if [[ -d /etc/gdm ]]; then
  $SUDO_OR_NOTHING touch /etc/gdm/custom.conf
  ensure_DisallowTCP_false_to_gdm_custom_dot_conf
elif [[ -d /etc/gdm? ]]; then
  $SUDO_OR_NOTHING touch /etc/gdm?/custom.conf /etc/gdm?/daemon.conf
  ensure_DisallowTCP_false_to_gdm_custom_dot_conf /etc/gdm?/custom.conf
  ensure_DisallowTCP_false_to_gdm_custom_dot_conf /etc/gdm?/daemon.conf
fi
# Another special case: lightdm
if [[ -d /etc/lightdm ]]; then
  $SUDO_OR_NOTHING touch /etc/lightdm/lightdm.conf
  ensure_xserver_allow_tcp_in_lightdm_dot_conf
fi
[[ -n $CHANGED_FILES ]]
}

# Main of this section:
# ---
# Obsolete for series after the 0.90.x and for trunk:
if [[ $MARIONNET_SERIES = "0.90.x" ]]; then
  if ps -A -o cmd | grep -q '^[a-zA-Z0-9/]*X.*[-]nolisten tcp'; then
  echo '---'
  echo "* Warning: your X server has been launched with the option '-nolisten tcp'"
  echo "  => This option should be removed from your X display manager configuration."
  echo -n "     Shall I try to fix it ([y]/n)? "
  read z
  if [[ $z != n && $z != N ]]; then
    if adjust_X_display_manager; then
      echo "     Ok. File(s) changed: $CHANGED_FILES"
      echo "     You must restart your X display manager for the changes to take effect."
    else
      echo "     Sorry, no change performed: you must edit your configuration manually."
    fi
  fi
  fi
fi

# =============================================================
#               Fix problems in Debian or derived
# =============================================================

if are_we_in_debian_or_derived; then
  if type update-rc.d; then
    $SUDO_OR_NOTHING update-rc.d marionnet-daemon defaults
  elif type insserv; then
    $SUDO_OR_NOTHING insserv marionnet-daemon
  fi
fi 1>/dev/null 2>/dev/null

# =============================================================
#                  Fix problems in Ubuntu
# =============================================================

if are_we_in_ubuntu_11_or_greater ; then
  echo "* Warning: Ubuntu (>= 11.x) systems require to launch marionnet with UBUNTU_MENUPROXY=0"
  echo "  => The problem may be solved defining an alias in your shell configuration:"
  echo "     alias marionnet='UBUNTU_MENUPROXY=0 marionnet'"
  case $USER in
   root)
     DEST='/etc/profile'
     echo -n "     Shall I add this line to $DEST ([y]/n)? "
     ;;
   *)
     DEST=~/.bashrc
     echo -n "     Shall I add this line to your ~/.bashrc ([y]/n)? "
     ;;
  esac
  read z
  if [[ $z != n && $z != N ]]; then
    append_line_if_needed "alias marionnet='UBUNTU_MENUPROXY=0 marionnet'" $DEST
  fi
fi

function is_the_packaged_vde2_version_lt_2_3_0 {
 local VDE2_VERSION
 if type 1>&2 aptitude && type 1>&2 vde_switch; then
   VDE2_VERSION=$(aptitude show vde2 | awk '/^Version.*[2-9][.][0-9][.][0-9].*/ {print $2}' | awk -F '-' '{print $1}')
   VDE2_VERSION=$(echo $VDE2_VERSION | awk -F '.' '(($2 * 100 + $3 * 10 + $4) <= 230) {print}')
   [[ -n "$VDE2_VERSION" ]]
 else
   return 1
 fi
}

if are_we_in_ubuntu_12_04 && is_the_packaged_vde2_version_lt_2_3_0; then
  echo "* Warning: Ubuntu 12.04 systems have an old packaged version of vde2"
  echo "  => The problem may be solved installing a vde2 backport (Virtualization)"
  echo "     (see: https://launchpad.net/~pdffs/+archive/precise-virt)"
  echo -n "     Shall I install the vde2 backport ([y]/n)? "
  read z
  if [[ $z != n && $z != N ]]; then
    launch_and_log --sudo "Installing vde2 backport for Ubuntu 12.04" "add-apt-repository -y ppa:pdffs/precise-virt && { aptitude update; aptitude install -y vde2; }"
  fi
fi

# =============================================================
#       Fix problems with uml-utilities (port-helper)
# =============================================================

# Sometimes the program `port-helper' is not installed 
# in the PATH, so:
if type -t port-helper 1>&2 || test -x $PREFIX/bin/port-helper; then
  echo "* Fine, port-helper is in the path."
else
  PORT_HELPER=$(find $(find /usr/ -maxdepth 2 -type d -name "lib*") -maxdepth 2 -type f -name port-helper -print -quit)
  if [[ -n $PORT_HELPER && -x $PORT_HELPER  && $PORT_HELPER != $PREFIX/bin/port-helper ]]; then
    $SUDO_OR_NOTHING ln -sf $PORT_HELPER $PREFIX/bin/port-helper || true
    echo "* Warning: port-helper was not in the binaries' path => fixed with a symlink."
  else
    echo "* Warning: port-helper is not in the binaries' path neither in the directory /usr."
  fi
fi

# =============================================================
#                         Adjust PATH
# =============================================================

# Path warning:
if echo "$PATH_BACKUP" | tr ':' '\n' | grep -q "$PREFIX/bin"; then
 echo "PATH contains $PREFIX/bin. Good." 1>&2
else
 echo '---'
 echo "* Warning: the path $PREFIX/bin seems not to be contained in your PATH."
 echo "  => Put something like the following line in your shell configuration:"
 echo "     export PATH=$PREFIX/bin:$PREFIX/sbin:\$PATH"
 case $USER in
   root)
     DEST='/etc/profile'
     echo -n "     Shall I add this line to $DEST ([y]/n)? "
     ;;
   *)
     DEST=~/.bashrc
     echo -n "     Shall I add this line to your ~/.bashrc ([y]/n)? "
     ;;
 esac
 read z
 if [[ $z != n && $z != N ]]; then
   append_line_if_needed "export PATH=$PREFIX/bin:$PREFIX/sbin:\$PATH" $DEST
 fi
fi


# =============================================================
#                       Adjust LOCALES
#     `/usr/share/locale'  vs  `/usr/local/share/locale'
# =============================================================

# When PREFIX is set to `/usr/local' ocamlbricks and marionnet install their
# locale-related files in `$PREFIX/share/locale' (i.e. `/usr/local/share/locale')
# while some distributions install their locales into `/usr/share/locale'
# ignoring files installed in `/usr/local/share/locale'
# (for instance Ubuntu 12.04 LTS 64 bits). So:
if [[ $PREFIX = "/usr/local" && -d "/usr/share/locale/" && -d "/usr/local/share/locale" ]]; then
PROBABLY_GOOD="/usr/share/locale/"
PROBABLY_BAD="/usr/local/share/locale"
COUNT_GOOD=$(find $PROBABLY_GOOD -type f -name "*.mo" | wc -l)
COUNT_BAD=$(find $PROBABLY_BAD -type f -name "*.mo" | wc -l)
# Heuristic method (of course): is $COUNT_GOOD twenty times bigger then $COUNT_BAD?
if [[ $((COUNT_GOOD/COUNT_BAD)) -gt 20 ]]; then
  # Move `marionnet.mo' files from $PROBABLY_BAD to $PROBABLY_GOOD:
  echo -n "* Moving installed locales into $PROBABLY_GOOD"
  pushd >/dev/null $PROBABLY_BAD
  find . -name "marionnet.mo" | xargs tar -cf - | $SUDO_OR_NOTHING tar -C $PROBABLY_GOOD -xf -
  $SUDO_OR_NOTHING find . -name "marionnet.mo" -exec rm {} \;
  popd >/dev/null
  echo_at_right_side --newline "ok"
fi
fi

# =============================================================
#                        64-bit warning
# =============================================================

# 64-bit architecture warning:
if [[ -z $DISABLE_libc6_i386_WARNING ]]; then
 if type uname 1>&2 && [[ $(uname -m) = "x86_64" ]]; then
  echo '---'
  echo "* Warning: this is 64-bit architecture."
  echo "  => Make sure that the package libc6-i386 is installed."
 fi
fi

# =============================================================
#                          Mr Proper
# =============================================================

# Mr proper
echo '---'
if [[ $KEEP_DEBRIS = yes ]]; then
 echo -n "* Cleaning: $TWDIR not removed (-k)"
 echo_at_right_side --newline "ok"
else
 echo "* Cleaning..."
 rm -rf $TWDIR
fi

# =============================================================
#                          Notes
# =============================================================

# Where to install filesystems and kernels:
echo '---'
echo "* Notes:"
echo "  - Install additional filesystem in" $PREFIX/share/marionnet/filesystems/
echo "  - Install additional kernels in" $PREFIX/share/marionnet/kernels/
echo "  - Customize your installation by editing /etc/marionnet/marionnet.conf"

echo '---'
echo "Success."
exit 0
