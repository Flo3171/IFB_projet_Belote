#include "main.h"

int ecriturePseudo (char *pPseudo,FILE *pFichier)
{
    int ligne=-1, retour=0;
    char pseudoRecup[TAILLE_MAXI_PESEUDO];

    while(retour!= 1 && retour !=2 ){

        ligne=ligne+1;
        fseek(pFichier,ligne*NB_CARRACTERE_SCORE,SEEK_SET);
        fscanf(pFichier,"%s",pseudoRecup);

        if(strcmp(pPseudo,pseudoRecup)==0 ){
            retour=1;
        }else if(fgets(pseudoRecup,20,pFichier) == NULL){
            retour=2;
        }else{
            retour=0;
        }

    }
    if(retour==2){
        aligneModifieChaine(pPseudo,TAILLE_MAXI_PESEUDO);
        fseek(pFichier,0,SEEK_END);
        fprintf(pFichier,"\n%20s;%3d;%4d;%1d",pPseudo,0,0,0);
    }
    return ligne;
}

int ecrireStatistique(FILE *fichier,int ligne, int statAModifier, int type)
{
    int valeurCherchee=0;
    switch(type){
        case 1 :
            {
                fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_NB_VICTOIRE,SEEK_SET);
                fscanf(fichier,"%3d",&valeurCherchee);

                if(statAModifier <= 999){
                    statAModifier=statAModifier+valeurCherchee;
                    fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_NB_VICTOIRE,SEEK_SET);
                    fprintf(fichier,"%3d",statAModifier);
                }
            }
            break ;
        case 2 :
            {
                fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_SCORE_MAX,SEEK_SET);
                fscanf(fichier,"%4d",&valeurCherchee);
                if(statAModifier > valeurCherchee && statAModifier <= 9999){
                    fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_SCORE_MAX,SEEK_SET);
                    fprintf(fichier,"%4d",statAModifier);
                }
            }
            break;
        case 3 :
            {
                fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_NB_MANCHES_POUR_GAGNER,SEEK_SET);
                fscanf(fichier,"%1d",&valeurCherchee);
                if(statAModifier < valeurCherchee && statAModifier <= 9){
                    fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_NB_MANCHES_POUR_GAGNER,SEEK_SET);
                    fprintf(fichier,"%1d",statAModifier);
                }
            }
            break;
        default:
            break;
    }
    return 0;
}
