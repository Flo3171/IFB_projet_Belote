/*on regroupe dans ce ficher les include des bibliothèque et la declaration des constante*/

#ifndef _MAIN_H_
#define _MAIN_H_

/* Constantes */
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
#define NB_CARRACTERE_LEADERBOARD 26
#define POSITION_RECORD_VICTOIRE 21
#define DEBUG_MODE 0 /**< 0 pour le mode normal, 1 pour le mode débug */
#define MODE_1_MANCHE 0 /**< 0 pour le mode normal, 1 pour le mode ou une partie est constitué d'une uique manche */

/**< Structure et énumérations */

/**
 *\enum Couleur
 *\brief Les différentes couleur d'atout possible a la belote coinchée
 *
 *toute les couleur disponible ainsi que tout atouts et sans atout
 *sert a la fois pour le type Carte et le type Contrat
 *
 */

typedef enum Couleur
{
    SANS_COULEUR = 0, /*!Couleur par défaut, pour une carte vide */
    COEUR        = 1, /*!Couleur coeur */
    PIQUE        = 2, /*!Couleur pique */
    CARREAU      = 3, /*!Couleur carreau */
    TREFLE       = 4, /*!Couleur trefle */
    TOUT_ATOUT   = 5, /*!Tout atout */
    SANS_ATOUT   = 6  /*!Sans atout */

}Couleur;

/**
 *\enum Valeur
 *\brief Les différentes valeur possible des cartes d'un jeu de 32 cartes
 *
 * Les valeurs associée on été placée de manière arbitraire et n'ont pas d'importance sur le programme
 *
 */

typedef enum Valeur
{
    SANS_VALEUR = 0,  /*!Valeur par défaut, pour une carte vide  */
    AS          = 1,  /*!Valeur As */
    VALET       = 11, /*!Valeur Valet */
    DAME        = 12, /*!Valeur Dame */
    ROI         = 13, /*!Valeur Roi */
    SEPT        = 7, /*!Valeur 7 */
    HUIT        = 8, /*!Valeur 8 */
    NEUF        = 9, /*!Valeur 9 */
    DIX         = 10 /*!Valeur 10 */
}Valeur;

/**
 *\enum Joueur
 *\brief Les différente joueur lors d'une partie
 *
 * Les joueur sont nomé par les different point cardinaut correspondant à leur placement sur la table
 *
 */

typedef enum Joueur
{
    SANS_JOUEUR = 0,/*!Joueur par défaut, quand il n'y a pas de joueur ou pour l'initialitation */
    NORD        = 1,/*!Joueur en haut */
    EST         = 2,/*!Joueur à gauche */
    SUD         = 3,/*!Joueur en bas */
    OUEST       = 4 /*!Joueur à droite */
}Joueur;

/**
 *\enum Coinche
 *\brief indique il un contrat est coinché ou surcoinché
 *
 *
 */

typedef enum Coinche
{
    NORMAL     = 0,/*!Le contrat n'est pas coiché, par défaut */
    COINCHE    = 1,/*!Le contrat est Coinché */
    SURCOINCHE = 2 /*!Le contrat est Surcoiché */
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

/**< Fontions standard*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>

/**< Fontions créée dans le cardre du projet */
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


