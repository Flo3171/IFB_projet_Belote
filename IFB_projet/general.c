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
    sprintf(message, "Bonjour %s, vous allez commencer une partie de Belote coinche. Votre alie est %s et vaus ennemis sont %s et %s. Bonne chance", pseudo[SUD-1], pseudo[NORD-1], pseudo[EST-1], pseudo[OUEST-1]);
    afficheSousMenus(message, "Debut de la partie");
    printf("appyer sur une touche pour continuer");
    getch();

    /**< Création des variable  */
    int score[4] = {0};
    Joueur dealer = nbAleatoire(1, 4);


    do{
        manche(pseudo, score, dealer);
        dealer = joueurSuivant(dealer);
        score[SUD - 1] = 800;/**< a suprimer une fois de debug fini */

    }while ((score[NORD-1] + score[SUD-1] < 701) && (score[EST-1] + score[OUEST-1] < 701));

    /**< Fin de partie */
    /**< affichage des resultat */
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
    Contrat contrat;

    /**< distribution des cartes */
    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);

    /**< anonce des contrat */
    contrat  = annonceContrat(pseudo, dealer, pMainJoueur);


}

Contrat annonceContrat(char *pseudo[], Joueur dealer, Carte *pCarteMain)
{
    int nbPasse = 0;
    Joueur parle = joueurSuivant(dealer);
    Contrat contratPropose, nouveauContrat;
    setContrat(&contratPropose, SANS_JOUEUR, ZERO, SANS_COULEUR, NORMAL);
    system("cls");
    printf(" Debut de la phase d'anonce des contrat \n");
    while (nbPasse < 3){
        nouveauContrat = proposeContrat(contratPropose, parle, pseudo, pCarteMain);

        /**< Affichage du choix du joueur */
        if (nouveauContrat.nbPoint > 0){
                printf("%s propose le contrat suivant\n", pseudo[parle - 1]);
            afficheContrat(nouveauContrat, pseudo);
            }
            else{
                printf("\n%s passe\n", pseudo[parle - 1]);
            }

        /**< Si un nouveau contrat est proposé alors il devient le cotrat proposé sinon on incrémemnt nbPasse*/
        if (nouveauContrat.nbPoint > contratPropose.nbPoint || nouveauContrat.coinche > contratPropose.coinche){
            contratPropose = nouveauContrat;
            nbPasse = 0;
        }
        else{
            nbPasse ++;
        }
        parle = joueurSuivant(parle);

    }
    if (contratPropose.nbPoint == 0){
        printf("\nTout les joueur on passe, une nouvelle manche va recomencer dans quelque instants\n");

    }
    else{
        printf("\nLe contrat suivant a ete choisi pour la manche\n");
        afficheContrat(contratPropose, pseudo);
    }
    return  contratPropose;
}

Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[], Carte *pCarteMain)
{
    Contrat nouveauContrat;
    setContrat(&nouveauContrat, SANS_JOUEUR, ZERO, SANS_COULEUR, NORMAL);
    if (parle == SUD){
        /**< acquisition par l'utilisateur */
        afficheMain(pCarteMain + (SUD - 1)*8);
        printf("\nQue voulez vous anoncer :\n");
        printf("1 : Passer\n2 : Encherir\n");
        if (dernierContrat.nbPoint > 0 && (dernierContrat.preneur == joueurSuivant(parle) || dernierContrat.preneur == joueurSuivant(joueurSuivant(joueurSuivant(parle)))){
           printf("3 : coincher\n");
        }
        if (dernierContrat.nbPoint > 0 && dernierContrat.coinche == COINCHE && (dernierContrat.preneur == parle || dernierContrat.preneur == joueurSuivant(joueurSuivant(parle))){
           printf("3 : surcoinche\n");
        }

        int choix = acquisitionEntierSansMessageAvecConsigne(1, 3, ""), choixCouleur;
        Couleur atoutEnchere;
        switch(choix)
        {
        case 1 :
            setContrat(&nouveauContrat, parle, 0, SANS_COULEUR, NORMAL);
            break;
        case 2 :
            system("cls");
            afficheMain(pCarteMain + (SUD - 1)*8);
            printf("\nQuel atout voulez vous choisir :\n1 : Coeur\n2 : Pique\n3 : Carreau\n4 : Trefle\n5 : Tout atout\n6 : Sans atout\n");
            choixCouleur = acquisitionEntierSansMessageAvecConsigne(1, 6, "");
            switch(choixCouleur)
            {
            case 1 :
                atoutEnchere = COEUR;
                break;
            case 2 :
                atoutEnchere = PIQUE;
                break;
            case 3 :
                atoutEnchere = CARREAU;
                break;
            case 4 :
                atoutEnchere = TREFLE;
                break;
            case 5 :
                atoutEnchere = TOUT_ATOUT;
                break;
            case 6 :
                atoutEnchere = SANS_ATOUT;
                break;

            }
            setContrat(&nouveauContrat, parle,10* (acquisitionEntierSansMessageAvecConsigne(80, 170, "\nA combien de points voulez vous encherir (entre 80 et 150) \nEntrer 160 pour un caopot et 170 pour une generale:")/10),atoutEnchere,NORMAL);
            break;
        case 3 :
            break;
        default :
            break;

        }


    }
    else{
        /**< choix par l'ia d'un contrat */
        nouveauContrat = proposeContratIa(parle, pCarteMain + (parle - 1)*8, dernierContrat);
    }
    return nouveauContrat;
}
