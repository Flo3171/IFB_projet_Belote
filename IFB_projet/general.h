#ifndef _GENERAL_H_
#define _GENERAL_H_


/**
 * \file general.h
 * \brief ficher header contenant les prototypes des fonctions les plus impotantes pour le jeu de la belote
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/



/**
 * \brief fonction qui gère l'initialitation et le lancement du programme
 * \fn void initialisation(int nbLigneFenetre, int nbColloneFenetre)
 *
 * \param nbLigneFenetre : taille verticale de la fenêtre
 * \param nbColloneFenetre : taille horizonotale de la fenêtre
 * \return void
 *
 */
void initialisation(int nbLigneFenetre, int nbColloneFenetre);

/**
 * \brief fonction qui gère le debut de la partie
 * \fn void menuPrincipal ()
 *
 * \return void
 *
 */
void menuPrincipal ();

/**
 * \brief lancement d'une nouvelle partie
 * \fn int nouvellePartie(char *pseudo[], Joueur utilisateur, int *pStatistique, int infoEcritureFicher[])
 *
 * \param char *pseudo[] : tableau de pointeurs contenant les pseudos des différents joueurs
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \param int *pStatistique : pointeur sur un tableau 4*4 qui contient des statistique sur chaque joueur
 * \param int infoEcritureFichier[] : tableau contenant les info qui devront etre écrite dans le fichier
 * \return int : nombre de manche jusqu'a la victoir d'une équipe
 *
 */
int nouvellePartie(char *pseudo[], Joueur utilisateur, int *pStatistique, int infoEcritureFicher[]);


/**
 * \brief lancement d'une manche
 * \fn char manche(char *pseudo[], int score[], Joueur dealer, Joueur utilisateur, int *pStatistique)
 *
 * \param char *pseudo[] : tableau de pointeurs contenant les pseudos des différents joueurs
 * \param int score[] : tableau contenant les scores des joueur
 * \param Joueur dealer : joueur qui distibue les cartes
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \param int *pStatistique : pointeur sur un tableau 4*4 qui contient des statistique sur chaque joueur
 * \return char : 0 si tout le monde passe, 1 si la manche a bien lieu
 *
 */

char manche(char *pseudo[], int score[], Joueur dealer, Joueur utilisateur, int *pStatistique);


/**
 * \brief gère l'annonce et la surenchère des contats par les joueurs
 * \fn Contrat annonceContrat(char *pseudo[], Joueur dealer, Carte *pCarteMain, Joueur utilisateur)
 *
 * \param char *pseudo[]: tableau de pointeurs contenant les pseudos des différents joueurs
 * \param Joueur dealer : joueur qui distibue les cartes
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les cartes dans la main de chaque joueur
 * \param Joueuer utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return Contrat : contrat final qui a ete choisi pour la partie
 *
 */

Contrat annonceContrat(char *pseudo[], Joueur dealer, Carte *pCarteMain, Joueur utilisateur);

/**
 * \brief proposition d'un contrat par un joueur
 * \fn Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[], Carte *pCarteMain, Joueur utilisateur)
 *
 * \param Contrat dernierContrat : dernier contrat proposé
 * \param Joueur parle : joueur qui parle
 * \param char *pseudo[]: tableau de pointeurs contenant les pseudos des différents joueurs
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les cartes dans la main de chaque joueurs
 * \param Joueur utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return Contrat : nouveau contrat proposé par le joueur
 *
 */
 Contrat proposeContrat(Contrat dernierContrat, Joueur parle, char *pseudo[], Carte *pCarteMain, Joueur utilisateur);


/**
 * \brief fonction qui gère un pli
 * \fn Joueur pli(Contrat contrat, Joueur premierAJouer, char *pseudo[], Carte *pCarteMain, int pointManche[], int pointAnonce[], char belote[], Carte cartePli[], Carte carteAncienPli[], int score[], Joueur utilisateur, int numPli)
 *
 * \param Contrat contrat : contrat qui a été choisipour cette manche
 * \param Joueur premierAjouer :  premier joueur a jouer dans le pli
 * \param char *pseudo[]: tableau de pointeur contenant les pseudo des différents joueur
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main de chaque joueur
 * \param int pointManche[] : tableau contenant les point de chaque joueur dans la manche
 * \param int pointAnonce[] : tableau contenant les point d'anonce de chaque joueur
 * \param char belote[] : tableau contenant les ancone belote rebelote de chaque joueur
 * \param Carte cartePli[] : tableau contenant les 4 carte du pli
 * \param Carte carteAncienPli[] : tableau contenant les carte du pli précédent
 * \param int score[] : tableau qui contient les score de la partie
 * \param Joueur utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return Joueur :  le vainceur du pli
 *
 */

Joueur pli(Contrat contrat, Joueur premierAJouer, char *pseudo[], Carte *pCarteMain, int pointManche[], int pointAnonce[], char belote[], Carte cartePli[], Carte carteAncienPli[], int score[], Joueur utilisateur, int numPli);

/**
 * \brief fonction qui verifie la validité d'une carte est la pose
 * \fn int poseCarte (Joueur joueur, int numCarte, Carte *pMainJoueurs, Carte pli[], int carteRestante)
 *
 * \param joueur: variable qui defini la position du joueur qui effectue l'action
 * \param numCarte: variable qui defini la carte choisie par le joueur
 * \param pMainJoueurs : pointeur qui renvoie vers le tableau de la main de tous les joueurs
 * \param pPli : pointeur qui renvoie vers le tableau des carte jouées dans le pli
 * \return
 *
 */

int poseCarte (Joueur joueur, int numCarte, Carte *pMainJoueurs, Carte pli[], int carteRestante);

/**
 * \brief compte les point gagné par chaque joueur au cour de la manche e fonction du contrat et ajoute ces point au tableau qui contient tout les score de la partie
 * \fn char calculPointManche(Contrat contrat, int pointManche[],int pointAnonce[],int pointBelote[], int score[],char *pseudo[], Joueur utilisateur)
 *
 * \param Contrat contrat : contrat qui a été choisi durant la manche
 * \param int pointManche[] : tableau qui contient les points de la manche
 * \param int pointAnonce[] : tableau qui contient les points d'anonce de la manche
 * \param int pointBelote[] : tableau contenant les point de belote rebelote de chaque joueur
 * \param int score[] : tableau qui contient les score de la partie
 * \param char *pseudo[]: tableau de pointeur contenant les pseudo des différents joueur
 * \param Joueur utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \return char : 1 si le contrtat a été réussi et 0 si le contrat a échoué
 *
 */

char calculPointManche(Contrat contrat, int pointManche[],int pointAnonce[],int pointBelote[], int score[],char *pseudo[], Joueur utilisateur);


#endif // _GENERAL_H_
