SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES: .c = .o)
EXEC = project

%.o: %.c
	gcc -c $^ -o $@

$(EXEC):  $(OBJECTS)
	gcc $^ -o $@
	
clean: 
	rm $(OBJECTS) $(EXEC)
