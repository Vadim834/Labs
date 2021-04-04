#ifndef LIB_H
#define LIB_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int size_counter(char text[]);
char* read_from_file();
void write_in_file(char* message, char filename[64]);
#endif					  