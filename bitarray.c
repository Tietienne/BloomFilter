#include "bitarray.h"
#include <stdio.h>
#include <stdlib.h>

bitarray *create_bitarray(int m) {
	bitarray* a = (bitarray*) malloc (sizeof(bitarray));

	if(a != NULL) {
		a->size = m;
		a->tab = (unsigned char*) malloc (sizeof(unsigned char)*m);
		
		int i = 0;
		for(i=0; i<m; i++) {
			a->tab[i] = 0;
		}
		if(a->tab == NULL) {
			fprintf(stderr, "Not enough memory ! Program abort !\n");
			exit(1);
		}
		return a;
	}
	fprintf(stderr, "Not enough memory ! Program abort !\n");
	exit(1);
}


void free_bitarray(bitarray *a) {
	free(a->tab);
	free(a);
}


void set_bitarray(bitarray *a, int pos) {
	if (pos>=0 && pos<=a->size && a!=NULL) {
		a->tab[pos] = 1;
	}
}

void reset_bitarray(bitarray *a, int pos) {
	if (pos>=0 && pos<=a->size && a!=NULL) {
		a->tab[pos] = 0;
	}
}

int get_bitarray(bitarray* a, int pos) {
	if (pos>=0 && pos<=a->size && a!=NULL) {
		return a->tab[pos];
	}
	return -1;
}

void clear_bitarray(bitarray *a) {
	if(a==NULL) {
		return;
	}
	int i = 0;
	for (i=0; i<a->size; i++) {
		a->tab[i] = 0;
	}
}