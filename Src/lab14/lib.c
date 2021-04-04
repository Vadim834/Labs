#include "lib.h"


int size_counter(char text[]) {

    char spacer[] = " ";
    char* res = strtok(text, spacer);
    int count = 0;

    while (res != NULL)
    {
        count++;
        res = strtok(NULL, spacer);
    }

    return count;
}

char* read_from_file() {
    char filename[64];
    char cc[64];
    FILE* fp;
    
    printf("Reading from a file\n");
    printf("Enter file path (In the file path use \\\\): ");
    scanf("%s", filename);     

    if ((fp = fopen(filename, "r")) == NULL){
        perror("Error occured while opening file");
        return 1;
    }

    fgets(cc, 64, fp);   

    fclose(fp);
    return cc;
}

void write_in_file(char* message,char filename[64]) { 
    FILE* fp;
            
    if ((fp = fopen(filename, "a")) == NULL){
        perror("Error occured while opening file");
        return 1;
    }
    
    fprintf(fp, "%s ", message);

    fclose(fp);    
}
