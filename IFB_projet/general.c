#include "main.h"

void initialisation(int nbLigneFenetre, int nbColloneFenetre)
{
    modifieTailleFenetre(nbLigneFenetre, nbColloneFenetre);
}

void debutDePartie(char *pseudo[]){
    afficheMenuPrincipal(0);
    acquisitionPseudoAvecMessage(pseudo[2]);
}
