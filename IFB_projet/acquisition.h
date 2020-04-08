#ifndef ACQUISITION_H_INCLUDED
#define ACQUISITION_H_INCLUDED


/** \brief revois au progammme un entier saisi par l'utilisateur avec message d'erreur entre 2 entiers
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



#endif // ACQUISITION_H_INCLUDED

