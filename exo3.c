#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void clear_screen() {
    #ifdef _WIN32
        system("cls");  
    #else
        system("clear");  
    #endif
}

typedef struct Etudiant {
    char nom[50];
    char prenom[50];
    int age;
    float note;
}etudiant;

FILE* ouvrir_fichier(char mode[] ){
    FILE *ptr_f;

    ptr_f = fopen("students.bin", mode);
    if(ptr_f == NULL){
        perror("Impossible d'ouvrir le fichier.");
        return NULL;
    }else{
        return ptr_f;
    }
}

void ajouter_etudiant(FILE *fichier){
    etudiant etu;
    long success = 0;
    
    clear_screen();
    printf("Entrer le nom de l'etudiant: ");
    scanf("%s", etu.nom);

    printf("Entrer le prenom de l'etudiant : ");
    scanf("%s", etu.prenom);

    printf("Entrer l'age de l'etudiant: ");
    scanf("%d", &etu.age);

    printf("Entrer la note de l'etudiant: ");
    scanf("%f", &etu.note);

    success = fwrite(&etu, sizeof(etudiant), 1, fichier);
    if(success){
        printf("***Etudiant Enregistre avec succes*** \n");
        
    }else{
        perror("Impossible d'enregistrer l'etudiant.");
    }

    fclose(fichier);

}


void afficher_etudiants(FILE *fichier){
    etudiant etu;
    long success = 0;
    clear_screen();
    printf("Voici tous les etudiants:\n");
    printf("----------------------------\n");
    while (fread(&etu, sizeof(etudiant), 1, fichier)) {
        printf("Nom: %s\n", etu.nom);
        printf("Prenom: %s\n", etu.prenom);
        printf("Age: %d\n", etu.age);
        printf("Note: %.2f\n", etu.note);
        printf("----------------------------\n");
    }

    fclose(fichier);
}

void chercher_etudiant(FILE *fichier) {
    etudiant etu;
    int found = 0;
    char nom[50];

    clear_screen();
    printf("Entrer le nom de l'etudiant: ");
    scanf("%s", nom);

    while(fread(&etu, sizeof(etudiant), 1, fichier)) {
        if(strcmp(etu.nom, nom) == 0) {
            printf("Etudiant trouve:\n");
            printf("Nom: %s\n", etu.nom);
            printf("Prenom: %s\n", etu.prenom);
            printf("Age: %d\n", etu.age);
            printf("Note: %.2f\n", etu.note);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Etudiant avec le nom '%s' non trouve.\n", nom);
    }

    fclose(fichier);
}

void menu(char option){
    switch (option)
    {
    case '1':
        ajouter_etudiant(ouvrir_fichier("ab"));
        break;
    case '2':
        afficher_etudiants(ouvrir_fichier("rb"));
        break;
    case '3':
        chercher_etudiant(ouvrir_fichier("rb"));
        break;
    case '4':
        break;
    default:
        printf("Option Invalide! Veuillez reessayer. \n");
    }
}

int main()
{
   char option;

   do{
    printf("\nMenu Principal:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher tous les etudiants\n");
        printf("3. Chercher un etudiant par nom\n");
        printf("4. Quitter le programme\n");
        printf("Entrer votre choix: ");
        scanf(" %c", &option);
        menu(option);
   }while( option != '4');
    
    
    return 0;
}