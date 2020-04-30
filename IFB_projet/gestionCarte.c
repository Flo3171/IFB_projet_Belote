#include "main.h"


void distribueCarte(Carte *pCarteMain)
{
    Carte carteDisponible[32];
    int curseur = 0, indiceCarte;
    for (int i = 0;i < 4; i++){
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = AS;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = SEPT;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = HUIT;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = NEUF;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = DIX;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = VALET;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = DAME;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = ROI;
        curseur ++;
    }

    for (int i = 0; i < NB_TOATAL_CARTE; i++){
        indiceCarte = nbAleatoire(0, NB_TOATAL_CARTE - i - 1);
        setCarte((pCarteMain + i), carteDisponible[indiceCarte].valeur, carteDisponible[indiceCarte].couleur);
        supprimeCarte(carteDisponible, NB_TOATAL_CARTE-i, indiceCarte);
    }
}

void setCarte(Carte *carte, Valeur valeurCarte, Couleur couleurCarte)
{
    (*carte).couleur = couleurCarte;
    (*carte).valeur = valeurCarte;
}

void supprimeCarte(Carte carte[], int nbCarte, int carteASupprimer)
{
    for (int i = carteASupprimer; i < nbCarte ; i++){
        setCarte(&carte[i], carte[i+1].valeur, carte[i+1].couleur);
    }
    setCarte(&carte[nbCarte -1], SANS_VALEUR, SANS_COULEUR);
}
