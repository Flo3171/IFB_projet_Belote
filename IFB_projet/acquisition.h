#ifndef ACQUISITION_H_INCLUDED
#define ACQUISITION_H_INCLUDED

/**
 * \file acquisition.h
 * \brief ficher header contenant les prototype des fonctions relative a l'acquisirion
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/


/**
 * \brief renvois au progammme un entier saisi par l'utilisateur avec message d'erreur entre 2 entiers
 * \fn int acquisitionEntierAvecMessage(int min, int max)
 *
 * \param min : borne inférieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \return la valeur saise par l'utilisateur et vérifier
 *
 */

int acquisitionEntierAvecMessage(int min, int max);


/**
 * \brief accisition  d'un entier saisi par l'utilisateur sans message d'erreur entre 2 entiers
 * \fn int acquisitionEntierSansMessage(int min, int max);
 *
 * \param min : borne inférieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \return la valeure entiere saise par l'utilisateur et vérifier
 *
 */

int acquisitionEntierSansMessage(int min, int max);


/**
 * \brief accisition O/N 'oui ou non' saisi par l'utilisateur sans message d'erreur
 * \fn char acquisitionOuiNonSansMessage()
 *
 * \return le caratere saisi par l'utilisateur, 'O' ou 'N' qui a ete verifie
 *
 */

 char acquisitionOuiNonSansMessage();

 /**
 * \brief accisition  d'un entier saisi par l'utilisateur sans message d'erreur entre 2 entiers avec une consigne paramétrable
 * \fn acquisitionEntierSansMessageAvecConsigne(int min, int max, char consigne[])
 *
 * \param min : borne inférieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param max : borne superieur de l'ensemble dans lequel la valeur saisi doit ce trouver
 * \param consigne : message affiché avant a l'utilisateur pour lui indiquer ce qu'il doit saisir
 * \return la valeure entiere saise par l'utilisateur et vérifier
 *
 */

int acquisitionEntierSansMessageAvecConsigne(int min, int max, char consigne[]);

/**
 * \brief acquisition d'un pseudo saisi par l'utilisateur avec message d'erreur
 * \fn void acquisitionPseudoAvecMessage(char *pointeurPseudo,char instruction[],int type)
 *
 * \param char *pointeurPseudo : pointeur renvoyant vers le premier caractère du pseudo à modifier
 * \param char instruction[] : phrase à affichier pour donner l'instruction à l'utilisateur
 * \return void
 */
void acquisitionPseudoAvecMessage(char *pointeurPseudo,char instruction[],int type);

/**
 * \brief fonction qui fait l'acquisition securisée d'un nombre
 * \fn  int acquisitionEntierSecurise()
 *
 * \return renvoie le nombre saisi par l'utilisateur et -1 si aucun nombre a été saisi
 *
 */
 int acquisitionEntierSecurise();

#endif // ACQUISITION_H_INCLUDED

