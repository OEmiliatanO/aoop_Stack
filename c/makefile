CC:=gcc

all: main.o stack.o
	$(CC) -o main main.o stack.o
dep: main.c stack.c
	$(CC) -Wall -c main.c
	$(CC) -Wall -c stack.c
clean:
	rm *.o