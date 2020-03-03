#-------------
#Using makefile 
#-------------
# $@ target
# $^ components
# $< the first component
# MACROS ;; SOURCES= LL.c Stack.c main.c

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXEC=project

%.o : %.c 
	gcc -c $^ -o $@

$(EXEC) : BSTree.o fifo.o main.o
	gcc $^ -o $@

clean :
	rm $(OBJECTS) $(EXEC)
