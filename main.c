#include "bitarray.h"
#include "filter.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	filter *f = create_filter(100,2);
	
	add_filter(f, "oui");

	if(is_member_filter(f,"oui")){
		printf("Member\n");
	} else {
		printf("No!\n");
	}

	if(is_member_filter(f,"non")){
		printf("Member\n");
	} else {
		printf("No!\n");
	}

	free_filter(f);
	return 0;
}