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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

Joueur vainqueurPli(int couleur, int valeur);

/** \brief ddétermine si une carte peut etre posé par un joueur
 *
 * \param Carte cartPose : carte que l'on veut poser
 * \param Carte pli[] : tableau contenet les carte du pli
 * \param Couleur atout : couleur de l'atout
 * \param Carte *pCarteMainJoueur pointeur sur un tableau de 8 carte contenent les cartes dans la main du joueur
 * \param Joueur premierAJouer : premeier joueur a jouer dans le pli
 * \return char 1 si la carte est valide 0 sinon
 *
 */

char carteValide(Carte cartePose, Carte pli[], Couleur atout, Carte *pCarteMainJoueur, Joueur premierAJouer);

/** \brief cherche dans un tableau de carte si il y a une certaine couleur ou une certaine valeur ou les deux
 *
 * \param Carte *pCarte : pointeur sur un tableau de carte
 * \param int nbCarte : nombre de carte dans le tableau
 * \param Couleur couleurCherche : couleur que l'on veut chercher dans le tableau (mettre SANS_COULEUR pour rechercher toutes les couleur)
 * \param Valeur valeurCherche : valeur que l'on cherche dans le tableau (mettre SANS_VALEUR pour chercher toutes les valeur
 * \param int version : 1 pour la version ou la recherche de la valeur est strictement égale et 2 pour la version ou on recherche des carte de valeur supérieur
 * \return char 1 si on a trouvé une carte qui correspond au critère 0 sinon
 *
 */

char rechercherCarte(Carte *pCarte, int nbCarte, Couleur couleurCherche, Valeur valeurCherche, int version);




#endif // _GESTION_CARTE_H_
