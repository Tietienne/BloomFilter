#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

node *create_node(char *word) {
	node *n = (node *)malloc(sizeof(node));
	assert(n != NULL);
	n->data = (char *)malloc((strlen(word)+1)*sizeof(char));
	strcpy(n->data, word);
	n->left = NULL;
	n->right = NULL;
	return n;
}

int equal_word(char *s1, char *s2) {
    return strcmp(s1, s2) == 0;
}

int less(char *s1, char *s2) {
    return strcmp(s1, s2) < 0;
}

// Affichage lexicographique
void display_infix(node *t) {
	if (t==NULL) {
		return;
	}

	display_infix(t->left);
	printf("%s ", t->data);
	display_infix(t->right);	
}

// Affichage des mots situés entre 2 autres
void display_between(node *t, char *word1, char *word2) {
	if (t==NULL) {
		return;
	}

	display_between(t->left, word1, word2);
	// On affiche dans les cas suivants : égal à word 1 ou à word 2, ou compris entre les 2
	if (equal_word(t->data, word1) || equal_word(t->data, word2) || (less(word1, t->data) && less(t->data, word2))) {
		printf("%s ", t->data);
	}
	display_between(t->right, word1, word2);	
}

void free_tree(node *t) {
	if (t==NULL) {
		return;
	}
	free(t->data);
	free_tree(t->left);
	free_tree(t->right);
	free(t);
}

node *insert_bst(node *t, char *elt) {
	if (t==NULL) {
		return create_node(elt);
	}
	if (!equal_word(t->data, elt)) {
		if (less(t->data, elt)) {
			t->right = insert_bst(t->right, elt);
		} else {
			t->left = insert_bst(t->left, elt);
		}
	}
	return t;
}

node *find_bst(node *t, char *elt) {
    node *ptr = t;
    while (ptr != NULL && !(equal_word(ptr->data, elt))) {
        if (less(ptr->data, elt))
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }
    return ptr;
}