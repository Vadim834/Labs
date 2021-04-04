#include "lib.h"


int main() {
    //our text
    char *text = read_from_file();

    //empty array
    char text_for_size[64] = "";
    char text_for_sort[64] = "";
    //copying the text to our temp (so the text didnt get changed)
    strcat(text_for_size, text);
    strcat(text_for_sort, text);

    //spacer we want to remove
    char spacer[] = " ";
    int amount_of_words = size_counter(text_for_size);

    int count = 0;

    //making an array
    char** arr = (char**)malloc(amount_of_words * sizeof(int));

    //making it a 2d array
    for (int i = 0; i < amount_of_words; i++)
        arr[i] = (char*)malloc(30 * sizeof(char));

    char* res = strtok(text_for_sort, spacer);
    while (res) {

        strcpy(arr[count], res);
        count++;

        res = strtok(NULL, spacer);
    }


    char temp[30];


    //here the make a "bubble sort", but with words
    for (int i = 0; i < amount_of_words-1; i++) {
        for (int j = 0; j < amount_of_words-i-1; j++) {
            if (arr[j][0] > arr[j + 1][0]) {
                strcpy(temp, arr[j + 1]);
                strcpy(arr[j + 1], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }


    char filename[64];
    printf("Write to file\n");
    printf("Enter file path: ");
    scanf("%s", filename);

    FILE* fp;
    if ((fp = fopen(filename, "w")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    fprintf(fp, "Result:");
    printf("Result:");
    fclose(fp);
        
    for (int j = 0; j < amount_of_words; j++) {
        printf("%s ", arr[j]);
        write_in_file(arr[j],filename);
    }

    return 0;
}

