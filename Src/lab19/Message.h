#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#define filename "D:\\Test15.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void fwrite(struct Message);
Message create(char* topic, char* text, char* recip_mail, char* recip_name,
	char* sender_mail, char* sender_name, int encoding, bool insurance);
void print(struct Message);
Message create(int);
char* createMail();