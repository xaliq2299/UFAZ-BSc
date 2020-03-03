


CC = gcc
COPTIONS = -g -Wall

grid2D : main.o grid2D.o
	$(CC) $(COPTIONS) $^ -o $@

grid1D : main.o grid1D.o
	$(CC) $(COPTIONS) $^ -o $@

%.o : %.c
	$(CC) $(COPTIONS) -c $^ -o $@

clean :
	rm *.o grid1D grid2D
