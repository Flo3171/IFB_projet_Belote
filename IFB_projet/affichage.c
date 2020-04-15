#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include "acquisition.h"

int affichMenuPrinc()
{
    printf("	 ______________________\n	|%c}##{____________}##{%c|\n	|$|<>~#~#~#~~#~#~#~<>|$|\n	|#|><><><></%c><><><><|#|\n	|$|<><><></  %c><><><>|$|\n	|#|><><></    %c><><><|#|\n	|$|<><></      %c><><>|$|\n	|#|><></        %c><><|#|\n	|$|<></  Belote  %c><>|$|\n	|$|<><%c COINCH%cE /><>|$|\n	|#|><><%c        /><><|#|\n	|$|<><><%c      /><><>|$|\n	|#|><><><%c    /><><><|#|\n	|$|<><><><%c  /><><><>|$|\n	|#|><><><><%c/><><><><|#|\n	|$|<>~#~#~#~~#~#~#~<>|$|\n	|%c?#?}============{?#?%c|\n	!!!!!!!!!!!!!!!!!!!!!!!!\n\nappuyez sur n'importe quelle touche pour commencer\n",245,245,92,92,92,92,92,92,92,144,92,92,92,92,92,245,245);
    getch();
    system("cls");

    printf("	 ______________________\n	|%c}##{____________}##{%c|\n	|$|<>Menu Principal<>|$|\n	|#|                  |#|\n	|$| 1-nouvelle partie|$|\n	|#|                  |#|\n	|$| 2-leaderboard    |$|\n	|#|                  |#|\n	|$| 3-statistiques   |$|\n	|$|                  |$|\n	|#| 4-changement     |#|\n	|$|   d%cutilisateur  |$|\n	|#| 5-param%ctres     |#|\n	|$|                  |$|\n	|#| 6-quitter        |#|\n	|$|<>~#~#~~#~#~#~#~<>|$|\n	|%c?#?}============{?#?%c|\n	!!!!!!!!!!!!!!!!!!!!!!!!\n",245,245,39,138,245,245);

    return acquisitionEntierSansMessageAvecConsigne(1,6,"         que voulez vous faire ?");
}

