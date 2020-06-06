#include "main.h"

Contrat proposeContratIa(Joueur parle, Carte *pCarteMain, Contrat dernierContrat)
{

    float seuilMinPrise = 0.61, seuilMaxPrise = 1;

    /**< Permet de déterminer de manière euristique la meilleur valeur de seuilMinPrise et seuilMaxPrise */
    /*if (parle == NORD || parle == SUD){
        seuilMaxPrise = 1;
    }
    else{
        seuilMaxPrise = 0.95;

    }*/

    Contrat nouveauContrat;
    setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
    return nouveauContrat;

}
