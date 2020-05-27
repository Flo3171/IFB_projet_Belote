#include "main.h"

Contrat proposeContratIa(Joueur parle, Carte *pCarteMain, Contrat dernierContrat)
{
    float seuilMinPrise = 0.6, seuilMaxPrise = 0.9;

    Contrat nouveauContrat;
    setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
    Couleur meilleurCouleur = SANS_COULEUR;
    float forceMeilleurCouleur = 0, sommeForce = 0;
    afficheMain(pCarteMain);
    for (Couleur i = 1; i < 7; i++){
        sommeForce = sommeForceCarte(pCarteMain, 8, i);
        printf("%f\n", sommeForce);
        if (sommeForce > forceMeilleurCouleur){
            meilleurCouleur = i;
            forceMeilleurCouleur = sommeForce;
        }
    }
    printf("La meuilleur coueleur est %d\n", meilleurCouleur);
    if(forceMeilleurCouleur > seuilMinPrise){
        int enchereMax = 10*floor(ajusteEchelle(forceMeilleurCouleur, seuilMinPrise, 1, 8, 17));
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
