CC = gcc
CCFLAGS = -Wall
SRCS = tp2.c 
OBJS = $(SRCS:.c=.o)

tp2 : tp2.c tp2.o 
	@echo "Building $@"
	$(CC) $(CCFLAGS) -o $@ tp2.o 

.c.o :
	@echo "Building $@"
	$(CC) $(CCFLAGS) -o $@ -c $<

clean : 
	@rm *.o tp2 
	
all :
	make clean && make || make 

