#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

void reduce(char* mass, int indexStart, int indexEnd);
char* insert(char* mass, char* mass2, int index);

int main() {

    char mass[] = "babkakadavra";
    char mass2[] = "TEXT2";
    char* result = insert(mass, mass2, 4);
    reduce(result, 4, 8);

    return 0;
}

char* insert(char* mass, char* mass2, int index) {

    int size = strlen(mass) + strlen(mass2);
    char* s = (char*)malloc((size + 1) * sizeof(char));

    for (int i = 0; i < index; i++)
        s[i] = mass[i];
    for (int i = index; i < strlen(mass2) + index; i++)
        s[i] = mass2[i - index];
    for (int i = strlen(mass2) + index; i < size; i++)
        s[i] = mass[i - strlen(mass2)];

    s[size] = '\0';

    printf("%s\n", s);

    return s;
}

void reduce(char* mass, int indexStart, int indexEnd) {

    int size = strlen(mass) - (indexEnd - indexStart + 1);
    char* s = (char*)malloc((size + 1) * sizeof(char));

    for (int i = 0; i < indexStart; i++)
        s[i] = mass[i];

    for (int i = indexEnd + 1; i < strlen(mass); i++)
        s[i - (indexEnd - indexStart + 1)] = mass[i];
    s[size] = '\0';
    printf("%s", s);
    return;
}