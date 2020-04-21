#include "main.h"

int afficheMenuPrincipal()
{
    printf("	 ______________________\n	|%c}##{____________}##{%c|\n	|$|<>~#~#~#~~#~#~#~<>|$|\n	|#|><><><></%c><><><><|#|\n	|$|<><><></  %c><><><>|$|\n	|#|><><></    %c><><><|#|\n	|$|<><></      %c><><>|$|\n	|#|><></        %c><><|#|\n	|$|<></  Belote  %c><>|$|\n	|$|<><%c COINCH%cE /><>|$|\n	|#|><><%c        /><><|#|\n	|$|<><><%c      /><><>|$|\n	|#|><><><%c    /><><><|#|\n	|$|<><><><%c  /><><><>|$|\n	|#|><><><><%c/><><><><|#|\n	|$|<>~#~#~#~~#~#~#~<>|$|\n	|%c?#?}============{?#?%c|\n	!!!!!!!!!!!!!!!!!!!!!!!!\n\nappuyez sur n'importe quelle touche pour commencer\n",245,245,92,92,92,92,92,92,92,144,92,92,92,92,92,245,245);
    getch();
    system("cls");

    printf("	 ______________________\n	|%c}##{____________}##{%c|\n	|$|<>Menu Principal<>|$|\n	|#|                  |#|\n	|$| 1-nouvelle partie|$|\n	|#|                  |#|\n	|$| 2-leaderboard    |$|\n	|#|                  |#|\n	|$| 3-statistiques   |$|\n	|$|                  |$|\n	|#| 4-changement     |#|\n	|$|   d%cutilisateur  |$|\n	|#| 5-param%ctres     |#|\n	|$|                  |$|\n	|#| 6-quitter        |#|\n	|$|<>~#~#~~#~#~#~#~<>|$|\n	|%c?#?}============{?#?%c|\n	!!!!!!!!!!!!!!!!!!!!!!!!\n",245,245,39,138,245,245);

    return acquisitionEntierSansMessageAvecConsigne(1,6,"Choisisez une action :");
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





