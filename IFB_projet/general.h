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
 * \param Joueur utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return Contrat : nouveau contrat propos� par le joueur
 *
 */
 Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[], Carte *pCarteMain, Joueur utilisateur);


 /** \brief fonction qui g�re un pli
  *
  * \param Contrat contrat : contrat qui a �t� choisipour cette manche
  * \param Joueur premierAjouer :  premier joueur a jouer dans le pli
  * \param char *pseudo[]: tableau de pointeur contenant les pseudo des diff�rents joueur
  * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main de chaque joueur
  * \param int pointManche[] : tableau contenant les point de chaque joueur dans la manche
  * \param int pointAnonce[] : tableau contenant les point d'anonce de chaque joueur
  * \param int pointBelote[] : tableau contenant les point de belote rebelote de chaque joueur
  * \param Carte cartePli[] : tableau contenant les 4 carte du pli
  * \param Carte carteAncienPli[] : tableau contenant les carte du pli pr�c�dent
  * \param Joueur utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
  * \return Joueur :  le vainceur du pli
  *
  */

Joueur pli(Contrat contrat, Joueur premierAJouer, char *pseudo[], Carte *pCarteMain, int pointManche[],int pointAnonce[],int pliBelote, Carte cartePli[], Carte carteAncienPli[], Joueur utilisateur, int numPli);

/** \brief fonction qui verifie la validit� d'une carte est la pose
 *
 * \param joueur: variable qui defini la position du joueur qui effectue l'action
 * \param numCarte: variable qui defini la carte choisie par le joueur
 * \param pMainJoueurs : pointeur qui renvoie vers le tableau de la main de tous les joueurs
 * \param pPli : pointeur qui renvoie vers le tableau des carte jou�es dans le pli
 * \return
 *
 */

int poseCarte (Joueur joueur, int numCarte, Carte *pMainJoueurs, Carte pli[], int carteRestante);

/** \brief compte les point gagn� par chaque joueur au cour de la manche e fonction du contrat et ajoute ces point au tableau qui contient tout les score de la partie
 *
 * \param Contrat contrat : contrat qui a �t� choisi durant la manche
 * \param int pointManche[] : tableau qui contient les points de la manche
 * \param int pointAnonce[] : tableau qui contient les points d'anonce de la manche
 * \param int pointBelote[] : tableau contenant les point de belote rebelote de chaque joueur
 * \param int score[] : tableau qui contient les score de la partie
 * \return char : 1 si le contrtat a �t� r�ussi et 0 si le contrat a �chou�
 *
 */

char calculPointManche(Contrat contrat, int pointManche[],int pointAnonce[],int pointBelote[], int score[]);


#endif // _GENERAL_H_
