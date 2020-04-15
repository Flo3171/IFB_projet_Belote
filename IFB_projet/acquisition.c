#include "main.h"

int acquisitionEntierAvecMessage(int min, int max){
    int valeur;
    printf("Entrer un nombre entier entre %d et %d\n", min, max);
    scanf("%d", &valeur);
    while(valeur < min || valeur > max){
        printf("Ce nombre n'est pas valide\n");
        printf("Entrer un nombre entier entre %d et %d\n", min, max);
        scanf("%d", &valeur);
    }
    return valeur;

}

int acquisitionEntierSansMessage(int min, int max){
    int valeur;
    do{
        printf("Entrer un nombre entier entre %d et %d\n", min, max);
        scanf("%d", &valeur);
    }while (valeur < min || valeur > max);
    return valeur;
}

char acquisitionOuiNonSansMessage(){
    char reponse;
    do {
        printf("Voulez vous recomencer O/N\n");
        reponse = getch();
    }while (reponse != 'O' && reponse != 'N');
    return reponse;
}

int acquisitionEntierSansMessageAvecConsigne(int min, int max, char consigne[])
{
    int valeur;
    do{
        printf("%s ", consigne);
        scanf("%d", &valeur);
    }while (valeur < min || valeur > max);
    return valeur;
}

