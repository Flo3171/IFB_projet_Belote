#include "main.h"
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


