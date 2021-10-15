CC:=g++

all: main.o stack.o
	$(CC) -o main main.o stack.o
dep: main.cpp stack.cpp
	$(CC) -Wall -c main.cpp
	$(CC) -Wall -c stack.cpp
clean:
	rm *.o