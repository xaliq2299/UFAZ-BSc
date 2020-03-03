SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

exec : $(OBJECTS)
	gcc $(OBJECTS) -o exec

%.o : %.c
	gcc -c $^ -o $@

clean : 
	rm *.o exec
