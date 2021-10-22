CC:=g++
TARGET=main

all: ${TARGET}.o stack.o
	$(CC) -o ${TARGET} ${TARGET}.o stack.o

dep: main.cpp stack.cpp
	$(CC) -c main.cpp
	$(CC) -c stack.cpp

clean:
	rm *.o ${TARGET}