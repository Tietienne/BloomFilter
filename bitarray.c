#include "bitarray.h"
#include <stdio.h>
#include <stdlib.h>

bitarray *create_bitarray(int m) {
	bitarray* a = (bitarray*) malloc (sizeof(bitarray));
	a->tab = (unsigned char*) malloc (sizeof(unsigned char)*m);
	a->size = m;
	return a;
}


void free_bitarray(bitarray *a) {
	free(a->tab);
	free(a);
}


void set_bitarray(bitarray *a, int pos) {
	if (pos>=0 && pos<=a->size) {
		a->tab[pos] = 1;
	}
}

void reset_bitarray(bitarray *a, int pos) {
	if (pos>=0 && pos<=a->size) {
		a->tab[pos] = 0;
	}
}

int get_bitarray(bitarray* a, int pos) {
	if (pos>=0 && pos<=a->size) {
		return a->tab[pos];
	}
	return -1;
}

void clear_bitarray(bitarray *a) {
	for (int i=0; i<a->size; i++) {
		a->tab[i] = 0;
	}
}