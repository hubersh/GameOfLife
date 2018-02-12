#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

int createArray(int r, int c, char** arr);
void game(char filename[]);
int main(int c, char **v);

#endif