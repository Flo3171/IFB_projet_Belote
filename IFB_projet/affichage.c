#include "main.h"

int afficheMenuPrincipal(int type)
{
    if (type == 0){
        system("cls");

        printf("\t\t ______________________\n");
        printf("\t\t|¤}##{____________}##{¤|\n");
        printf("\t\t|$|<>~#~#~#~~#~#~#~<>|$|\n");
        printf("\t\t|#|><><><></\\><><><><|#|\n");
        printf("\t\t|$|<><><></  \\><><><>|$|\n");
        printf("\t\t|#|><><></    \\><><><|#|\n");
        printf("\t\t|$|<><></      \\><><>|$|\n");
        printf("\t\t|#|><></        \\><><|#|\n");
        printf("\t\t|$|<></  Belote  \\><>|$|\n");
        printf("\t\t|$|<><\\ COINCHÉE /><>|$|\n");
        printf("\t\t|#|><><\\        /><><|#|\n");
        printf("\t\t|$|<><><\\      /><><>|$|\n");
        printf("\t\t|#|><><><\\    /><><><|#|\n");
        printf("\t\t|$|<><><><\\  /><><><>|$|\n");
        printf("\t\t|#|><><><><\\/><><><><|#|\n");
        printf("\t\t|$|<>~#~#~#~~#~#~#~<>|$|\n");
        printf("\t\t|¤?#?}============{?#?¤|\n");
        printf("\t\t!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
        printf("\t\t appuyez pour continuer");

        getch();
        return 0;
    }

    if (type == 1){
        system("cls");
        printf("\t\t ______________________ \n");
        printf("\t\t|¤}##{____________}##{¤|\n");
        printf("\t\t|$|<>Menu Principal<>|$|\n");
        printf("\t\t|#|                  |#|\n");
        printf("\t\t|$| 1-nouvelle partie|$|\n");
        printf("\t\t|#|                  |#|\n");
        printf("\t\t|$| 2-leaderboard    |$|\n");
        printf("\t\t|#|                  |#|\n");
        printf("\t\t|$| 3-statistiques   |$|\n");
        printf("\t\t|$|                  |$|\n");
        printf("\t\t|#| 4-changement     |#|\n");
        printf("\t\t|$|   d'utilisateur  |$|\n");
        printf("\t\t|#| 5-paramètres     |#|\n");
        printf("\t\t|$|                  |$|\n");
        printf("\t\t|#| 6-quitter        |#|\n");
        printf("\t\t|$|<>~#~#~~#~#~#~#~<>|$|\n");
        printf("\t\t|¤?#?}============{?#?¤|\n");
        printf("\t\t!!!!!!!!!!!!!!!!!!!!!!!!\n");

        int retour = acquisitionEntierSansMessageAvecConsigne(1,6,"Choisisez une action :");
        return retour;
    }
}


int afficheInterfacePli(Carte dernierPli[], Carte pli[], char *pseudo[], Carte cartesEnMain[], Contrat contratActuel, char message[], Joueur dernierVainqueur)
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

    int retour = 0;




    system("cls");
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
    printf("|					 _______					 |\n");
    printf("|					|%s|					 |\n", pliFormate[2][1]);
    printf("|					|	|					 |\n");
    printf("|					|%s|					 |\n", pliFormate[2][0]);
    printf("|					|_______|					 |\n");
    printf("|					   						 |\n");
    printf("|		                   %s            	           	 |\n", pseudoCentre[2]);
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
    printf("|	|________________________________________________________________________|	 |\n");
    printf("|________________________________________________________________________________________|\n");


    retour  = acquisitionEntierSansMessageAvecConsigne(1, 8, "Quelle carte voulez vous jouer :");
    return retour;
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

