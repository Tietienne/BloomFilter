CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
LDFLAGS=-lm
DEPS=bitarray.h filter.h link.h hashTable.h tree.h
OBJ=bitarray.o filter.o link.o hashTable.o tree.o
all:main test

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

test: test.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) test test.o