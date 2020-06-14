#ifndef _MAIN_H_
#define _MAIN_H_

/**
 * \file main.h
 * \brief ficher la déclaration des contrante, les énumérations, les structe et l'inclusion des haeder du projet
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/

/**< Constantes */
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
 * Pour simplifier, le tout atout et le sans atout sont considéré comme des couleurs
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

/**
 *\enum NnPoinr
 *\brief nombre de point possible pour un contrat
 *
 * pour simplifier, le capot et la général sont considéré comme un nombre de points
 *
 */

typedef enum NbPoint
{
    ZERO = 0, /*!Le contrat vaut zéro point, par défaut correspont a un joueur qui passe ou pour l'initiatilation */
    QUATRE_VINGT = 80,/*!Le contrat vaut 80 points */
    QUATRE_VINGT_DIX = 90,/*!Le contrat vaut 90 points */
    CENT = 100,/*!Le contrat vaut 100 points */
    CENT_DIX = 110,/*!Le contrat vaut 110 points */
    CENT_VINGT = 120,/*!Le contrat vaut 120 points */
    CENT_TRENTE = 130,/*!Le contrat vaut 130 points */
    CENT_QUARANTE = 140,/*!Le contrat vaut 140 points */
    CENT_CINQUANTE = 150,/*!Le contrat vaut 150 points */
    CENT_SOIXANTE = 160,/*!Le contrat vaut 160 points */
    CAPOT = 170,/*!Le contrat est un capot */
    GENERALE = 180/*!Le contrat est une générale */
}NbPoint;

/**
 * \struct Carte
 * \brief represente une carte d'un jeu de 32 cartes
 */

typedef struct Carte
{
    Couleur couleur;/*! type Couleur, donne la famille à laquel la carte apprartient */
    Valeur valeur; /*! type Valeur, donne la valeur de la carte */
}Carte;

/**
 * \struct Contrat
 * \brief represente un contrat à la belote coichée
 *
 * Permet d'avoir toutes les information concernant un contrat stocké dans une seuil et même variable
 *
 */


typedef struct Contrat
{
    Joueur preneur; /*! type Joueur, joueur qui a pris le contrat */
    NbPoint nbPoint;/*! type NbPoint, nombre de point du contrat */
    Couleur atout;/*! type Couleur, couleur de l'atout qui à été prise pour le contrat*/
    Coinche coinche;/*! type Coinche, deterine si le contrat été coinché ou surcoiché*/

}Contrat;

/**
 * \enum TypeMessage
 * \brief contante à passer en paramètre à la fonction génèreMessage() pour donner le type de message a générer
 *
 *
 */

typedef enum TypeMessage
{
    SANS_MESSAGE,/*! pas de message a afficher, par defaut*/
    POSE_CARTE,/*! lorsqu'un joueur vien de poser une carte*/
    RESULTAT_PLI,/*! anonce le vainceur d'un plis*/
    RESULTAT_MANCHE,/*! anonce le resultat d'une manche */

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


