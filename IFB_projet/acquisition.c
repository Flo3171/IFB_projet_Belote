#include "main.h"

/**
 * \file acquisition.c
 * \brief ficher source contenant les fonctions relative a l'acquisirion
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/

int acquisitionEntierAvecMessage(int min, int max){
    int valeur;
    printf("Entrer un nombre entier entre %d et %d\n", min, max);
    scanf("%d", &valeur);
    while(valeur < min || valeur > max){
        printf("Ce nombre n'est pas valide\n");
        printf("Entrer un nombre entier entre %d et %d\n", min, max);
        valeur= acquisitionEntierSecurise();
    }
    return valeur;

}

int acquisitionEntierSansMessage(int min, int max){
    int valeur;
    do{
        printf("Entrer un nombre entier entre %d et %d\n", min, max);
        valeur = acquisitionEntierSecurise();
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
        valeur=acquisitionEntierSecurise();
    }while (valeur < min || valeur > max);
    return valeur;
}

 void acquisitionPseudoAvecMessage(char *pointeurPseudo,char instruction [],int type)
 {
    char pseudo[100];
    int controle=0;
    afficheSousMenus(instruction,"pseudo");
    printf("\t");
    if(type==1){
        fgets(pseudo,99,stdin);
    }
    do{
        fgets(pseudo,99,stdin);
        controle=0 ;

        for(int i=0; i< strlen(pseudo)-1 && i < TAILLE_MAXI_PESEUDO ;i++){
            if ((pseudo[i]<'0' || pseudo[i]>'9') && (pseudo[i]<'A' || pseudo[i]>'Z') && (pseudo[i]<'a' || pseudo[i]>'z') ){
                controle=1;
            }
        }

        if (strlen(pseudo)> TAILLE_MAXI_PESEUDO+1 || strlen(pseudo)< 2){
            controle = controle +2;
        }
        switch (controle)
        {
            case 1 : afficheSousMenus("Votre pseudo possede des carracteres interdis. Choisisez votre pseudo:","pseudo");
                break;
            case 2 : afficheSousMenus("Votre pseudo n'as pas le nombre de carracteres recquis. Choisisez votre pseudo:","pseudo");
                break;
            case 3 : afficheSousMenus("Votre pseudo ne respecte pas les criteres. Choisisez votre pseudo:","pseudo");
        }
    }while(controle != 0);

    for (int j=0;j<strlen(pseudo);j++){
        if(j==strlen(pseudo)-1){
           *(pointeurPseudo+j)='\0';
        }else{
            *(pointeurPseudo+j)=pseudo[j];
        }

    }
 }

 int acquisitionEntierSecurise()
 {
     char num[50];
    int NB=0;
/** Lecture de l'entrée du joueur de type char **/
    fgets(num,50,stdin);
/** Test si le premier caractère est un 0 **/
    if(num[0]=='0'){
        NB=strtol(num,NULL,10);
    }else{
/** Conversion du char en int **/
        NB=strtol(num,NULL,10);
        if(NB==0){
            NB=-1;
        }
    }
    return NB;
 }
