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
    system("cls");
    printf(" _______________________________________________________________________________________\n");
    printf("|************************************Belote coinchée************************************|\n");
    printf("| ______________________					 ______________________ |\n");
    printf("||Dernier pli :		|	      Antony Philipe		|Contrat :	       ||\n");
    printf("||	   10 Tr	|		 _______		| Antony Philipe       ||\n");
    printf("||  V Pi	  9 Co	|		|   V	|		| 80 point	       ||\n");
    printf("||	   R Ca		|		|	|		| Atout : Pique	       ||\n");
    printf("||Vainqueur : Tutu	|		| Pique	|		| Coinché	       ||\n");
    printf("||______________________|		|_______|		|______________________||\n");
    printf("|											|\n");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
}

