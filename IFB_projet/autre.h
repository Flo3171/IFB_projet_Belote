#ifndef _AUTRE_H_
#define _AUTRE_H_

/** \brief passe au joueur suivant
 *
 * \param Joueur joueur : joueur actuel
 * \return Joueur : le joueur suivant
 *
 */
Joueur joueurSuivant(Joueur joueur);

/** \brief renvoit in nombre al�atoire entre deux bornes
 *
 * \param int mini : borne inf�rieur
 * \param int maxi : borne surp�rieur
 * \return int : le nombre al�atoire
 *
 */
int nbAleatoire(int mini, int maxi);

/** \brief d�finit un contrat
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

/** \brief compte le nombre de points d'un pli
 *
 * \param Carte pli []: tableau des cartes poss�es dont on doit faire la somme des points
 * \param Couleur atout: couleur de l'atout jou� dans la manche
 * \return points
 *
 */
int pointPli(Carte pli[], Couleur atout);

/** \brief met a l'echelle la valeur d'une variable comprise entre deux bornes pour que la variable de retour soit compris entre deux autres bornes
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



#endif // _AUTRE_H_
