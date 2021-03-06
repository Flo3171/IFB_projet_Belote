#ifndef _GESTION_CARTE_H_
#define _GESTION_CARTE_H_


/**
 * \file gestionCarte.h
 * \brief ficher header contenant les protypes des fonctions relative a la gestion des cartes
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/


/**
 * \brief distribue les cartes entre les diff�rent joueur
 * \fn void distribueCarte(Carte *pCarteMain)
 *
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main de chaque joueur
 * \param
 * \return void
 *
 */
void distribueCarte(Carte *pCarteMain);

/**
 * \brief donne une valeur et une couleur a une carte
 * \fn void setCarte(Carte *carte, Valeur valeurCarte, Couleur couleurCarte)
 *
 * \param Carte *carte : pointeur sur la carte a modifier
 * \param Valeur valeurCarte : valeur a donner a la carte
 * \param Couleur couleurCarte : couleur a donner a la carte
 * \return void
 *
 */
void setCarte(Carte *carte, Valeur valeurCarte, Couleur couleurCarte);

/**
 * \brief supprime une carte d'un tableau et r�duit la taille de ce tableu par le bas
 * \fn void supprimeCarte(Carte carte[], int nbCarte, int carteASupprimer)
 *
 * \param Carte carte[] : tableau conteneant les carte a modifier
 * \param int nbCarte : nombre total de carte
 * \param int carteASupprimer : indice dans le tableau de la carte a enlever
 * \return void
 *
 */
void supprimeCarte(Carte carte[], int nbCarte, int carteASupprimer);

/**
 * \brief donne le vainquer d'un pli
 * \fn Joueur vainqueurPli(Carte pli[], Couleur atout, Joueur premierAJouer)
 *
 * \param Carte pli[] : tableau contenant les carte du pli
 * \param Couleur atout : couleur de l'atout durant cette manche
 * \param Joueur premierAJouer : joueur qui pose la premi�re carte du pli
 * \return Joueur : le jouer qui a gagn� le pli
 *
 */

Joueur vainqueurPli(Carte pli[], Couleur atout, Joueur premierAJouer);

/**
 * \brief calcul la force d'une carte, en faisant la probabilit�e qu'elle a de gagn� contre toutes les autres cartes
 * \fn float forceCarte(Carte carteACalculer, Couleur atout, Couleur entame)
 *
 * \param Carte carteACalculer : carte dont on veut connaitre la force
 * \param Couleur atout : couleur de l'atout durant la partie
 * \param Couleur entame : couleur de l'entame durant la partie
 * \return float : probabilit�e de victoir de la carte
 *
 */

float forceCarte(Carte carteACalculer, Couleur atout, Couleur entame);


/**
 * \brief dd�termine si une carte peut etre pos� par un joueur
 * \fn char carteValide(Carte cartePose, Carte pli[], Couleur atout, Carte *pCarteMainJoueur, Joueur premierAJouer, Joueur parle)
 *
 * \param Carte cartPose : carte que l'on veut poser
 * \param Carte pli[] : tableau contenet les carte du pli
 * \param Couleur atout : couleur de l'atout
 * \param Carte *pCarteMainJoueur pointeur sur un tableau de 8 carte contenent les cartes dans la main du joueur
 * \param Joueur premierAJouer : premier joueur a jouer dans le pli
 * \param Joueur parle : joueur en train de jouer
 * \return char 1 si la carte est valide 0 sinon
 *
 */

char carteValide(Carte cartePose, Carte pli[], Couleur atout, Carte *pCarteMainJoueur, Joueur premierAJouer, Joueur parle);

/**
 * \brief cherche dans un tableau de carte si il y a une certaine couleur ou une certaine valeur ou les deux
 * \fn char rechercherCarte(Carte *pCarte, int nbCarte, Couleur couleurCherche, Valeur valeurCherche)
 *
 * \param Carte *pCarte : pointeur sur un tableau de carte
 * \param int nbCarte : nombre de carte dans le tableau
 * \param Couleur couleurCherche : couleur que l'on veut chercher dans le tableau (mettre SANS_COULEUR pour rechercher toutes les couleur)
 * \param Valeur valeurCherche : valeur que l'on cherche dans le tableau (mettre SANS_VALEUR pour chercher toutes les valeur
 * \return char 1 si on a trouv� une carte qui correspond au crit�re 0 sinon
 *
 */

char rechercherCarte(Carte *pCarte, int nbCarte, Couleur couleurCherche, Valeur valeurCherche);

/**
 * \brief cherche dans un tableau de carte si il y a une carte d'une force supp�rieur a carteCherche
 * \fn char rechercherCarteSuperieur(Carte *pCarte, int nbCarte, Carte carteCherche, Couleur atout, Couleur entame)
 *
 * \param Carte *pCarte : pointeur sur un tableau de carte
 * \param int nbCarte : nombre de carte dans le tableau
 * \param Carte carteCherche : carte a laquele on veut que la carte cherch�e soit sup�rieur
 * \param Couleur atout : couleur de l'atout dans la manche
 * \param Couleur entame : couleur de l'entame dans la manche
 * \return char 1 si on a trouv� une carte qui correspond au crit�re 0 sinon
 *
 */

char rechercherCarteSuperieur(Carte *pCarte, int nbCarte, Carte carteCherche, Couleur atout, Couleur entame);


/**
 * \brief calucule la somme force des carte dans un tableau
 * \fn float sommeForceCarte(Carte *tableauCarte, int nbCarte, Couleur atout)
 *
 * \param Carte tableauCarte : tableau de carte sur lequel on veut travailler
 * \param int nbCarte : nombre de carte dans le tableau
 * \param Couleur atout : couleur de l'atout sur la manche
 * \return float : la valeur de lla somme des force des carte
 *
 */

 float sommeForceCarte(Carte *tableauCarte, int nbCarte, Couleur atout);

/**
 * \brief trie un tableau de cartes
 * \fn void trieCarte(Carte tableauCarte[], int nbCarte, Couleur atout)
 *
 * \param Carte tableauCarte[] : tableau contenant les cartes a trier
 * \param int nbCarte nombre de carte dans le tableau
 * \param Couleur atout : couleur de l'atout dans la manche
 * \return void
 *
 */

 void trieCarte(Carte tableauCarte[], int nbCarte, Couleur atout);

 /**
  * \brief permet de savoir si une carte doit etre plac�e avant lors du trie des cartes
  * \fn char cartePlaceAvant(Carte carteRefference, Carte carteCompare, Couleur atout)
  *
  * \param Carte carteRefference : carte par raport a laquelle on compare
  * \param Carte carteCompare : carte que l'on compare
  * \param Couleur atout : couleur de l'atout dans la manche
  * \return char : renvoie 1 si la catre doit etre plac�e avant 0 sinon
  *
  */

char cartePlaceAvant(Carte carteRefference, Carte carteCompare, Couleur atout);






/** \brief calucule la somme force des carte dans un tableau
 *
 * \param Carte tableauCarte : tableau de carte sur lequel on veut travailler
 * \param int nbCarte : nombre de carte dans le tableau
 * \param Couleur atout : couleur de l'atout sur la manche
 * \return float : la valeur de lla somme des force des carte
 *
 */

 float sommeForceCarte(Carte *tableauCarte, int nbCarte, Couleur atout);

/** \brief trie un tableau de cartes
 *
 * \param Carte tableauCarte[] : tableau contenant les cartes a trier
 * \param int nbCarte nombre de carte dans le tableau
 * \param Couleur atout : couleur de l'atout dans la manche
 * \return void
 *
 */

 void trieCarte(Carte tableauCarte[], int nbCarte, Couleur atout);



 /** \brief rechere dans un tableau de cartes qui correspond a la main d'un joureur si il peut faire des anonc, et si oui ajoute les points assacier au tableau dans le tableau des anonce
 *
 * \param Carte *pCarteMain : pointeur sur le premier �l�ment du tableau qui cintient les cartes de tout les joueur
 * \param int pointAnonce[] : tableau contenant les point d'anonce
 * \param Joueur utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \param char *pseudo[] : tableau contenant les pseudo des 4 joueur
 * \return void
 *
 */
void rechercheAnnonce(Carte *pCarteMain, int pointAnonce[], Joueur utilisateur, char *pseudo[]);



#endif // _GESTION_CARTE_H_
