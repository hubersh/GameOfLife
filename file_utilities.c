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
* 
* Help converting int to char* -- sprintf
* https://stackoverflow.com/questions/8770408/convert-int-to-char-in-standard-c-without-itoa
**/


// int createArray(int r, int c, char **buffer){

// 	*buffer = (int *)malloc(r * c * sizeof(int));
// 	int i, j = 0;//, count = 0;
// 	for (i = 0; i < r; i++){
// 		for (j = 0; j < c; j++){
// 			int val = rand() %11;
// 			if (val <= 6){
// 				*(buffer + i*c + j) = 0;
// 			} else if (val > 6 && val < 9){
// 				*(buffer + i*c + j) = 1;
// 			} else {
// 				*(buffer + i*c + j) = 2;//++count;
// 			}
// 		}
// 	}
// 	for (i = 0; i < r; i++){
// 	    for (j = 0; j < c; j++){
// 		    printf("%d ", *(buffer + i*c + j));
// 	    }
// 		printf("\n");
// 	}
// 	//Move for actual game
// 	free(buffer);
// 	return 0;
// }




int rowCount;
int colCount;

int read_file(char* filename, char **buffer){
	int c;
	FILE *file = fopen(filename, "r");

	colCount = 0;
	rowCount = 0;

	if (file) {
	    while ((c = getc(file)) != EOF){
	    	 if(c == '\n'){
	    	 	colCount = 0;
	    	 	rowCount++;
	    	 	//putchar(c);
	    	 }
	        putchar(c);
	        colCount++;
	    }


	    printf("\nNumber of Columns: %d\n", colCount - 1);
	    printf("Number of Rows: %d\n\n", rowCount + 1);

	    //*buffer = (char *)malloc(rowCount * colCount * sizeof(char));
	    // free(buffer);

	    //allocate space for the file contents
		//Don't forget to free this bitch
		//*buffer = (char*)malloc(sz * sizeof(char));

	    //go back to the beggining of the file
	    //fseek(file, 0L, SEEK_SET);
	   
	    // int i, j = 0;
	    // for(i = 0; i < rowCount + 1; i++){
	    // 	for (j = 0; j < colCount; j++){
	    // 		c = getc(file);
	    // 		if(i < rowCount + 1 && j < colCount -1){
	    // 			putchar(c);
	    // 		}
	    // 		//char* str;
	    // 		//sprintf(str, "%d", c);
	    // 		//*(buffer + i*colCount + j) = str;
	    // 	}
	    // 	printf("\n");
	    // }

	    fclose(file);
	} else {
		size_t sz = strlen(filename);
		char temp[sz];
		memcpy(temp, &filename[0],sz);
		temp[sz-1]='\0';

		FILE *newFile = fopen(temp, "r");
		if(newFile){
			 while ((c = getc(newFile)) != EOF){
			 	if(c == '\n'){
		    	 	colCount = 0;
		    	 	rowCount++;
		    	 	//putchar(c);
		    	 }
		        putchar(c);
		        colCount++;
		    }
		    fclose(newFile);
		} else {
			perror("fopen");
			printf("\nProgram exited due to error.\n");
			exit(0);
		}

		printf("\nNumber of Columns: %d\n", colCount - 1);
	    printf("Number of Rows: %d\n\n", rowCount + 1);

		// *buffer = (char *)malloc(rowCount * colCount * sizeof(char));
	 //    free(buffer);
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

	if (f == NULL){
		printf("Error opening file\n");
		exit(0);
	}

	//Buffer currently has nothing so expect error.
	fwrite(&buffer, sizeof(char), sizeof(buffer), f);

	fclose(f);
	return 0;
}