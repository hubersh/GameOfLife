#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "GameOfLife.h"
/**
* Citation and game logic help
* https://rosettacode.org/wiki/Conway%27s_Game_of_Life#C
**/


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
	return 0;
}



/**
* Citation and inspiration
* https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
**/
int createArray(int r, int c){
	int *arr = (int *)malloc(r * c * sizeof(int));
	int i, j = 0;//, count = 0;
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			int val = rand() %11;
			if (val <= 6){
				*(arr + i*c + j) = 0;
			} else if (val > 6 && val < 9){
				*(arr + i*c + j) = 1;
			} else {
				*(arr + i*c + j) = 2;//++count;
			}
		}
	}
	for (i = 0; i < r; i++){
	    for (j = 0; j < c; j++){
		    printf("%d ", *(arr + i*c + j));
	    }
		printf("\n");
	}
	//Move for actual game
	free(arr);
	return 0;
}

void game(char filename[]){
	printf("Filename: %s\n", filename);
	char* buffer;
	read_file(filename, &buffer);

	int x;
	//char status [1024];

	printf("Save (S), Load (L), continue another generation (C), continue some number of iterations (# of iterations), or quit (Q)?\n");
	printf("\n");
	//new
	char* status;
	// fgets(status, sizeof(status), stdin);
	//new
	size_t len = 0;
	ssize_t read = getline(&status, &len, stdin);

	if (*status == 'S') {
		char newFile [1024];
		printf("Please provide a new filename: ");
		fgets(newFile, sizeof(newFile), stdin);
		//write_file(newFile, &buffer, size);

	} else if (*status == 'L'){
		char* newFile;
		printf("Please provide a filename to load: ");
		ssize_t read = getline(&newFile, &len, stdin);
		//printf(newFile);
		read_file(newFile, &buffer);

	} else if (*status == 'C'){
		;

	} else if ((x = atoi(status))){
		printf("%s\n","Hit");

	} else if (*status == 'Q'){
		exit(0);

	} else {
		printf("Please enter a valid input.");
	}

	// printf("%s\n", strlen(status));

}

int main(int c, char **v){
	//If no user input prompt for filename
	if(c <= 1) {
		printf("\nHello. Please include a filename.\n");
		printf("For example: './a.out test.txt'\n\n");
		exit(0);
	} else { 
		game(v[1]);
	}
}