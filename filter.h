#include "bitarray.h"

#ifndef FILTER_H
#define FILTER_H

typedef struct _filter {
	bitarray* a; /* The bitarray (With unsigned char for the moment) */
	int* weight; /* Int tab with a random value for each spot */
	int k; /* Amount of Hash functions */
} filter;

/* Return a pointer to an empty filter with parameters m and k */
filter *create_filter(int m, int k);

/* Free the memory associated with the filter */
void free_filter(filter *f);

/* Compute k hash values for the string str and place them in thearray hashes. */
void hash(filter *f, char *str, unsigned hashes[]);

/* Add the key str to the filter */
void add_filter(filter *f, char *str);

/* Check if the key str is in the filter, 0 means no, 1 means maybe */
int is_member_filter(filter *f, char *str);

/* Display the filter */
void display_filter(filter *f);

#endif /* FILTER_H */