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

void option(FILE *pFile, char letter){
    switch (letter)
    {
    case 'm':
        printf("Number of words: %d", compte_m(pFile));
        break;
    case 'c':
        printf("Number of characters: %d", compte_c(pFile));
        break;
    case 'l':
        printf("Number of lines: %d", compte_l(pFile));
        break;
    default:
        printf("Invalid option.");
        break;
    }
}

int main ()
{
    FILE *pFile;
    char nom[80], letter;

    printf("Enter the relative or absolute path to the file: ");
    scanf("%s", nom);
    printf("Entrer m( Number of words ) ou l( Number of lines ) ou c( Number of characters ): ");
    scanf(" %c", &letter);

    
    pFile = fopen(nom, "r");

    if(pFile == NULL){
        perror("Could not open file for reading.");
    }else{
        option(pFile, letter);
        fclose(pFile);
    }


}