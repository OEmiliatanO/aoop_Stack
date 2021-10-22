CC:=gcc
TARGET=main

all: ${TARGET}.o stack.o
	$(CC) -o ${TARGET} ${TARGET}.o stack.o

dep: main.c stack.c
	$(CC) -c main.c
	$(CC) -c stack.c

clean:
	rm *.o ${TARGET}