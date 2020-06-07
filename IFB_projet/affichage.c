#include "main.h"

int afficheMenuPrincipal(int type)
{
    int retour;
    if (type == 0){
        system("cls");

        printf("\t ____________________________________ \n");
        printf("\t|C}--\\/?##?{______________}?##?\\/--{C|\n");
        printf("\t|$|<>/\\--#~#~#~#~#--#~#~#~#~#--/\\<>|$|\n");
        printf("\t|#|<><><><><><><></\\><><><><><><><>|#|\n");
        printf("\t|$|><><><><><><></  \\><><><><><><><|$|\n");
        printf("\t|#|<><><><><><></    \\><><><><><><>|#|\n");
        printf("\t|$|><><><><><></      \\><><><><><><|$|\n");
        printf("\t|#|<><><><><></        \\><><><><><>|#|\n");
        printf("\t|$|><><><><></          \\><><><><><|$|\n");
        printf("\t|#|<><><><></            \\><><><><>|#|\n");
        printf("\t|$|><><><></  & BELOTE &  \\><><><><|$|\n");
        printf("\t|#|<><><></  & COINCHEE &  \\><><><>|#|\n");
        printf("\t|$|><><></                  \\><><><|$|\n");
        printf("\t|$|><><><\\        BY        /><><><|$|\n");
        printf("\t|#|<><><><\\    FLORIAN     /><><><>|#|\n");
        printf("\t|$|><><><><\\      &&      /><><><><|$|\n");
        printf("\t|#|<><><><><\\    CARLO   /><><><><>|#|\n");
        printf("\t|$|><><><><><\\          /><><><><><|$|\n");
        printf("\t|#|<><><><><><\\        /><><><><><>|#|\n");
        printf("\t|$|><><><><><><\\      /><><><><><><|$|\n");
        printf("\t|#|><><><<><><><\\    /><><><><><><>|#|\n");
        printf("\t|$|><><><><><><><\\  /><><><><><><><|$|\n");
        printf("\t|#|<><><><><><><><\\/><><><><><><><>|#|\n");
        printf("\t|$|<__>~?#?~?#?~?#~~#?~?#?~?#?~<__>|$|\n");
        printf("\t|\\C?#?#?}}=======----======={{?#?#?C/|\n");
        printf("\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("\t\t appuyez pour continuer");

        getch();
        retour = 0;
    }

    if (type == 1){
        afficheMenuSelection("<>Menu Principal<>","1-nouvelle partie;2-leaderboard;3-statistiques;4-changement d'utilisateur;5-parametres;6-quitter",2);

        retour = acquisitionEntierSansMessageAvecConsigne(1,6,"Choisissez une des actions proposees dans le menu:");
        return retour;
    }
    return retour;
}


int afficheInterfacePli(Carte dernierPli[], Carte pli[], char *pseudo[], Carte cartesEnMain[], Contrat contratActuel, char message[],Joueur utilisteur, Joueur dernierVainqueur,int score[], int pointManche[], int type)
{
    /**< Formatage des chaine de caracère relative aux pseudo */
    char pseudoCentre[4][TAILLE_MAXI_PESEUDO + 1];
    for (int i = 0; i < NB_JOUEUR; i++){
        centreChaine(pseudo[i], pseudoCentre[i], TAILLE_MAXI_PESEUDO);
    }
    char dernierVainqueurFormate[TAILLE_MAXI_PESEUDO + 1];
    formatePseudo(dernierVainqueur, pseudo, TAILLE_MAXI_PESEUDO, dernierVainqueurFormate, 1);


    /**< Formatage des chaine de caractère relative au message */
    char messageCentre[3][71];
    char *pMessageCentre = &messageCentre[0][0];
    decoupeChaine(message, pMessageCentre, 70, 3);

     /**< Formatage des chaine de caractère relative aux cartes */
     char pliFormate[4][2][8];
     char *pPliFormate = &pliFormate[0][0][0];
     formateCarte(pli, pPliFormate, 4, 7, 1);

     char dernierPliFormate[4][2][8];
     char *pDernierPliFormate = &dernierPliFormate[0][0][0];
     formateCarte(dernierPli, pDernierPliFormate, 4, 7, 0);

     char carteEnMainFormate[8][2][8];
     char *pCarteEnMainFormate = &carteEnMainFormate[0][0][0];
     formateCarte(cartesEnMain, pCarteEnMainFormate, 8, 7, 1);

     /**< Formatage des chaine de caractère relative au contrat*/
     char contratActuelFormate[4][TAILLE_MAXI_PESEUDO + 1];
     char *pContratActuelFormate = &contratActuelFormate[0][0];
     formateContrat(contratActuel, pContratActuelFormate, TAILLE_MAXI_PESEUDO, pseudo);

    int carteSelection = 0,retour=0;




    system("cls");

    if(DEBUG_MODE && utilisteur == SUD){
        printf("Main de %s\n", pseudo[NORD-1]);
        afficheMain(cartesEnMain - 8*2);
        printf("Main de %s\n", pseudo[EST-1]);
        afficheMain(cartesEnMain - 8*1);
        printf("Main de %s\n", pseudo[SUD-1]);
        afficheMain(cartesEnMain);
        printf("Main de %s\n", pseudo[OUEST-1]);
        afficheMain(cartesEnMain + 8);


    }
    printf(" ________________________________________________________________________________________\n");
    printf("|************************************Belote coinchee*************************************|\n");
    printf("| ______________________					 _______________________ |\n");
    printf("||Dernier pli :		|	   %s 	|Contrat :	        ||\n", pseudoCentre[0]);
    printf("||        %s       |		 _______		| %s  ||\n", dernierPliFormate[0][0], contratActuelFormate[0]);
    printf("||  %s     %s |		|%s|		| %s  ||\n",dernierPliFormate[3][0], dernierPliFormate[1][0], pliFormate[0][1], contratActuelFormate[1]);
    printf("||        %s       |		|	|		| Atout : %s||\n", dernierPliFormate[2][0], contratActuelFormate[2]);
    printf("||Vainqueur :           |		|%s|		| %s  ||\n", pliFormate[0][0], contratActuelFormate[3]);
    printf("|| %s |		|_______|		|_______________________||\n", dernierVainqueurFormate);
    printf("||______________________|		                                                 |\n");
    printf("|											 |\n");
    printf("| %s 						   %s  |\n", pseudoCentre[3], pseudoCentre[1]);
    printf("|	 _______							 _______	 |\n");
    printf("|	|%s|							|%s|	 |\n", pliFormate[3][1], pliFormate[1][1]);
    printf("|	|	|							|	|	 |\n");
    printf("|	|%s|							|%s|	 |\n", pliFormate[3][0], pliFormate[1][0]);
    printf("|	|_______|							|_______|	 |\n");
    printf("|											 |\n");
    printf("| _________________________              _______               _________________________ |\n");
    printf("||Score :                  |            |%s|             |Point dans la manche :   ||\n", pliFormate[2][1]);
    printf("||_________________________|            |       |             |_________________________||\n");
    printf("||   Equipe   |   Equipe   |            |%s|             |   Equipe   |   Equipe   ||\n", pliFormate[2][0]);
    printf("||  Latitude: | Longitude: |            |_______|             |  Latitude: | Longitude: ||\n");
    printf("||            |            |                                  |            |            ||\n");
    printf("||%4d points |%4d points |       %s       | %3d points | %3d points ||\n",score[SUD-1], score[EST-1], pseudoCentre[2], pointManche[NORD-1]+ pointManche[SUD-1], pointManche[EST-1]+pointManche[OUEST-1]);
    printf("||____________|____________|                                  |____________|____________||\n");
    printf("|											 |\n");
    printf("|Votre main :										 |\n");
    printf("|  _______    _______    _______    _______    _______    _______    _______    _______  |\n");
    printf("| |%s|  |%s|  |%s|  |%s|  |%s|  |%s|  |%s|  |%s| |\n", carteEnMainFormate[0][1], carteEnMainFormate[1][1], carteEnMainFormate[2][1], carteEnMainFormate[3][1], carteEnMainFormate[4][1], carteEnMainFormate[5][1], carteEnMainFormate[6][1], carteEnMainFormate[7][1]);
    printf("| |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       | |\n");
    printf("| |%s|  |%s|  |%s|  |%s|  |%s|  |%s|  |%s|  |%s| |\n", carteEnMainFormate[0][0], carteEnMainFormate[1][0], carteEnMainFormate[2][0], carteEnMainFormate[3][0], carteEnMainFormate[4][0], carteEnMainFormate[5][0], carteEnMainFormate[6][0], carteEnMainFormate[7][0]);
    printf("| |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______| |\n");
    printf("|											 |\n");
    printf("|    (1)        (2)        (3)        (4)        (5)        (6)        (7)        (8)    |\n");
    printf("|											 |\n");
    printf("|	 ________________________________________________________________________	 |\n");
    printf("|	| %s |       |\n", messageCentre[0]);
    printf("|	| %s |       |\n", messageCentre[1]);
    printf("|	| %s |       |\n", messageCentre[2]);
    printf("|	|                   Pressez une touche pour continuer                    |       |\n");
    printf("|	|________________________________________________________________________|	 |\n");
    printf("|________________________________________________________________________________________|\n");

    Carte carteAJouer;
    Carte *pCarteEnMain = &cartesEnMain[0];
    Couleur atout=contratActuel.atout;


    if(type == 0){
        do{
            carteSelection  = acquisitionEntierSansMessageAvecConsigne(1, 8, "Quelle carte voulez vous jouer :");
            carteAJouer =  *(pCarteEnMain + carteSelection-1);
            retour = carteValide(carteAJouer,pli,atout,cartesEnMain, dernierVainqueur,SUD);
            if (retour == 0){
                printf("Les regles vous interdisent de jouer cette carte\n");
            }
        }while (retour == 0);
    }else{
        carteSelection = 0 ;
        getch();
    }
    return carteSelection;
}

void modifieTailleFenetre(int nbLigneFenetre, int nbColloneFentre)
{
    char comande[100];
    sprintf(comande, "mode con LINES=%d COLS=%d", nbLigneFenetre, nbColloneFentre);
    system(comande);

}


void afficheSousMenus(char phrase[],char intitule [])
{
    /**< contrôle le centrage du titre du sous-menu */
    char titre[27];
    centreChaine(intitule,titre,26);

    /**< découpe la phrase pour pouvoir l'afficher  */
    char messageCentre[18][31];
    char *pMessageCentre = &messageCentre[0][0];
    decoupeChaine(phrase, pMessageCentre, 30, 18);

    /**<efface l'écran et affiche le sous-menu avec le texte correspondant */
    system("cls");
    printf("\t ____________________________________\n");
    printf("\t|¤}--\\/?##?{______________}?##?\\/--{¤|\n");
    printf("\t|$|<>/%s\\<>|$|\n",titre);
    printf("\t|#|_/                            \\_|#|\n");
    printf("\t|$| %s |$|\n",messageCentre[0]);
    printf("\t|#| %s |#|\n",messageCentre[1]);
    printf("\t|$| %s |$|\n",messageCentre[2]);
    printf("\t|#| %s |#|\n",messageCentre[3]);
    printf("\t|$| %s |$|\n",messageCentre[4]);
    printf("\t|#| %s |#|\n",messageCentre[5]);
    printf("\t|$| %s |$|\n",messageCentre[6]);
    printf("\t|#| %s |#|\n",messageCentre[7]);
    printf("\t|$| %s |$|\n",messageCentre[8]);
    printf("\t|$| %s |$|\n",messageCentre[9]);
    printf("\t|#| %s |#|\n",messageCentre[10]);
    printf("\t|$| %s |$|\n",messageCentre[11]);
    printf("\t|#| %s |#|\n",messageCentre[12]);
    printf("\t|$| %s |$|\n",messageCentre[13]);
    printf("\t|#| %s |#|\n",messageCentre[14]);
    printf("\t|$| %s |$|\n",messageCentre[15]);
    printf("\t|#| %s |#|\n",messageCentre[16]);
    printf("\t|$| %s |$|\n",messageCentre[17]);
    printf("\t|#|                                |#|\n");
    printf("\t|$|<__>~?#?~?#?~?#~~#?~?#?~?#?~<__>|$|\n");
    printf("\t|\\¤?#?#?}}=======----======={{?#?#?¤/|\n");
    printf("\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

void afficheMain(Carte carte[])
{
    char carteEnMainFormate[8][2][8];
    char *pCarteEnMainFormate = &carteEnMainFormate[0][0][0];
    formateCarte(carte, pCarteEnMainFormate, 8, 7, 1);
    printf(" ________________________________________________________________________________________\n");
    printf("|Votre main :										 |\n");
    printf("|  _______    _______    _______    _______    _______    _______    _______    _______  |\n");
    printf("| |%s|  |%s|  |%s|  |%s|  |%s|  |%s|  |%s|  |%s| |\n", carteEnMainFormate[0][1], carteEnMainFormate[1][1], carteEnMainFormate[2][1], carteEnMainFormate[3][1], carteEnMainFormate[4][1], carteEnMainFormate[5][1], carteEnMainFormate[6][1], carteEnMainFormate[7][1]);
    printf("| |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       | |\n");
    printf("| |%s|  |%s|  |%s|  |%s|  |%s|  |%s|  |%s|  |%s| |\n", carteEnMainFormate[0][0], carteEnMainFormate[1][0], carteEnMainFormate[2][0], carteEnMainFormate[3][0], carteEnMainFormate[4][0], carteEnMainFormate[5][0], carteEnMainFormate[6][0], carteEnMainFormate[7][0]);
    printf("| |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______| |\n");
    printf("|											 |\n");
    printf("|    (1)        (2)        (3)        (4)        (5)        (6)        (7)        (8)    |\n");
    printf("|											 |\n");
    printf("|________________________________________________________________________________________|\n");

}


void afficheContrat(Contrat contrat, char *pseudo[], int version)
{
    char contratActuelFormate[4][TAILLE_MAXI_PESEUDO + 1];
    char *pContratActuelFormate = &contratActuelFormate[0][0];
    formateContrat(contrat, pContratActuelFormate, TAILLE_MAXI_PESEUDO, pseudo);

    if (version == 1){
        printf("\n ______________________ \n");
        printf("|Contrat :	       |\n");
        printf("| %s |\n", contratActuelFormate[0]);
        printf("| %s |\n", contratActuelFormate[1]);
        printf("| Atout: %s|\n", contratActuelFormate[2]);
        printf("| %s |\n", contratActuelFormate[3]);
        printf("|______________________|\n\n");
    }
    else if (version == 2){
        printf("%s atout : %s %s\n", contratActuelFormate[1], contratActuelFormate[2], contratActuelFormate[3]);
    }


}

void afficheMenuSelection(char intitule [],char phrase[],int sautDeLigne)
{
    int nbMenu=1;
    /**< contrôle le centrage du titre du sous-menu */
    char titre[27];
    centreChaine(intitule,titre,26);


    char selection[18][200];
    int ligne=0,colonne=0;
    /**< effacement de la chaine de carrateres */
    /*for(int w=0; w < 18; w++){
        for(int k = 0; k < 200; k++){
            selection[w][k]=" ";
        }
    }*/
    for (int i = 0; i < 18; i++){
        rempliEspace(selection[i], 199);
    }

    /**< decoupage de la chaine en entrée au niveau des ';' est remplacement par des '\0' */
    for(int i=0;i<strlen(phrase)+1;i++){
        if (phrase[i]==';' || phrase[i]=='\0' ){
            selection[ligne][colonne]='\0';
            ligne = ligne+1;
            colonne =0;
            nbMenu=nbMenu+1;
        }else{
            selection[ligne][colonne]=phrase[i];
            colonne=colonne+1;
        }
    }

    /**< découpe des morceaux de phrase pour pouvoir les afficher  */

    char messageCentre[18][31];
    char *pMessageCentre = &messageCentre[0][0];
    int decalage=0;
    ligne = 0;
    for(int j=0;j<nbMenu;j++){
        decalage= (strlen(selection[j])/30+1);
        decoupeChaine(selection[j], pMessageCentre, 30,decalage);
        pMessageCentre = pMessageCentre+(decalage*31);
        decoupeChaine("", pMessageCentre, 30,sautDeLigne);
        ligne=ligne + decalage;
        pMessageCentre = pMessageCentre+sautDeLigne*31;
    }
    decoupeChaine("", pMessageCentre, 30, 18-ligne);

    /**<efface l'écran et affiche le sous-menu avec le texte correspondant */
    system("cls");
    printf("\t ____________________________________\n");
    printf("\t|¤}--\\/?##?{______________}?##?\\/--{¤|\n");
    printf("\t|$|<>/%s\\<>|$|\n",titre);
    printf("\t|#|_/                            \\_|#|\n");
    printf("\t|$| %s |$|\n",messageCentre[0]);
    printf("\t|#| %s |#|\n",messageCentre[1]);
    printf("\t|$| %s |$|\n",messageCentre[2]);
    printf("\t|#| %s |#|\n",messageCentre[3]);
    printf("\t|$| %s |$|\n",messageCentre[4]);
    printf("\t|#| %s |#|\n",messageCentre[5]);
    printf("\t|$| %s |$|\n",messageCentre[6]);
    printf("\t|#| %s |#|\n",messageCentre[7]);
    printf("\t|$| %s |$|\n",messageCentre[8]);
    printf("\t|$| %s |$|\n",messageCentre[9]);
    printf("\t|#| %s |#|\n",messageCentre[10]);
    printf("\t|$| %s |$|\n",messageCentre[11]);
    printf("\t|#| %s |#|\n",messageCentre[12]);
    printf("\t|$| %s |$|\n",messageCentre[13]);
    printf("\t|#| %s |#|\n",messageCentre[14]);
    printf("\t|$| %s |$|\n",messageCentre[15]);
    printf("\t|#| %s |#|\n",messageCentre[16]);
    printf("\t|$| %s |$|\n",messageCentre[17]);
    printf("\t|#| %s |#|\n",messageCentre[18]);
    printf("\t|$|<__>~?#?~?#?~?#~~#?~?#?~?#?~<__>|$|\n");
    printf("\t|\\¤?#?#?}}=======----======={{?#?#?¤/|\n");
    printf("\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

Contrat proposeContratUtilisateur(Contrat dernierContrat, Joueur parle, Carte *pCarteMain)
{
    Contrat nouveauContrat;
    setContrat(&nouveauContrat, parle, 0, SANS_COULEUR, NORMAL);
    afficheMain(pCarteMain);
    int miniContrat = 80;
    if (dernierContrat.nbPoint >= 80){
        miniContrat = dernierContrat.nbPoint +10;
    }
    char message[TAILLE_MAXI_MESSAGE];
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
            afficheMain(pCarteMain);
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
            sprintf(message, "\nA combien de points voulez vous encherir (entre %d et 160) \nEntrer 170 pour un caopot et 180 pour une generale:", miniContrat);
            setContrat(&nouveauContrat, parle,10* (acquisitionEntierSansMessageAvecConsigne(miniContrat, 180, message)/10),atoutEnchere,NORMAL);
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

        return nouveauContrat;


}
