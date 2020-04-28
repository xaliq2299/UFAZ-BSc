#
# Ce Makefile contient les cibles suivantes :
#
# all		: compile les programmes
# clean		: supprime les fichiers générés automatiquement
# coverage	: compile les programmes pour mesurer la couverture de code
# test		: lance tous les tests (scripts shell test-xxx.sh)
#		  (sans appeler valgrind)
# gcov		: génère les rapports de couverture (à lancer après avoir
#		  lancé les cibles 'coverage' et 'test').
#		  Résultats dans *.gcov
# ctags		: génère un fichier tags pour la navigation avec vim.
#		  (voir http://usevim.com/2013/01/18/tags/)
#
# De plus, les cibles supplémentaires suivantes sont fournies pour
# simplifier les tâches répétitives :
#
# test-avec-valgrind	: lance les tests avec valgrind (conseillé)
# couverture-et-tests	: automatise les tests avec rapport de couverture
#

COV = -coverage
CFLAGS = -Wall -Wextra -Werror -g $(COVERAGE)
PROGS	= detecter
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
CC=gcc

all: ctags $(PROGS)

%.o: %.c
	$(CC) -c $^ -o $@

detecter: $(OBJECTS)
	$(CC) $^ -o $@

coverage: $(SOURCES)
	$(MAKE) clean
	$(MAKE) COVERAGE=$(COV)
	$(CC) -fprofile-arcs -ftest-coverage $^ -o $(PROGS)

gcov: 
	gcov $(SOURCES)

# Par défaut, "test" lance les tests sans valgrind.
# Si on souhaite utiliser valgrind (conseillé), positionner la
# variable VALGRIND ou utiliser la cible "test-avec-valgrind"

test:	test-sans-valgrind

test-sans-valgrind: all
	@for i in test-*.sh ; do echo $$i ; sh $$i || exit 1 ; done

test-avec-valgrind: all
	VALGRIND="valgrind -q" ; export VALGRIND ; for i in test-*.sh ; do echo $$i ; sh $$i || exit 1 ; done

couverture-et-tests: clean coverage test gcov

ctags:
	ctags *.[ch]

clean:
	rm -f $(PROGS) *.o
	rm -f *.gc*
	rm -f *.log *.tmp
	rm -f tags core