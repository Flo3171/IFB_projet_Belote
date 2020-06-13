#include "main.h"

/**
 * \file main.c
 * \brief ficher contenant la fonction main
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/
int main(int argc, char *argv[])
{
    /**< CODE FINAL */
    srand(time(NULL));
    if(!DEBUG_MODE){
            initialisation(48, 90); /**< definit la taille de la fennetre a 50 lignes et 91 colones */
    }
    menuPrincipal();
    /**< FIN CODE FINAL */
    return 0;
}


