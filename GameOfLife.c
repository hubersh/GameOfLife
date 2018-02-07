#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

	//https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
	fseek(file, 0L, SEEK_END);
	int sz = ftell(file);
	fseek(file, 0L, SEEK_SET);

	printf("%d\n", sz);

	if (file) {
	    while ((c = getc(file)) != EOF){
	    	if(c == '\n'){
	    		putchar('H');
	    	}
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
int createArray(r, c){
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