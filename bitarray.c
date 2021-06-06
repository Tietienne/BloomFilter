#include "bitarray.h"
#include <stdio.h>
#include <stdlib.h>

bitarray *create_bitarray(int m) {
	bitarray* a = (bitarray*) malloc (sizeof(bitarray));

	if(a != NULL) {
		int nb_tab = m%8==0 ? m/8 : (m/8)+1;
		a->size = m;
		a->tab = (unsigned char*) malloc (sizeof(unsigned char)*nb_tab);
		
		int i = 0;
		for(i=0; i<nb_tab; i++) {
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
		int pos_tab = pos/8;
		int rem = pos%8;
		a->tab[pos_tab] = a->tab[pos_tab]|(1<<rem);
	}
}

void reset_bitarray(bitarray *a, int pos) {
	if (pos>=0 && pos<=a->size && a!=NULL) {
		int pos_tab = pos/8;
		int rem = pos%8;
		a->tab[pos_tab] = a->tab[pos_tab]&~(1<<rem);
	}
}

int get_bitarray(bitarray* a, int pos) {
	if (pos>=0 && pos<=a->size && a!=NULL) {
		int pos_tab = pos/8;
		int rem = pos%8;
		return a->tab[pos_tab]&1<<rem ? 1 : 0;
	}
	return -1;
}

void clear_bitarray(bitarray *a) {
	if(a==NULL) {
		return;
	}
	int i = 0;
	int nb_tab = a->size%8==0 ? a->size/8 : (a->size/8)+1;
	for (i=0; i<nb_tab; i++) {
		a->tab[i] = 0;
	}
}