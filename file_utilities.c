#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "file_utilities.h"

/**
* Help with initial read of the file
* https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
*
* Help getting size of a file
* https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
**/

int rowCount = 0;
int colCount = 0;

int read_file(char* filename, char **buffer){
	int c;
	FILE *file = fopen(filename, "r");

	if (file) {
	    while ((c = getc(file)) != EOF){
	    	if (c == '\n'){
	    		rowCount++;
	    		colCount = 0;
	    	}
	        putchar(c);
	        colCount++;
	    }
	    printf("\n");

	    /*
	    * https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-of-a-file-and-write-that-to-another-file
	    */
	    int size;
		fseek(file, 0L, SEEK_END);
		size=ftell(file);
		*buffer = malloc(size*sizeof(char));
		rewind(file);
		fread(*buffer,size,1,file);
		fclose(file);
		return size;

	} else {
		size_t sz = strlen(filename);
		char temp[sz];
		memcpy(temp, &filename[0],sz);
		temp[sz-1]='\0';

		FILE *newFile = fopen(temp, "r");
		if(newFile){
			while ((c = getc(newFile)) != EOF){
				if (c == '\n'){
		    		rowCount++;
		    		colCount = 0;
		    	}
				putchar(c);
				colCount++;
			}
			printf("\n");

			int size;
			fseek(newFile, 0L, SEEK_END);
			size=ftell(newFile);
			*buffer = malloc(size*sizeof(char));
			rewind(newFile);
			fread(*buffer,size,1,newFile);
			fclose(newFile);
			return size;
		} else {
			perror("fopen");
			printf("\nProgram exited due to error.\n");
			exit(0);
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

	if (f){
		if (size == 0){
			fputs(buffer, f);
			free(buffer);
		} else {
			printf("%s\n", "HIT");
			int i, j = 0;
			for (i = 0; i < rowCount+1; i++){
			    for (j = 0; j < colCount-1; j++){
				    printf("%s", (buffer + i*colCount + j));
			    }
				printf("\n");
			}
		}
	} else {
		perror("fopen");
		printf("\nProgram exited due to error.\n");
		exit(0);
	}

	fclose(f);
	return 0;
}

int get_row(){
	return rowCount+1;
}
int get_col(){
	return colCount-1;
}



