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
    printf("|************************************Belote coinchee************************************|\n");
    printf("| ______________________					 ______________________ |\n");
    printf("||Dernier pli :		|	      Antony Philipe		|Contrat :	       ||\n");
    printf("||	   10 Tr	|		 _______		| Antony Philipe       ||\n");
    printf("||  V Pi	  9 Co	|		|   V	|		| 80 point	       ||\n");
    printf("||	   R Ca		|		|	|		| Atout : Pique	       ||\n");
    printf("||Vainqueur : Tutu	|		| Pique	|		| Coinché	       ||\n");
    printf("||______________________|		|_______|		|______________________||\n");
    printf("|											|\n");
    printf("|	   Tutu								  Gilou		|\n");
    printf("|	 _______							 _______	|\n");
    printf("|	|  10	|							|   As	|	|\n");
    printf("|	|	|							|	|	|\n");
    printf("|	|Trephle|							|Carreau|	|\n");
    printf("|	|_______|							|_______|	|\n");
    printf("|											|\n");
    printf("|					 _______					|\n");
    printf("|					|   7	|					|\n");
    printf("|					|	|					|\n");
    printf("|					| Coeur	|					|\n");
    printf("|					|_______|					|\n");
    printf("|					   						|\n");
    printf("|					 Pseudo						|\n");
    printf("|											|\n");
    printf("|Votre main :										|\n");
    printf("|      _______    _______    _______    _______    _______    _______    _______	|\n");
    printf("|     |       |  |       |  |       |  |       |  |       |  |       |  |       |	|\n");
    printf("|     |       |  |       |  |       |  |       |  |       |  |       |  |       |	|\n");
    printf("|     |       |  |       |  |       |  |       |  |       |  |       |  |       |	|\n");
    printf("|     |_______|  |_______|  |_______|  |_______|  |_______|  |_______|  |_______|	|\n");
    printf("|											|\n");
    printf("|	 (1)        (2)        (3)        (4)        (5)        (6)        (7)		|\n");
    printf("|Quelle carte voulez vous jouer :							|\n");
    printf("|											|\n");
    printf("|	 _______________________________________________________________________	|\n");
    printf("|	|									|      	|\n");
    printf("|	|		       Antony Philipe remporte le pli 			|      	|\n");
    printf("|	|									|	|\n");
    printf("|	|_______________________________________________________________________|	|\n");
    printf("|_______________________________________________________________________________________|\n");

    return 0;
}



int centreChaine(char chaineInitial[], char chaineFinal[], int longeurChaine)
{
    if (strlen(chaineInitial) >= longeurChaine){
        for (int i = 0; i < longeurChaine; i++){
            chaineFinal[i] = chaineInitial[i];
        }
        chaineFinal[longeurChaine] = 0;
        return 1;
    }
    else{
        char devant[100], deriere[100];
        if ((longeurChaine - strlen(chaineInitial)) % 2 == 0){
            for (int i = 0; i < ((longeurChaine - strlen(chaineInitial)) / 2); i++){
                devant[i] = ' ';
                deriere[i] = ' ';
            }
            devant[((longeurChaine - strlen(chaineInitial)) / 2)] = 0;
            deriere[((longeurChaine - strlen(chaineInitial)) / 2)] = 0;

        }
        else{
            for (int i = 0; i < ((longeurChaine - strlen(chaineInitial)) / 2); i++){
                devant[i] = ' ';
            }
            for (int i = 0; i < ((longeurChaine - strlen(chaineInitial)) / 2)+1; i++){
                deriere[i] = ' ';
            }
            devant[((longeurChaine - strlen(chaineInitial)) / 2)] = 0;
            deriere[((longeurChaine - strlen(chaineInitial)) / 2)+1] = 0;
        }
        sprintf(chaineFinal,"%s%s%s", devant, chaineInitial, deriere);
        return 0;
    }

}

int centreModifieChaine(char chaine[], int longeurChaine)
{
    char* chaineCentre = (char*) malloc(sizeof(char)*(longeurChaine+1));
    centreChaine(chaine, chaineCentre, longeurChaine);
    sprintf(chaine, "%s", chaineCentre);

    free(chaineCentre);
    return 0;
}

