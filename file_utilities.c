#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "file_utilities.h"

/**
* Help with initial read of the file
* https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
**/

int read_file(char* filename, char **buffer){

	int c;
	
	FILE *file = fopen(filename, "r");

	if (file) {
	    while ((c = getc(file)) != EOF){
	    	// if(c == '\n'){
	    	// 	putchar('H');
	    	// }
	        putchar(c);
	    }
	    fclose(file);
	} else {
		perror("fopen");
	}
	printf("\n");
	return 0;
}

int write_file(char* filename, char *buffer, int size){
	printf("%s\n", filename);
	return 0;
}