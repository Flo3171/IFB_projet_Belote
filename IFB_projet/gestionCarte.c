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
/*< je ne sais pas si je dois utiliser "int" en type de variable... */
{
    Couleur joueurNord_c, joueurEst_c, joueurSud_c, joueurOuest_c;
    Valeur joueurNord_v, joueurEst_v, joueurSud_v, joueurOuest_v;
    /*< Il y a sûrement une meilleure facon de nommer les variables, voir d'utiliser une autre structure */

    Carte tableauDeCarte[4];


    tableauDeCarte[0].valeur = joueurNord_v;
    tableauDeCarte[0].couleur = joueurNord_c;
    tableauDeCarte[1].valeur = joueurEst_v;
    tableauDeCarte[1].couleur = joueurEst_c;
    tableauDeCarte[2].valeur = joueurSud_v;
    tableauDeCarte[2].couleur = joueurSud_c;
    tableauDeCarte[3].valeur = joueurOuest_v;
    tableauDeCarte[3].couleur = joueurOuest_c;
    /**< PAS FINI Ensuite j'applique la fonction forceCarte pour déterminer qui remporte le pli */

}


char carteValide(Carte cartePose, Carte pli[], Couleur atout, Carte *pCarteMainJoueur, Joueur premierAJouer)
{
    /**< Fonction faite a partir de l'oranigrame qui montre comment déterminer si une carte est valide a partir des règle*/
    char valide = 0;

    return valide;
}

char rechercherCarte(Carte *pCarte, int nbCarte, Couleur couleurCherche, Valeur valeurCherche, int version)
{
    char trouve = 0;
    if (version == 1){
        for(int i = 0; i < nbCarte; i++){
            if (((*(pCarte + i)).couleur == couleurCherche || couleurCherche == SANS_COULEUR) && ((*(pCarte + i)).valeur == valeurCherche || valeurCherche == SANS_VALEUR)){
                trouve = 1;
            }
        }
    }
    else if (version == 0){
        /**< si la force d'une carte est suppérieur a la force de la carte recherché */
    }

    return trouve;
}
