#include "main.h"

void parametre(char *pseudo[])
{
    int sortie =0;
    do{
    int retour=0;
    afficheMenuSelection("parametre","1-changer le pseudo du joueur NORD;2-changer le pseudo du joueur EST;3-changer le pseudo du joueur OUEST;4-Quitter ",2);
    retour=acquisitionEntierSansMessageAvecConsigne(1,4,"Choisisez une action :");

    switch(retour){
        case 1 : acquisitionPseudoAvecMessage(pseudo[NORD-1],"choisisez un nouveau nom pour le joueur NORD",1);
            break;
        case 2 : acquisitionPseudoAvecMessage(pseudo[EST-1],"choisisez un nouveau nom pour le joueur EST",1);
            break;
        case 3 : acquisitionPseudoAvecMessage(pseudo[OUEST-1],"choisisez un nouveau nom pour le joueur OUEST",1);
            break;
        case 4 : sortie=1;
            break;
    }
    }while(sortie == 0);
}

