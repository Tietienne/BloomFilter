#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include "bitarray.h"
#include "filter.h"
#include "hashTable.h"
#include "link.h"

#define MAX_SIZE_PASSWORD 128

const char* program_name;

void print_usage(FILE* stream, int exit_code) {
    fprintf(stream, "Utilisation : %s options [-f -k ...]\n",program_name);
    fprintf(stream,
        "-h --help      Affiche ce message.\n"
        "-f --file      Donne le nom du fichier à charger.\n"
        "-k             Donne le nombre de fonctions de hachage.\n"
        "-m             Donne le nombre de bit dans le bit array.\n");
    exit(exit_code);
}

int main(int argc, char *argv[]) {
    const char* const short_options = "hf:k:m:";
    const struct option long_options[] = {
        {"help"   , 0, NULL, 'h'},
        {"file"   , 0, NULL, 'f'},
        {NULL     , 0, NULL, 'k'},
        {NULL     , 0, NULL, 'm'},
        {NULL     , 0, NULL,  0 }
    };
    const char* file_to_read = NULL;
    int k = 6, m = 8000;
    int next_option;
    
    program_name = argv[0];

    do {
        next_option = getopt_long(argc, argv, short_options,
                                    long_options, NULL);
        switch (next_option)
        {
        case 'h':
            print_usage(stdout, 0);
            break;
        case 'f':
            file_to_read = optarg;
            break;
        case 'k':
            k = atoi(optarg);
            break;
        case 'm':
            m = atoi(optarg);
            break;
        case '?':
            print_usage(stderr, 1);
            break;
        case -1:
            break;
        default:
            abort();
        }
    } while(next_option != -1);

    /*TODO Programme ici*/
    FILE* file = fopen(file_to_read,"r");
    if(file == NULL) {
        fprintf(stderr, "File doesn't exist.\n");
        exit(1);
    }

    filter* f = create_filter(m,k);
    table* hashTable = create_table(m);
    char word[MAX_SIZE_PASSWORD];
    double nbWord = 0;
    while( fscanf(file,"%1024s",word)==1 ) {
        nbWord++;
        add_filter(f, word);
        add_occ(hashTable, word);
    }
    fclose(file);

    FILE* file2 = fopen("word.txt","r");
    if(file2 == NULL) {
        fprintf(stderr, "File doesn't exist.\n");
        exit(1);
    }
    double maybe = 0;
    double isin = 0;
    double nbWordTested = 0;
    while( fscanf(file2,"%1024s",word)==1 ) {
        nbWordTested++;
        if(is_member_filter(f, word)) {
            maybe++;
            if(table_find(hashTable, word) != NULL) {
                isin++;
            }
        }
    }
    fclose(file2);
    free_filter(f);
    free_table(hashTable);

    printf("%f -> %f\n",nbWordTested,nbWord);
    printf("%f -> %f\n",maybe, isin);
    return 0;
}