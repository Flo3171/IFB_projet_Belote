#ifndef _GENERAL_H_
#define _GENERAL_H_

/** \brief fonction qui g�re l'initialitation et le lancement du programme
 *
 * \param nbLigneFenetre : taille verticale de la fen�tre
 * \param nbColloneFenetre : taille horizonotale de la fen�tre
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

/** \brief lancement d'une nouvelle partie
 *
 * \param char *pseudo[] : tableau de pointeurs contenant les pseudos des diff�rents joueurs
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return void
 *
 */
void nouvellePartie(char *pseudo[], Joueur utilisateur);


/** \brief lancement d'une manche
 *
 * \param char *pseudo[] : tableau de pointeurs contenant les pseudos des diff�rents joueurs
 * \param int score[] : tableau contenant les scores des joueur
 * \param Joueur dealer : joueur qui distibue les cartes
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return void
 *
 */

void manche(char *pseudo[], int score[], Joueur dealer, Joueur utilisateur);

/** \brief g�re l'annonce et la surench�re des contats par les joueurs
 *
 * \param char *pseudo[]: tableau de pointeurs contenant les pseudos des diff�rents joueurs
 * \param Joueur dealer : joueur qui distibue les cartes
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les cartes dans la main de chaque joueur
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return Contrat : contrat final qui a ete choisi pour la partie
 *
 */

Contrat annonceContrat(char *pseudo[], Joueur dealer, Carte *pCarteMain, Joueur utilisateur);

/** \brief proposition d'un contrat par un joueur
 *
 * \param Contrat dernierContrat : dernier contrat propos�
 * \param Joueur parle : joueur qui parle
 * \param char *pseudo[]: tableau de pointeurs contenant les pseudos des diff�rents joueurs
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les cartes dans la main de chaque joueurs
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return Contrat : nouveau contrat propos� par le joueur
 *
 */
 Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[], Carte *pCarteMain, Joueur utilisateur);


 /** \brief fonction qui g�re un pli
  *
  * \param Contrat contrat : contrat qui a �t� choisipour cette manche
  * \param Joueur parle : joueur qui parle (le premier a jouer)
  * \param char *pseudo[]: tableau de pointeur contenant les pseudo des diff�rents joueur
  * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main de chaque joueur
  * \param int pointManche [] : tableau contenant les point de chaque joueur dans la manche
  * \param Carte cartePli[] : tableau contenant les 4 carte du pli
  * \param Carte carteAncienPli[] : tableau contenant les carte du pli pr�c�dent
  * \param Joueur dernierVainceur : vainceur du dernnier pli
  * \return Joueur :  le vainceur du pli
  *
  */

Joueur pli(Contrat contrat, Joueur parle, char *pseudo[], Carte *pCarteMain, int pointManche[], Carte cartePli[], Carte carteAncienPli[], Joueur dernierVainceur, int numPli, Joueur utilisateur);

/** \brief fonction qui verifie la validit� d'une carte est la pose
 *
 * \param joueur: variable qui defini la position du joueur qui effectue l'action
 * \param numCarte: variable qui defini la carte choisie par le joueur
 * \param pMainJoueurs : pointeur qui renvoie vers le tableau de la main de tous les joueurs
 * \param pPli : pointeur qui renvoie vers le tableau des carte jou�es dans le pli
 * \return
 *
 */

<<<<<<< Updated upstream
int poseCarte (Joueur joueur, int numCarte, Carte *pMainJoueurs, Carte pli[], int cartePosee, int carteRestante);
=======
<<<<<<< HEAD
int poseCarte (Joueur joueur,int numCarte, Carte *pMainJoueurs, Carte pli[],int carteRestante);
=======
int poseCarte (Joueur joueur, int numCarte, Carte *pMainJoueurs, Carte pli[], int cartePosee, int carteRestante);
>>>>>>> 3ee8ff38cdce5d3080ca1eabf523ee8265217b1c
>>>>>>> Stashed changes

#endif // _GENERAL_H_
