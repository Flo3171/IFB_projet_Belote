#ifndef _GESTION_FICHIER_H_
#define _GESTION_FICHIER_H_

/** \brief fonction qui recherche dans un fichier si le joueur est deja enregistré au le rajoute à la fin si ce n'est pas le cas
 *
 * \param char *pPseudo: pointeur vers le nom du joueur
 * \param FILE *pFichier : pointeur vers le fichier contenant les statistiques
 * \return le numero de la ligne dans lequel est noté le pseudo
 *
 */

int ecriturePseudo (char *pPseudo,FILE *pFichier);

/** \brief modifie la valeur d'une statistique dans le fichier de sauvegarde des scores
 *
 * \param FILE *fichier : pointeur vers le fichier
 * \param int ligne : ligne du fichier à laquelle sont sauvegardée les statistiques du joueur
 * \param int statAModifier : la nouvelle statistique à enregistrer
 * \param int type : vaut 1 pour mdifier le nombre de victoires, vaut 2 pour changer le score max, vaut 3 pour changer le nombre de manche min pour une victoire
 * \return valeur enregistrée
 *
 */

int ecrireStatistique(FILE *fichier,int ligne, int statAModifier, int type);

/** \brief vérifie si un nouveau record à été battu et l'ajoute si c'est le cas
 *
 * \param FILE *fichier : pointeur vers fichier de meilleurs score
 * \param char *pPseudo : pointeur vers le pseudo du joueur
 * \param int score : score a éventuellement enregistrer
 * \return 0
 *
 */
int ecrireLeaderboard(FILE *fichier,char *pseudo,int score);

#endif // _GESTION_FICHIER_H_
