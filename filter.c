#include "filter.h"
#include "bitarray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

filter *create_filter(int m, int k) {
	srand(time(NULL));
	filter* f = (filter*) malloc (sizeof(filter));
	if(f == NULL) {
		fprintf(stderr, "Not enough memory ! Program abort !\n");
		exit(1);
	}
	f->k = k;
	f->a = create_bitarray(m);
	f->weight = (int*) malloc (sizeof(int)*k);
	if(f->weight == NULL) {
		fprintf(stderr, "Not enough memory ! Program abort !\n");
		exit(1);
	}
	for (int i=0; i<k; i++) {
		f->weight[i] = rand() % 255;
	}
	return f;
}

void free_filter(filter *f) {
	free_bitarray(f->a);
	free(f->weight);
	free(f);
}

void hash(filter *f, char *str, unsigned hashes[]) {
	int i = 0, j = 0;
	int lenght = strlen(str);
	for(i=0; i<f->k; i++) {
		int hash_value = 0;
		for(j=0; j<lenght; j++) {
			hash_value += pow((double)(f->weight[i]),(double)(lenght-i)) * (int)str[i];
		}
		hashes[i] = hash_value % f->a->size;
	}
}

void add_filter(filter *f, char *str) {
	int i = 0;
	unsigned hashes[f->k];
	hash(f, str, hashes);
	for(i=0; i<f->k; i++) {
		set_bitarray(f->a, hashes[i]);
	}
}

int is_member_filter(filter *f, char *str) {
	int i = 0;
	unsigned hashes[f->k];
	hash(f, str, hashes);
	for(i=0; i<f->k; i++) {
		if(!get_bitarray(f->a, hashes[i])) {
			return 0;
		}
	}
	return 1;
}

void display_filter(filter *f) {
	int i = 0;
	printf("BitArray of the filter :\n");
	for(i = 0; i < f->a->size; i++) {
		printf("%d\n",f->a->tab[i]);
	}
}