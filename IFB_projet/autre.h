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

/** \brief d�finin un contrat
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





#endif // _AUTRE_H_
