#include "main.h"

void initialisation(int nbLigneFenetre, int nbColloneFenetre)
{
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
    for(int i=0; i<4; i++)
    {
        pPseudo[i] = &pseudo[i][0];
    }

    do
    {
        choix = afficheMenuPrincipal(1);
        /* contrôle d'acquisition avec réaffichage de l'interfface */
        switch(choix)
        {
        case 1 : /*executer la fonction nouvelle partie */
            nouvellePartie(pPseudo, SUD);
            break;
        case 2 : /*executer la fonction leaderboard */
            break;
        case 3 : /*executer la fonction statistiques */
            break;
        case 4 : /*executer la fonction changement d'utilisateur */
            break;
        case 5 :
            parametre(pPseudo);
            break;
        default : /*executer la fonction quitter*/
            sortie = 0;
            break;
        }
    }
    while (sortie);
}

void nouvellePartie(char *pseudo[], Joueur utilisateur)
{

    char message[TAILLE_MAXI_MESSAGE];
    /**< On change l'affichege pour avoir un affichage plsu simple a lire lors d'une partie entre 4 ordinateur */
    if (utilisateur != SANS_JOUEUR)
    {
        system("cls");
        sprintf(message, "Bonjour %s, vous allez commencer une partie de Belote coinche.;Votre allie est %s et vos ennemis sont %s et %s.;Bonne chance",pseudo[SUD-1],pseudo[NORD-1],pseudo[EST-1],pseudo[OUEST-1] /*pseudo+(EST-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(NORD-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(SUD-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(OUEST-1)*(TAILLE_MAXI_PESEUDO+1)*/);
        afficheMenuSelection("Debut de la partie",message,1);
        printf("appyer sur une touche pour continuer");
        getch();
    }
    else
    {
        printf("debut de la partie \n%s et %s contre %s et %s\n", pseudo[SUD-1],pseudo[NORD-1],pseudo[EST-1],pseudo[OUEST-1]);
    }


    /**< Création des variable  */
    int score[4] = {0};
    Joueur dealer = nbAleatoire(1, 4);


    do
    {
        manche(pseudo, score, dealer, utilisateur);
        dealer = joueurSuivant(dealer);
        /*score[SUD - 1] = 800;//**< a suprimer une fois de debug fini*/

    }
    while ((score[NORD-1] < 701) && (score[EST-1] < 701));

    /**< Fin de partie */
    /**< affichage des resultat */
    if (score[NORD-1] > 701)
    {
        /**< L'utilisatuer et nord gagnent */
        if (utilisateur != SANS_JOUEUR)
        {
            sprintf(message, "Felicitation vous remportez la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d point", pseudo[NORD-1], score[NORD-1] + score[SUD-1], score[EST-1] + score[OUEST-1]);
            afficheSousMenus(message, "Gagne");
        }
        else
        {
            printf("%s et %s remportent la partie avec %d point et %s et %s perdent avec %d points\n",pseudo[SUD -1], pseudo[NORD-1], score[NORD-1] + score[SUD-1],pseudo[EST - 1], pseudo[OUEST -1], score[EST-1] + score[OUEST-1]);
        }

    }
    else
    {
        /**< est et touest gagnent */

        if (utilisateur != SANS_JOUEUR)
        {
            sprintf(message, "Domage vous perder la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d point", pseudo[NORD-1], score[NORD-1] + score[SUD-1], score[EST-1] + score[OUEST-1]);
            afficheSousMenus(message, "Defaite");
        }
        else
        {
            printf("%s et %s remportent la partie avec %d point et %s et %s perdent avec %d points\n",pseudo[EST - 1], pseudo[OUEST -1], score[EST-1] + score[OUEST-1], pseudo[SUD -1], pseudo[NORD-1], score[NORD-1] + score[SUD-1]);
        }

    }

    /**< Lancement de la fonction qui écrit les score et me a jour les stat */

    printf("\nPartie finie \nPressez une touche pour continuer\n");
}


void manche(char *pseudo[], int score[], Joueur dealer, Joueur utilisateur)
{
    if(utilisateur != SANS_JOUEUR){
        system("cls");
    }
    printf("\n*****DEBUT DE LA MANCHE*****\n");
    Carte mainJoueur[4][8];
    Contrat contrat;
    int pointManche[4] = {0};
    int pointAnonce[4] = {0};
    int pointBelote[4] = {0};
    char contratRempli = 0;

    /**< distribution des cartes */
    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);
    printf("\ndistribution des cartes\n");

    /**< anonce des contrat */
    contrat  = annonceContrat(pseudo, dealer, pMainJoueur, utilisateur);

    if (utilisateur != SANS_JOUEUR){
        printf("Appuyer sur une touche pour continuer\n");
        getch();
    }

    /**<plis */
    if (contrat.nbPoint != 0)
    {
        /**< On passe a la phase suivante uniquement si un contrat a ete pris sinon on relance une manche */
        Joueur vainqueurPli = joueurSuivant(dealer);
        Carte cartePli[4], carteDernierPli[4];
        for (int i = 0; i < 4; i++)
        {
            setCarte(&carteDernierPli[i], SANS_VALEUR, SANS_COULEUR);
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                setCarte(&cartePli[j], SANS_VALEUR, SANS_COULEUR);
            }
            vainqueurPli = pli(contrat, vainqueurPli, pseudo, pMainJoueur, pointManche, pointAnonce, pointBelote, cartePli, carteDernierPli, utilisateur, i);


            for (int i = 0; i < 4; i++)
            {
                setCarte(&carteDernierPli[i], cartePli[i].valeur, cartePli[i].couleur);
            }
        }
        /**< Fin de manche et calcul des score */
        /*printf("%d, %d, %d, %d, total : %d\n", pointManche[0], pointManche[1], pointManche[2], pointManche[3], pointManche[0]+ pointManche[1]+ pointManche[2]+ pointManche[3] );*/
        contratRempli = calculPointManche(contrat, pointManche, pointAnonce, pointBelote, score, pseudo, utilisateur);
        if (utilisateur != SANS_JOUEUR){
            printf("Appuyer sur une touche pour continuer\n");
            getch();
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
    while (nbPasse < 3)
    {
        nouveauContrat = proposeContrat(contratPropose, parle, pseudo, pCarteMain, utilisateur);

        /**< Affichage du choix du joueur */
        if (nouveauContrat.nbPoint > 0 && nouveauContrat.coinche == NORMAL)
        {
            printf("%s propose le contrat suivant : ", pseudo[parle - 1]);

            if (utilisateur != SANS_JOUEUR)
            {
                afficheContrat(nouveauContrat, pseudo, 1);
            }
            else
            {
                afficheContrat(nouveauContrat, pseudo, 2);
            }

        }
        else if(nouveauContrat.coinche == COINCHE)
        {
            printf("%s COINCHE !!\n", pseudo[parle - 1]);
        }
        else if(nouveauContrat.coinche == SURCOINCHE)
        {
            printf("%s SURCOINCHE !!!!\n", pseudo[parle - 1]);
        }
        else
        {
            printf("%s passe\n", pseudo[parle - 1]);
        }

        /**< Si un nouveau contrat est proposé alors il devient le cotrat proposé sinon on incrémemnt nbPasse*/
        if (nouveauContrat.nbPoint > contratPropose.nbPoint || nouveauContrat.coinche > contratPropose.coinche)
        {
            contratPropose = nouveauContrat;
            nbPasse = 0;
        }
        else
        {
            nbPasse ++;
        }
        parle = joueurSuivant(parle);

    }


    if (contratPropose.nbPoint == 0)
    {
        printf("\nTout les joueur on passe, on redistribue les carte\n");

    }
    else
    {
        printf("Le contrat suivant a ete choisi pour la manche : %s  ", pseudo[contratPropose.preneur -1]);
        if (utilisateur != SANS_JOUEUR)
        {
            afficheContrat(contratPropose, pseudo, 1);
        }
        else
        {
            afficheContrat(contratPropose, pseudo, 2);
        }
        printf("\n");

    }
    return  contratPropose;
}

Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[], Carte *pCarteMain, Joueur utilisateur)
{
    Contrat nouveauContrat;
    setContrat(&nouveauContrat, SANS_JOUEUR, ZERO, SANS_COULEUR, NORMAL);
    if (parle == utilisateur)
    {
        /**< acquisition par l'utilisateur */
        nouveauContrat = proposeContratUtilisateur(dernierContrat, parle, pCarteMain + (parle -1)*8);

    }
    else
    {
        /**< choix par l'ia d'un contrat */
        nouveauContrat = proposeContratIa(parle, pCarteMain + (parle - 1)*8, dernierContrat);
    }
    return nouveauContrat;
}

Joueur pli(Contrat contrat, Joueur premierAJouer, char *pseudo[], Carte *pCarteMain, int pointManche[],int pointAnonce[],int pliBelote, Carte cartePli[], Carte carteAncienPli[], Joueur utilisateur, int numPli)
{
    Joueur vainceur = SANS_JOUEUR, parle = premierAJouer;
    char message[TAILLE_MAXI_MESSAGE];
    int numCarte=0;
    for (int i = 0; i < 4; i++)
    {
        if (parle == utilisateur)
        {
            /**< interface de pli Utilisateur */
            numCarte = afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(parle -1), contrat, "Entrer le numero de la carte que vous voulez jouer", utilisateur, premierAJouer,0);
        }
        else
        {
            /**< interface de pli ordinateur */
            numCarte  = choixCarteIA(parle, pCarteMain+ 8*(parle -1), cartePli, premierAJouer, contrat.atout,8-numPli);


        }
        poseCarte(parle, numCarte, pCarteMain+ 8*(parle -1), cartePli, 8-numPli);

        /**< affichage de la carte qui vien d'etre jouée */
        genereMessage(message, parle, pseudo, cartePli[parle-1], 0, POSE_CARTE);
        if (utilisateur != SANS_JOUEUR)
        {
            afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(utilisateur -1), contrat, message, utilisateur, premierAJouer,1);
        }
        else
        {
            printf("%s\n", message);

        }
        parle = joueurSuivant(parle);

    }
    /**< Recherche un vainceur et ajout du nombre de point gagné au score du vainceur du nombre point gagné */
    vainceur = vainqueurPli(cartePli, contrat.atout, premierAJouer);
    int pointDuPli = pointPli(cartePli, contrat.atout, 4);
    pointManche[vainceur -1] += pointDuPli;

    /**< 10 de der, on ajoute 10 point au vainceur si on est dans le dernier pli */
    if (numPli == 7)
    {
        pointManche[vainceur -1] += 10;
    }

    genereMessage(message, vainceur, pseudo, cartePli[parle-1], pointDuPli, RESULTAT_PLI);
    if (utilisateur != SANS_JOUEUR)
    {
        afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(utilisateur -1), contrat, message,utilisateur, premierAJouer,1);
    }
    else
    {
        printf("%s\n\n", message);

    }


    return vainceur;
}

int poseCarte (Joueur joueur,int numCarte, Carte *pMainJoueurs, Carte pli[],int carteRestante)
{
    int retour=NULL;
    Carte carteAJouer;
    carteAJouer =  *((numCarte-1)+ pMainJoueurs);

    supprimeCarte(pMainJoueurs,carteRestante,numCarte-1);
    setCarte(pli+joueur-1,carteAJouer.valeur,carteAJouer.couleur);
    retour=1;
    return retour;
}


char calculPointManche(Contrat contrat, int pointManche[],int pointAnonce[],int pointBelote[], int score[],char *pseudo[], Joueur utilisateur)
{
    char contratRempli = 0;
    int pointPreneur = pointManche[contrat.preneur-1] + pointManche[joueurSuivant(joueurSuivant(contrat.preneur))-1];
    int pointAnoncePreneur = pointAnonce[contrat.preneur-1] + pointAnonce[joueurSuivant(joueurSuivant(contrat.preneur))-1];
    int pointBelotePreneur = pointBelote[contrat.preneur-1] + pointBelote[joueurSuivant(joueurSuivant(contrat.preneur))-1];

    int pointDefendant = pointManche[joueurSuivant(contrat.preneur)-1] + pointManche[joueurSuivant(joueurSuivant(joueurSuivant(contrat.preneur)))-1];
    int pointAnonceDefendant = pointAnonce[joueurSuivant(contrat.preneur)-1] + pointAnonce[joueurSuivant(joueurSuivant(joueurSuivant(contrat.preneur)))-1];
    int pointBeloteDefendant = pointBelote[joueurSuivant(contrat.preneur)-1] + pointBelote[joueurSuivant(joueurSuivant(joueurSuivant(contrat.preneur)))-1];

    int totalPointPreneur = 0;
    int totalPointDefandant = 0;

    /**< On reche si le contrat est rampli */
    if (contrat.nbPoint == 170) /**< cas ou un des joueur a pris un capot */
    {
        if (pointPreneur == 162)
        {
            contratRempli = 1;
        }
    }
    else if (contrat.nbPoint == 180) /**< cas ou un des joueur a pris une générale */
    {
        if (pointManche[contrat.preneur-1] == 162)
        {
            contratRempli = 1;
        }
    }
    else
    {
        if(pointPreneur >= 82 && pointPreneur + pointAnoncePreneur >= contrat.nbPoint) /**< Le contrat est rempli si le les point de l'équipe est suppérieur a ce qui anoncé et si il on 82 point sans les anonces */
        {
            contratRempli = 1;
        }

    }

    /**< on donne les point a chaque équipe en dans chaque cas */
    if (contratRempli)
    {
        totalPointPreneur = pointPreneur + pointAnoncePreneur + pointBelotePreneur + contrat.nbPoint;
        totalPointDefandant = pointDefendant + pointAnoncePreneur + pointBeloteDefendant;
        if (contrat.coinche == COINCHE)
        {
            totalPointPreneur *= 2;
            totalPointPreneur += pointAnonceDefendant;
            totalPointDefandant = pointBeloteDefendant;

        }
        else if (contrat.coinche == SURCOINCHE)
        {
            totalPointPreneur *= 4;
            totalPointPreneur += pointAnonceDefendant;
            totalPointDefandant = pointBeloteDefendant;
        }

    }
    else
    {
        totalPointPreneur = pointBelotePreneur;
        totalPointDefandant = 162 + contrat.nbPoint + pointAnonceDefendant + pointAnoncePreneur + pointBeloteDefendant;
        if (contrat.coinche == COINCHE)
        {
            totalPointDefandant *= 2;
        }
        else if (contrat.coinche == SURCOINCHE)
        {
            totalPointDefandant *= 4;
        }

    }
    score[contrat.preneur - 1] += totalPointPreneur;
    score[joueurSuivant(joueurSuivant(contrat.preneur)) - 1] += totalPointPreneur;
    score[joueurSuivant(contrat.preneur)-1] += totalPointDefandant;
    score[joueurSuivant(joueurSuivant(joueurSuivant(contrat.preneur)))-1] += totalPointDefandant;

    /**< on affiche ce qui c'est passé */
    char message[TAILLE_MAXI_MESSAGE];
    if (contratRempli)
    {
        sprintf(message, "%s rempporte son contrat et gagne %d points ;ses adversaires gagnent %d points", pseudo[contrat.preneur-1], totalPointPreneur, totalPointDefandant);

    }
    else
    {
        sprintf(message, "%s echoue son contrat et gagne %d points ;ses adversaires gagnent %d points", pseudo[contrat.preneur-1], totalPointPreneur, totalPointDefandant);
    }
    if (utilisateur != SANS_JOUEUR)
    {
        afficheMenuSelection("Resultat manche", message, 1);
    }
    else
    {
        printf("%s\n", message);
    }



    return contratRempli;
}
