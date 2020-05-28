#include "main.h"

Contrat proposeContratIa(Joueur parle, Carte *pCarteMain, Contrat dernierContrat)
{
    float seuilMinPrise = 0.6, seuilMaxPrise = 1;

    Contrat nouveauContrat;
    setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
    Couleur meilleurCouleur = SANS_COULEUR;
    float forceMeilleurCouleur = 0, sommeForce = 0;
    for (Couleur i = 1; i < 7; i++){
        sommeForce = sommeForceCarte(pCarteMain, 8, i);
        if (sommeForce > forceMeilleurCouleur){
            meilleurCouleur = i;
            forceMeilleurCouleur = sommeForce;
        }
    }
    if(forceMeilleurCouleur > seuilMinPrise){
        int enchereMax = 10*floor(ajusteEchelle(forceMeilleurCouleur, seuilMinPrise, seuilMaxPrise, 8, 17));
        if (dernierContrat.nbPoint < enchereMax){
            setContrat(&nouveauContrat, parle, enchereMax, meilleurCouleur, NORMAL);
        }
        else{
            setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
        }
    }
    else {
        setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
    }

    return nouveauContrat;

}
