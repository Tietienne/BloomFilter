#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

table *create_table(int M){
    table* tb = malloc(sizeof(table));
    tb->M = M;
    tb->size = 0;
    tb->bucket = calloc((size_t)tb->M, sizeof(link));
    return tb;
}

void free_table(table* tb){
    int i =0;
    for(i=0 ;i<tb->M ;i++){
        link* lk = tb->bucket[i];
        if(lk != NULL) {
            free_link(lk);
        }
    }
    free(tb->bucket);
    free(tb);
}

int hashHash(char *str,int a,int M){
    int hash = 0;
    int i = 0;
    int str_lenght= strlen(str);
    for(i=0; i<str_lenght; i++){
        hash += (a * str[i]);
    }
    hash = hash%M;
    return hash;
}

link *table_find(table* tb, char *str){
    int index = hashHash(str, 31, tb->M);
    link* lk = NULL;
    for(lk = tb->bucket[index];lk != NULL; lk=lk->next){
        if(equal(lk->word, str)){
            return lk;
        }
    }
    return NULL;
}

void add_occ(table *tb, char *str, int pos){
    link* lk = table_find(tb, str);
    int index = hashHash(str, 31, tb->M);
    if(lk != NULL){
        add_occurrence(lk,pos);
    } else {
        tb->bucket[index] = insert_first_list(tb->bucket[index],str,pos);
    }
    tb->size++;
    return;
}