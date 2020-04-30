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



#endif // _GESTION_CARTE_H_
