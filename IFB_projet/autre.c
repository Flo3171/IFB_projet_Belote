#include "main.h"

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

int pointPli(Carte pli[], Couleur atout)
{
    int point=0;

    for(int i=0;i<4;i++){
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
