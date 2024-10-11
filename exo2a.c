#include <stdio.h>
#include <stdlib.h>

int compte_c(FILE *pFile)
{
    int count = 0;
    char ch = '0';
    while((ch = fgetc(pFile)) != EOF){
        count++;
    }   
    return count;
}

int compte_m(FILE *pFile)
{
    int count = 1;
    char ch;

    while((ch = fgetc(pFile)) != EOF) {
       if (ch == ' ' || ch == '\n' || ch == '\0')
            count++;
    }

   return count;
}

int compte_l(FILE *pFile)
{
    int count = 1;
    char ch;
    while ((ch = fgetc(pFile)) != EOF){
       if (ch == '\n')
           count++;
    }
   return count;
}

int main()
{
    FILE *pFile;
    pFile = fopen("data2.txt", "r");

    if(pFile == NULL){
        perror("Could not open file for reading.");
    }else{
        printf("Nombre de characteres: %d\n", compte_c(pFile));
        fseek(pFile, 0, SEEK_SET);
        printf("Nombre de mots: %d\n", compte_m(pFile));
        fseek(pFile, 0, SEEK_SET);
        printf("Nombre de ligns: %d\n", compte_l(pFile));
        fclose(pFile);
    }

    return 0;
}