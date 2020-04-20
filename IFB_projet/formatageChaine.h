#ifndef _FORMATAGE_CHAINE_H_
#define _FORMATAGE_CHAINE_H_

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

/** \brief formate les chaine de carac�re qui affiche la valeur et la couleur des cartes
 *
 * \param chaineFinale[][][] tableau a trois dimention qui stocke les chaine de carac�re de la valeur et la couleurs des cartes
 * \param carte[] : tableau de typpe Carte contenant les carte a afficher
 * \param nbCarte : nombre de carte dans le tableau carte[]
 * \param tailleChaine : taille des chaineFinale
 * \param version : 0 si c'est la verion courte et 1 pour la verision longue
 * \return void
 *
 */
void formateCarte(Carte carte[], char *chaineFinale[], int nbCarte, int tailleChaine, int version);



#endif // _FORMATAGE_CHAINE_H_
