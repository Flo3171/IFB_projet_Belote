#include "main.h"

Contrat proposeContratIa(Joueur parle, Carte *pCarteMain, Contrat dernierContrat)
{
    float seuilMinPrise = 0.6, seuilMaxPrise = 1;

    Contrat nouveauContrat;
    setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
    Couleur meilleurCouleur = SANS_COULEUR;
    float forceMeilleurCouleur = 0, sommeForce = 0;
    for (Couleur i = 1; i < 7; i++){
        sommeForce = sommeForceCarte(pCarteMain, 8, i);
        if (sommeForce > forceMeilleurCouleur){
            meilleurCouleur = i;
            forceMeilleurCouleur = sommeForce;
        }
    }
    if(forceMeilleurCouleur > seuilMinPrise){
        int enchereMax = 10*floor(ajusteEchelle(forceMeilleurCouleur, seuilMinPrise, seuilMaxPrise, 8, 17));
        if (dernierContrat.nbPoint < enchereMax){
            setContrat(&nouveauContrat, parle, enchereMax, meilleurCouleur, NORMAL);
        }
        else{
            setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
        }
    }
    else {
        setContrat(&nouveauContrat, parle, ZERO, SANS_COULEUR, NORMAL);
    }

    return nouveauContrat;

}

int choixCarteIA(Joueur joueur, Carte *pMainJoueur, Carte pli[], Joueur premierJoueur, Couleur atout, int carteRestante)
{
    int retour=NULL, numCarte=0, nbCarteValide=0, offset=0;
    Carte carteAJouer;
    Carte carteValidee[8],carteGagnante[8];
    Carte *pCarteValidee = &carteValidee[0], *pCarteGagante = &carteGagnante[0];
    int numCarteValide[8], numCarteGagnante[8];
    Joueur Meneur;

    if (NIVEAU_IA == 1){

        do{
                numCarte=numCarte+1;
                carteAJouer =  *(pMainJoueur + numCarte-1);
                retour = carteValide(carteAJouer, pli, atout, pMainJoueur, premierJoueur,joueur);
            }while (retour == 0);

    }else if(NIVEAU_IA == 2){

        for(numCarte; numCarte < carteRestante; numCarte++ ){
            carteAJouer =  *(pMainJoueur + numCarte);

            if(carteValide(carteAJouer, pli, atout, pMainJoueur, premierJoueur,joueur)==1){
                setCarte(pCarteValidee+nbCarteValide,carteAJouer.valeur, carteAJouer.couleur);
                numCarteValide[nbCarteValide]=numCarte+1;
                nbCarteValide++;
            }
        }

        /** debug
        for(int i=0;i<nbCarteValide;i++){
            printf("|%d| \n",numCarteValide[i]);
        }
        afficheMain(pCarteValidee);
        **/
        Meneur = vainqueurPli(pli, atout, premierJoueur);

        if(nbCarteValide != 1){
            for(int j=0; j<nbCarteValide; j++ ){
                if (rechercherCarteSuperieur(pCarteValidee+j,nbCarteValide, pli[Meneur-1], atout, pli[premierJoueur-1].couleur)==1){
                    setCarte(pCarteGagante+offset,carteValidee[j].valeur,carteValidee[j].couleur);
                    numCarteGagnante[offset]=numCarteValide[j];
                    offset = offset +1 ;
                }
            }
        }else{
            numCarte = numCarteValide[nbCarteValide-1];
        }

        /** debug
        for(int i=0;i<offset;i++){
            printf("|%d|| \n",numCarteGagnante[i]);
        }
        afficheMain(pCarteGagante);
        **/
        if(offset == 0 ){
            carteAJouer = *pCarteValidee;
            numCarte= numCarteValide[0];
            for(int i=1; i<nbCarteValide;i++){
                if (rechercherCarteSuperieur(pCarteValidee+i,nbCarteValide,carteAJouer,atout,pli[premierJoueur-1].couleur)==0){
                    carteAJouer = *(pCarteValidee + i);
                    numCarte = numCarteValide[i];
                    /*printf("%d|%d\n",carteAJouer.valeur,carteAJouer.couleur);*/
                }
            }
        }else if(offset ==1){
            numCarte = numCarteGagnante[0];
        }else if(offset > 1 ){
            carteAJouer = *pCarteGagante;
            numCarte= numCarteGagnante[0];
            for(int i=1; i<offset;i++){
                if (rechercherCarteSuperieur(pCarteGagante+i,offset,carteAJouer,atout,pli[premierJoueur-1].couleur)==1){
                    carteAJouer = *(pCarteGagante + i);
                    numCarte = numCarteGagnante[i];
                    /*printf("%d|%d\n",carteAJouer.valeur,carteAJouer.couleur);*/
                }
            }
        }

    }

    return numCarte;
}
