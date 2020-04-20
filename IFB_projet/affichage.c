#include "main.h"

int afficheMenuPrincipal()
{
    printf("	 ______________________\n	|%c}##{____________}##{%c|\n	|$|<>~#~#~#~~#~#~#~<>|$|\n	|#|><><><></%c><><><><|#|\n	|$|<><><></  %c><><><>|$|\n	|#|><><></    %c><><><|#|\n	|$|<><></      %c><><>|$|\n	|#|><></        %c><><|#|\n	|$|<></  Belote  %c><>|$|\n	|$|<><%c COINCH%cE /><>|$|\n	|#|><><%c        /><><|#|\n	|$|<><><%c      /><><>|$|\n	|#|><><><%c    /><><><|#|\n	|$|<><><><%c  /><><><>|$|\n	|#|><><><><%c/><><><><|#|\n	|$|<>~#~#~#~~#~#~#~<>|$|\n	|%c?#?}============{?#?%c|\n	!!!!!!!!!!!!!!!!!!!!!!!!\n\nappuyez sur n'importe quelle touche pour commencer\n",245,245,92,92,92,92,92,92,92,144,92,92,92,92,92,245,245);
    getch();
    system("cls");

    printf("	 ______________________\n	|%c}##{____________}##{%c|\n	|$|<>Menu Principal<>|$|\n	|#|                  |#|\n	|$| 1-nouvelle partie|$|\n	|#|                  |#|\n	|$| 2-leaderboard    |$|\n	|#|                  |#|\n	|$| 3-statistiques   |$|\n	|$|                  |$|\n	|#| 4-changement     |#|\n	|$|   d%cutilisateur  |$|\n	|#| 5-param%ctres     |#|\n	|$|                  |$|\n	|#| 6-quitter        |#|\n	|$|<>~#~#~~#~#~#~#~<>|$|\n	|%c?#?}============{?#?%c|\n	!!!!!!!!!!!!!!!!!!!!!!!!\n",245,245,39,138,245,245);

    return acquisitionEntierSansMessageAvecConsigne(1,6,"Choisisez une action :");
}

int afficheInterfacePli(Carte dernierPli[], Carte pli[], char *pseudo[], Carte cartesEnMain[], Contrat contratActuel, char message[])
{
    /**< Formatage des chaine de caracère relative aux pseudo */
    char pseudoCentre[4][TAILLE_MAXI_PESEUDO + 1];
    for (int i = 0; i < NB_JOUEUR; i++){
        centreChaine(pseudo[i], pseudoCentre[i], TAILLE_MAXI_PESEUDO);
    }

    /**< Formatage des chaine de caracère relative au message */
    char *messageCentre[3], messageCentre1[71], messageCentre2[71], messageCentre3[71];
    messageCentre[0] = &messageCentre1;
    messageCentre[1] = &messageCentre2;
    messageCentre[2] = &messageCentre3;
    decoupeChaine(message, messageCentre, 70, 3);

     /**< Formatage des chaine de caracère relative aux cartes */
     char pliFormate[8][20];
     formateCarte(pli, pliFormate, 4, 7, 1);





    system("cls");
    printf(" ________________________________________________________________________________________\n");
    printf("|************************************Belote coinchee*************************************|\n");
    printf("| ______________________					 _______________________ |\n");
    printf("||Dernier pli :		|	   %s 	|Contrat :	        ||\n", pseudoCentre[0]);
    printf("||	   10 Tr	|		 _______		| Antony Philipe        ||\n");
    printf("||  V Pi	  9 Co	|		|   V	|		| 80 point	        ||\n");
    printf("||	   R Ca		|		|	|		| Atout : Pique	        ||\n");
    printf("||Vainqueur : Tutu	|		| Pique	|		| Coinche	        ||\n");
    printf("||______________________|		|_______|		|_______________________||\n");
    printf("|											 |\n");
    printf("| %s 						   %s  |\n", pseudoCentre[3], pseudoCentre[1]);
    printf("|	 _______							 _______	 |\n");
    printf("|	|  10	|							|   As	|	 |\n");
    printf("|	|	|							|	|	 |\n");
    printf("|	|Trephle|							|Carreau|	 |\n");
    printf("|	|_______|							|_______|	 |\n");
    printf("|											 |\n");
    printf("|					 _______					 |\n");
    printf("|					|   7	|					 |\n");
    printf("|					|	|					 |\n");
    printf("|					| Coeur	|					 |\n");
    printf("|					|_______|					 |\n");
    printf("|					   						 |\n");
    printf("|		                   %s            	           	 |\n", pseudoCentre[2]);
    printf("|											 |\n");
    printf("|Votre main :										 |\n");
    printf("|  _______    _______    _______    _______    _______    _______    _______    _______  |\n");
    printf("| |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       | |\n");
    printf("| |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       | |\n");
    printf("| |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       | |\n");
    printf("| |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______| |\n");
    printf("|											 |\n");
    printf("|    (1)        (2)        (3)        (4)        (5)        (6)        (7)        (8)    |\n");
    printf("|Quelle carte voulez vous jouer :							 |\n");
    printf("|											 |\n");
    printf("|	 ________________________________________________________________________	 |\n");
    printf("|	| %s |       |\n", messageCentre[0]);
    printf("|	| %s |       |\n", messageCentre[1]);
    printf("|	| %s |       |\n", messageCentre[2]);
    printf("|	|________________________________________________________________________|	 |\n");
    printf("|________________________________________________________________________________________|\n");

    return 0;
}

void modifieTailleFenetre(int nbLigneFenetre, int nbColloneFentre)
{
    char comande[100];
    sprintf(comande, "mode con LINES=%d COLS=%d", nbLigneFenetre, nbColloneFentre);
    system(comande);

}





