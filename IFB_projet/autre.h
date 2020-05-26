#ifndef _AUTRE_H_
#define _AUTRE_H_

/** \brief passe au joueur suivant
 *
 * \param Joueur joueur : joueur actuel
 * \return Joueur : le joueur suivant
 *
 */
Joueur joueurSuivant(Joueur joueur);

/** \brief renvoit in nombre aléatoire entre deux bornes
 *
 * \param int mini : borne inférieur
 * \param int maxi : borne surpérieur
 * \return int : le nombre aléatoire
 *
 */
int nbAleatoire(int mini, int maxi);

/** \brief définit un contrat
 *
 * \param Contat *contrat : pointeur sur le contrat a modifier
 * \param Joueur preneur : preneur du contrat
 * \param int nbPoint : nombre de point
 * \param Couleur atout : couleur de l'aout
 * \param Coinche coinche : normal, coinché , surcoinché
 * \return void
 *
 */
void setContrat(Contrat *contrat, Joueur preneur, int nbPoint,Couleur atout, Coinche coinche);

/** \brief compte le nombre de points d'un pli
 *
 * \param Carte pli []: tableau des cartes possées dont on doit faire la somme des points
 * \param Couleur atout: couleur de l'atout joué dans la manche
 * \param nbCarte: nombre de carte à compter
 * \return points
 *
 */
int pointPli(Carte pli[], Couleur atout, int nbCarte);



#endif // _AUTRE_H_
