#define _CRT_SECURE_NO_WARNINGS
#define filename "D:\\Test15.txt"
#define filenameB "D:\\TestB15.dat"

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

struct User {
	string name;
	string mail;
};

struct Message {
	string topic;
	string text;
	User sender;
	User recipient;
	int encoding;	
	bool draft;
};

void fread(struct Message*,int);
void fwrite(struct Message*,int);
void write(struct Message*,int);
void sort(struct Message*,int);
Message create(int index);
Message freadB();
void fwriteB(struct Message*,int);



