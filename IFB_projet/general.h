#ifndef _GENERAL_H_
#define _GENERAL_H_

/** \brief fonction qui ger�re l'initialitation et le lancement du programe
 *
 * \param nbLigneFenetre : taille vertical de la fenetre
 * \param nbColloneFenetre : taille horizonotal de la fenetre
 * \return void
 *
 */
void initialisation(int nbLigneFenetre, int nbColloneFenetre);

/** \brief fonction qui g�re le debut de la partie
 *
 * \param *pseudo[] : tableau de pointeurs qui renvoie vers le nom des diff�rents joueurs
 *
 * \return void
 *
 */
void debutDePartie(char *pseudo[]);



#endif // _GENERAL_H_
