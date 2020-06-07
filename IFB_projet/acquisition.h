#ifndef ACQUISITION_H_INCLUDED
#define ACQUISITION_H_INCLUDED


/** \brief renvois au progammme un entier saisi par l'utilisateur avec message d'erreur entre 2 entiers
 *
 * \param min : borne inf�rieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \return la valeur saise par l'utilisateur et v�rifier
 *
 */

int acquisitionEntierAvecMessage(int min, int max);


/** \brief accisition  d'un entier saisi par l'utilisateur sans message d'erreur entre 2 entiers
 *
 * \param min : borne inf�rieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \return la valeure entiere saise par l'utilisateur et v�rifier
 *
 */

int acquisitionEntierSansMessage(int min, int max);


/** \brief accisition O/N 'oui ou non' saisi par l'utilisateur sans message d'erreur
 *
 * \return le caratere saisi par l'utilisateur, 'O' ou 'N' qui a ete verifie
 *
 */

 char acquisitionOuiNonSansMessage();

 /** \brief accisition  d'un entier saisi par l'utilisateur sans message d'erreur entre 2 entiers avec une consigne param�trable
 *
 * \param min : borne inf�rieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param consigne : message affich� avant a l'utilisateur pour lui indiquer ce qu'il doit saisir
 * \return la valeure entiere saise par l'utilisateur et v�rifier
 *
 */

int acquisitionEntierSansMessageAvecConsigne(int min, int max, char consigne[]);

/** \brief acquisition d'un pseudo saisi par l'utilisateur avec message d'erreur
 *
 * \param PPseudo: pointeur renvoyant vers le premier carract�re du pseudo � modifier
 * \param instruction: phrase � affichier pour donner l'instruction � l'utilisateur
 * \param type : vaut 1 si la fonction est appel�e dans la fonction param�tre
 * \return void
 *
 */

void acquisitionPseudoAvecMessage(char *pointeurPseudo,char instruction[],int type);

/** \brief fonction qui fait l'acquisition securis�e d'un nombre
 *
 * \return renvoie le nombre saisi par l'utilisateur et -1 si aucun nombre a �t� saisi
 *
 */
 int acquisitionEntierSecurise();

#endif // ACQUISITION_H_INCLUDED

