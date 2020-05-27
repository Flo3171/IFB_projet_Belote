#ifndef _GESTION_CARTE_H_
#define _GESTION_CARTE_H_
/* liste des fonction concerant la gestion des cartes */

/** \brief distribue les cartes entre les différent joueur
 *
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main de chaque joueur
 * \param
 * \return void
 *
 */
void distribueCarte(Carte *pCarteMain);

/** \brief donne une valeur et une couleur a une carte
 *
 * \param Carte *carte : pointeur sur la carte a modifier
 * \param Valeur valeurCarte : valeur a donner a la carte
 * \param Couleur couleurCarte : couleur a donner a la carte
 * \return void
 *
 */
void setCarte(Carte *carte, Valeur valeurCarte, Couleur couleurCarte);

/** \brief supprime une carte d'un tableau et réduit la taille de ce tableu par le bas
 *
 * \param Carte carte[] : tableau conteneant les carte a modifier
 * \param int nbCarte : nombre total de carte
 * \param int carteASupprimer : indice dans le tableau de la carte a enlever
 * \return void
 *
 */
void supprimeCarte(Carte carte[], int nbCarte, int carteASupprimer);

/** \brief donne le vainquer d'un pli
 *
 * \param Carte pli[] : tableau contenant les carte du pli
 * \param Couleur atout : couleur de l'atout durant cette manche
 * \param Joueur premierAJouer : joueur qui pose la première carte du pli
 * \return Joueur : le jouer qui a gagné le pli
 *
 */

Joueur vainqueurPli(Carte pli[], Couleur atout, Joueur premierAJouer);

/** \brief calcul la force d'une carte, en faisant la probabilitée qu'elle a de gagné contre toutes les autres cartes
 *
 * \param Carte carteACalculer : carte dont on veut connaitre la force
 * \param Couleur atout : couleur de l'atout durant la partie
 * \param Couleur entame : couleur de l'entame durant la partie
 * \return float : probabilitée de victoir de la carte
 *
 */

float forceCarte(Carte carteACalculer, Couleur atout, Couleur entame);


/** \brief ddétermine si une carte peut etre posé par un joueur
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

/** \brief cherche dans un tableau de carte si il y a une certaine couleur ou une certaine valeur ou les deux
 *
 * \param Carte *pCarte : pointeur sur un tableau de carte
 * \param int nbCarte : nombre de carte dans le tableau
 * \param Couleur couleurCherche : couleur que l'on veut chercher dans le tableau (mettre SANS_COULEUR pour rechercher toutes les couleur)
 * \param Valeur valeurCherche : valeur que l'on cherche dans le tableau (mettre SANS_VALEUR pour chercher toutes les valeur
 * \return char 1 si on a trouvé une carte qui correspond au critère 0 sinon
 *
 */

char rechercherCarte(Carte *pCarte, int nbCarte, Couleur couleurCherche, Valeur valeurCherche);

/** \brief cherche dans un tableau de carte si il y a une carte d'une force suppérieur a carteCherche
 *
 * \param Carte *pCarte : pointeur sur un tableau de carte
 * \param int nbCarte : nombre de carte dans le tableau
 * \param Carte carteCherche : carte a laquele on veut que la carte cherchée soit supérieur
 * \param Couleur atout : couleur de l'atout dans la manche
 * \param Couleur entame : couleur de l'entame dans la manche
 * \return char 1 si on a trouvé une carte qui correspond au critère 0 sinon
 *
 */

char rechercherCarteSuperieur(Carte *pCarte, int nbCarte, Carte carteCherche, Couleur atout, Couleur entame);


/** \brief calucule la somme force des carte dans un tableau
 *
 * \param Carte tableauCarte : tableau de carte sur lequel on veut travailler
 * \param int nbCarte : nombre de carte dans le tableau
 * \param Couleur atout : couleur de l'atout sur la manche
 * \return float : la valeur de lla somme des force des carte
 *
 */

 float sommeForceCarte(Carte *tableauCarte, int nbCarte, Couleur atout);





#endif // _GESTION_CARTE_H_
