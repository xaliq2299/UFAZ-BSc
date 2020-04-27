EXE=exploit1 vulnerable exp shellcodeasm
all: $(EXE)

CC=gcc
CFLAGS=-m32 -O0 -fno-stack-protector -z execstack -mpreferred-stack-boundary=2 -D_FORTIFY_SOURCE=0 -static -g
#CFLAGS=-m32 -static

clean:
	rm -f $(EXE)
