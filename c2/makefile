CC:=gcc

all: main.o stack.o
	$(CC) -o main main.o stack.o
dep: main.c stack.c
	$(CC) -c main.c
	$(CC) -c stack.c
clean:
	rm *.o