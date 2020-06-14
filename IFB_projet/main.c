#include "main.h"

/**
 * \file main.c
 * \brief ficher contenant la fonction main
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/

/**
 * \fn int main(int argc, char *argv[])
 * \brief Entrée du programme
 * \author Florian.C
 *
 * \return EXIT_SUCCESS - Arrêt normal du programme
 */

        int main(int argc, char *argv[])
        {
        /**< CODE FINAL */
            srand(time(NULL));
            if(!DEBUG_MODE){
        /**< definit la taille de la fennetre a 50 lignes et 91 colones */
                    initialisation(48, 90);
            }
            menuPrincipal();
        /**< FIN CODE FINAL */
            return EXIT_SUCCESS;
        }


