#include "main.h"
int main(int argc, char *argv[])
{
    srand(time(NULL));

    /*initialisation(50, 91); /**< definit la taille de la fennetre a 50 lignes et 91 colones */

    /* DEBUG ET TEST DES FONTIONS */


    /*afficheMenuPrincipal(0);*/
    Carte pli[4];
    pli[0].couleur = CARREAU;
    pli[0].valeur = 9;
    pli[1].couleur = PIQUE;
    pli[1].valeur = AS;
    pli[2].couleur = TREFLE;
    pli[2].valeur = DAME;
    pli[3].couleur = SANS_COULEUR;
    pli[3].valeur = SANS_VALEUR;

    Carte carteMain[8];
    carteMain[0].couleur = PIQUE;
    carteMain[0].valeur = DIX;
    carteMain[1].couleur = PIQUE;
    carteMain[1].valeur = AS;
    carteMain[2].couleur = TREFLE;
    carteMain[2].valeur = DIX;
    carteMain[3].couleur = TREFLE;
    carteMain[3].valeur = AS;
    carteMain[4].couleur = CARREAU;
    carteMain[4].valeur = DIX;
    carteMain[5].couleur = CARREAU;
    carteMain[5].valeur = AS;
    carteMain[6].couleur = COEUR;
    carteMain[6].valeur = DIX;
    carteMain[7].couleur = COEUR;
    carteMain[7].valeur = AS;


    /*afficheMain(carteMain);
    supprimeCarte(carteMain, 8, 2);
    afficheMain(carteMain);*/

    /*Carte mainJoueur[4][8] = {0};
    Carte *pMainJoueur;
    pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);
    afficheMain(mainJoueur[0]);
    afficheMain(mainJoueur[1]);
    afficheMain(mainJoueur[2]);
    afficheMain(mainJoueur[3]);*/
    /**< victor a tord */
    /**for (Joueur parle = dealer; parle != dealer; joueurSuivant(parle)){

    }*/

    Contrat contrat;
    contrat.preneur = NORD;
    contrat.nbPoint = 80;
    contrat.atout = TOUT_ATOUT;
    contrat.coinche = SURCOINCHE;


    char *pseudo[4] = {"A_Philipe", "Gilou", "Utilisateur", "Tutu"};

    /*afficheInterfacePli(pli, pli, pseudo, carteMain, contrat, "pate", OUEST);
    for (int i = 0; i < 8; i++){
        printf("%d\t",carteValide(carteMain[i], pli, contrat.atout, carteMain, NORD, OUEST));
    }*/

    /*Carte mainJoueur[4][8];
    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);*/



    /*
    Contrat contratIA;
    contratIA = proposeContratIa(NORD, pMainJoueur, contrat);
    afficheContrat(contratIA, pseudo);
    */
    /*
    afficheContrat(contratIA, pseudo);*/


    /*afficheMain(pMainJoueur);
    for (Couleur atout = 1; atout < 7; atout ++){
        printf("%d %f\n",atout,  sommeForceCarte(pMainJoueur, 8, atout));
    }*/

    /*char pseudo[4][TAILLE_MAXI_PESEUDO+1];
    strcpy(pseudo[0],"A_Philipe");
    strcpy(pseudo[1],"Gilou");
    strcpy(pseudo[2],"Utilisateur");
    strcpy(pseudo[3],"Tutu");
    getch();
    acquisitionPseudoAvecMessage(pseudo[2],"Choisisez votre pseudo:");
    puts(pseudo[0]);
    puts(pseudo[1]);
    puts(pseudo[2]);
    puts(pseudo[3]);*/

    /*menuPrincipal();*/
    int score[4] = {0};
    /*manche(pseudo, score, NORD);*/

    /*menuPrincipal();*/

    nouvellePartie(pseudo, SANS_JOUEUR);

    /*afficheMenuSelection("parametre","1-changer le pseudo du joueur;2-changer le pseudo du joueur;3-changer le pseudo du joueur ouest inch ca marche ptn;4-c'est un test; 5-on va bien voir si ca marche ");*
    manche(pseudo, score, SUD);*/

    /*char message[TAILLE_MAXI_MESSAGE] = "Felicitation vous remportezaaa la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d points";
    int noCarteJouee;

    char messageFormate[9][31];
    char *pMessageFormate = &messageFormate[0][0];
    decoupeChaine(message, pMessageFormate, 30, 9);
    printf("________\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n_______\n", messageFormate[0], messageFormate[1], messageFormate[2], messageFormate[3], messageFormate[4], messageFormate[5], messageFormate[6], messageFormate[7], messageFormate[8]);
    */
    /*afficheSousMenus("Felicitation vous remportezaaa la partie avec %s, vous avez ateint un total de %d point et vos advresaire ont %d points", "coucou");*/

    /*printf("Vous jouez la carte %d", noCarteJouee);*/

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

    /*Carte mainJoueur[4][8];
    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);*/

    /** essais pour compter les points**/
    /*printf("|%d|",pointPli(pli,TOUT_ATOUT));
    printf("|%d|",pointPli(pli,SANS_ATOUT));
    printf("|%d|",pointPli(pli,COEUR));
    printf("|%d|",pointPli(pli,PIQUE));
    printf("|%d|",pointPli(pli,TREFLE));
    printf("|%d|",pointPli(pli,CARREAU));*/


    Carte mainJoueur[4][8];

    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);

    Carte pliVide[4];
    pliVide[0].couleur = SANS_COULEUR;
    pliVide[0].valeur = SANS_VALEUR;
    pliVide[1].couleur = SANS_COULEUR;
    pliVide[1].valeur = SANS_VALEUR;
    pliVide[2].couleur = SANS_COULEUR;
    pliVide[2].valeur = SANS_VALEUR;
    pliVide[3].couleur = SANS_COULEUR;
    pliVide[3].valeur = SANS_VALEUR;

    for(int i=1; i<5;i++){

        choixCarteIA(NORD+i-1,pMainJoueur+8*(i-1),pliVide,NORD,COEUR,8);
    }

    /*for(int j=0;j<21;j++){
        distribueCarte(pMainJoueur);
        for(int i=1;i<5;i++){
            poseCarte(SUD,1,pMainJoueur,pliVide,0,9-1);
        }
    getch();
    menuPrincipal();


    /**<CODDE VRAIMENT UTLILE (ne pas supprimer)*/

    return 0;
}
