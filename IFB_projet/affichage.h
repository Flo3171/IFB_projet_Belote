#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_

/** \brief affiche  le logo du jeu puis le menu principal
 *
 * \return la valeur de l'action que l'utilisateur decide de faire
 *
 */

int afficheMenuPrincipal();



/** \brief affiche l'interface de jeu durant un pli
 *
 * \param Carte dernierPli[] : tableau contenant les 4 cartes du dernier plis
 * \param Carte pli[] : tableau contenant les cartes du pli en cours, mettre 0, 0 si il n'y a pas de carte
 * \param char pseudo[] : tableau contenant les pseudo des 4 joueur
 * \param Carte cartesEnMain[] : tableau contenant les carte dans la main de l'utilisateur
 * \param Contrat contratActuel : contrat qui est en cour dans cette manche
 * \param char message[500]
 * \return int : valeur choisie par l'utilisateur
 *
 */

int afficheInterfacePli(Carte dernierPli[], Carte pli[], char *pseudo[], Carte cartesEnMain[], Contrat contratActuel, char message[]);


/** \brief transphorme une chaine de caract�re de longeur inconue en une chaine de carat�re fix� de tel sorte que le texte soit centr�
 *
 * \param char chaineInitial : chaine a modifier
 * \param char chaineFinal : pointeur vers la variable qui stocke la chainne final
 * \param int longeurChaine : longeur de la chaine final
 * \return int : 0 si tout va bien, 1 si la chaine est Initiale test plus longue que la longeur d�sir�e
 *
 */
int centreChaine(char chaineInitial[], char chaineFinal[], int longeurChaine);


/** \brief transforme une chaine de cararact�re en sa vertion centr�e
 *
 * \param char chaine : chaine a modifier
 * \param int longeurChaine
 * \return int : 0 si tout c'est bien pass�
 *
 */
int centreModifieChaine(char chaine[], int longeurChaine);


#endif

