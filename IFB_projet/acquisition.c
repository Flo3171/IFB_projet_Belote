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

 void acquisitionPseudoAvecMessage()
 {
    char pseudo[100];
    int controle=2;
    afficheSousMenus("Choisisez votre pseudo:","pseudo");

    do{
        controle=0;
        fgets(pseudo,99,stdin);
        for(int i=0; i<100;i++){
            if ((pseudo[i]<48 && pseudo[i]>57) || (pseudo[i]<65 && pseudo[i]>90) || (pseudo[i]<97 && pseudo[i]>122) ){
                controle=1;
            }
        }
        if (strlen(pseudo)>=20){
            controle = controle +2;
        }
        switch (controle)
        {
            case 1 : afficheSousMenus("Votre pseudo possede des carractères interdis.Choisisez votre pseudo:","pseudo");
                break;
            case 2 : afficheSousMenus("Votre pseudo est trop long. Choisisez votre pseudo:","pseudo");
                break;
            case 3 : afficheSousMenus("Votre pseudo ne respecte pas les critères. Choisisez votre pseudo:","pseudo");
        }
    }while(controle != 0);
    puts(pseudo);
 }
