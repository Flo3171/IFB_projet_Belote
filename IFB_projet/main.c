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

    /*menuPrincipal();*/


    char message[TAILLE_MAXI_MESSAGE] = "Felicitation vous remportezaaa la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d points";
    int noCarteJouee;

    char messageFormate[9][31];
    char *pMessageFormate = &messageFormate[0][0];
    decoupeChaine(message, pMessageFormate, 30, 9);
    printf("________\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n_______\n", messageFormate[0], messageFormate[1], messageFormate[2], messageFormate[3], messageFormate[4], messageFormate[5], messageFormate[6], messageFormate[7], messageFormate[8]);

    afficheSousMenus("Felicitation vous remportezaaa la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d points", "coucou");
   /* noCarteJouee = afficheInterfacePli(pli, pli, pseudo, carteMain, contrat, message, OUEST);
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
