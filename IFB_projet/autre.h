#ifndef _AUTRE_H_
#define _AUTRE_H_


/**
 * \file autre.h
 * \brief ficher header contenant les prototype des fonctions qui n'allait dans aucun autre fichier
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/


/** \brief passe au joueur suivant
 * \fn Joueur joueurSuivant(Joueur joueur)
 *
 * \param Joueur joueur : joueur actuel
 * \return Joueur : le joueur suivant
 *
 */
Joueur joueurSuivant(Joueur joueur);

/**
 * \brief renvoit in nombre al�atoire entre deux bornes
 * \fn int nbAleatoire(int mini, int maxi)
 *
 * \param int mini : borne inf�rieur
 * \param int maxi : borne surp�rieur
 * \return int : le nombre al�atoire
 *
 */
int nbAleatoire(int mini, int maxi);

/**
 * \brief d�finit un contrat
 * \fn void setContrat(Contrat *contrat, Joueur preneur, int nbPoint,Couleur atout, Coinche coinche)
 *
 * \param Contat *contrat : pointeur sur le contrat a modifier
 * \param Joueur preneur : preneur du contrat
 * \param int nbPoint : nombre de point
 * \param Couleur atout : couleur de l'aout
 * \param Coinche coinche : normal, coinch� , surcoinch�
 * \return void
 *
 */
void setContrat(Contrat *contrat, Joueur preneur, int nbPoint,Couleur atout, Coinche coinche);

/**
 * \brief compte le nombre de points d'un pli
 * \fn int pointPli(Carte pli[], Couleur atout, int nbCarte)
 *
 * \param Carte pli []: tableau des cartes poss�es dont on doit faire la somme des points
 * \param Couleur atout: couleur de l'atout jou� dans la manche
 * \param nbCarte: nombre de carte � compter
 * \return points
 *
 */
int pointPli(Carte pli[], Couleur atout, int nbCarte);

/**
 * \brief met a l'echelle la valeur d'une variable comprise entre deux bornes pour que la variable de retour soit compris entre deux autres bornes
 * \fn float ajusteEchelle(float valeur, float entreMin, float entreMax, float sortieMin, float sortieMax)
 *
 * \param float valeur : valeur a mettre � l'echelle
 * \param float entreMin : valeur minimum que peut prendre l'entr�e
 * \param float entreMax : valeur maximum que peut prendre l'entr�e
 * \param float sortieMin : valeur minimum que peut prendre la sortie
 * \param float sortieMax : valeur maximum que peut prendre la sortie
 * \return float : la valeur de valeur une fois mise a l'echelle
 *
 */

float ajusteEchelle(float valeur, float entreMin, float entreMax, float sortieMin, float sortieMax);


/**
 * \brief joue n partie aves uniquement des ia pour controler si tout ce passe bien et reuceillir des statistique
 * \fn void joue1000Partie(int nbPartie)
 *
 * \param int nbPartie nombre de partie que l'on veut jouer
 * \return voir
 *
 */

void joue1000Partie(int nbPartie);



#endif // _AUTRE_H_
