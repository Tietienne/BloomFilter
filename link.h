#ifndef __LIST_H__
#define __LIST_H__

typedef struct _link {
    char *word;
    struct _link *next;
} link;


link *create_link(char word[]);
void free_link(link *lnk);

void free_list(link *lst);
int equal(char* w1, char* w2);

link *insert_first_list(link *lst, char word[]);

#endif