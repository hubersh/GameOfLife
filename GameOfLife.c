#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "GameOfLife.h"
#include "file_utilities.h"

/**********************************************
 Game of life/reading and writing files

 @author Hunter Hubers
 @author Sam Carson
 @version Winter 2018
***********************************************/


/**
* Citation and inspiration for handling array
* https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
* author: Abhay Rathi
**/



/***********************************************
 Handles user input and the logic for the game
 aswell as handling opening a file using 
 file_utilities library

 @param filename name of the file being opened
************************************************/
void game(char filename[]){
	printf("\nFilename: %s\n\n", filename);
	char* arr;
	int filesize = read_file(filename, &arr);

	int n = 0;
	while (n == 0) {
		printf("\n\nSave (S), Load (L), continue another generation (C), continue some number of iterations (# of 			iterations), or quit (Q)?\n\n");
		/*
		* https://www.gnu.org/software/libc/manual/html_node/Line-Input.html
		*/
		int x;
		char* status;
		size_t len = 0;
		ssize_t read = getline(&status, &len, stdin);
		
		//check for user input
		if (*status == 'S' || *status == 's') {
			char newFile [1024];
			printf("Please provide a new filename: ");
			fgets(newFile, sizeof(newFile), stdin);
			
			//write the file 
			write_file(newFile, arr, filesize);
		} else if (*status == 'L' || *status == 'l'){
			char* newFile;
			printf("Please provide a filename to load: ");
			ssize_t read = getline(&newFile, &len, stdin);
			
			//read the file
			read_file(newFile, &arr);
		} else if (*status == 'C' || *status == 'c'){
            int rows = 0;
            int cols = 0;
            
			//get number of cols and rows
            for (int i = 0; i < filesize; i++) {
                if((*(arr + i)) == '\n'){
                    rows++;
                    cols = 0;
                }
                cols++;
            }
            
            //randomly generate values for board
            for(int i = 0; i < rows + 1; i++){
                for(int j = 0; j < cols-1; j++){
            		int val = rand() %11;
            		if(*(arr + i*cols + j) == '\n'){
            			*(arr + i*cols + j) = '\n';
            		} else if (*(arr + i*cols + j) == '?'){
            			*(arr + i*cols + j) = ' ';
            		} else if (val <= 6){
						*(arr + i*cols + j) = '0';
					} else if (val > 6 && val < 9){
						*(arr + i*cols + j) = '1';
					} else {
						*(arr + i*cols + j) = '2';
					}
                }
            }
                
            //print the new board
            for (int i = 0; i < filesize; i++) {
                    printf("%c", *(arr + i));
            }
            

		} else if ((x = atoi(status))){
			printf("Progressing life along by %d generations\n\n", x);

            int rows = 0;
            int cols = 0;
			
			//get number of cols and rows
            for (int i = 0; i < filesize; i++) {
                if((*(arr + i)) == '\n'){
                    rows++;
                    cols = 0;
                }
                cols++;
            }
            
            //radnomly generate values for board
            for(int i = 0; i < rows + 1; i++){
                for(int j = 0; j < cols-1; j++){
            		int val = rand() %11;
            		if(*(arr + i*cols + j) == '\n'){
            			*(arr + i*cols + j) = '\n';
            		} else if (*(arr + i*cols + j) == '?'){
            			*(arr + i*cols + j) = ' ';
            		} else if (val <= 6){
						*(arr + i*cols + j) = '0';
					} else if (val > 6 && val < 9){
						*(arr + i*cols + j) = '1';
					} else {
						*(arr + i*cols + j) = '2';
					}
                }
            }
            
            //print the new board
            for (int i = 0; i < filesize; i++) {
                    printf("%c", *(arr + i));
            }
		} else if (*status == 'Q' || *status == 'q'){
			printf("%s\n", "Thanks for playing!");
			
			//quit game and free memory
			free(arr);			
			exit(0);
		} else {
			printf("Please enter a valid input.\nGame exiting.");
			
			//quit game and free memory
			free(arr);
			exit(0);
		}
	}
}


/**********************************************
 Checks if file name is included at game start
 
 @param c number of command line parameters
 @param v array of command line parameters
***********************************************/
int main(int c, char **v){
	//If no user input prompt for filename and quit
	if(c <= 1) {
		printf("\nHello. Please include a filename.\n");
		printf("For example: './a.out test.txt'\n\n");
		exit(0);
	} else { 
		//pass file name to game method
		game(v[1]);
	}
}
