#include "main.h"


void distribueCarte(Carte *pCarteMain)
{
    Carte carteDisponible[32];
    int curseur = 0, indiceCarte;
    for (int i = 0;i < 4; i++){
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = AS;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = SEPT;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = HUIT;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = NEUF;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = DIX;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = VALET;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = DAME;
        curseur ++;
        carteDisponible[curseur].couleur = i+1;
        carteDisponible[curseur].valeur = ROI;
        curseur ++;
    }

    for (int i = 0; i < NB_TOATAL_CARTE; i++){
        indiceCarte = nbAleatoire(0, NB_TOATAL_CARTE - i - 1);
        setCarte((pCarteMain + i), carteDisponible[indiceCarte].valeur, carteDisponible[indiceCarte].couleur);
        supprimeCarte(carteDisponible, NB_TOATAL_CARTE-i, indiceCarte);
    }
}

void setCarte(Carte *carte, Valeur valeurCarte, Couleur couleurCarte)
{
    (*carte).couleur = couleurCarte;
    (*carte).valeur = valeurCarte;
}

void supprimeCarte(Carte carte[], int nbCarte, int carteASupprimer)
{
    for (int i = carteASupprimer; i < nbCarte ; i++){
        setCarte(&carte[i], carte[i+1].valeur, carte[i+1].couleur);
    }
    setCarte(&carte[nbCarte -1], SANS_VALEUR, SANS_COULEUR);
}

Joueur vainqueurPli(Carte pli[], Couleur atout, Joueur premierAJouer)
{
    Joueur vainqueur = SANS_JOUEUR;
    float probabiliteVictoireMax = 0;
    Couleur entame = pli[premierAJouer - 1].couleur;
    for (Joueur joueurTest = NORD; joueurTest <= OUEST; joueurTest ++){
        printf("%d   %f\n", joueurTest, forceCarte(pli[joueurTest - 1], atout, entame));
        if (forceCarte(pli[joueurTest - 1], atout, entame) > probabiliteVictoireMax){/**< La carte du joueur que l'on test est plus forte que la meilleur actuelle alors ca devient la meilleure */
            probabiliteVictoireMax = forceCarte(pli[joueurTest - 1], atout, entame);
            vainqueur = joueurTest;
        }
    }

    return vainqueur;
}


float forceCarte(Carte carteACalculer, Couleur atout, Couleur entame)
{
    int nbCatreBatue = 0;

    if (carteACalculer.couleur == atout || (atout == TOUT_ATOUT && carteACalculer.couleur == entame)){/**< la carte est un atout ou que la manche se joue en tout atout */

        switch(carteACalculer.valeur)
        {
        case VALET :
            nbCatreBatue = 31;
            break;
        case NEUF :
            nbCatreBatue = 30;
            break;
        case AS :
            nbCatreBatue = 29;
            break;
        case DIX :
            nbCatreBatue = 28;
            break;
        case ROI :
            nbCatreBatue = 27;
            break;
        case DAME :
            nbCatreBatue = 26;
            break;
        case HUIT :
            nbCatreBatue = 25;
            break;
        case SEPT :
            nbCatreBatue = 24;
            break;
        default:
            nbCatreBatue = 0;
            break;
        }

    }
    else if (atout == TOUT_ATOUT){/**< si on est en tout atout mais que la couleur de la carte n'est pa la couleur de l'entame alors la carte sera plus faible que toutes les cartees dans la bonne couleur */

        switch(carteACalculer.valeur)
        {
        case VALET :
            nbCatreBatue = 7;
            break;
        case NEUF :
            nbCatreBatue = 6;
            break;
        case AS :
            nbCatreBatue = 5;
            break;
        case DIX :
            nbCatreBatue = 4;
            break;
        case ROI :
            nbCatreBatue = 3;
            break;
        case DAME :
            nbCatreBatue = 2;
            break;
        case HUIT :
            nbCatreBatue = 1;
            break;
        case SEPT :
            nbCatreBatue = 0;
            break;
        default:
            nbCatreBatue = 0;
            break;
        }
    }
    else if(carteACalculer.couleur == entame && atout == SANS_ATOUT){/**< la manche est en sans atout et la carte est dans la couleur de l'entame */

        switch(carteACalculer.valeur)
        {
        case AS :
            nbCatreBatue = 31;
            break;
        case DIX :
            nbCatreBatue = 30;
            break;
        case ROI :
            nbCatreBatue = 29;
            break;
        case DAME :
            nbCatreBatue = 28;
            break;
        case VALET :
            nbCatreBatue = 27;
            break;
        case NEUF :
            nbCatreBatue = 26;
            break;
        case HUIT :
            nbCatreBatue = 25;
            break;
        case SEPT :
            nbCatreBatue = 24;
            break;
        default:
            nbCatreBatue = 0;
            break;
        }


    }
    else{/**< on est en atout d'une certaine couleur ou en sans atoutavec une couleur différente de l'entame */
        if (carteACalculer.couleur == entame){

            switch(carteACalculer.valeur)
            {
            case AS :
                nbCatreBatue = 23;
                break;
            case DIX :
                nbCatreBatue = 22;
                break;
            case ROI :
                nbCatreBatue = 21;
                break;
            case DAME :
                nbCatreBatue = 20;
                break;
            case VALET :
                nbCatreBatue = 19;
                break;
            case NEUF :
                nbCatreBatue = 18;
                break;
            case HUIT :
                nbCatreBatue = 17;
                break;
            case SEPT :
                nbCatreBatue = 16;
                break;
            default:
                nbCatreBatue = 0;
                break;
            }
        }
        else{/**< quand l'entame est différent de la couleur de la carte et que ce n'est pas un atout alor on pert a chaque fois */

                        switch(carteACalculer.valeur)
            {
            case AS :
                nbCatreBatue = 7;
                break;
            case DIX :
                nbCatreBatue = 6;
                break;
            case ROI :
                nbCatreBatue = 5;
                break;
            case DAME :
                nbCatreBatue = 4;
                break;
            case VALET :
                nbCatreBatue = 3;
                break;
            case NEUF :
                nbCatreBatue = 2;
                break;
            case HUIT :
                nbCatreBatue = 1;
                break;
            case SEPT :
                nbCatreBatue = 0;
                break;
            default:
                nbCatreBatue = 0;
                break;
            }

        }

    }


    return (float)nbCatreBatue/(NB_TOATAL_CARTE -1);

}

char carteValide(Carte cartePose, Carte pli[], Couleur atout, Carte *pCarteMainJoueur, Joueur premierAJouer, Joueur parle)
{
    /**< Fonction faite a partir de l'oranigrame qui montre comment déterminer si une carte est valide a partir des règle*/
    char valide = 0;

    if (pli[premierAJouer-1].valeur == SANS_VALEUR && pli[premierAJouer - 1].couleur == SANS_COULEUR){/**< première carte du plis ? */
        valide = 1;
    }
    else{
        if (rechercherCarte(pCarteMainJoueur, 8, pli[premierAJouer-1].couleur, SANS_VALEUR, 1)){/**< Le joueur posède il la couleur demandée ? */
            if (pli[premierAJouer - 1].couleur == atout){/**< l'entame est en atout */
                if (1/**<rechercherCarte(atout de valeur supérieur)*/){/**< Le joueur a il un ajout de valeur supérieur au meilleur ajout posé */
                    if (1/**< forceCarte(cartePose) > foreCarte(pli[vainceur du pli - 1]) */){/**< si la carte est un ajout le valeur supérieur au meilleur atout posé */
                        valide = 1;
                    }
                    else{
                        valide = 0 ;
                    }
                }
                else{
                    valide = 1;
                }
            }
            else{
                if (cartePose.couleur == pli[premierAJouer - 1].couleur){/**< Si la carte est dans la couleur demandée */
                    valide = 1;
                }
                else{
                    valide = 0;
                }
            }
        }
        else{
            if(1/**< vainqueur pli == joueurSuivant(joueurSuivant(parle))*/){/**< Le partemenaire est maitre ? */
                valide = 1;
            }
            else{
                if (rechercherCarte(pCarteMainJoueur, 8, atout, SANS_VALEUR, 1)){/**< Le joueur a il un atout ? */
                    if (rechercherCarte(pli, 4, atout, SANS_VALEUR, 1)){/**< il y a deja un ajout de posé */
                        if (1/**<rechercherCarte(atout de valeur supérieur)*/){/**< Le joueur a il un ajout de valeur supérieur au meilleur ajout posé */
                            if (1/**< forceCarte(cartePose) > foreCarte(pli[vainceur du pli - 1]) */){/**< si la carte est un ajout le valeur supérieur au meilleur atout posé */
                                valide = 1;
                            }
                            else{
                                valide = 0 ;
                            }
                        }
                        else{
                            valide = 1;
                        }
                    }
                }
                else{
                    valide = 1;
                }
            }
        }

    }

    return valide;
}

char rechercherCarte(Carte *pCarte, int nbCarte, Couleur couleurCherche, Valeur valeurCherche, int version)
{
    char trouve = 0;
    if (version == 1){
        for(int i = 0; i < nbCarte; i++){
            if (((*(pCarte + i)).couleur == couleurCherche || couleurCherche == SANS_COULEUR) && ((*(pCarte + i)).valeur == valeurCherche || valeurCherche == SANS_VALEUR)){
                trouve = 1;
            }
        }
    }
    else if (version == 0){
        /**< si la force d'une carte est suppérieur a la force de la carte recherché */
    }

    return trouve;
}
