#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

int read_file(char* filename, char **buffer);
int write_file(char* filename, char *buffer, int size);
int createArray(int r, int c);
void game(char filename[]);
int main(int c, char **v);

#endif