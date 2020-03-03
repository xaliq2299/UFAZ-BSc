SOURCES = main.c color.c image.c ppm.c
OBJECTS = $(SOURCES:.c=.o)

#question 1
#exec : image.c main.c color.c ppm.c
#	gcc main.c color.c ppm.c image.c -o exec

exec : $(OBJECTS)
	gcc $(OBJECTS) -o exec

objects : $(OBJECTS)	

%.o : %.c
	gcc -c $^ -o $@

tamiz : 
	rm *.o
