#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#define Pi 3.14

int main()
{


    char ch;
    int choice = 0;
    int esym = -1;

    printf("Enter the counting function:\n   1) Square\n   2) Length\n   3) Volume \n\n      Your choise:");
    scanf("%d", &choice);

    float R = 4;
    float R2;
    float R3;
    float result;

    R2 = R * R;
    R3 = R2 * R;


    switch (choice) {
    case 2:
        result = 2 * Pi * R;
        break;
    case 1:
        result = Pi * R2;
        break;
    case 3:
        result = 4 / 3 * Pi * R3;
        break;
    }

    puts("\nResult: ");
    printf("%f\n\nHow many points will this laboratory receive?\n(Grade?)   ", result);

    getchar();
    ch = getchar();
    printf("Grade:");
    putchar(ch);



    return 0;
}
