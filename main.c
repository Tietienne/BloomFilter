#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include "bitarray.h"
#include "filter.h"

const char* program_name;

void print_usage(FILE* stream, int exit_code) {
    fprintf(stream, "Utilisation : %s options [-f -k ...]\n",program_name);
    fprintf(stream,
        "-h --help      Affiche ce message.\n"
        "-f --file      Donne le nom du fichier à charger.\n"
        "-v --verbose   Affiche les messages détaillés.\n"
        "-k             Donne le nombre de fonctions de hachage.\n"
        "-m             Donne le nombre de bit dans le bit array.\n");
    exit(exit_code);
}

int main(int argc, char *argv[]) {
    const char* const short_options = "hf:vk:m:";
    const struct option long_options[] = {
        {"help"   , 0, NULL, 'h'},
        {"file"   , 0, NULL, 'f'},
        {"verbose", 1, NULL, 'v'},
        {NULL     , 0, NULL, 'k'},
        {NULL     , 0, NULL, 'm'},
        {NULL     , 0, NULL,  0 }
    };

    const char* output_filename = NULL;
    const char* file_to_read = NULL;
    int verbose = 0, k = 0, m = 0;
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
        case 'v':
            verbose = 1;
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

    if(verbose) {
        int i;
        for(i = optind; i<argc; ++i) {
            printf("Argument : %s\n", argv[i]);
        }
    }

    /*TODO Programme ici*/

    return 0;
}