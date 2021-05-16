#ifndef BITARRAY_H
#define BITARRAY_H

typedef struct _bitarray {
	/* TO DO */
} bitarray;

/* Return a pointer to an empty bitarray that can store m bits */
bitarray *create_bitarray(int m);

/* Free the memory associated with the bitarray */
void free_bitarray(bitarray *a);

/* Set position pos in the bitarray to 1 */
void set_bitarray(bitarray *a, int pos);

/* Set position pos in the bitarray to 0 */
void reset_bitarray(bitarray *a, int pos);

/* Get the value at position pos in the bitarray */
int get_bitarray(bitarray* a, int pos);

/* Set all positions in the bitarray to 0 */
void clear_bitarray(bitarray *a);

#endif /* BITARRAY_H */