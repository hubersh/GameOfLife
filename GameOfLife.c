#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* Citation and game logic help
* https://rosettacode.org/wiki/Conway%27s_Game_of_Life#C
**/


int read_file(char* filename, char **buffer){
	return 0;
}

int write_file(char* filename, char *buffer, int size){
	return 0;
}

/**
* Citation and inspiration
* https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
**/
int createArray(r, c){
	int *arr = (int *)malloc(r * c * sizeof(int));

	int i, j = 0;//, count = 0;
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			int val = rand() %11;
			if (val <= 6){
				*(arr + i*c + j) = 0;
			}
			else if (val > 6 && val < 9){
				*(arr + i*c + j) = 1;
			}
			else{
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

void game(int w, int h){
	createArray(w, h);
}

int main(int c, char **v){
	//Size of the file name
	char filename [100];

	//If no user input prompt for filename
	if(c <= 1) {
		printf("Hello. Please include a filename:\n");
		fgets(filename,100,stdin);
		printf("%s\n", filename);
		//PASS FILE HERE
	} else { 
		printf("%s\n", v[1]);
		//PASS FILE HERE
	}
	
	// int w = 0;
	// int h = 0;
	// if (c > 1){ w = v[1] }
	// if (c > 2){ h = atoi(v[2]); }
	// if (w <= 0){ w = 4; }
	// if (h <= 0){ h = 5; }
	// game(w, h);

}