#ifndef _TABLEAU_H_
#define _TABLEAU_H_

/**
 * \file tableau.h
 * \brief ficher header contenant les prototypes des fonctions relative à la gestion des tableau
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/

/**
 * \brief fait la somme des valeur d'un tableau contenant des entiers
 * \fn int sommeTableau(int tableau[], int tailleTableau)
 *
 * \param tableau[] : le nom du tableau
 * \param tailleTableau : la taille du tableau, entier positif
 * \return la somme des valeur du table entier
 *
 */
int sommeTableau(int tableau[], int tailleTableau);


/**
 * \brief fait la moyenne des valeur d'un tableau contenant des entiers
 * \fn float moyenneTableau(int tableau[], int tailleTableau)
 *
 * \param tableau[] : le nom du tableau
 * \param tailleTableau : la taille du tableau, entier positif
 * \return la moyenne des valeur du tableau, réel
 *
 */
float moyenneTableau(int tableau[], int tailleTableau);

/**
 * \brief copie un tableau dans un autre
 * \fn void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
 *
 * \param tableauOriginal[] : tableaau que l'on veut copier
 * \param tableauCopie[] : tableau dans lequel on copie tableauOriaginal
 * \param tailleTableau : la taille du tableau, entier positif
 * \return void
 *
 */
void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau);


/**
 * \brief trouve la valeur minimum d'un tableau
 * \fn int mini(int tableau[], int tailleTableau)
 *
 * \param tableau [] : tableau dont on veut travailler
 * \param tailleTableau : la taille du tableau, entier positif
 * \return int valeur la plus petite du tableau
 *
 */
int mini(int tableau[], int tailleTableau);



/**
 * \brief trouve la valeur maximum d'un tableau
 * \fn int maxi(int tableau[], int tailleTableau)
 *
 * \param tableau [] : tableau dont on veut travailler
 * \param tailleTableau : la taille du tableau, entier positif
 * \return int valeur la plus grande du tableau
 *
 */
int maxi(int tableau[], int tailleTableau);





/**
 * \brief met a 0 toute les valeur d'un tableau qui sont superieur a un maximum
 * \fn void zeroSiSuperieur(int tableau[], int tailleTableau, int maximum)
 *
 * \param tableau[] : tableau sur lequel on veut travailler
 * \param tailleTableau : la taille du tableau, entier positif
 * \param maximum : valeur maximum au dessus de quoi la valeur est remise a 0
 * \return void
 *
 */
void zeroSiSuperieur(int tableau[], int tailleTableau, int maximum);


/**
 * \brief classe les valeur d'un tableau dans l'orde croissant
 * \fn void ordonnerTableau(int tableau[], int tailleTableau)void ordonnerTableau(int tableau[], int tailleTableau)
 *
 * \param tableau[] : le tableau à classer
 * \param tailleTableau : la taille du tableau, entier positif
 * \return void
 *
 */
void ordonnerTableau(int tableau[], int tailleTableau);



/**
 * \brief affiche un tableau
 * \fn void afficheTableau(int tableau[], int tailleTableau)
 *
 * \param tableau[] : le tableau a afficher
 * \param tailleTableau : la taille du tableau, entier positif
 * \return void
 *
 */

void afficheTableau(int tableau[], int tailleTableau);



/**
 * \brief demande a l'utilisateurde saisir les valeurs d'un tableau
 * \fn void acquiertTableau(int tableau[], int tailleTableau)
 *
 * \param tableau[] : nom du tableau a saisir
 * \param tailleTableau : la taille du tableau, entier positif
 * \return void
 *
 */
void acquiertTableau(int tableau[], int tailleTableau);





/**
 * \brief donne a toute les valeur d'un tableau une constante
 * \fn void constanteTableau(int tableau[], int tailleTableau, int valeur)
 *
 * \param tableau[] : tableau a modifier
 * \param tailleTableau : taille du tableau  entier positif
 * \param valeur : valeur a donner a toutes les valeur du tableau
 * \return void
 *
 */
void constanteTableau(int tableau[], int tailleTableau, int valeur);


/**
 * \brief donne des nombres aléatoire au valeur d'un tableau
 * \fn void aleatoireTableau(int tableau[], int tailleTableau, int mini, int maxi)
 *
 * \param tableau[] : tableau a modifier
 * \param tailleTableau : taille du tableau  entier positif
 * \param mini : valeur minimum des nombres aléatoires
 * \param maxi : valeur maximum des nombres aléatoires
 * \return
 *
 */
 void aleatoireTableau(int tableau[], int tailleTableau, int mini, int maxi);



/**
 * \brief chercherche par dicotomie si une valeur est au moin une fois dans le tableau
 * \fn int rechercheDichotomie(int tableau[], int tailleTableau, int nCherche)
 *
 * \param tableau[] : tableau dans lequel on fait la recherche
 * \param tailleTableau : taille du tableau  entier positif
 * \param nCherche: nombre que l'on cherche dans le tableau
 * \return int : 1 si on a trouvé, 0 sinon
 *
 */
int rechercheDichotomie(int tableau[], int tailleTableau, int nCherche);

#endif


