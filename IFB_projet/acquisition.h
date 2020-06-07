#ifndef ACQUISITION_H_INCLUDED
#define ACQUISITION_H_INCLUDED


/** \brief renvois au progammme un entier saisi par l'utilisateur avec message d'erreur entre 2 entiers
 *
 * \param min : borne inférieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \return la valeur saise par l'utilisateur et vérifier
 *
 */

int acquisitionEntierAvecMessage(int min, int max);


/** \brief accisition  d'un entier saisi par l'utilisateur sans message d'erreur entre 2 entiers
 *
 * \param min : borne inférieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \return la valeure entiere saise par l'utilisateur et vérifier
 *
 */

int acquisitionEntierSansMessage(int min, int max);


/** \brief accisition O/N 'oui ou non' saisi par l'utilisateur sans message d'erreur
 *
 * \return le caratere saisi par l'utilisateur, 'O' ou 'N' qui a ete verifie
 *
 */

 char acquisitionOuiNonSansMessage();

 /** \brief accisition  d'un entier saisi par l'utilisateur sans message d'erreur entre 2 entiers avec une consigne paramétrable
 *
 * \param min : borne inférieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param consigne : message affiché avant a l'utilisateur pour lui indiquer ce qu'il doit saisir
 * \return la valeure entiere saise par l'utilisateur et vérifier
 *
 */

int acquisitionEntierSansMessageAvecConsigne(int min, int max, char consigne[]);

/** \brief acquisition d'un pseudo saisi par l'utilisateur avec message d'erreur
 *
 * \param PPseudo: pointeur renvoyant vers le premier carractère du pseudo à modifier
 * \param instruction: phrase à affichier pour donner l'instruction à l'utilisateur
 * \param type : vaut 1 si la fonction est appelée dans la fonction paramètre
 * \return void
 *
 */

void acquisitionPseudoAvecMessage(char *pointeurPseudo,char instruction[],int type);

/** \brief fonction qui fait l'acquisition securisée d'un nombre
 *
 * \return renvoie le nombre saisi par l'utilisateur et -1 si aucun nombre a été saisi
 *
 */
 int acquisitionEntierSecurise();

#endif // ACQUISITION_H_INCLUDED

