#ifndef _IA_H_
#define _IA_H_

/**
 * \file ia.h
 * \brief ficher header contenant les prototypes des fonctions relative au inteligences artificielles
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/


/**
 * \brief proposition par l'ia d'un contrat
 * \fn Contrat proposeContratIa(Joueur parle, Carte *pCarteMain, Contrat dernierContrat)
 *
 * \param Joueur parle : joueur qui parle
 * \param Carte *pCarteMain pointeur sur le tableau qui contient les cartes du joueur
 * \param Contrat dernierContrat : dernier contrat qui a été proposé
 * \return Contrat
 *
 */

Contrat proposeContratIa(Joueur parle, Carte *pCarteMain, Contrat dernierContrat);

/**
 * \brief proposition de la pose d'une carte  par l'IA
 * \fn int choixCarteIA(Joueur joueur, Carte *pMainJoueur, Carte pli[], Joueur dernierVainqueur, Couleur atout, int carteRestante)
 *
 * \param Joueur joueur : determine qu'elle IA doit jouer
 * \param Carte *pMainJoueur : pointeur vers le tableau qui enregistre la main de l'IA
 * \param Carte pli[] : tableau qui enregistre les cartes jouées pendant le pli
 * \param Joueur dernierVainqueur : defini quel joueur à posé la première carte
 * \param Couleur atout : defini quelle couleur est en atout
 * \param int carteRestante : nombre de cartes resantes en main
 * \return
 *
 */

 int choixCarteIA(Joueur joueur, Carte *pMainJoueur, Carte pli[], Joueur dernierVainqueur, Couleur atout, int carteRestante);

#endif // _IA_H_
