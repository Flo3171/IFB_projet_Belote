#include "main.h"

void initialisation(int nbLigneFenetre, int nbColloneFenetre)
{
    modifieTailleFenetre(nbLigneFenetre, nbColloneFenetre);
}

void menuPrincipal()
{
    int choix, sortie=1,ligne=0;
    int statistique[5][4] = {0};
    int *pStatistique = &statistique[0][0];

    FILE *fichier=NULL, *fichier2=NULL;
    fichier= fopen("sauvegarde/gestion_scores_joueurs.csv","r+");
    fichier2= fopen("sauvegarde/leaderboard.csv","r+");
    if(fichier == NULL || fichier2 == NULL){
        fichier = NULL;
        fichier2 = NULL;
    }

    char pseudo[4][TAILLE_MAXI_PESEUDO+1];
    strcpy(pseudo[0],"A_Philipe");
    strcpy(pseudo[1],"Gilou");
    strcpy(pseudo[3],"Tutu");

    afficheMenuPrincipal(0);


    acquisitionPseudoAvecMessage(pseudo[SUD-1],"Choisisez votre pseudo:",0);
    ligne=ecriturePseudo(pseudo[SUD-1],fichier);

    char *pPseudo[4];
    for(int i=0; i<4; i++)
    {
        pPseudo[i] = &pseudo[i][0];
    }

    do
    {
        choix = afficheMenuPrincipal(1);
        /**< contrôle d'acquisition avec réaffichage de l'interfface */
        switch(choix)
        {
        case 1 :{/**<executer la fonction nouvelle partie */
                int infoEcritureFichier[3] = {0}, nbVictoire = 0;
                nouvellePartie(pPseudo, SUD, pStatistique, infoEcritureFichier);
                nbVictoire = ecrireStatistique(fichier,ligne,infoEcritureFichier[1],1);
                ecrireStatistique(fichier,ligne,infoEcritureFichier[2],2);
                if(infoEcritureFichier[1]==1){
                    ecrireStatistique(fichier,ligne,infoEcritureFichier[0],3);
                }
                ecrireLeaderboard(fichier2,pseudo[SUD-1],nbVictoire);
        }
            break;
        case 2 : /*executer la fonction leaderboard */

            leaderboard(fichier2);
            break;
        case 3 : /*executer la fonction statistiques */
            statistiqueJoueur(fichier,ligne);
            break;
        case 4 :
            joue1000Partie(1000);
            break;
        case 5 : /*executer la fonction changement d'utilisateur */
            acquisitionPseudoAvecMessage(pseudo[SUD-1],"Choisissez un nouveau joueur",1);
            ligne=ecriturePseudo(pseudo[SUD-1],fichier);

            break;
        case 6 :
            parametre(pPseudo);
            break;
        default : /*executer la fonction quitter*/
            sortie = 0;
            break;
        }
    }
    while (sortie);
}

int nouvellePartie(char *pseudo[], Joueur utilisateur, int *pStatistique, int infoEcritureFicher[])
{

    char message[TAILLE_MAXI_MESSAGE];
    int nbManche = 0;
    /**< On change l'affichage pour avoir un affichage plus simple a lire lors d'une partie entre 4 ordinateur */
    if (utilisateur != SANS_JOUEUR)
    {
        system("cls");
        sprintf(message, "Bonjour %s, vous allez commencer une partie de Belote coinchee.;Vous etes dans l'equipe Longitude, votre allie est %s et vous jouez contre l'equipe Latitude qui est composee de %s et %s.;Bonne chance",pseudo[SUD-1],pseudo[NORD-1],pseudo[EST-1],pseudo[OUEST-1] /*pseudo+(EST-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(NORD-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(SUD-1)*(TAILLE_MAXI_PESEUDO+1), pseudo+(OUEST-1)*(TAILLE_MAXI_PESEUDO+1)*/);
        afficheMenuSelection("Debut de la partie",message,1);
        printf("appuyer sur une touche pour continuer");
        getch();
    }
    else if(DEBUG_MODE == 1)
    {
        printf("debut de la partie \n%s et %s contre %s et %s\n", pseudo[SUD-1],pseudo[NORD-1],pseudo[EST-1],pseudo[OUEST-1]);
    }


    /**< Création des variable  */
    int score[4] = {0};
    Joueur dealer = nbAleatoire(1, 4);


    do
    {
        if(manche(pseudo, score, dealer, utilisateur, pStatistique)){
            dealer = joueurSuivant(dealer);
            nbManche ++;
        }
        if (MODE_1_MANCHE == 1){
            score[NORD - 1] += 800;/**< a suprimer une fois de debug fini*/
        }
    }
    while ((score[NORD-1] < 701) && (score[EST-1] < 701));

    /**< Fin de partie */
    /**< affichage des resultat */
    infoEcritureFicher[2] = score[SUD-1];
    if (score[NORD-1] > 701)
    {
        /**< L'utilisatuer et nord gagnent */
        *(pStatistique + NORD - 1) += 1;
        *(pStatistique + SUD - 1) +=1;
        infoEcritureFicher[1] = 1;
        if (utilisateur != SANS_JOUEUR)
        {
            sprintf(message, "Felicitations !! Vous remportez la partie avec %s, vous avez atteint un total de %d points et vos adversaires ont %d points", pseudo[NORD-1], score[NORD-1], score[EST-1]);
            afficheSousMenus(message, "Gagne");
            getch();
        }
        else if (DEBUG_MODE == 1)
        {
            printf("%s et %s remportent la partie avec %d points et %s et %s perdent avec %d points\n",pseudo[SUD -1], pseudo[NORD-1], score[NORD-1],pseudo[EST - 1], pseudo[OUEST -1], score[EST-1]);
        }

    }
    else
    {
        /**< est et touest gagnent */
        *(pStatistique + EST - 1) +=1;
        *(pStatistique + OUEST - 1) +=1;

        if (utilisateur != SANS_JOUEUR)
        {
            sprintf(message, "Dommage !! Vous perdez la partie avec %s, vous avez atteint un total de %d points et vos adversaires ont %d points", pseudo[NORD-1], score[NORD-1], score[EST-1]);
            afficheSousMenus(message, "Defaite");
            getch();
        }
        else if (DEBUG_MODE == 1)
        {
            printf("%s et %s remportent la partie avec %d points et %s et %s perdent avec %d points\n",pseudo[EST - 1], pseudo[OUEST -1], score[EST-1],  pseudo[SUD -1], pseudo[NORD-1], score[NORD-1]);
        }

    }

    /**< Lancement de la fonction qui écrit les score et me a jour les stat */
    if (utilisateur != SANS_JOUEUR || DEBUG_MODE == 1){
     printf("\nPartie finie \nPressez une touche pour continuer\n");
     if (utilisateur != SANS_JOUEUR){
            getch();
        }

    }
    infoEcritureFicher[0] = nbManche;
    return nbManche;
}

char manche(char *pseudo[], int score[], Joueur dealer, Joueur utilisateur, int *pStatistique)
{
    char mancheJouee = 0;
    if(utilisateur != SANS_JOUEUR){
        system("cls");
    }
    if (utilisateur != SANS_JOUEUR || DEBUG_MODE == 1){
        printf("\n*****DEBUT DE LA MANCHE*****\n");
    }

    Carte mainJoueur[4][8];
    Contrat contrat;
    int pointManche[4] = {0};
    int pointAnonce[4] = {0};
    int pointBelote[4] = {0};

    char belote[4] = {0};/**< tableau qui stocke les anonce de chaque joueur, on y ajoute 1 pour le roi d'atout puis 1 pour la dame d'atout */

    /**< distribution des cartes */
    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);
    if (utilisateur != SANS_JOUEUR || DEBUG_MODE == 1){
        printf("\nDistribution des cartes\n");
    }
    /**< On trie les carte de l'utilisateur */
    if(utilisateur != SANS_JOUEUR){
        trieCarte(mainJoueur[utilisateur-1], 8, TOUT_ATOUT);
    }


    /**< anonce des contrat */
    contrat  = annonceContrat(pseudo, dealer, pMainJoueur, utilisateur);

    /**< On cherche si les joueurs on des anonce a faire */
    rechercheAnnonce(pMainJoueur, pointAnonce, utilisateur, pseudo);

    if (utilisateur != SANS_JOUEUR){
        printf("Appuyer sur une touche pour continuer\n");
        getch();
        trieCarte(mainJoueur[utilisateur-1], 8, contrat.atout);

    }

    /**<plis */
    if (contrat.nbPoint != 0)
    {
        mancheJouee = 1;
        *(pStatistique + 4 + contrat.preneur - 1) +=1;
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
            vainqueurPli = pli(contrat, vainqueurPli, pseudo, pMainJoueur, pointManche, pointAnonce, belote, cartePli, carteDernierPli,score, utilisateur, i);
            *(pStatistique + 3*4 + vainqueurPli - 1) += 1;

            for (int i = 0; i < 4; i++)
            {
                setCarte(&carteDernierPli[i], cartePli[i].valeur, cartePli[i].couleur);
            }
        }
        /**< Fin de manche et calcul des score */

        for (int i = 0; i < 4; i++){/**< si un joueur a fait une belote rebelote il gagne 20 point */
            if (belote[i] == 2){
                pointBelote[i] += 20;
            }
        }
        /*printf("%d, %d, %d, %d, total : %d\n", pointManche[0], pointManche[1], pointManche[2], pointManche[3], pointManche[0]+ pointManche[1]+ pointManche[2]+ pointManche[3] );*/
        if (calculPointManche(contrat, pointManche, pointAnonce, pointBelote, score, pseudo, utilisateur)){
            *(pStatistique + 4*2 + contrat.preneur - 1) += 1;
            *(pStatistique + 4*4 + contrat.preneur - 1) += 1;
            *(pStatistique + 4*4 + joueurSuivant(joueurSuivant(contrat.preneur)) - 1) += 1;
        }
        else{
            *(pStatistique + 4*4 + joueurSuivant(contrat.preneur) - 1) += 1;
            *(pStatistique + 4*4 + joueurSuivant(joueurSuivant(joueurSuivant(contrat.preneur))) - 1) += 1;
        }


        if (utilisateur != SANS_JOUEUR){
            printf("Appuyer sur une touche pour continuer\n");
            getch();
        }

    }
    return mancheJouee;


}

Contrat annonceContrat(char *pseudo[], Joueur dealer, Carte *pCarteMain, Joueur utilisateur)
{
    int nbPasse = -1;
    Joueur parle = joueurSuivant(dealer);
    Contrat contratPropose, nouveauContrat;
    setContrat(&contratPropose, SANS_JOUEUR, ZERO, SANS_COULEUR, NORMAL);
    if (utilisateur != SANS_JOUEUR || DEBUG_MODE == 1){
        printf("\nDebut de la phase d'annonce des contrats \n");
    }
    while (nbPasse < 3)
    {
        nouveauContrat = proposeContrat(contratPropose, parle, pseudo, pCarteMain, utilisateur);

        /**< Affichage du choix du joueur */
        if (utilisateur != SANS_JOUEUR || DEBUG_MODE == 1){
            if (nouveauContrat.nbPoint > 0 && nouveauContrat.coinche == NORMAL){
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

    if (utilisateur != SANS_JOUEUR || DEBUG_MODE == 1){
        if (contratPropose.nbPoint == 0)
        {
            printf("\nTous les joueurs ont passe, on redistribue les cartes\n");

        }
        else{
            if (utilisateur != SANS_JOUEUR || DEBUG_MODE == 1){
                printf("Le contrat suivant a ete choisi pour la manche :");
                if (DEBUG_MODE == 1){
                    printf(" %s ", pseudo[contratPropose.preneur -1]);
                }
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

        }
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


Joueur pli(Contrat contrat, Joueur premierAJouer, char *pseudo[], Carte *pCarteMain, int pointManche[], int pointAnonce[], char belote[], Carte cartePli[], Carte carteAncienPli[], int score[], Joueur utilisateur, int numPli)
{
    Joueur vainceur = SANS_JOUEUR, parle = premierAJouer;
    char message[TAILLE_MAXI_MESSAGE];
    int numCarte=0;
    for (int i = 0; i < 4; i++)
    {
        if (parle == utilisateur)
        {
            /**< interface de pli Utilisateur */
            numCarte = afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(parle -1), contrat, "Entrez le numero de la carte que vous voulez jouer", utilisateur, premierAJouer, score, pointManche, 0);
        }
        else
        {
            /**< interface de pli ordinateur */
            numCarte  = choixCarteIA(parle, pCarteMain+ 8*(parle -1), cartePli, premierAJouer, contrat.atout,8-numPli);


        }
        poseCarte(parle, numCarte, pCarteMain+ 8*(parle -1), cartePli, 8-numPli);

        /**< on regarde si une dame ou un roi d'atout vien d'etre jouer pour ajouter au tableau belote[] */


        /**< affichage de la carte qui vien d'etre jouée */
        genereMessage(message, parle, pseudo, cartePli[parle-1], 0, POSE_CARTE);
        if ((cartePli[parle-1].couleur == contrat.atout || contrat.atout == TOUT_ATOUT) && (cartePli[parle-1].valeur == DAME ||cartePli[parle-1].valeur == ROI)){
            belote[parle-1] += 1;
            if (belote[parle-1]== 1){
                strcat(message, " et anonce une Belote");
            }
            else if (belote[parle-1] == 2){
                strcat(message, " et anonce une Rebelote");
            }
       }
        if (utilisateur != SANS_JOUEUR)
        {
            afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(utilisateur -1), contrat, message, utilisateur, premierAJouer, score, pointManche, 1);
        }
        else if (DEBUG_MODE == 1)
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
        afficheInterfacePli(carteAncienPli, cartePli, pseudo, pCarteMain + 8*(utilisateur -1), contrat, message,utilisateur, premierAJouer, score, pointManche, 1);
    }
    else if (DEBUG_MODE == 1)
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
        sprintf(message, "%s remporte son contrat et gagne %d points ;Ses adversaires gagnent %d points. ;L'equipe Longitude a %d points et l'equipe Latitude en a %d", pseudo[contrat.preneur-1], totalPointPreneur, totalPointDefandant, score[NORD -1], score[EST-1]);

    }
    else
    {
        sprintf(message, "%s echoue son contrat et gagne %d points ;Ses adversaires gagnent %d points. ;L'equipe Longitude a %d points et l'equipe Latitude en a %d", pseudo[contrat.preneur-1], totalPointPreneur, totalPointDefandant, score[NORD -1], score[EST-1]);
    }
    if (utilisateur != SANS_JOUEUR)
    {
        afficheMenuSelection("Resultat manche", message, 1);
    }
    else if (DEBUG_MODE == 1)
    {
        printf("%s\n", message);
    }



    return contratRempli;
}
