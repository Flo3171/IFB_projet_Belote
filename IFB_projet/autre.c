#include "main.h"

Joueur joueurSuivant(Joueur joueur){
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
    system("cls");
    int statisitique[5][4] = {0};
    int *pSatistique = &statisitique[0][0];
    char *pseudo[4] = {"A_Philipe", "Gilou", "Utilisateur", "Tutu"};
    int nbManche = 0;
    for (int noPartie = 1; noPartie <= nbPartie; noPartie ++){
        nbManche += nouvellePartie(pseudo, SANS_JOUEUR, pSatistique);
    }

    printf("%d partie viennent d'etre jouee entre 4 ia. \nVoici des statistiques qui permetent de tester les fonctions d'ia \nles plus efficaces sur un grand nombre de partie\n", nbPartie);
    printf("   STATISTIQUE :\n\t\t\t\tNORD\t EST\t SUD\t OUEST\t\n");
    printf("PROPORSTION DE VICTOIRE :\t %3.0f %%\t %3.0f %%\t \%3.0f %%\t \%3.0f %%\n", (float)statisitique[0][0]*100/nbPartie, (float)statisitique[0][1]*100/nbPartie, (float)statisitique[0][2]*100/nbPartie, (float)statisitique[0][3]*100/nbPartie);
    printf("PROPORSTION DE CONTRAT GAGNE :\t %3.0f %%\t %3.0f %%\t \%3.0f %%\t \%3.0f %%\n", (float)statisitique[2][0]*100/statisitique[1][0], (float)statisitique[2][1]*100/statisitique[1][1], (float)statisitique[2][2]*100/statisitique[1][2], (float)statisitique[2][3]*100/statisitique[1][3]);
    printf("PROPORSTION DE PLI GAGNE :\t %3.0f %%\t %3.0f %%\t \%3.0f %%\t \%3.0f %%\n", (float)statisitique[3][0]*100/(8*nbManche), (float)statisitique[3][1]*100/(8*nbManche), (float)statisitique[3][2]*100/(8*nbManche), (float)statisitique[3][3]*100/(8*nbManche));
    printf("PROPORSTION DE MANCHE GAGNE :\t %3.0f %%\t %3.0f %%\t \%3.0f %%\t \%3.0f %%\n", (float)statisitique[4][0]*100/(nbManche), (float)statisitique[4][1]*100/(nbManche), (float)statisitique[4][2]*100/(nbManche), (float)statisitique[4][3]*100/(nbManche));
    printf("\nPressez une touche pour revenir au menu");
    getch();


}

