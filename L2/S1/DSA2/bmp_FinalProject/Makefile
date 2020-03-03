FLAGS= -Wall -lm -g


%.o: %.c 
	gcc $(FLAGS) -c $^ -o $@

resize: bmp.o resize.o
	gcc $^ -o $@ $(FLAGS)

stitch: bmp.o stitch.o
	gcc $^ -o $@ $(FLAGS)

clean: 
	rm *.o resize stitch