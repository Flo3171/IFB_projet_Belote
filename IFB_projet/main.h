/*on regroupe dans ce ficher les include des bibliothèque et la declaration des constante*/

#ifndef _MAIN_H_
#define _MAIN_H_

/* Constante */
#define TAILLE_MAXI_PESEUDO 20
#define TAILLE_MAXI_COULEUR 8
#define NB_JOUEUR 4
#define TAILLE_MAXI_MESSAGE 500
#define NB_TOATAL_CARTE 32
#define NIVEAU_IA 2
#define NB_CARRACTERE_SCORE 33
#define POSITION_NB_VICTOIRE 21
#define POSITION_SCORE_MAX 25
#define POSITION_NB_MANCHES_POUR_GAGNER 30
#define DEBUG_MODE 0 /**< 0 pour le mode normal, 1 pour le mode débug */

/* Structure */

typedef enum Couleur
{
    SANS_COULEUR = 0,
    COEUR        = 1,
    PIQUE        = 2,
    CARREAU      = 3,
    TREFLE       = 4,
    TOUT_ATOUT   = 5,
    SANS_ATOUT   = 6

}Couleur;

typedef enum Valeur
{
    SANS_VALEUR = 0,
    AS          = 1,
    VALET       = 11,
    DAME        = 12,
    ROI         = 13,
    SEPT        = 7,
    HUIT        = 8,
    NEUF        = 9,
    DIX         = 10
}Valeur;

typedef enum Joueur
{
    SANS_JOUEUR = 0,
    NORD        = 1,
    EST         = 2,
    SUD         = 3,
    OUEST       = 4
}Joueur;

typedef enum Coinche
{
    NORMAL     = 0,
    COINCHE    = 1,
    SURCOINCHE = 2
}Coinche;

typedef enum NbPoint
{
    ZERO = 0,
    QUATRE_VINGT = 80,
    QUATRE_VINGT_DIX = 90,
    CENT = 100,
    CENT_DIX = 110,
    CENT_VINGT = 120,
    CENT_TRENTE = 130,
    CENT_QUARANTE = 140,
    CENT_CINQUANTE = 150,
    CAPOT = 160,
    GENERALE = 170
}NbPoint;

typedef struct Carte
{
    Couleur couleur;
    Valeur valeur;
}Carte;

typedef struct Contrat
{
    Joueur preneur;
    NbPoint nbPoint;
    Couleur atout;
    Coinche coinche;

}Contrat;

typedef enum TypeMessage
{
    SANS_MESSAGE,
    POSE_CARTE,
    RESULTAT_PLI,
    RESULTAT_MANCHE,
    RESULTAT_PARTIE,
    PROPOSE_CONTRAT,
    CONTRAT_FINAL

}TypeMessage;

/* Fontions standard*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>

/* Fontions créée dans le cardre du projet */
#include "tableau.h"
#include "acquisition.h"
#include "affichage.h"
#include "gestionCarte.h"
#include "general.h"
#include "formatageChaine.h"
#include "autre.h"
#include "ia.h"
#include "sous-menus.h"
#include "gestionFichier.h"





#endif // _MAIN_H_


