#-------------
#Using makefile 
#-------------
# $@ target
# $^ components
# $< the first component
# MACROS ;; SOURCES= LL.c Stack.c main.c

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXEC=extractStrip
FLAGS= -g -Wall

%.o : %.c 
	gcc $(FLAGS) -c $^ -o $@

$(EXEC) : $(OBJECTS)
	gcc $^ -o $@ $(FLAGS)

clean :
	rm $(OBJECTS) $(EXEC)
