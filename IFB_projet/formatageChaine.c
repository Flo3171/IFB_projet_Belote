#include "main.h"

int centreChaine(char chaineInitial[], char chaineFinal[], int longeurChaine)
{
    int retour = 0;
    if (strlen(chaineInitial) >= longeurChaine){
        for (int i = 0; i < longeurChaine; i++){
            chaineFinal[i] = chaineInitial[i];
        }
        chaineFinal[longeurChaine] = 0;
        retour = 1;
    }
    else{
        char devant[100], deriere[100];
        if ((longeurChaine - strlen(chaineInitial)) % 2 == 0){
            rempliEspace(devant, ((longeurChaine - strlen(chaineInitial)) / 2));
            rempliEspace(deriere, ((longeurChaine - strlen(chaineInitial)) / 2));
        }
        else{
            rempliEspace(devant, ((longeurChaine - strlen(chaineInitial)) / 2));
            rempliEspace(deriere, ((longeurChaine - strlen(chaineInitial)) / 2) + 1);
        }
        sprintf(chaineFinal,"%s%s%s", devant, chaineInitial, deriere);
    }
    return retour;
}

int centreModifieChaine(char chaine[], int longeurChaine)
{
    char* chaineCentre = (char*) malloc(sizeof(char)*(longeurChaine+1));
    centreChaine(chaine, chaineCentre, longeurChaine);
    sprintf(chaine, "%s", chaineCentre);

    free(chaineCentre);
    return 0;
}

int decoupeChaine(char chaineInitiale[], char *chaineFinale[],int tailleLigne,int nbLigne)
{
    int tailleChaine = strlen(chaineInitiale), retour = 0;
    for(int i = 0; i < nbLigne; i++){
        rempliEspace(chaineFinale[i], tailleLigne);
    }

    if (tailleChaine <= tailleLigne){
        strcpy(chaineFinale[nbLigne/2], chaineInitiale);
        centreModifieChaine(chaineFinale[nbLigne/2], tailleLigne);
    }
    else {
            printf("ici");
            int i = 0, ip = 0;
            for (int j = 0; j < nbLigne; j++){
                while ((i < tailleChaine) && (i-ip < tailleLigne)){
                    i++;
                }
                while ((chaineInitiale[i-1] != ' ') && (chaineInitiale[i] != 0)){
                    i--;
                }
                if(chaineInitiale[i] == 0){
                    i++;
                }
                for (int k = 0; k <  i - ip - 1; k++ ){
                    *(chaineFinale[j] + k) = chaineInitiale[k+ip];
                }
                *(chaineFinale[j] +  i-ip -1) = 0;
                centreModifieChaine(chaineFinale[j], tailleLigne);
                ip = i;
            }

    }


    return retour;
}

void rempliEspace(char *chaine,int nbEspace)
{
    for (int i = 0; i < nbEspace; i++){
        *(chaine+i) = ' ';
    }
    *(chaine + nbEspace) = 0;
}

void formateCarte(Carte carte[], char *chaineFinale[], int nbCarte, int tailleChaine, int version)
{
    if (version){
        /**< affichage des carte du pli actuel et de la main */


    }
    else{
        /**< affichage du pli précédent */
    }
}
