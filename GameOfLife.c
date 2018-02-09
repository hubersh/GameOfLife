#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "GameOfLife.h"
#include "file_utilities.h"

/**
* Citation and game logic help
* https://rosettacode.org/wiki/Conway%27s_Game_of_Life#C
**/


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

	printf("Save (S), Load (L), continue another generation (C), continue some number of iterations (# of iterations), or quit (Q)?\n\n");

	int x;
	char* status;
	size_t len = 0;
	ssize_t read = getline(&status, &len, stdin);

	if (*status == 'S') {
		char newFile [1024];
		int size = 0;
		printf("Please provide a new filename: ");
		fgets(newFile, sizeof(newFile)-1, stdin); //Double Check -1
		write_file(newFile, buffer, size);
	} else if (*status == 'L'){
		char* newFile;
		printf("Please provide a filename to load: ");
		ssize_t read = getline(&newFile, &len, stdin);
		read_file(newFile, &buffer);
	} else if (*status == 'C'){
		; //Game Logic called here
	} else if ((x = atoi(status))){
		printf("%s\n","Hit");
		//Game Logic called here
	} else if (*status == 'Q'){
		printf("%s\n", "Thanks for playing!");
		exit(0);
	} else {
		printf("Please enter a valid input.");
	}
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