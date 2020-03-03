# Options utiles a la compilation
CFLAGS = -g -Wall -Wextra -std=c11

SRCS = associative_cache_simulation.c direct_cache_simulation.c test_associative_cache.c test_direct_cache.c associative_cache.c direct_cache.c bits.c

# Par defaut, on fait tout
all:	test_direct_cache direct_cache_simulation test_associative_cache associative_cache_simulation

# Edition de liens des divers programmes
test_direct_cache: test_direct_cache.o direct_cache.o bits.o
	@echo "Building $@"
	cc $(CFLAGS) -o test_direct_cache test_direct_cache.o direct_cache.o bits.o

direct_cache_simulation: direct_cache_simulation.o direct_cache.o bits.o
	@echo "Building $@"
	cc $(CFLAGS) -o direct_cache_simulation direct_cache_simulation.o direct_cache.o bits.o 

test_associative_cache: test_associative_cache.o associative_cache.o direct_cache.o bits.o
	@echo "Building $@"
	cc $(CFLAGS) -o test_associative_cache test_associative_cache.o associative_cache.o direct_cache.o bits.o

associative_cache_simulation: associative_cache_simulation.o associative_cache.o direct_cache.o bits.o
	@echo "Building $@"
	cc $(CFLAGS) -o associative_cache_simulation associative_cache_simulation.o associative_cache.o direct_cache.o bits.o

.c.o :
	@echo "Building $@"
	cc $(CFLAGS) -o $@ -c $< 

# Pour indiquer les dependances non implicites
test_direct_cache.o: direct_cache.h

direct_cache_simulation.o: direct_cache.h

direct_cache.o: bits.h

associative_cache.o: direct_cache.h

associative_cache_simulation.o: associative_cache.h

test_associative_cache.o: associative_cache.h

# Utile pour y voir clair
clean:
	rm -f *.o test_direct_cache direct_cache_simulation test_associative_cache associative_cache_simulation
