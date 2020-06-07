#ifndef _SOUS_MENUS_H_
#define _SOUS_MENUS_H_

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void parametre(char *pseudo[]);

/** \brief fonction qui recup�re les meilleurs score dans un ficher et les affiche dans la console
 *
 * \param pointeur vers le fichier � lire
 * \return 0
 *
 */
 int leaderboard(FILE *fichier);

 /** \brief fonction qui recup�re les statistiques du joueur et les affiches dans la console
  *
  * \param pointeur vers le fichier de sauvegarde des scores
  * \param numero de la ligne � laquelle sont ecrites les statistiques du joueur
  * \return 0
  *
  */

int statistiqueJoueur(FILE *fichier,int ligne);

#endif
