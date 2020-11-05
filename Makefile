CC=g++

CFLAGS=-c -Wall

all: task

task: main.o BMP_Reader.o
		$(CC) main.o BMP_Reader.o -o task

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

BMP_Reader.o: BMP_Reader.cpp
		$(CC) $(CFLAGS) BMP_Reader.cpp

clean:
		rm -rf *o task

