#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int read_file(char* filename, char **buffer){

}

int write_file(char* filename, char *buffer, int size){

}

void game(int w, int h){

}

int main(int c, char **v){
	int w = 0;
	int h = 0;
	if (c > 1){ w = atoi(v[1]); }
	if (c > 2){ h = atoi(v[2]); }
	if (w <= 0){ w = 4; }
	if (h <= 0){ h = 5; }
	game(w, h);
}