#include "main.h"

Joueur joueurSuivant(Joueur joueur)
{
    if (joueur == OUEST){
        return NORD;
    }
    else {
        return joueur+1;
    }
}

int nbAleatoire(int mini, int maxi)
{
    srand(time(0));
    return (rand()%(maxi - mini + 1)) + mini;
}
