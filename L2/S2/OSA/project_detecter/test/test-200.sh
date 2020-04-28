#!/bin/sh

#
# Tests divers et variés
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

DN=/dev/null

# vérifier que :
# - -i prend bien un temps en ms
# - -l fonctionne bien
# - -t %s fonctionne bien

INTERV=5
$V ./detecter -i $((INTERV * 1000)) -t %s -l 2 cat $DN > f1.tmp \
						|| fail "test1-etape1"
[ $(cat f1.tmp | wc -l) = 2 ]			|| fail "test1-etape2"
N=$(awk 'BEGIN { i = 0 }
		{ tab[i++] = $1 }
	    END { printf "%d\n", tab[1]-tab[0] }' f1.tmp)
[ $N = $INTERV ]				|| fail "test1-etape3"

# vérifier que -c fonctionne bien
touch f1.tmp	# existe déjà, mais indépendance vis-à-vis des tests précédents
cat > script.tmp <<'EOF'
#!/bin/sh
    if [ -f f1.tmp ]
    then
	rm f1.tmp
	exit 0
    else
	exit 1
    fi
EOF
chmod +x script.tmp

(
    echo exit 0
    echo exit 1
) > f3.tmp

$V ./detecter -c -i1 -l2 ./script.tmp > f2.tmp \
	&& cmp -s f2.tmp f3.tmp			|| fail "-c"

exit 0
