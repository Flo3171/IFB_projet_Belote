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

Joueur vainqueurPli(int couleur, int valeur)
/*< je ne sais pas si je dois utiliser "int" en type de variable... */
{
    Couleur joueurNord_c, joueurEst_c, joueurSud_c, joueurOuest_c;
    Valeur joueurNord_v, joueurEst_v, joueurSud_v, joueurOuest_v;
    /*< Il y a s�rement une meilleure facon de nommer les variables, voir d'utiliser une autre structure */

    Carte tableauDeCarte[4];


    tableauDeCarte[0].valeur = joueurNord_v;
    tableauDeCarte[0].couleur = joueurNord_c;
    tableauDeCarte[1].valeur = joueurEst_v;
    tableauDeCarte[1].couleur = joueurEst_c;
    tableauDeCarte[2].valeur = joueurSud_v;
    tableauDeCarte[2].couleur = joueurSud_c;
    tableauDeCarte[3].valeur = joueurOuest_v;
    tableauDeCarte[3].couleur = joueurOuest_c;
    /**< PAS FINI Ensuite j'applique la fonction forceCarte pour d�terminer qui remporte le pli */

}


char carteValide(Carte cartePose, Carte pli[], Couleur atout, Carte *pCarteMainJoueur, Joueur premierAJouer, Joueur parle)
{
    /**< Fonction faite a partir de l'oranigrame qui montre comment d�terminer si une carte est valide a partir des r�gle*/
    char valide = 0;

    if (pli[premierAJouer-1].valeur == SANS_VALEUR && pli[premierAJouer - 1].couleur == SANS_COULEUR){/**< premi�re carte du plis ? */
        valide = 1;
    }
    else{
        if (rechercherCarte(pCarteMainJoueur, 8, pli[premierAJouer-1].couleur, SANS_VALEUR, 1)){/**< Le joueur pos�de il la couleur demand�e ? */
            if (pli[premierAJouer - 1].couleur == atout){/**< l'entame est en atout */
                if (1/**<rechercherCarte(atout de valeur sup�rieur)*/){/**< Le joueur a il un ajout de valeur sup�rieur au meilleur ajout pos� */
                    if (1/**< forceCarte(cartePose) > foreCarte(pli[vainceur du pli - 1]) */){/**< si la carte est un ajout le valeur sup�rieur au meilleur atout pos� */
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
                if (cartePose.couleur == pli[premierAJouer - 1].couleur){/**< Si la carte est dans la couleur demand�e */
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
                    if (rechercherCarte(pli, 4, atout, SANS_VALEUR, 1)){/**< il y a deja un ajout de pos� */
                        if (1/**<rechercherCarte(atout de valeur sup�rieur)*/){/**< Le joueur a il un ajout de valeur sup�rieur au meilleur ajout pos� */
                            if (1/**< forceCarte(cartePose) > foreCarte(pli[vainceur du pli - 1]) */){/**< si la carte est un ajout le valeur sup�rieur au meilleur atout pos� */
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
        /**< si la force d'une carte est supp�rieur a la force de la carte recherch� */
    }

    return trouve;
}
