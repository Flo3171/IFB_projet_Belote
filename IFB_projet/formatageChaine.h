#ifndef _FORMATAGE_CHAINE_H_
#define _FORMATAGE_CHAINE_H_

/** \brief transphorme une chaine de caractère de longeur inconue en une chaine de caratère fixé de tel sorte que le texte soit centré
 *
 * \param char chaineInitial : chaine a modifier
 * \param char chaineFinal : pointeur vers la variable qui stocke la chainne final
 * \param int longeurChaine : longeur de la chaine final
 * \return int : 0 si tout va bien, 1 si la chaine est Initiale test plus longue que la longeur désirée
 *
 */
int centreChaine(char chaineInitial[], char chaineFinal[], int longeurChaine);


/** \brief transforme une chaine de cararactère en sa vertion centrée
 *
 * \param char chaine : chaine a modifier
 * \param int longeurChaine
 * \return int : 0 si tout c'est bien passé
 *
 */
int centreModifieChaine(char chaine[], int longeurChaine);


/** \brief fontion qui permet de découper une chaine de caracère en plusieur chaine de taille fixée en coupant sur un espace
 *
 * \param chaineInitiale[] : chaine a decouper
 * \param chaineFinale[][] : tableau contenant les chaine un fois découpé
 * \param tailleLigne : nobre de caracète maximun par ligne
 * \param nbLinge : nombre maximun de ligne
 * \return 0 si tout va bien 1 si la chaine est trop longue
 *
 */
int decoupeChaine(char chaineInitiale[], char *chaineFinale[],int tailleLigne,int nbLigne);

/** \brief rempli une chaine de caractère de nbEspace caractère espace ' '
 *
 * \param chaine[] : chaine a remplir;
 * \param nbEspace[] : nombre d'espaca a placer dans la chaine
 * \return void
 *
 */
void rempliEspace(char *chaine,int nbEspace);

/** \brief formate les chaine de caracère qui affiche la valeur et la couleur des cartes
 *
 * \param chaineFinale[][][] tableau a trois dimention qui stocke les chaine de caracère de la valeur et la couleurs des cartes
 * \param carte[] : tableau de typpe Carte contenant les carte a afficher
 * \param nbCarte : nombre de carte dans le tableau carte[]
 * \param tailleChaine : taille des chaineFinale
 * \param version : 0 si c'est la verion courte et 1 pour la verision longue
 * \return void
 *
 */
void formateCarte(Carte carte[], char *chaineFinale[], int nbCarte, int tailleChaine, int version);



#endif // _FORMATAGE_CHAINE_H_
