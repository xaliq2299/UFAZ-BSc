#!/bin/sh

#
# Test de fonctionnalité de date (option -t)
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

for i in $(seq 1 10)
do
    date +%m:%Y
done > f1.tmp

$V ./detecter -t %m:%Y -i1 -l10 cat /dev/null > f2.tmp \
	&& cmp -s f1.tmp f2.tmp 		|| fail "date"

exit 0
