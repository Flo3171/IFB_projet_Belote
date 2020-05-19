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

Joueur vainqueurPli(int couleur, int valeur)
/< je ne sais pas si je dois utiliser "int" en type de variable... */
{
    Couleur joueurNord_c, joueurEst_c, joueurSud-c, joueurOuest_c;
    Valeur joueurNord_v, joueurEst_v, joueurSud_v, joueurOuest_v;
    /< Il y a sûrement une meilleure facon de nommer les variables, voir d'utiliser une autre structure */

    Carte tableauDeCarte[4];


    tableauDeCarte[0].Valeur = joueurNord_v;
    tableauDeCarte[0].Couleur = joueurNord_c;
    tableauDeCarte[1].Valeur = joueurEst_v;
    tableauDeCarte[1].Couleur = joueurEst_c;
    tableauDeCarte[2].Valeur = joueurSud_v;
    tableauDeCarte[2].Couleur = joueurSud_c;
    tableauDeCarte[3].Valeur = joueurOuest_v;
    tableauDeCarte[3].Couleur = joueurOuest_c;
    /**< PAS FINI Ensuite j'applique la fonction forceCarte pour déterminer qui remporte le pli */

}
