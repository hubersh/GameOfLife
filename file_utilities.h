#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H

int read_file(char* filename, char **buffer);
int write_file(char* filename, char *buffer, int size);
int get_row();
int get_col();

#endif