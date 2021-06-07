#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"


link *create_link(char word[]) {
    link *lnk = malloc(sizeof(link));
    lnk->word = malloc(strlen(word)+1);
    strcpy(lnk->word, word);
    lnk->next = NULL;
    lnk->occurrences = NULL;
    return lnk;
}

void free_link(link *lnk) {
    while(lnk->occurrences != NULL) {
        olink* tmp = lnk->occurrences;
        lnk->occurrences = lnk->occurrences->next;
        free(tmp);
    }
    free(lnk->word);
    free(lnk);
}

void display_list(link *lst) {
    olink *tmp = NULL;
    while (lst) {
        printf("%s\n", lst->word);
        if(lst->occurrences != NULL){
            for(tmp= lst->occurrences;tmp !=NULL;tmp=tmp->next){
                printf("\t -> %d\n",tmp->pos);
                
            }
        }
        lst = lst->next;
    }
    free(tmp);
}

int count_list(link *lst){
    olink *tmp = NULL;
    int cpt=0;
    while (lst) {
        if(lst->occurrences != NULL){
            for(tmp= lst->occurrences;tmp !=NULL;tmp=tmp->next){
                cpt++;
            }
        }
        lst = lst->next;
    }
    free(tmp);
    return cpt;
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

void add_occurrence(link *lnk, int pos){
    olink *occ = malloc(sizeof(olink));
    occ->pos = pos;
    occ->next = lnk->occurrences;
    lnk->occurrences = occ;
    occ->pos = pos;
}

link *find_list(link* lst, char word[],int pos) {
    link *ptr = lst;

    while (ptr->next != NULL){
        if(equal(ptr->word, word)){
            add_occurrence(ptr, pos);
            return NULL;
        }
        ptr = ptr->next;
    }
    return ptr;
}

link *insert_first_list(link *lst, char word[], int pos){
    link *tmp = create_link(word);
    tmp->next = lst;
    add_occurrence(tmp, pos);
    return tmp;
}