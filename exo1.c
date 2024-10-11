#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nom[80], article[80];
    int nombre, prix_unitaire;
    FILE *pFile;

    pFile = fopen("data.txt", "r");
    if(pFile == NULL){
        perror("Could not open file for reading.");
    }else{
        while(!feof(pFile)){
            fscanf(pFile, "%s %s %d %d", nom,article,&nombre,&prix_unitaire);
            printf("%s %s %d %d\n",nom,article,nombre,prix_unitaire);
        }
        fclose(pFile);
    }

    return 0;
}