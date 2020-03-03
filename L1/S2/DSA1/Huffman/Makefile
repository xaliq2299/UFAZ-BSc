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

$(EXEC) : $(OBJECTS)
	gcc $^ -o $@ -lm

clean :
	rm $(OBJECTS) $(EXEC)
