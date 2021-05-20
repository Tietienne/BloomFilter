#include "filter.h"
#include <stdio.h>
#include <stdlib.h>

filter *create_filter(int m, int k) {
	filter* f = (filter*) malloc (sizeof(filter));
	f->a = create_bitarray(m);
	f->poids = (int*) malloc (sizeof(int)*k);
	for (int i=0; i<k; i++) {
		f->poids[i] = 2; // Prendre une valeur aléatoire entre 2 et 255 à la place du 2
	}
	return f;
}

void free_filter(filter *f) {
	free_bitarray(f->a);
	free(f->poids);
	free(f);
}

void hash(filter *f, char *str, unsigned hashes[]) {

}

void add_filter(filter *f, char *str) {

}

int is_member_filter(filter *f, char *str) {
	return 0;
}