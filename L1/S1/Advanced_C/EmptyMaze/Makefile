LIB=lMaze
HEADERS=include

maze: main.c
	gcc main.c -I $(HEADERS) -L. -$(LIB) -o $@ -lm

clean:
	rm maze
