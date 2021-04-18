#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#define filename "D:\\Test15.txt"
#define filenameB "D:\\TestB15.dat"

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

struct User {
	char name[SIZE];
	char mail[SIZE];
};

struct Message {
	char topic[64];
	char text[256];
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
int addMessage(struct Message*, int);
int removeMessage(struct Message*, int, int);



