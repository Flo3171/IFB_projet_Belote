#include "main.h"

int sommeTableau(int tableau[], int tailleTableau)
{
    int somme = 0;
    for (int i = 0; i < tailleTableau; i++){
        somme = somme + tableau[i];
    }
    return somme;
}

float moyenneTableau(int tableau[], int tailleTableau)
{
    return ((float)sommeTableau(tableau, tailleTableau)/tailleTableau);
}

 void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
 {
     for (int i = 0; i < tailleTableau; i++){
        tableauCopie[i] = tableauOriginal[i];
     }
 }


 int mini(int tableau[], int tailleTableau)
 {
     int mini;
     mini = tableau[0];
     for (int i = 1; i < tailleTableau; i++){
        if (tableau[i] < mini){
            mini = tableau[i];
        }
     }
     return mini;
 }

int maxi(int tableau[], int tailleTableau)
{
    int maxi;
    maxi = tableau[0];
    for (int i = 1; i < tailleTableau; i++){
        if (tableau[i] > maxi){
            maxi = tableau[i];
        }
    }
    return maxi;
}

void zeroSiSuperieur(int tableau[], int tailleTableau, int maximum)
{
        for (int i = 0; i < tailleTableau; i++){
            if (tableau[i] > maximum){
                tableau[i] = 0;
            }
        }
}

void ordonnerTableau(int tableau[], int tailleTableau)
{
    int tampon;
    for (int i = 0; i < tailleTableau; i++){
        for (int j = 0; j <tailleTableau - i; j++){
            if (tableau[j] > tableau [j+1]){
                tampon = tableau[j];
                tableau[j] = tableau[j+1];
                tableau[j+1] = tampon;

            }
        }
    }

}


void afficheTableau(int tableau[], int tailleTableau)
{
    printf("\n  cle\t| valeur\n__________________\n");
    for (int i = 0; i < tailleTableau; i++){
        printf("|  %d\t|  %d\t|\n", i, tableau[i]);
    }
    printf("__________________\n");
}


void acquiertTableau(int tableau[], int tailleTableau)
{
    for (int i = 0; i < tailleTableau; i++){
        printf("Entrer la valeur de la %d case : ", i);
        scanf("%d", &tableau [i]);
    }
}

void constanteTableau(int tableau[], int tailleTableau, int valeur)
{
    for(int i = 0; i < tailleTableau; i++){
        tableau[i] = valeur;
    }
}

int rechercheDichotomie(int tableau[], int tailleTableau, int nCherche)
{
    int trouve = 0, debut = 0, fin = tailleTableau - 1, millieu;
    while (debut <= fin && trouve == 0){
        millieu = floor((fin - debut)/2);
        if (tableau[millieu] == nCherche){
            trouve = 1;
        }
        else if(tableau[millieu] < nCherche){
            debut = millieu+1;
        }
        else{
            fin = millieu-1;
        }
    }
    return trouve;
}


 void aleatoireTableau(int tableau[], int tailleTableau, int mini, int maxi)
 {
     srand(time(NULL));
     for (int i = 0; i < tailleTableau; i++){
        tableau[i] = rand()%(maxi-mini+1) + mini;
     }
 }
