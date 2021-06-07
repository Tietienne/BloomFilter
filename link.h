#ifndef __LIST_H__
#define __LIST_H__

typedef struct _olink {
    int pos;
    struct _olink *next;
} olink;

typedef struct _link {
    char *word;
    olink *occurrences;     /* liste des occurrences */
    struct _link *next;
} link;


link *create_link(char word[]);
void free_link(link *lnk);

void display_list(link *lst);
int count_list(link *lst);

void free_occ(link *lnk);
void free_list(link *lst);
int equal(char* w1, char* w2);

link *find_list(link *lst, char word[], int pos);
link *insert_first_list(link *lst, char word[],int pos);

void add_occurrence(link *lnk, int pos);

#endif