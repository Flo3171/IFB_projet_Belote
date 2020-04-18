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


/** \brief modifie la taille de la fenetre dans laquel le programme s'execute
 *
 * \param nbLingeFenetre : nombre de ligne de la fenetre
 * \param nbColloneFenetre : nombre de collone de la fenetre
 * \return void
 *
 */
void modifieTailleFenetre(int nbLigneFenetre, int nbColloneFentre);

/** \brief fontion qui permet de d�couper une chaine de carac�re en plusieur chaine de taille fix�e en coupant sur un espace
 *
 * \param chaineInitiale[] : chaine a decouper
 * \param chaineFinale[][] : tableau contenant les chaine un fois d�coup�
 * \param tailleLigne : nobre de carac�te maximun par ligne
 * \param nbLinge : nombre maximun de ligne
 * \return 0 si tout va bien 1 si la chaine est trop longue
 *
 */
int decoupeChaine(char chaineInitiale[], char *chaineFinale[],int tailleLigne,int nbLigne);

/** \brief rempli une chaine de caract�re de nbEspace caract�re espace ' '
 *
 * \param chaine[] : chaine a remplir;
 * \param nbEspace[] : nombre d'espaca a placer dans la chaine
 * \return void
 *
 */
void rempliEspace(char *chaine,int nbEspace);


#endif

