#!/bin/sh

#
# Test avec de gros volumes
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

cat > script.tmp <<'EOF'
#!/bin/sh
    # script pour faire un doublement exponentiel
    F=f1.tmp
    if [ -f $F ]
    then cat $F $F > $F.new && mv $F.new $F
    else echo x > $F
    fi
    cat $F
EOF
chmod +x script.tmp

N=24		# fichier de 2^N octets
N=18
rm -f f1.tmp
$V ./detecter -i1 -l$N ./script.tmp > /dev/null	|| fail "gros volume devnull"

for i in $(seq 1 6)
do
    cat f1.tmp
done > f3.tmp	# f3 = 6 * f1

$V ./detecter -i1 -l2 ./script.tmp > f2.tmp \
    && cmp -s f2.tmp f3.tmp 		|| fail "gros volume test"

exit 0
