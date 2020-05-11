#include "main.h"

void parametre(char *pseudo[])
{
    int retour=0;
    afficheMenuSelection("parametre","1-changer le pseudo du joueur NORD;2-changer le pseudo du joueur EST;3-changer le pseudo du joueur OUEST");
    retour=acquisitionEntierSansMessageAvecConsigne(1,3,"Choisisez une action :");

    switch(retour){
        case 1 : acquisitionPseudoAvecMessage(pseudo[NORD-1],"choisisez un nouveau nom pour le joueur NORD");
            break;
        case 2 : acquisitionPseudoAvecMessage(pseudo[EST-1],"choisisez un nouveau nom pour le joueur EST");
            break;
        case 3 : acquisitionPseudoAvecMessage(pseudo[OUEST-1],"choisisez un nouveau nom pour le joueur OUEST");
            break;
    }
}


