#include "main.h"

int ecriturePseudo (char *pPseudo,FILE *pFichier)
{
    int ligne=-1, retour=0;
    char pseudoRecup[TAILLE_MAXI_PESEUDO+1],pseudoJ[TAILLE_MAXI_PESEUDO+1];

    if (pFichier == NULL){
        retour=EOF;
    }else{
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
            strcpy(pseudoJ,pPseudo);
            aligneModifieChaine(pseudoJ,TAILLE_MAXI_PESEUDO);
            fseek(pFichier,0,SEEK_END);
            fprintf(pFichier,"\n%20s;%3d;%4d;%1d",pseudoJ,0,0,0);
        }
    }
    return ligne;
}

int ecrireStatistique(FILE *fichier,int ligne, int statAModifier, int type)
{
    int valeurCherchee=0,retour=0;
    if (fichier == NULL){
        retour=EOF;
    }else{
        switch(type){
            case 1 :
                {
                    fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_NB_VICTOIRE,SEEK_SET);
                    fscanf(fichier,"%3d",&valeurCherchee);

                    if(statAModifier <= 999){
                        statAModifier=statAModifier+valeurCherchee;
                        fseek(fichier,ligne*NB_CARRACTERE_SCORE+POSITION_NB_VICTOIRE,SEEK_SET);
                        fprintf(fichier,"%3d",statAModifier);
                        retour=statAModifier;
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
                        retour=statAModifier;
                    }else{
                        retour = valeurCherchee;
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
                        retour=statAModifier;
                    }else{
                        retour = valeurCherchee;
                    }
                }
                break;
            default:
                break;
        }
    }
    return retour;
}

int ecrireLeaderboard(FILE *fichier,char *pseudo,int scoreJ)
{
    char pseudoRecup[TAILLE_MAXI_PESEUDO+1];
    int score=0,stop=0,ligne=0,retour=0;

    if (fichier == NULL){
        retour=EOF;
    }else{
        while(stop!=1 && ligne<=9){
            fseek(fichier,ligne*NB_CARRACTERE_LEADERBOARD,SEEK_SET);
            fscanf(fichier,"%20s",pseudoRecup);
            if(strcmp(pseudo,pseudoRecup)==0){
                ligne-=2;
                stop=1;
            }
            ligne++;
        }
        if(ligne<0){
            fseek(fichier,POSITION_RECORD_VICTOIRE,SEEK_SET);
            fprintf(fichier,"%3d",scoreJ);
        }
        stop=0;
        while( stop!=1 && ligne>=0){
            fseek(fichier,ligne*NB_CARRACTERE_LEADERBOARD,SEEK_SET);
            aligneModifieChaine(pseudoRecup,TAILLE_MAXI_PESEUDO);
            fscanf(fichier,"%20s",pseudoRecup);
            printf("%6s|",pseudoRecup);

            fseek(fichier,ligne*NB_CARRACTERE_LEADERBOARD+POSITION_RECORD_VICTOIRE,SEEK_SET);
            fscanf(fichier,"%3d",&score);
            printf("%3d\n",score);

            if(scoreJ > score && ligne<9 ){
                fseek(fichier,(ligne+1)*NB_CARRACTERE_LEADERBOARD,SEEK_SET);
                aligneModifieChaine(pseudoRecup,TAILLE_MAXI_PESEUDO);
                fprintf(fichier,"%20s;",pseudoRecup);

                fseek(fichier,(ligne+1)*NB_CARRACTERE_LEADERBOARD+POSITION_RECORD_VICTOIRE,SEEK_SET);
                fprintf(fichier,"%3d\n",score);

                if ( ligne==0 && scoreJ>=score ){
                    fseek(fichier,ligne*NB_CARRACTERE_LEADERBOARD,SEEK_SET);
                    aligneModifieChaine(pseudo,TAILLE_MAXI_PESEUDO);
                    fprintf(fichier,"%20s;",pseudo);

                    fseek(fichier,ligne*NB_CARRACTERE_LEADERBOARD+POSITION_RECORD_VICTOIRE,SEEK_SET);
                    fprintf(fichier,"%3d\n",scoreJ);
                    stop=1;
                }
            }else if (scoreJ<=score){
                if(ligne<9){
                    fseek(fichier,(ligne+1)*NB_CARRACTERE_LEADERBOARD,SEEK_SET);
                    aligneModifieChaine(pseudo,TAILLE_MAXI_PESEUDO);
                    fprintf(fichier,"%20s;",pseudo);

                    fseek(fichier,(ligne+1)*NB_CARRACTERE_LEADERBOARD+POSITION_RECORD_VICTOIRE,SEEK_SET);
                    fprintf(fichier,"%3d\n",scoreJ);
                    stop=1;
                }else if(ligne==9){
                    stop=1;
                }
            }
            ligne-=1;
        }
        retour=0;
    }
    return retour;
}

