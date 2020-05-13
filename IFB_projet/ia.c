#include "main.h"

Contrat proposeContratIa(Joueur parle, Carte *pCarteMain, Contrat dernierContrat)
{
    Contrat nouveauContrat;
    setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
    return nouveauContrat;

}
