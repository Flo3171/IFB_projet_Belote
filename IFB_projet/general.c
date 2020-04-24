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
        /* contr�le d'acquisition avec r�affichage de l'interfface */
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
            case 5 : /*executer la fonction param�tres */
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
    printf("\n\n\tBonjour %s, vout aller commencer une partie de Belote coinche\n\tVotre alie est %s et vaut enemis sont %s et %s \n\tBonne chanche", pseudo[SUD-1], pseudo[NORD-1], pseudo[EST-1], pseudo[OUEST-1]);

    /**< Cr�ation des variable  */
    int score[4] = {0};
    Joueur dealer = nbAleatoire(1, 4);

    do{
        manche(pseudo, score, dealer);
        dealer = joueurSuivant(dealer);
        score[SUD - 1] = 800;

    }while ((score[NORD-1] + score[SUD-1] < 701) && (score[EST-1] + score[OUEST-1] < 701));
    char messages[TAILLE_MAXI_MESSAGE];
    if (score[NORD-1] + score[SUD-1] > 701){
        /**< L'utilisatuer et nord gagnent */
        sprintf(messages, "Felicitation vous remportez la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d point", pseudo[NORD-1], score[NORD-1] + score[SUD-1], score[EST-1] + score[OUEST-1]);
        afficheSousMenus(messages, "Gagne");
    }
    else{
        /**< est et touest gagnent */
        sprintf(messages, "Domage vous perder la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d point", pseudo[NORD-1], score[NORD-1] + score[SUD-1], score[EST-1] + score[OUEST-1]);
        afficheSousMenus(messages, "Defaite");
    }

    /**< Lancement de la fonction qui �crit les score et me a jour les stat */

    printf("\nPressez une touche pour revenir au menu\n");
    getch();
}


void manche(char *pseudo[], int score[], Joueur dealer)
{

}
