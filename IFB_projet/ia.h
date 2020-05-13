#ifndef _IA_H_
#define _IA_H_

/** \brief proposition par l'ia d'un contrat
 *
 * \param Joueur parle : joueur qui parle
 * \param Carte *pCarteMain pointeur sur le tableau qui contient les cartes du joueur
 * \param Contrat dernierContrat : dernier contrat qui a été proposé
 * \return Contrat
 *
 */

Contrat proposeContratIa(Joueur parle, Carte *pCarteMain, Contrat dernierContrat);

#endif // _IA_H_
