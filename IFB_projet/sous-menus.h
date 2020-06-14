#ifndef _SOUS_MENUS_H_
#define _SOUS_MENUS_H_

/**
 * \file sous-menue.h
 * \brief ficher header contenant les prototypes des fonctions des different sous menu disponible sur le menu principal
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/

/**
 * \brief affiche le sous menu des paramètre, permet de changer le psedo de tout les ordinateur
 * \fn void parametre(char *pseudo[])
 *
 * \param char *pseudo[] : tableau de pointeurs contenant les pseudos des différents joueurs
 * \return void
 *
 */
void parametre(char *pseudo[]);

/**
 * \brief fonction qui recupère les meilleurs score dans un ficher et les affiche dans la console
 * \fn int leaderboard(FILE *fichier)
 *
 * \param pointeur vers le fichier à lire
 * \return 0
 *
 */
 int leaderboard(FILE *fichier);

/**
 * \brief fonction qui recupère les statistiques du joueur et les affiches dans la console
 * \fn int statistiqueJoueur(FILE *fichier,int ligne)
 *
 * \param pointeur vers le fichier de sauvegarde des scores
 * \param numero de la ligne à laquelle sont ecrites les statistiques du joueur
 * \return 0
 *
 */

int statistiqueJoueur(FILE *fichier,int ligne);

#endif
