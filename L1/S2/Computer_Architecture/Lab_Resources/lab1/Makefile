CC = gcc
CCFLAGS = -Wall
SRCS = tp1.c 
OBJS = $(SRCS:.c=.o)

tp1 : tp1.c tp1.o 
	@echo "Building $@"
	$(CC) $(CCFLAGS) -o $@ tp1.o 

.c.o :
	@echo "Building $@"
	$(CC) $(CCFLAGS) -o $@ -c $<

clean : 
	@rm *.o tp1 
	
all :
	make clean && make || make 
