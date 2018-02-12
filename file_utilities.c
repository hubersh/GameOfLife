#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "file_utilities.h"

/**********************************************
 Library for reading and writing files

 @author Hunter Hubers
 @author Sam Carson
 @version Winter 2018
***********************************************/


/**
* Citation and inspiration for...
*
* Help with initial read of the file
* https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
* author: Alok Singhal
*
* Help getting size of a file
* https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
* authors: vaxquis and Rob Walker
**/


/***************************************************
 Reads a file into an array
 
 @param filename name of the file to open
 @param buffer array to fill
***************************************************/
int read_file(char* filename, char **buffer){
	int c;
	int rowCount = 0;
	int colCount = 0;
	
	//open the file
	FILE *file = fopen(filename, "r");
	
	//checks for ? at end of filename
	if (file) {
	
		//get rows and cols and print file contents
	    while ((c = getc(file)) != EOF){
	    	if (c == '\n'){
	    		rowCount++;
	    		colCount = 0;
	    	}
	        putchar(c);
	        colCount++;
	    }
	    /*
	    * Citation and inspiration for reading a file into an array
	    * https://stackoverflow.com/questions/42033932/c-program-to-reverse-content-
	    * of-a-file-and-write-that-to-another-file
	    * author: Tom Zych
	    */
	    
	    //read the file contents to array
	    int size;
		fseek(file, 0L, SEEK_END);
		size=ftell(file);
		*buffer = malloc(size*sizeof(char));
		rewind(file);
		fread(*buffer,size,1,file);
		fclose(file);
		return size;
		
	//else if there was a ? at the end of the filename
	} else {
	
		//strip the last char(?) from the string
		size_t sz = strlen(filename);
		char temp[sz];
		memcpy(temp, &filename[0],sz);
		temp[sz-1]='\0';
		
		//open file
		FILE *newFile = fopen(temp, "r");
		if(newFile){
		
			//get rows and cols and print file contents
			while ((c = getc(newFile)) != EOF){
				if (c == '\n'){
		    		rowCount++;
		    		colCount = 0;
		    	}
				putchar(c);
				colCount++;
			}
			
			//read the file contents to array
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
* citation and inspiration for...
*
* using fputs to write an array to a file
* https://www.tutorialspoint.com/c_standard_library/c_function_fputs.htm
*
* stripping the last character from a string
* https://stackoverflow.com/questions/4214314/get-a-substring-of-a-char
* author: Andrew Medico
*/


/**************************************************************
 Writes a file from an array
 
 @param filename name of the file to write to
 @param buffer array to write from
 @param size size of the array contents
***************************************************************/
int write_file(char* filename, char *buffer, int size){
	//Strip Extra Characters
	size_t sz = strlen(filename);
	char temp[sz];
	memcpy(temp, &filename[0],sz);
	temp[sz-1]='\0';
	
	//open file
	FILE *f = fopen(temp, "wb");
	
	//check if f is a valid file
	if (f){
		fputs(buffer, f);
	} else {
		perror("fopen");
		printf("\nProgram exited due to error.\n");
		//free the array
		free(buffer);
		exit(0);
	}
	fclose(f);
	return 0;
}



