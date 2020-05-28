#include "main.h"

void initialisation(int nbLigneFenetre, int nbColloneFenetre)
{
    srand(time(0));
    modifieTailleFenetre(nbLigneFenetre, nbColloneFenetre);
}

void menuPrincipal()
{
    int choix, sortie=1;

    char pseudo[4][TAILLE_MAXI_PESEUDO+1];
    strcpy(pseudo[0],"A_Philipe");
    strcpy(pseudo[1],"Gilou");
    strcpy(pseudo[3],"Tutu");

    afficheMenuPrincipal(0);

    acquisitionPseudoAvecMessage(pseudo[2],"Choisisez votre pseudo:");
    char *pPseudo[4];
    for(int i=0;i<4;i++){
        pPseudo[i] = &pseudo[i][0];
    }

    do{
        choix = afficheMenuPrincipal(1);
        /* contrôle d'acquisition avec réaffichage de l'interfface */
        switch(choix){
            case 1 : /*executer la fonction nouvelle partie */
                nouvellePartie(pPseudo, SUD);
                break;
            case 2 : /*executer la fonction leaderboard */
                break;
            case 3 : /*executer la fonction statistiques */
                break;
            case 4 : /*executer la fonction changement d'utilisateur */
                break;
            case 5 : parametre(pPseudo);
                break;
            default : /*executer la fonction quitter*/
                sortie = 0;
                break;
        }
    }while (sortie);
}

void nouvellePartie(char *pseudo[], Joueur utilisateur)
{

    char message[TAILLE_MAXI_MESSAGE];
    /**< On change l'affichege pour avoir un affichage plsu simple a lire lors d'une partie entre 4 ordinateur */
    if (utilisateur != SANS_JOUEUR){
        system("cls");
        sprintf(message, "Bonjour %s, vous allez commencer une partie de Belote coinche.;Votre allie est %s et vos ennemis sont %s et %s.;Bonne chance",pseudo[SUD-1],pseudo[NORD-1],pseudo[EST-1],pseudo[OUEST-1] /*pseudo+(EST-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(NORD-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(SUD-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(OUEST-1)*(TAILLE_MAXI_PESEUDO+1)*/);
        afficheMenuSelection("Debut de la partie",message ,1);
        printf("appyer sur une touche pour continuer");
        getch();
    }
    else {
        printf("debut de la partie \n%s et %s contre %s et %s\n", pseudo[SUD-1],pseudo[NORD-1],pseudo[EST-1],pseudo[OUEST-1]);
    }


    /**< Création des variable  */
    int score[4] = {0};
    Joueur dealer = nbAleatoire(1, 4);


    do{
        manche(pseudo, score, dealer, utilisateur);
        dealer = joueurSuivant(dealer);
        score[SUD - 1] = 800;/**< a suprimer une fois de debug fini*/

    }while ((score[NORD-1] + score[SUD-1] < 701) && (score[EST-1] + score[OUEST-1] < 701));

    /**< Fin de partie */
    /**< affichage des resultat */
    if (score[NORD-1] + score[SUD-1] > 701){
        /**< L'utilisatuer et nord gagnent */
        if (utilisateur != SANS_JOUEUR){
            sprintf(message, "Felicitation vous remportez la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d point", pseudo[NORD-1], score[NORD-1] + score[SUD-1], score[EST-1] + score[OUEST-1]);
            afficheSousMenus(message, "Gagne");
        }
        else{
            printf("%s et %s remportent la partie avec %d point et %s et %s perdent avec %d points\n",pseudo[SUD -1], pseudo[NORD-1], score[NORD-1] + score[SUD-1],pseudo[EST - 1], pseudo[OUEST -1], score[EST-1] + score[OUEST-1]);
        }

    }
    else{
        /**< est et touest gagnent */

        if (utilisateur != SANS_JOUEUR){
            sprintf(message, "Domage vous perder la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d point", pseudo[NORD-1], score[NORD-1] + score[SUD-1], score[EST-1] + score[OUEST-1]);
            afficheSousMenus(message, "Defaite");
        }
        else{
            printf("%s et %s remportent la partie avec %d point et %s et %s perdent avec %d points\n",pseudo[EST - 1], pseudo[OUEST -1], score[EST-1] + score[OUEST-1], pseudo[SUD -1], pseudo[NORD-1], score[NORD-1] + score[SUD-1]);
        }

    }

    /**< Lancement de la fonction qui écrit les score et me a jour les stat */

    printf("\nPartie finie \nPressez une touche pour continuer\n");
    getch();
}


void manche(char *pseudo[], int score[], Joueur dealer, Joueur utilisateur)
{
    Carte mainJoueur[4][8];
    Contrat contrat;
    int pointManche[4] = {0};

    /**< distribution des cartes */
    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);
    printf("\ndistribution des cartes\n");

    /**< anonce des contrat */
    contrat  = annonceContrat(pseudo, dealer, pMainJoueur, utilisateur);
    getch();

    /**<plis */
    Joueur parle = joueurSuivant(dealer);
    if (contrat.nbPoint != 0){
        /**< On passe a la phase suivante uniquement si un contrat a ete pris sinon on relance une manche */
        Joueur vainqueurPli = dealer;
        Carte cartePli[4], carteDernierPli[4];
        for (int i = 0; i < 4; i++){
            setCarte(&carteDernierPli[i], SANS_VALEUR, SANS_COULEUR);
        }
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 4; j++){
                setCarte(&cartePli[i], SANS_VALEUR, SANS_COULEUR);
            }
            vainqueurPli = pli(contrat, parle, pseudo, pMainJoueur, pointManche, cartePli, carteDernierPli, vainqueurPli, i+1, utilisateur);

            for (int i = 0; i < 4; i++){
                setCarte(&carteDernierPli[i], cartePli[i].valeur, cartePli[i].couleur);
            }
        }
    }


}

Contrat annonceContrat(char *pseudo[], Joueur dealer, Carte *pCarteMain, Joueur utilisateur)
{
    int nbPasse = -1;
    Joueur parle = joueurSuivant(dealer);
    Contrat contratPropose, nouveauContrat;
    setContrat(&contratPropose, SANS_JOUEUR, ZERO, SANS_COULEUR, NORMAL);
    printf("\nDebut de la phase d'anonce des contrat \n");
    while (nbPasse < 3){
        nouveauContrat = proposeContrat(contratPropose, parle, pseudo, pCarteMain, utilisateur);

        /**< Affichage du choix du joueur */
        if (nouveauContrat.nbPoint > 0 && nouveauContrat.coinche == NORMAL){
            printf("%s propose le contrat suivant : ", pseudo[parle - 1]);

            if (utilisateur != SANS_JOUEUR){
                afficheContrat(nouveauContrat, pseudo, 1);
            }
            else{
                afficheContrat(nouveauContrat, pseudo, 2);
            }

        }
        else if(nouveauContrat.coinche == COINCHE){
            printf("%s COINCHE !!\n", pseudo[parle - 1]);
        }
        else if(nouveauContrat.coinche == SURCOINCHE){
            printf("%s SURCOINCHE !!!!\n", pseudo[parle - 1]);
        }
        else{
            printf("%s passe\n", pseudo[parle - 1]);
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
        printf("\nTout les joueur on passe, on redistribue les carte\n");

    }
    else{
        printf("Le contrat suivant a ete choisi pour la manche : %s  ", pseudo[contratPropose.preneur -1]);
        if (utilisateur != SANS_JOUEUR){
            afficheContrat(contratPropose, pseudo, 1);
        }
        else{
            afficheContrat(contratPropose, pseudo, 2);
        }

    }
    return  contratPropose;
}

Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[], Carte *pCarteMain, Joueur utilisateur)
{
    Contrat nouveauContrat;
    setContrat(&nouveauContrat, SANS_JOUEUR, ZERO, SANS_COULEUR, NORMAL);
    if (parle == utilisateur){
        /**< acquisition par l'utilisateur */
        nouveauContrat = proposeContratUtilisateur(dernierContrat, parle, pCarteMain + (parle -1)*8);

    }
    else{
        /**< choix par l'ia d'un contrat */
        nouveauContrat = proposeContratIa(parle, pCarteMain + (parle - 1)*8, dernierContrat);
    }
    return nouveauContrat;
}


Joueur pli(Contrat contrat, Joueur parle, char *pseudo[], Carte *pCarteMain, int pointManche[], Carte cartePli[], Carte carteAncienPli[], Joueur dernierVainceur,int numPli, Joueur utilisateur)
{
    Joueur vainceur = SANS_JOUEUR;
    int numCarte=0;
    for (int i = 0; i < 4; i++){
        if (parle == utilisateur){
            /**< interface de pli Utilisateur */
            numCarte=afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(utilisateur -1), contrat, " ", dernierVainceur,0);
            poseCarte(SUD,numCarte,pCarteMain+ 8*(utilisateur -1),cartePli,i,8-numPli);
            afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(utilisateur -1), contrat, " ", dernierVainceur,1);
        }
        else{
            /**< interface de pli ordinateur */

        }
        parle = joueurSuivant(parle);
    }
    return vainceur;
}

int poseCarte (Joueur joueur,int numCarte, Carte *pMainJoueurs, Carte pli[],int cartePosee,int carteRestante)
{
    int retour=NULL;
    Carte carteAJouer;
    carteAJouer =  *((numCarte-1)+ pMainJoueurs);

    supprimeCarte(pMainJoueurs,carteRestante,numCarte-1);
    setCarte(pli+joueur-1,carteAJouer.valeur,carteAJouer.couleur);
    retour=1;

    return retour;
}
