#ifndef TREE_H
#define TREE_H

typedef struct _node {
    char *data;                /* data stored : a char    */
    struct _node *left;      /* pointer to the left child   */
    struct _node *right;     /* pointer to the right child  */
} node;

/*
 * Allocate memory for a new node.
 */
node *create_node(char *word);

/*
 * Display the tree in lexicographic order.
 */
void display_infix(node *t);

/*
 * Display the words between 2 words.
 */
void display_between(node *t, char *word1, char *word2);

/*
 * Free the memory associated to the tree t.
 */
void free_tree(node *t);

/*
 * Insert an element elt in the bst t. Or do nothing if the elt is already here.
 */
node *insert_bst(node *t, char *word);

/*
 * Find an element elt in the bst t. Return a node* or NULL.
 */
node* find_bst(node *t, char *elt);

#endif /* TREE_H */
