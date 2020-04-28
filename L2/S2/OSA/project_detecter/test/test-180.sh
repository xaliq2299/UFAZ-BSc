#!/bin/sh

#
# Test avec un fichier binaire
#

TEST=$(basename $0 .sh)

TMP=/tmp/$TEST
LOG=$TEST.log
V=${VALGRIND}		# appeler avec la var. VALGRIND à "" ou "valgrind -q"

exec 2> $LOG
set -x

rm -f *.tmp

fail ()
{
    echo "==> Échec du test '$TEST' sur '$1'."
    echo "==> Log : '$LOG'."
    echo "==> Exit"
    exit 1
}

# Tester deux fichiers binaires radicalement différents

dd if=/dev/urandom bs=1000k count=1 of=f1.tmp
dd if=/dev/urandom bs=1000k count=1 of=f2.tmp

cat > script.tmp <<'EOF'
#!/bin/sh
    # script pour générer f1 et f2, et afficher f1 puis f2
    if [ ! -f f1-fait.tmp ]
    then
	cat f1.tmp
	touch f1-fait.tmp
    else cat f2.tmp
    fi
    exit 0
EOF
chmod +x script.tmp

cat f1.tmp f2.tmp > f3.tmp

$V ./detecter -i1 -l2 ./script.tmp > f4.tmp \
	&& cmp -s f3.tmp f4.tmp			|| fail "binaire 1"

# Tester deux fichiers binaires très légèrement différents

dd if=/dev/urandom bs=12345 count=1 of=f1.tmp
cp f1.tmp f2.tmp
/usr/bin/printf "\x00 1" >> f1.tmp
/usr/bin/printf "\x00 2" >> f2.tmp
rm -f f1-fait.tmp

cat > script.tmp <<'EOF'
#!/bin/sh
    # script pour générer f1 et f2, et afficher f1 puis f2
    if [ ! -f f1-fait.tmp ]
    then
	cat f1.tmp
	touch f1-fait.tmp
    else cat f2.tmp
    fi
    exit 0
EOF
chmod +x script.tmp

cat f1.tmp f2.tmp > f3.tmp

$V ./detecter -i1 -l2 ./script.tmp > f4.tmp \
	&& cmp -s f3.tmp f4.tmp			|| fail "binaire 2"

exit 0
