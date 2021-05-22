CC=gcc
CFLAGS=-Wall -ansi -std=c99 -lm
DEPS=bitarray.h filter.h
OBJ=bitarray.o filter.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.c $(OBJ)
	$(CC) -lm -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) main main.o bitarray.o filter.o