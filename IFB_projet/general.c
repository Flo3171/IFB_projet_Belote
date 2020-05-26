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
                nouvellePartie(pPseudo);
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

void nouvellePartie(char *pseudo[])
{
    system("cls");
    char message[TAILLE_MAXI_MESSAGE];
    sprintf(message, "Bonjour %s, vous allez commencer une partie de Belote coinche.;Votre allie est %s et vos ennemis sont %s et %s.;Bonne chance",pseudo[SUD-1],pseudo[NORD-1],pseudo[EST-1],pseudo[OUEST-1] /*pseudo+(EST-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(NORD-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(SUD-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(OUEST-1)*(TAILLE_MAXI_PESEUDO+1)*/);
    afficheMenuSelection("Debut de la partie",message ,1);
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
    int pointManche[4] = {0};

    /**< distribution des cartes */
    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);

    /**< anonce des contrat */
    contrat  = annonceContrat(pseudo, dealer, pMainJoueur);

    /**<plis */
    Joueur parle = joueurSuivant(dealer);
    if (contrat.nbPoint != 0){
        Joueur vainceurPli = SANS_JOUEUR;
        Carte cartePli[4], carteDernierPli[4];
        for (int i = 0; i < 4; i++){
            setCarte(&carteDernierPli[i], SANS_VALEUR, SANS_COULEUR);
        }
        for (int i = 0; i < 8; i++){
            for (int i = 0; i < 4; i++){
                setCarte(&cartePli[i], SANS_VALEUR, SANS_COULEUR);
            }
            vainceurPli = pli(contrat, parle, pseudo, pMainJoueur, pointManche, cartePli, carteDernierPli, vainceurPli,i);
            for (int i = 0; i < 4; i++){
                setCarte(&carteDernierPli[i], cartePli[i].valeur, cartePli[i].couleur);
            }
        }
    }


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
        if (nouveauContrat.nbPoint > 0 && nouveauContrat.coinche == NORMAL){
            printf("%s propose le contrat suivant\n", pseudo[parle - 1]);
            afficheContrat(nouveauContrat, pseudo);
        }
        else if(nouveauContrat.coinche == COINCHE){
            printf("%s COINCHE !!\n", pseudo[parle - 1]);
        }
        else if(nouveauContrat.coinche == SURCOINCHE){
            printf("%s SURCOINCHE !!!!\n", pseudo[parle - 1]);
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
        if (dernierContrat.nbPoint > 0 && (dernierContrat.preneur == joueurSuivant(parle) || dernierContrat.preneur == joueurSuivant(joueurSuivant(joueurSuivant(parle))))){
           printf("3 : coincher\n");
        }
        else if (dernierContrat.nbPoint > 0 && dernierContrat.coinche == COINCHE && (dernierContrat.preneur == parle || dernierContrat.preneur == joueurSuivant(joueurSuivant(parle)))){
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
            setContrat(&nouveauContrat, parle,10* (acquisitionEntierSansMessageAvecConsigne(dernierContrat.nbPoint+1, 170, "\nA combien de points voulez vous encherir (entre 80 et 150) \nEntrer 160 pour un caopot et 170 pour une generale:")/10),atoutEnchere,NORMAL);
            break;
        case 3 :
            if (dernierContrat.nbPoint > 0 && (dernierContrat.preneur == joueurSuivant(parle) || dernierContrat.preneur == joueurSuivant(joueurSuivant(joueurSuivant(parle))))){
           setContrat(&nouveauContrat, dernierContrat.preneur, dernierContrat.nbPoint, dernierContrat.atout, COINCHE);
        }
        else if (dernierContrat.nbPoint > 0 && dernierContrat.coinche == COINCHE && (dernierContrat.preneur == parle || dernierContrat.preneur == joueurSuivant(joueurSuivant(parle)))){
            setContrat(&nouveauContrat, dernierContrat.preneur, dernierContrat.nbPoint, dernierContrat.atout, SURCOINCHE);
        }
        else{
            printf("Vous ne pouvez pas coincher ou surcoincher");
        }

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


Joueur pli(Contrat contrat, Joueur parle, char *pseudo[], Carte *pCarteMain, int pointManche[], Carte cartePli[], Carte carteAncienPli[], Joueur dernierVainceur,int numPli)
{
    Joueur vainceur = SANS_JOUEUR;
    int numCarte=0;
    for (int i = 0; i < 4; i++){
        if (parle == SUD){
            /**< interface de pli Utilisateur */
            numCarte=afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(SUD -1), contrat, "coucou", dernierVainceur,0);
            poseCarte(SUD,numCarte,pCarteMain+ 8*(SUD -1),cartePli,i,8-numPli);
            afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(SUD -1), contrat, "coucou", dernierVainceur,1);
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
    afficheMain(pMainJoueurs);

    supprimeCarte(pMainJoueurs,carteRestante,numCarte-1);
    setCarte(pli+joueur-1,carteAJouer.valeur,carteAJouer.couleur);
    retour=1;

    afficheMain(pMainJoueurs),
    afficheMain(pli);
    printf("\n\n\n\n");
    getch();
    return retour;
}
