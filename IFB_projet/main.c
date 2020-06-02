#include "main.h"
int main(int argc, char *argv[])
{
    /**< CODE FINAL */
    srand(time(NULL));
    if(!DEBUG_MODE){
            initialisation(50, 91); /**< definit la taille de la fennetre a 50 lignes et 91 colones */
    }
    menuPrincipal();
    /**< FIN CODE FINAL */


    /* DEBUG ET TEST DES FONTIONS */
    menuPrincipal();
    /*afficheMenuPrincipal(0);*/
    /*Carte pli[4];
    pli[0].couleur = SANS_COULEUR;
    pli[0].valeur = SANS_VALEUR;
    pli[1].couleur = COEUR;
    pli[1].valeur = DIX;
    pli[2].couleur = SANS_COULEUR;
    pli[2].valeur = SANS_VALEUR;
    pli[3].couleur = SANS_COULEUR;
    pli[3].valeur = SANS_VALEUR;

    Carte carteMain[8];
    carteMain[0].couleur = TREFLE;
    carteMain[0].valeur = DAME;
    carteMain[1].couleur = PIQUE;
    carteMain[1].valeur = 10;
    carteMain[2].couleur = TREFLE;
    carteMain[2].valeur = 8;
    carteMain[3].couleur = PIQUE;
    carteMain[3].valeur = 9;
    carteMain[4].couleur = PIQUE;
    carteMain[4].valeur = ROI;
    carteMain[5].couleur = COEUR;
    carteMain[5].valeur = DAME;
    carteMain[6].couleur = PIQUE;
    carteMain[6].valeur = 7;
    carteMain[7].couleur = CARREAU;
    carteMain[7].valeur = AS;

    char *pseudo[4] = {"A_Philipe", "Gilou", "Utilisateur", "Tutu"};


    Contrat contrat;
    contrat.preneur = EST;
    contrat.nbPoint = 90;
    contrat.atout = TOUT_ATOUT;
    contrat.coinche = NORMAL;

    afficheInterfacePli(pli, pli, pseudo, carteMain, contrat, "pate",SUD, EST, 1);
    for (int i = 0; i < 8; i++){
        printf("%d\t",carteValide(carteMain[i], pli, contrat.atout, carteMain, EST, SUD));
    }*/


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
    /**< victor a thor */
    /**for (Joueur parle = dealer; parle != dealer; joueurSuivant(parle)){

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

    /*Carte pliVide[4];
    pliVide[0].couleur = SANS_COULEUR;
    pliVide[0].valeur = SANS_VALEUR;
    pliVide[1].couleur = SANS_COULEUR;
    pliVide[1].valeur = SANS_VALEUR;
    pliVide[2].couleur = SANS_COULEUR;
    pliVide[2].valeur = SANS_VALEUR;
    pliVide[3].couleur = SANS_COULEUR;
    pliVide[3].valeur = SANS_VALEUR;*/

    /*menuPrincipal();*/
    /*int score[4] = {0};*/
    /*manche(pseudo, score, NORD);*/

    /*menuPrincipal();*/
    /*afficheMain(carteMain);
    afficheMain(pli);
    printf("Le joueur joue la carte :%d\n", choixCarteIA(OUEST, carteMain, pli, NORD, COEUR, 8));*/


    /*char message[TAILLE_MAXI_MESSAGE];
    genereMessage(message, SUD, pseudo, carteMain[1], POSE_CARTE);
    printf("%s\n", message);*/

    /*nouvellePartie(pseudo, SUD);*/
    /*nouvellePartie(pseudo, SANS_JOUEUR);*/


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

    /**< ZONE DÉBUG SALE DE CARLO**/

    /*printf("|%d|",pointPli(pli,TOUT_ATOUT));
    printf("|%d|",pointPli(pli,SANS_ATOUT));
    printf("|%d|",pointPli(pli,COEUR));
    printf("|%d|",pointPli(pli,PIQUE));
    printf("|%d|",pointPli(pli,TREFLE));
    printf("|%d|",pointPli(pli,CARREAU));*/


    /*Carte mainJoueur[4][8];

    Carte *pMainJoueur = &mainJoueur[0][0];
    distribueCarte(pMainJoueur);

    Carte *pCarteMain = &carteMain[0];*/
    /*


    int r=0;

    for(int i=1; i<5;i++){

        r=choixCarteIA(NORD+i-1,pMainJoueur+8*(i-1),pliVide,NORD,COEUR,8);
        printf("%d",r);
    }*/

    /*for(int j=0;j<21;j++){
        distribueCarte(pMainJoueur);
        for(int i=1;i<5;i++){
            poseCarte(SUD,1,pMainJoueur,pliVide,0,9-1);
        }
    getch();
    menuPrincipal();*/
    /*
    afficheMain(pMainJoueur);
    afficheMain(pMainJoueur+3*8+5);
    printf("%d",choixCarteIA(OUEST,pMainJoueur,pMainJoueur+3*8+5,NORD,COEUR,8));

    */
    /*char message[TAILLE_MAXI_MESSAGE];
    sprintf(message, "%s rempporte son contrat et gagne %d ;points ses adversaires gagnent %d points;", "NORD", 800, 500);

    afficheMenuSelection("Resultat manche", message, 5);
    */
    /**< FIN ZONE SÉCIALE DÉBUG SALE*/

    return 0;
}
