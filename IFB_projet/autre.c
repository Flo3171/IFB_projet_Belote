#include "main.h"

/**
 * \file autre.c
 * \brief ficher source contenant les fonctions qui n'allait dans aucun autre fichier
 * \author Carlo.A & Florian.C
 * \version v1.0
 * \date 12 juin 2020
*/

Joueur joueurSuivant(Joueur joueur)
{
    if (joueur == OUEST){
        return NORD;
    }
    else {
        return joueur+1;
    }
}

int nbAleatoire(int mini, int maxi)
{
    return (rand()%(maxi - mini + 1)) + mini;
}

void setContrat(Contrat *contrat, Joueur preneur, int nbPoint, Couleur atout, Coinche coinche)
{
    (*contrat).preneur = preneur;
    (*contrat).nbPoint = nbPoint;
    (*contrat).atout = atout;
    (*contrat).coinche = coinche;
}

int pointPli(Carte pli[], Couleur atout,int nbCarte)
{
    int point=0;

    for(int i=0;i<nbCarte;i++){
        switch(atout){
            case TOUT_ATOUT:
                    {
                    switch (pli[i].valeur){
                        case VALET:
                            point = point + 14 ;
                            break;
                        case NEUF:
                            point = point + 9 ;
                            break;
                        case AS:
                            point = point + 6 ;
                            break;
                        case DIX:
                            point = point + 5 ;
                            break;
                        case ROI:
                            point = point + 3 ;
                            break;
                        case DAME:
                            point = point + 1 ;
                            break;
                        default:
                             point = point + 0 ;
                            break;
                        }
                    }
                    break;
            case SANS_ATOUT:
                    {
                     switch (pli[i].valeur){
                        case AS:
                            point = point + 19 ;
                            break;
                        case DIX:
                            point = point + 10 ;
                            break;
                        case ROI:
                            point = point + 4 ;
                            break;
                        case DAME:
                            point = point + 3 ;
                            break;
                        case VALET:
                            point = point + 2 ;
                            break;
                        default:
                             point = point + 0 ;
                            break;
                        }
                    }
                    break;
            default:
                    {
                    if (pli[i].couleur == atout){
                        switch (pli[i].valeur){
                        case VALET:
                            point = point + 14 ;
                            break;
                        case NEUF:
                            point = point + 9 ;
                            break;
                        case AS:
                            point = point + 6 ;
                            break;
                        case DIX:
                            point = point + 5 ;
                            break;
                        case ROI:
                            point = point + 3 ;
                            break;
                        case DAME:
                            point = point + 1 ;
                            break;
                        default:
                             point = point + 0 ;
                            break;
                        }
                    }else{
                        switch (pli[i].valeur){
                        case AS:
                            point = point + 19 ;
                            break;
                        case DIX:
                            point = point + 10 ;
                            break;
                        case ROI:
                            point = point + 4 ;
                            break;
                        case DAME:
                            point = point + 3 ;
                            break;
                        case VALET:
                            point = point + 2 ;
                            break;
                        default:
                             point = point + 0 ;
                            break;
                        }
                    }
                }
                break;
        }
    }
    return point;
}


float ajusteEchelle(float valeur, float entreMin, float entreMax, float sortieMin, float sortieMax)
{
    return (valeur - entreMin)*(sortieMax - sortieMin)/(entreMax - entreMin) + sortieMin;
}


void joue1000Partie(int nbPartie)
{
    int statisitique[5][4] = {0};
    int *pSatistique = &statisitique[0][0];
    int infoEcriture[3] = {0};
    char *pseudo[4] = {"A_Philipe", "Gilou", "Utilisateur", "Tutu"};
    int nbManche = 0;
    for (int noPartie = 1; noPartie <= nbPartie; noPartie ++){
        nbManche += nouvellePartie(pseudo, SANS_JOUEUR, pSatistique, infoEcriture);
    }
    system("cls");
    printf("%d parties viennent d'etre jouees entre 4 ia. \nVoici des statistiques qui permettent de tester les fonctions d'ia \npour determiner lesquelles sont les plus efficaces sur un grand nombre de parties\n", nbPartie);
    printf("   STATISTIQUES :\n\t\t\t\tNORD\t EST\t SUD\t OUEST\t\n");
    printf("PROPORTION DE VICTOIRES :\t %3.0f %%\t %3.0f %%\t \%3.0f %%\t \%3.0f %%\n", (float)statisitique[0][0]*100/nbPartie, (float)statisitique[0][1]*100/nbPartie, (float)statisitique[0][2]*100/nbPartie, (float)statisitique[0][3]*100/nbPartie);
    printf("PROPORTION DE CONTRATS GAGNES :\t %3.0f %%\t %3.0f %%\t \%3.0f %%\t \%3.0f %%\n", (float)statisitique[2][0]*100/statisitique[1][0], (float)statisitique[2][1]*100/statisitique[1][1], (float)statisitique[2][2]*100/statisitique[1][2], (float)statisitique[2][3]*100/statisitique[1][3]);
    printf("PROPORTION DE PLIS GAGNES :\t %3.0f %%\t %3.0f %%\t \%3.0f %%\t \%3.0f %%\n", (float)statisitique[3][0]*100/(8*nbManche), (float)statisitique[3][1]*100/(8*nbManche), (float)statisitique[3][2]*100/(8*nbManche), (float)statisitique[3][3]*100/(8*nbManche));
    printf("PROPORTION DE MANCHES GAGNEES :\t %3.0f %%\t %3.0f %%\t \%3.0f %%\t \%3.0f %%\n", (float)statisitique[4][0]*100/(nbManche), (float)statisitique[4][1]*100/(nbManche), (float)statisitique[4][2]*100/(nbManche), (float)statisitique[4][3]*100/(nbManche));
    printf("\nPressez une touche pour revenir au menu");
    getch();


}
