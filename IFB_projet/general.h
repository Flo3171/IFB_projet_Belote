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
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return void
 *
 */
void nouvellePartie(char *pseudo[], Joueur utilisateur);


/** \brief lancement d'une manche
 *
 * \param char *pseudo[] : tableau de pointeur contenant les pseudo des différent joueurs
 * \param int score[] : tableau contenant les scores des joueur
 * \param Joueur dealer : joueur qui distibue les cartes
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return void
 *
 */

void manche(char *pseudo[], int score[], Joueur dealer, Joueur utilisateur);

/** \brief gere l'anoce et la surenchère des contat par les joueur
 *
 * \param char *pseudo[]: tableau de pointeur contenant les pseudo des différents joueurs
 * \param Joueur dealer : joueur qui distibue les cartes
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main de chaque joueur
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return Contrat : contrat final qui a ete choisi pour la partie
 *
 */

Contrat annonceContrat(char *pseudo[], Joueur dealer, Carte *pCarteMain, Joueur utilisateur);

/** \brief proposistion d'un contrat par un joueur
 *
 * \param Contrat dernierContrat : dernier contrat proposé
 * \param Joueur parle : joueur qui parle
 * \param char *pseudo[]: tableau de pointeur contenant les pseudo des différents joueur
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main de chaque joueur
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return Contrat : nouveau contrat proposé par le joueur
 *
 */
 Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[], Carte *pCarteMain, Joueur utilisateur);


 /** \brief fonction qui gère un pli
  *
  * \param Contrat contrat : contrat qui a été choisipour cette manche
  * \param Joueur parle : joueur qui parle (le premier a jouer)
  * \param char *pseudo[]: tableau de pointeur contenant les pseudo des différents joueur
  * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main de chaque joueur
  * \param int pointManche [] : tableau contenant les point de chaque joueur dans la manche
  * \param Carte cartePli[] : tableau contenant les 4 carte du pli
  * \param Carte carteAncienPli[] : tableau contenant les carte du pli précédent
  * \param Joueur dernierVainceur : vainceur du dernnier pli
  * \return Joueur :  le vainceur du pli
  *
  */

Joueur pli(Contrat contrat, Joueur parle, char *pseudo[], Carte *pCarteMain, int pointManche[], Carte cartePli[], Carte carteAncienPli[], Joueur dernierVainceur, int numPli, Joueur utilisateur);

/** \brief fonction qui verifie la validité d'une carte est la pose
 *
 * \param joueur: variable qui defini la position du joueur qui effectue l'action
 * \param numCarte: variable qui defini la carte choisie par le joueur
 * \param pMainJoueurs : pointeur qui renvoie vers le tableau de la main de tous les joueurs
 * \param pPli : pointeur qui renvoie vers le tableau des carte jouées dans le pli
 * \return
 *
 */

int poseCarte (Joueur joueur, int numCarte, Carte *pMainJoueurs, Carte pli[], int cartePosee, int carteRestante);

#endif // _GENERAL_H_
