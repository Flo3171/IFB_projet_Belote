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
int decoupeChaine(char chaineInitiale[], char *chaineFinale,int tailleLigne,int nbLigne);

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
void formateCarte(Carte carte[], char *chaineFinale, int nbCarte, int tailleChaine, int version);


/** \brief met dans une chaine de caractère la valeur et la couleur d'une carte
 *
 * \param carte : variable de type carte qui contient la carte a afficher
 * \param valeur : pointeur vers la chaine  qui stocke la valeur (ou la valeur et la couleur si mode court)
 * \param couleur : pointeur vers la chaine  qui stocke la couleur
 * \param vesion : 0 si c'est la version courte et 1 pour la version longue
 * \param tailleChaine : taille de la chaine de caratère dans laquel on écrit
 * \return void
 *
 */
void stockeInfoCarte(Carte carte, char *valeur, char *couleur, int version, int tailleChaine);

/** \brief stocke dans une chaine de caractère le pseudo d'un des joueur
 *
 * \param Joueur joueur : joueur dont on veut afficher le pseudo
 * \param char *pseudo[] : tableau contennant les pseudo des joueur
 * \param int tailleChaine : taille de la chaine final
 * \param char chaineFinal[] : chaine final ou est stocké le pseudo
 * \param int varsion : 1 pour la version ou la chaine finale est centrée 0 pour l'aligné a gauche
 * \return void
 *
 */
void formatePseudo(Joueur joueur, char *pseudo[], int tailleChaine, char chaineFinal[], int version);

/** \brief stocke dans des chaine de caractère les info du contrat
 *
 * \param Contrat contrat : contrat a afficher
 * \param char *chainefinal : chaine final ou  on enregistre les info du contrat
 * \param int tailleLigne : taille d'une ligne
 * \param char *pseudo[] : tableau qui contient les pseudo des joueur
 * \return void
 *
 */
void formateContrat(Contrat contrat, char *chaineFinal, int tailleLigne, char *pseudo[]);

/** \brief transforme une chaine de cararactère en sa vertion aligné a gauche
 *
 * \param char chaine : chaine a modifier
 * \param int longeurChaine
 * \return int : 0 si tout c'est bien passé
 *
 */
int aligneModifieChaine(char chaine[], int longeurChaine);

/** \brief génere un message et l'enregistre dans une chaine de caractère
 *
 * \param char message[] : tableau de char ou on enregistre le message
 * \param Joueur parle : joueur qui pose une carte
 * \param char *pseudo[] : tableau qui contient les pseudo des joueur
 * \param Carte carteJoue : carte qui vine d'être jouée
 * \param int score : score a afficher
 * \param TypeMessage typeMessage : permet de savoir quelle message on veux afficher
 * \return void
 *
 */

void genereMessage(char message[], Joueur parle, char *pseudo[], Carte carteJoue, int score, TypeMessage typeMessage);





#endif // _FORMATAGE_CHAINE_H_
