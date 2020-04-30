#include "main.h"

void initialisation(int nbLigneFenetre, int nbColloneFenetre)
{
    modifieTailleFenetre(nbLigneFenetre, nbColloneFenetre);
}

void menuPrincipal()
{
    int choix, sortie=1;
    char *pseudo[4] = {"A_Philipe", "Gilou", "Utilisateur", "Tutu"};
    afficheMenuPrincipal(0);

    acquisitionPseudoAvecMessage();
    do{
        choix = afficheMenuPrincipal(1);
        /* contrôle d'acquisition avec réaffichage de l'interfface */
        switch(choix){
            case 1 : /*executer la fonction nouvelle partie */
                nouvellePartie(pseudo);
                break;
            case 2 : /*executer la fonction leaderboard */
                break;
            case 3 : /*executer la fonction statistiques */
                break;
            case 4 : /*executer la fonction changement d'utilisateur */
                break;
            case 5 : /*executer la fonction paramètres */
                break;
            default : /*executer la fonction quitter*/
                sortie = 0;
                break;
        }
    }while (sortie);
}

void nouvellePartie(char *pseudo[])
{
    system("cls");
    char message[TAILLE_MAXI_MESSAGE];
    sprintf(message, "Bonjour %s, vout aller commencer une partie de Belote coinche. Votre alie est %s et vaut enemis sont %s et %s. Bonne chance", pseudo[SUD-1], pseudo[NORD-1], pseudo[EST-1], pseudo[OUEST-1]);
    afficheSousMenus(message, "Debut de la partie");

    /**< Création des variable  */
    int score[4] = {0};
    Joueur dealer = nbAleatoire(1, 4);

    do{
        manche(pseudo, score, dealer);
        dealer = joueurSuivant(dealer);
        score[SUD - 1] = 800;/**< a suprimer une fois de debug fini */

    }while ((score[NORD-1] + score[SUD-1] < 701) && (score[EST-1] + score[OUEST-1] < 701));
    if (score[NORD-1] + score[SUD-1] > 701){
        /**< L'utilisatuer et nord gagnent */
        sprintf(message, "Felicitation vous remportez la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d point", pseudo[NORD-1], score[NORD-1] + score[SUD-1], score[EST-1] + score[OUEST-1]);
        afficheSousMenus(message, "Gagne");
    }
    else{
        /**< est et touest gagnent */
        sprintf(message, "Domage vous perder la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d point", pseudo[NORD-1], score[NORD-1] + score[SUD-1], score[EST-1] + score[OUEST-1]);
        afficheSousMenus(message, "Defaite");
    }

    /**< Lancement de la fonction qui écrit les score et me a jour les stat */

    printf("\nPressez une touche pour revenir au menu\n");
    getch();
}


void manche(char *pseudo[], int score[], Joueur dealer)
{
    Carte mainJoueur[4][8];

    /**< distribution des cartes */
    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);
    afficheMain(mainJoueur[SUD - 1]);

    /**< anonce des contrat */


}

Contrat annonceContrat(char *pseudo[], Joueur dealer)
{
    int nbPasse = 0;
    Joueur parle = joueurSuivant(dealer);
    Contrat contratPropose, nouveauContrat;
    contratPropose.nbPoint = 0;
    printf(" Debut de la phase d'anonce ds contrat \n");
    while (nbPasse < 3){
        nouveauContrat = proposeContrat(contratPropose, parle, pseudo);
        if (nouveauContrat.nbPoint > contratPropose.nbPoint || nouveauContrat.coinche > contratPropose.coinche){
            contratPropose = nouveauContrat;
            printf("%s propose le contrat suivant\n", pseudo[parle]);
            afficheContrat(contratPropose, pseudo);
        }
        else{
            nbPasse ++;
        }

    }
    return  contratPropose;
}

Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[])
{
    Contrat nouveauContrat;
    nouveauContrat.nbPoint = 0;
    if (parle == SUD){
        /**< acquisition par l'utilisateur */


    }
    else{
        /**< choix par l'ia d'un contrat */
    }
    return nouveauContrat;
}
