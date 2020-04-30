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
 * \return void
 *
 */
void menuPrincipal ();

/** \brief lancement d'une nouvel partie
 *
 * \param char *pseudo[] : tableau de pointeur contenant les pseudo des diff�rent joueurs
 * \return void
 *
 */
void nouvellePartie(char *pseudo[]);


/** \brief lancement d'une manche
 *
 * \param char *pseudo[] : tableau de pointeur contenant les pseudo des diff�rent joueurs
 * \param int score[] : tableau contenant les scores des joueur
 * \param Joueur dealer : joueur qui distibue les cartes
 * \return void
 *
 */

void manche(char *pseudo[], int score[], Joueur dealer);

/** \brief gere l'anoce et la surench�re des contat par les joueur
 *
 * \param char *pseudo[]: tableau de pointeur contenant les pseudo des diff�rents joueurs
 * \param Joueur dealer : joueur qui distibue les cartes
 * \return Contrat : contrat final qui a ete choisi pour la partie
 *
 */

Contrat annonceContrat(char *pseudo[], Joueur dealer);

/** \brief proposistion d'un contrat par un joueur
 *
 * \param Contrat dernierContrat : dernier contrat propos�
 * \param Joueur parle : joueur qui parle
 * \param char *pseudo[]: tableau de pointeur contenant les pseudo des diff�rents joueurs
 * \return Contrat : nouveau contrat propos� par le joueur
 *
 */
 Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[]);



#endif // _GENERAL_H_
