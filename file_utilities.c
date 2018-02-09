#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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

		size_t sz = strlen(filename);
		char temp[sz];
		memcpy(temp, &filename[0],sz);
		temp[sz-1]='\0';

		FILE *newFile = fopen(temp, "r");

		if(newFile){
			 while ((c = getc(newFile)) != EOF){
		        putchar(c);
		    }
		    fclose(newFile);
		} else {
			perror("fopen");
		}
	}
	printf("\n");
	return 0;
}

/*
* https://overiq.com/c-programming/101/fwrite-function-in-c/
* https://stackoverflow.com/questions/4214314/get-a-substring-of-a-char
*/
int write_file(char* filename, char *buffer, int size){
	printf("%s\n", filename);

	//Strip Extra Characters
	size_t sz = strlen(filename);
	char temp[sz];
	memcpy(temp, &filename[0],sz);
	temp[sz-1]='\0';

	FILE *f = fopen(temp, "wb");

	//Buffer currently has nothing so expect error.
	fwrite(buffer, sizeof(char), sizeof(buffer), f);
	fclose(f);
	return 0;
}