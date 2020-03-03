SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
CC=gcc
LIB=lMaze
HEADERS=include
DEBUGGER=g
EXEC=maze

$(EXEC): $(OBJECTS)
	$(CC) -Wall $^ -I $(HEADERS) -L. -$(LIB) -o $@ -lm -$(DEBUGGER)

%.o: %.c
	$(CC) -c $^ -I $(HEADERS) -o $@

clean:
	rm $(EXEC) *.o *.ppm
