/*on regroupe dans ce ficher les include des bibliothèque et la declaration des constante*/

#ifndef _MAIN_H_
#define _MAIN_H_

/* Constante */
#define TAILLE_MAXI_PESEUDO 20
#define TAILLE_MAXI_COULEUR 8


/* Structure */
typedef struct Carte
{
    char couleur[15];
    char valeur[2];
}Carte;

typedef struct Contrat
{
    char preneur[TAILLE_MAXI_PESEUDO];
    int nbPoint;
    char atout[TAILLE_MAXI_COULEUR];
    char coinche[20];

}Contrat;

/* Fontions standard*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

/* Fontions créée dans le cardre du projet */
#include "tableau.h"
#include "acquisition.h"
#include "affichage.h"
#include "gestionCarte.h"






#endif // _MAIN_H_


