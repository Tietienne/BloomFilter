#include "link.h"

typedef struct _table {
    link **bucket;
    int M;                      /* nombre de seaux */
    int size;                   /* nombre de mots dans la table */
} table;

table *create_table(int M);

void free_link(link* lk);
void free_table(table* tb);

int hashHash(char *str,int a,int M);

int insert(table* tb, char* str, int attempt);
link *table_find(table* tb, char *str);

void add_occ(table *tb, char *str, int pos);
void display_table(table *tb);