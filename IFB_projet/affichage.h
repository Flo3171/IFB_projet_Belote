#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_

/** \brief affiche  le logo du jeu puis le menu principal
 *
 * \param type: quel type de menu est souhaité
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
 * \param Joueur utilisateur : donne la position de l'utilisateur, mettre SANS_Joueur pour faire une partie avec uniquement des ordinateur
 * \param Joueur dernierVainqueur : joueur aylant gagné le dernier pli
 * \param int score[] : tableau qui contient les score de la partie
 * \param int pointManche[] : tableau qui contient les points de la manche
 * \param int type : version de la fonction : 0 pour un affichage et une acquisition et 1 pour l'acquisition seulle
 * \return int : valeur choisie par l'utilisateur
 *
 */

int afficheInterfacePli(Carte dernierPli[], Carte pli[], char *pseudo[], Carte cartesEnMain[], Contrat contratActuel, char message[],Joueur utilisteur, Joueur dernierVainqueur,int score[], int pointManche[], int type);

/** \brief modifie la taille de la fenetre dans laquel le programme s'execute
 *
 * \param nbLingeFenetre : nombre de ligne de la fenetre
 * \param nbColloneFenetre : nombre de collone de la fenetre
 * \return void
 *
 */
void modifieTailleFenetre(int nbLigneFenetre, int nbColloneFentre);

/** \brief affiche les différents sous menus
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
 * \param char *pseudo[]: tableau de pointeur contenant les pseudo des différents joueurs
 * \param int version : 1 pour la version belle et de grande taille et 2 pour la version courte
 * \return void
 *
 */

void afficheContrat(Contrat contrat, char *pseudo[], int version);

/** \brief affiche dans un cadre plusieurs chaines de carractères avec un certain nombre de lignes sautée entre chacunes d'elles
 *
 * \param char intitule []: titre du du cadre
 * \param char phrase[] : les chaines de carractère séparés par des points virgules
 * \param int sautDeLigne : nombre de lignes à sauter entre chaque chaine de carractères
 * \return void
 *
 */
void afficheMenuSelection(char intitule [],char phrase[],int sautDeLigne);

/** \brief gère le choix du contrat par l'utilisateur
 *
 * \param Contrat dernierContrat : dernier contrat proposé
 * \param Joueur parle : joueur qui parle
 * \param Carte *pCarteMain : pointeur sur le tableau qui stocke les carte dans la main du joueur
 * \return Contrat : nouveau contrat proposé par le joueur
 * \param
 * \return
 *
 */

Contrat proposeContratUtilisateur(Contrat dernierContrat, Joueur parle, Carte *pCarteMain);


#endif

