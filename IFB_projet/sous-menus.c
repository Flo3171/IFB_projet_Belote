#include "main.h"

/**
 * \file sous-menue.c
 * \brief ficher source contenant les fonctions des different sous menu disponible sur le menu principal
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/

void parametre(char *pseudo[])
{
    int sortie =0;
    do{
    int retour=0;
    afficheMenuSelection("parametre","1-changer le pseudo du joueur NORD;2-changer le pseudo du joueur EST;3-changer le pseudo du joueur OUEST;4-Quitter ",2);
    retour=acquisitionEntierSansMessageAvecConsigne(1,4,"Choisisez une action :");

    switch(retour){
        case 1 : acquisitionPseudoAvecMessage(pseudo[NORD-1],"choisisez un nouveau nom pour le joueur NORD",1);
            break;
        case 2 : acquisitionPseudoAvecMessage(pseudo[EST-1],"choisisez un nouveau nom pour le joueur EST",1);
            break;
        case 3 : acquisitionPseudoAvecMessage(pseudo[OUEST-1],"choisisez un nouveau nom pour le joueur OUEST",1);
            break;
        case 4 : sortie=1;
            break;
    }
    }while(sortie == 0);
}

int leaderboard(FILE *fichier)
{
    char listeDesScores[300]="\0",pseudo[21]="\0",score[4];
    int acquisition=0,retour=0;

    for(int ligne=0 ; ligne<10 ; ligne++){
        strcat(listeDesScores,"#");
        itoa(ligne+1,score,10);
        strcat(listeDesScores,score);
        strcat(listeDesScores," ");

        fseek(fichier,ligne*NB_CARRACTERE_LEADERBOARD,SEEK_SET);
        fscanf(fichier,"%20s",pseudo);
        if(strlen(pseudo)>14){
            fseek(fichier,ligne*NB_CARRACTERE_LEADERBOARD,SEEK_SET);
            fscanf(fichier,"%14s",pseudo);
            strcat(listeDesScores,pseudo);
            strcat(listeDesScores,"...");
        }else{
            strcat(listeDesScores,pseudo);
        }
        strcat(listeDesScores," score:");

        fseek(fichier,ligne*NB_CARRACTERE_LEADERBOARD+POSITION_RECORD_VICTOIRE,SEEK_SET);
        fscanf(fichier,"%s",score);
        strcat(listeDesScores,score);

        listeDesScores[strlen(listeDesScores)]=';';
    }

    while(retour !=1){
        afficheMenuSelection("leaderboard","1-Top 5 des champions ;2-Top 10 des champions ;3-quitter ;;choisissez le classement:",2);
        acquisition=acquisitionEntierSecurise();

        while(acquisition != 1 && acquisition != 2 && acquisition !=3 ){
            acquisition=acquisitionEntierSecurise();
        }
        switch(acquisition){
            case 1: afficheMenuSelection("leaderboard",listeDesScores,3);
                    printf("Pressez une touche pour continuer\n");
                    getch();
                break;
            case 2: afficheMenuSelection("leaderboard",listeDesScores,1);
                    printf("Pressez une touche pour continuer\n");
                    getch();
                break;
            default : retour=1;
                break;
        }
    }
    return 0;
}

int statistiqueJoueur(FILE *fichier,int ligne)
{
    char statistique[150]="pseudo :; ",pseudo[21];
    int score;

    fseek(fichier,ligne*NB_CARRACTERE_SCORE,SEEK_SET);
    fscanf(fichier,"%20s",pseudo);
    strcat(statistique,pseudo);

    strcat(statistique," ;;nombre de victoires :; ");

    fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_NB_VICTOIRE,SEEK_SET);
    fscanf(fichier,"%3d",&score);
    itoa(score,pseudo,10);
    strcat(statistique,pseudo);

    strcat(statistique," ;;meilleur score :; ");

    fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_SCORE_MAX,SEEK_SET);
    fscanf(fichier,"%4d",&score);
    itoa(score,pseudo,10);
    strcat(statistique,pseudo);

    strcat(statistique," points ;;partie la plus courte :; ");

    fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_NB_MANCHES_POUR_GAGNER,SEEK_SET);
    fscanf(fichier,"%1s",pseudo);
    strcat(statistique,pseudo);

    strcat(statistique," manches pour gagner ;;;appuyez pour continuer ");

    afficheMenuSelection("statistiques",statistique,0);
    getch();

    return 0;
}

