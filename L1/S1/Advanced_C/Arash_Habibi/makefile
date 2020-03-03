#ex1.c.bak : ex1.c hello.txt
#	cp ex1.c ex1.c.bak
	
#remove_backup : 
#	rm ex1.c.bak

#exec : source.c
#	echo "hello"
#source.c : exec
#	echo "bye"
	

CC=gcc
SOURCES = main.c color.c image.c ppm.c
OBJECTS = $(SOURCES:.c=.o)
COPTIONS = -Wall -g


color.o : color.c 
	gcc -c  $^ -o $@

image.o : image.c 
	gcc -c  $^ -o $@

ppm.o : ppm.c 
	gcc -c  $^ -o $@
	
color.o : color.c 
	gcc -c color.c -o color.o

main.o : main.c 
	gcc -c  $^ -o $@

%.o : %.c
	$(CC) $(COPTIONS) -c $^ -o $@	

exec : $(SOURCES)
	gcc $(SOURCES) -o exec
	
prog : $(OBJECTS) 
	gcc $(OBJECTS) -o prog
	
tryit : 
	echo $(OBJECTS)
	
try: ppm.c main.c 
	echo $^ #$@
