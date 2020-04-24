#ifndef _GENERAL_H_
#define _GENERAL_H_

/** \brief fonction qui gerère l'initialitation et le lancement du programe
 *
 * \param nbLigneFenetre : taille vertical de la fenetre
 * \param nbColloneFenetre : taille horizonotal de la fenetre
 * \return void
 *
 */
void initialisation(int nbLigneFenetre, int nbColloneFenetre);

/** \brief fonction qui gère le debut de la partie
 *
 * \return void
 *
 */
void menuPrincipal ();

/** \brief lancement d'une nouvel partie
 *
 * \param char *pseudo[] : tableau de pointeur contenant les pseudo des différent joueurs
 * \return void
 *
 */
void nouvellePartie(char *pseudo[]);


/** \brief lancement d'une manche
 *
 * \param char *pseudo[] : tableau de pointeur contenant les pseudo des différent joueurs
 * \param int score[] : tableau contenant les scores des joueur
 * \param Joueur dealer : joueur qui distibue les cartes
 * \return void
 *
 */

void manche(char *pseudo[], int score[], Joueur dealer);



#endif // _GENERAL_H_
