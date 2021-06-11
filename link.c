#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"


link *create_link(char word[]) {
    link *lnk = malloc(sizeof(link));
    lnk->word = malloc(strlen(word)+1);
    strcpy(lnk->word, word);
    lnk->next = NULL;
    return lnk;
}

void free_link(link *lnk) {
    free(lnk->word);
    free(lnk);
}

void free_list(link *lst) {
    while (lst) {
        link *tmp = lst;
        lst = lst->next;
        free_link(tmp);
    }
    free(lst);
}

int equal(char* w1, char* w2) {
    return strcmp(w1, w2) == 0;
}

link *insert_first_list(link *lst, char word[]){
    link *tmp = create_link(word);
    tmp->next = lst;
    return tmp;
}