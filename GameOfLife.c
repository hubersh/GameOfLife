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
int createArray(int r, int c, char** arr){
	// free(*arr)
	// char *arr;
	*arr = (char *)malloc(r * c * sizeof(char));
	int i, j = 0;//, count = 0;
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			int val = rand() %11;
			if (val <= 6){
				*(arr + i*c + j) = "0";
			} else if (val > 6 && val < 9){
				*(arr + i*c + j) = "1";
			} else {
				*(arr + i*c + j) = "2";
			}
		}
	}
	for (i = 0; i < r; i++){
	    for (j = 0; j < c; j++){
		    printf("%s", *(arr + i*c + j));
	    }
		printf("\n");
	}
	return 0;
}

char * getArray(){
	char* arr;
	return arr;
}



void game(char filename[]){
	printf("Filename: %s\n", filename);
	char* arr;
	int filesize = 0;
	filesize = read_file(filename, &arr);
	int switch1 = 0;
	int row, col = 0;


	int n = 0;
	while (n == 0) {
		printf("\nSave (S), Load (L), continue another generation (C), continue some number of iterations (# of iterations), or quit (Q)?\n\n");
		/*
		* https://www.gnu.org/software/libc/manual/html_node/Line-Input.html
		*/
		int x;
		char* status;
		size_t len = 0;
		ssize_t read = getline(&status, &len, stdin);

		if (*status == 'S' || *status == 's') {
			char newFile [1024];
			printf("Please provide a new filename: ");
			fgets(newFile, sizeof(newFile), stdin); //Double Check -1
			write_file(newFile, arr, switch1);
		} else if (*status == 'L' || *status == 'l'){
			char* newFile;
			printf("Please provide a filename to load: ");
			ssize_t read = getline(&newFile, &len, stdin);
			read_file(newFile, &arr);
			switch1 = 0;
		} else if (*status == 'C' || *status == 'c'){
			row = get_row();
			col = get_col();
			if (switch1 == 0){
				free(arr);
				arr = getArray();
			}
			createArray(row, col, &arr);
			switch1 = 1;
		} else if ((x = atoi(status))){
			printf("Progressing life along by %d generations\n", x);
			row = get_row();
			col = get_col();
			if (switch1 == 0){
				free(arr);
				arr = getArray();
			}
			createArray(row, col, &arr);
			switch1 = 1;
		} else if (*status == 'Q' || *status == 'q'){
			printf("%s\n", "Thanks for playing!");
			if(switch1 == 0){
				free(arr);
			}
			exit(0);
		} else {
			printf("Please enter a valid input.\nGame exiting.");
			if(switch1 == 0){
				free(arr);
			}
			exit(0);
		}
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