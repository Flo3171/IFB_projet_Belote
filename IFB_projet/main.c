#include "main.h"
int main(int argc, char *argv[])
{
    initialisation(50, 91); /* definit la taille de la fennetre a 44 lignes et 91 colones */
    /* DEBUG ET TEST DES FONTIONS */


    /*afficheMenuPrincipal(0);*/
    Carte pli[4];
    pli[0].couleur = COEUR;
    pli[0].valeur = 9;
    pli[1].couleur = PIQUE;
    pli[1].valeur = AS;
    pli[2].couleur = TREFLE;
    pli[2].valeur = DAME;
    pli[3].couleur = CARREAU;
    pli[3].valeur = ROI;

    Carte carteMain[8];
    carteMain[0].couleur = COEUR;
    carteMain[0].valeur = 7;
    carteMain[1].couleur = TREFLE;
    carteMain[1].valeur = 8;
    carteMain[2].couleur = CARREAU;
    carteMain[2].valeur = 9;
    carteMain[3].couleur = PIQUE;
    carteMain[3].valeur = 10;
    carteMain[4].couleur = COEUR;
    carteMain[4].valeur = VALET;
    carteMain[5].couleur = TREFLE;
    carteMain[5].valeur = DAME;
    carteMain[6].couleur = PIQUE;
    carteMain[6].valeur = ROI;
    carteMain[7].couleur = CARREAU;
    carteMain[7].valeur = AS;



    Contrat contrat;
    contrat.preneur = NORD;
    contrat.nbPoint = 80;
    contrat.atout = COEUR;
    contrat.coinche = SURCOINCHE;

    char *pseudo[4] = {"A_Philipe", "Gilou", "Utilisateur", "Tutu"};

    nouvellePartie(pseudo);



    char message[TAILLE_MAXI_MESSAGE] = "Tutu gagne le plis quel champion il est trop fort";
    int noCarteJouee;
    /*noCarteJouee = afficheInterfacePli(pli, pli, pseudo, carteMain, contrat, message, OUEST);
    printf("Vous jouez la carte %d", noCarteJouee);*/

    /*afficheSousMenus("1-nouvelle partie 2-leaderboard 3-statistiques  4-changement d'utilisateur  5-parametres  6-quitter ","pseudo");*/

    /*acquisitionPseudoAvecMessage();*/
    /*Pour voir la liste des caracère que on peut utliser
    for (int i = -127; i <=127; i++){
        printf(" %d-->%c\n", i,i);
    }*/
    /*char c = "coucou";
    char *pc;
    pc = &c;
    rempliEspace(pc, 4);
    printf("|%s|\n", pc);*/


    /*CODDE VRAIMENT UTLILE (ne pas supprimer)*/

    return 0;
}
