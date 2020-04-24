#include "main.h"

void initialisation(int nbLigneFenetre, int nbColloneFenetre)
{
    modifieTailleFenetre(nbLigneFenetre, nbColloneFenetre);
}

void menuPrincipal()
{
    int choix, sortie=1;
    afficheMenuPrincipal(0);
    acquisitionPseudoAvecMessage();
    do{
        afficheMenuPrincipal(1);
        scanf("%d",&choix);
        /* contrôle d'acquisition avec réaffichage de l'interfface */
        switch(choix){
            case 1 : /*executer la fonction nouvelle partie */;
                break;
            case 2 : /*executer la fonction leaderboard */;
                break;
            case 3 : /*executer la fonction statistiques */;
                break;
            case 4 : /*executer la fonction changement d'utilisateur */;
                break;
            case 5 : /*executer la fonction paramètres */;
                break;
            default : /*executer la fonction quitter*/;
        }

    }while (sortie);
}
