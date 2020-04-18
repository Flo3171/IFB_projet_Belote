#include "main.h"
int main(int argc, char *argv[])
{
    initialisation(44, 91); /* definit la taille de la fennetre a 44 lignes et 91 colones */
    /* DEBUG ET TEST DES FONTIONS */

    /*afficheMenuPrincipal();*/
    Carte pli[4];

    pli[0].couleur = COEUR;
    pli[0].valeur = 9;
    pli[1].couleur = PIQUE;
    pli[1].valeur = AS;
    pli[2].couleur = COEUR;
    pli[2].valeur = 9;
    pli[3].couleur = COEUR;
    pli[3].valeur = 9;

    Contrat contrat;

    char *pseudo[4] = {"A_Philipe", "Gilou", "Utilisateur", "Tutu"};
    printf("%s %s %s %s \n", pseudo[0], pseudo[1], pseudo[2], pseudo[3]);

    printf("La premiere catre est un %d de %d, la deuxieme un %d de %d \n", pli[0].valeur, pli[0].couleur, pli[1].valeur, pli[1].couleur);

    /*char chaineCentre[100];
    centreChaine("coucou", chaineCentre, 7);
    printf("la chaine %s sur %d caractere donne |%s|", "coucou", 7, chaineCentre);

    char chaine[100] = "coucou";
    centreModifieChaine(chaine, 10);
    printf("|%s|\n", chaine);*/


    afficheInterfacePli(pli, pli, pseudo, pli, contrat, "Tutu gagne le plis quel champion grace a sont 7 de pique il a defonce tout le monde, ils n'ont rien put faire en face c'est cpn tres tres tres con tout ca !!");
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
