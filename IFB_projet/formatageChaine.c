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

int decoupeChaine(char chaineInitiale[], char *chaineFinale,int tailleLigne,int nbLigne)
{
    int tailleChaine = strlen(chaineInitiale), retour = 0;
    int nbLigneRemplie = 0;
    for(int i = 0; i < nbLigne; i++){
        rempliEspace((chaineFinale + (tailleLigne + 1)*i), tailleLigne);
    }

    if (tailleChaine <= tailleLigne){
        strcpy((chaineFinale + ((tailleLigne + 1)*(nbLigne/2))), chaineInitiale);
        centreModifieChaine((chaineFinale + ((tailleLigne + 1)*(nbLigne/2))), tailleLigne);
        nbLigneRemplie = 1;
    }
    else {
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
                *(chaineFinale + j*(tailleLigne + 1) + k) = chaineInitiale[k+ip];
            }
            *(chaineFinale+ j*(tailleLigne + 1) +  i-ip -1) = 0;
            centreModifieChaine(chaineFinale+ j*(tailleLigne + 1), tailleLigne);
            if (ip != i - 1){
                nbLigneRemplie ++;
            }
            ip = i;
        }
        /**< Centrage verticale */
        for (int j = nbLigneRemplie; j >= 0; j--){
            strcpy(chaineFinale+ ((nbLigne - nbLigneRemplie)/2 +j)*(tailleLigne + 1), chaineFinale+ j*(tailleLigne + 1));
        }
        for (int j = (nbLigne-nbLigneRemplie)/2 -1; j >= 0; j--){
            rempliEspace((chaineFinale + (tailleLigne + 1)*j), tailleLigne);
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

void formateCarte(Carte carte[], char *chaineFinale, int nbCarte, int tailleChaine, int version)
{
        for (int i = 0; i < nbCarte; i++){
            stockeInfoCarte(carte[i], chaineFinale + (2*i+1)*(tailleChaine+1), chaineFinale + (2*i)*(tailleChaine+1), version, tailleChaine);
        }
}

void stockeInfoCarte(Carte carte, char *valeur, char *couleur, int version, int tailleChaine)
{
    if (version){
        switch(carte.couleur)
         {
        case COEUR :
            strcpy(couleur, "Coeur");
            break;
        case PIQUE :
            strcpy(couleur, "Pique");
            break;
        case CARREAU :
            strcpy(couleur, "Carreau");
            break;
        case TREFLE :
            strcpy(couleur, "Trephle");
            break;
        default:
            strcpy(couleur, " ");
            break;
        }
        centreModifieChaine(couleur, tailleChaine);

        switch(carte.valeur)
        {
        case AS :
            strcpy(valeur, "As");
            break;
        case 7 :
            strcpy(valeur, "7");
            break;
        case 8 :
            strcpy(valeur, "8");
            break;
        case 9 :
            strcpy(valeur, "9");
            break;
        case 10 :
            strcpy(valeur, "10");
            break;
        case VALET :
            strcpy(valeur, "Valet");
            break;
        case DAME :
            strcpy(valeur, "Dame");
            break;
        case ROI :
            strcpy(valeur, "Roi");
            break;
        default :
            strcpy(valeur, " ");
            break;
        }
        centreModifieChaine(valeur, tailleChaine);
    }
    else{
        char couleurCourte[3], valeurCourte[3];
        switch(carte.couleur)
         {
        case COEUR :
            strcpy(couleurCourte, "Co");
            break;
        case PIQUE :
            strcpy(couleurCourte, "Pi");
            break;
        case CARREAU :
            strcpy(couleurCourte, "Ca");
            break;
        case TREFLE :
            strcpy(couleurCourte, "Tr");
            break;
        default:
            strcpy(couleurCourte, " ");
            break;
        }

        switch(carte.valeur)
        {
        case AS :
            strcpy(valeurCourte, "As");
            break;
        case 7 :
            strcpy(valeurCourte, "7");
            break;
        case 8 :
            strcpy(valeurCourte, "8");
            break;
        case 9 :
            strcpy(valeurCourte, "9");
            break;
        case 10 :
            strcpy(valeurCourte, "10");
            break;
        case VALET :
            strcpy(valeurCourte, "V");
            break;
        case DAME :
            strcpy(valeurCourte, "D");
            break;
        case ROI :
            strcpy(valeurCourte, "R");
            break;
        default :
            strcpy(valeurCourte, " ");
            break;
        }
        sprintf(couleur, "%s %s", valeurCourte, couleurCourte);
        centreModifieChaine(couleur, tailleChaine);

    }
}

void formatePseudo(Joueur joueur, char *pseudo[], int tailleChaine, char chaineFinal[], int version)
{
    switch (joueur)
    {
    case NORD :
        strcpy(chaineFinal, pseudo[0]);
    break;
    case EST :
        strcpy(chaineFinal, pseudo[1]);
    break;
    case SUD :
        strcpy(chaineFinal, pseudo[2]);
    break;
    case OUEST :
        strcpy(chaineFinal, pseudo[3]);
    break;
    case SANS_JOUEUR :
        strcpy(chaineFinal, "Personne");
    break;
    default :
        strcpy(chaineFinal, " ");
    }
    if (version){
        centreModifieChaine(chaineFinal, tailleChaine);
    }
    else{
        aligneModifieChaine(chaineFinal, tailleChaine);
    }

}

void formateContrat(Contrat contrat, char *chaineFinal, int tailleLigne, char *pseudo[])
{
    formatePseudo(contrat.preneur, pseudo, tailleLigne, chaineFinal, 0);
    sprintf(chaineFinal + tailleLigne+1, "%d points", contrat.nbPoint);
    aligneModifieChaine(chaineFinal + tailleLigne+1, tailleLigne);
    switch(contrat.atout)
    {
    case COEUR :
        strcpy(chaineFinal + 2*(tailleLigne+1), "Coeur");
        break;
    case PIQUE :
        strcpy(chaineFinal + 2*(tailleLigne+1), "Pique");
        break;
    case CARREAU :
        strcpy(chaineFinal + 2*(tailleLigne+1), "Carreau");
        break;
    case TREFLE :
        strcpy(chaineFinal + 2*(tailleLigne+1), "Trephle");
        break;
    case TOUT_ATOUT :
        strcpy(chaineFinal + 2*(tailleLigne+1), "Tout Atout");
        break;
    case SANS_ATOUT :
        strcpy(chaineFinal + 2*(tailleLigne+1), "Sans Atout");
        break;
    default:
        strcpy(chaineFinal + 2*(tailleLigne+1), " ");
        break;
    }
    aligneModifieChaine(chaineFinal + 2*(tailleLigne+1), tailleLigne-6);
    switch(contrat.coinche)
    {
    case NORMAL:
        strcpy(chaineFinal + 3*(tailleLigne+1), " ");
        break;
    case COINCHE:
        strcpy(chaineFinal + 3*(tailleLigne+1), "Coinche");
        break;
    case SURCOINCHE:
        strcpy(chaineFinal + 3*(tailleLigne+1), "Surcoinche");
        break;
    default:
        strcpy(chaineFinal + 3*(tailleLigne+1), "??");
        break;
    }
    aligneModifieChaine(chaineFinal + 3*(tailleLigne+1), tailleLigne);
}

int aligneModifieChaine(char chaine[], int longeurChaine)
{
    int retour = 0;
    if (strlen(chaine) >= longeurChaine){
        chaine[longeurChaine] = 0;
        retour = 1;
    }
    else{
        char deriere[100];
        rempliEspace(deriere, ((longeurChaine - strlen(chaine))));
        sprintf(chaine,"%s%s",chaine, deriere);
    }
    return retour;
}


