#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_

/** \brief affiche  le logo du jeu puis le menu principal
 *
 * \param type: quel type de menu est souhait�
 * \return la valeur de l'action que l'utilisateur decide de faire
 *
 */

int afficheMenuPrincipal(int type);



/** \brief affiche l'interface de jeu durant un pli
 *
 * \param Carte dernierPli[] : tableau contenant les 4 cartes du dernier plis
 * \param Carte pli[] : tableau contenant les cartes du pli en cours, mettre 0, 0 si il n'y a pas de carte
 * \param char *pseudo[] : tableau contenant les pseudo des 4 joueur
 * \param Carte cartesEnMain[] : tableau contenant les carte dans la main de l'utilisateur
 * \param Contrat contratActuel : contrat qui est en cour dans cette manche
 * \param char message[500]
 * \param Joueur dernierVainqueur : joueur aylant gagn� le dernier pli
 * \return int : valeur choisie par l'utilisateur
 *
 */

int afficheInterfacePli(Carte dernierPli[], Carte pli[], char *pseudo[], Carte cartesEnMain[], Contrat contratActuel, char message[], Joueur dernierVainqueur);

/** \brief modifie la taille de la fenetre dans laquel le programme s'execute
 *
 * \param nbLingeFenetre : nombre de ligne de la fenetre
 * \param nbColloneFenetre : nombre de collone de la fenetre
 * \return void
 *
 */
void modifieTailleFenetre(int nbLigneFenetre, int nbColloneFentre);

/** \brief affiche les diff�rents sous menus
 *
 * \param phrase phrase correspondant au sous menu choisi
 * \return void
 *
 */
void afficheSousMenus(char phrase[],char intitule[]);

/** \brief affiche les carte qu'un joueur a en main
 *
 * \param Carte carte[] : tableau contanant les carte
 * \return void
 *
 */
void afficheMain(Carte carte[]);

/** \brief affiche un contrat
 *
 * \param Contrat contrat : contrat a afficher
 * \param char *pseudo[]: tableau de pointeur contenant les pseudo des diff�rents joueurs
 * \return void
 *
 */
void afficheContrat(Contrat contrat, char *pseudo[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void afficheMenuSelection(char intitule [],char phrase[]);

#endif

