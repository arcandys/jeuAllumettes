#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int menuPrincipal(){
    system("clear");
    int select =0;
    printf("Jeu des allumettes\n");
    printf("Sélectionnez le menu désiré:\n");
    printf("    1- Jouer\n");
    printf("    2- Règles du jeu\n");
    printf("    3- Crédits\n");
    printf("    4- Quitter\n");
    printf(">> Votre choix: ");
    scanf("%d",&select);
    switch (select){
    case 1 : jouer(); break;
    case 2 : regles(); break;
    case 3 : credits(); break;
    case 4 : printf("vous avez quitté le jeu\n"); return 0; break;
    
    default: printf("----- Une erreur est survenue -----"); return 0; break;
    }
}

int regles(){
    int entree = 0;
    system("clear");
    printf("les 2 joueurs s'affrontent en prenant qu' 1 à 3 allumettes et celui qui prend la dernière allumette a perdu\n\n");
    printf("écrire 1 pour retourner au menu principal: ");
    scanf("%d", &entree);
    switch(entree){
        case 1: menuPrincipal(); break;
        default: printf("----- Une erreur est survenue -----"); break;
    }
}

int credits(){
    int entree = 0;
    system("clear");
    printf("Développé par 'arcandys', Projet C 3e Année\n Classe 31 - ESIEA Paris - Décembre 2022\n\n");
    printf("écrire 1 pour retourner au menu principal: ");
    scanf("%d", &entree);
    switch(entree){
        case 1: menuPrincipal(); break;
        default: printf("----- Une erreur est survenue -----"); break;
    }
}

int jouer(){
    int modeJeu =0;
    printf("\nChoisissez votre mode de jeu:\n");
    printf("    1- 1v1 humain\n");
    printf("    2- 1v1 ordinateur facile\n");
    printf("    3- 1v1 ordinateur difficile\n");
    printf("    4- Menu principal\n");
    printf(">> Votre choix: ");
    scanf("%d",&modeJeu);
    switch (modeJeu){
    case 1 : humainHumain(); break;
    case 2 : humainOrdiSimple(); break;
    case 3 : humainOrdiDiff(); break;
    case 4 : menuPrincipal(); break;
    
    default:
        break;
    }
}


int humainHumain(){
    char J1[20];
    char J2[20];
    int nbAll[30];
    int i, j = 0;
    int imputJ1, imputJ2 = 0;
    int compteurLastPlayed = 0; 
    int tmp = 0;
    int k = 30;

    system("clear");
    printf("Vous avez choisi le mode Humain vs Humain!\n\n");
    printf("Quel est le nom du Joueur 1? -> ");
    scanf("%s", &J1);
    printf("Quel est le nom du Joueur 2? -> ");
    scanf("%s", &J2);
    printf("\nJoueur 1: %s et Joueur 2: %s\nLet's play!\n\n", J1, J2);

    for(i=0; i<=30;i++){
        nbAll[i] = 1;
    }

    while(nbAll[1] == 1){       //tant que la 2e case =1
        for(j=0;j<=30;j++){
            if(nbAll[j] == 1){
                printf("| ");
            }else{
                printf(" ");
            }
        }

        printf("\n");
        printf("%s: combien d'allumettes à enlever? ", J1);
        scanf("%d", &imputJ1);
        printf("\n");
        if(imputJ1 < 0 | imputJ1 > 3){
            printf(">> Merci de choisir un nombre entre 0 et 3.\n\n");
        }else{
            tmp = k-imputJ1;
            printf("\n>> Le joueur %s à enlevé %d allumette(s).\n\n", J1, imputJ1);
            while(k != tmp){
                nbAll[k] = 0;
                k--;
            }
            compteurLastPlayed++;   //=1 si le j1 joue, 0 si le j2 joue
        }       

        for(j=0;j<=30;j++){
            if(nbAll[j] == 1){
                printf("| ");
            }else{
                printf(" ");
            }
        }

        if(nbAll[1] == 0){  //pour sortir du while sans attendre la fin
            break;
        }else{
            printf("\n");
            printf("%s: combien d'allumettes à enlever? ", J2);
            scanf("%d", &imputJ2);
            printf("\n");
            if(imputJ2 < 0 | imputJ2 > 3){
                printf(">> Merci de choisir un nombre entre 0 et 3.\n\n");
            }else{
                tmp = k-imputJ2;
                printf("\n>> Le joueur %s à enlevé %d allumette(s).\n\n", J2, imputJ2);
                while(k != tmp){
                    nbAll[k] = 0;
                    k--;
                }
                compteurLastPlayed--;   //=1 si le j1 joue, 0 si le j2 joue
            }
        }

    }
    if(compteurLastPlayed == 0){
        printf("\nla partie est finie, le joueur %s à gagné car il a pris l'avant dernière allumette.\n", J2);
    }else{
        printf("\nla partie est finie, le joueur %s à gagné car il a pris l'avant dernière allumette.\n", J1);
    }
    

}


int humainOrdiSimple(){
    char J1[20];
    int nbAll[30];
    int i, j = 0;
    int imputJ1, imputJ2 = 0;
    int compteurLastPlayed = 0; 
    int tmp = 0;
    int k = 30;
    int nbAllumettes = 30;

    system("clear");
    printf("Vous avez choisi le mode Humain vs Ordi!\n\n");
    printf("Quel est le nom du Joueur 1? -> ");
    scanf("%s", &J1);
    printf("\nJoueur 1: %s et Joueur 2: Ordi\nLet's play!\n\n", J1);

    for(i=0; i<=30;i++){    //init du tab des allumettes à 
        nbAll[i] = 1;
    }

    while(nbAll[1] == 1){       //tant que la 2e case =1
        for(j=0;j<=30;j++){
            if(nbAll[j] == 1){
                printf("| ");
            }else{
                printf(" ");
            }
        }
        printf("nb allumettes = %d\n", nbAllumettes);

        printf("\n");
        printf("%s: combien d'allumettes à enlever? ", J1);
        scanf("%d", &imputJ1);
        printf("\n");
        if(imputJ1 < 0 | imputJ1 > 3){
            printf(">> Merci de choisir un nombre entre 0 et 3.\n\n");
        }else{
            tmp = k-imputJ1;
            printf("\n>> Le joueur %s à enlevé %d allumette(s).\n\n", J1, imputJ1);
            nbAllumettes -= imputJ1;
            printf("nb allumettes = %d\n", nbAllumettes);
            while(k != tmp){
                nbAll[k] = 0;
                k--;
            }
            compteurLastPlayed++;   //=1 si le j1 joue, 0 si le j2 joue
        }       

        for(j=0;j<=30;j++){
            if(nbAll[j] == 1){
                printf("| ");
            }else{
                printf(" ");
            }
        }

        if(nbAll[1] == 0){  //pour sortir du while sans attendre la fin
            break;
        }else{
            printf("\n");
            printf("Ordi: combien d'allumettes à enlever? ");
            printf("\n");
            imputJ2 = (rand() %3) +1;
            //scanf("%d", &imputJ2);
            if(imputJ2 < 0 | imputJ2 > 3){
                printf(">> Merci de choisir un nombre entre 0 et 3.\n\n");
            }else{
                tmp = k-imputJ2;
                printf("\n>> Le joueur Ordi à enlevé %d allumette(s).\n\n", imputJ2);
                nbAllumettes -= imputJ2;
                printf("nb allumettes = %d\n", nbAllumettes);
                while(k != tmp){
                    nbAll[k] = 0;
                    k--;
                }
                compteurLastPlayed--;   //=1 si le j1 joue, 0 si le j2 joue
            }
        }

    }
    if(compteurLastPlayed == 0){
        printf("\nla partie est finie, le joueur Ordi à gagné car il a pris l'avant dernière allumette.\n");
    }else{
        printf("\nla partie est finie, le joueur %s à gagné car il a pris l'avant dernière allumette.\n", J1);
    }
    

}


int humainOrdiDiff(){
    char J1[20];
    int nbAll[30];
    int i, j = 0;
    int imputJ1, imputJ2 = 0;
    int compteurLastPlayed = 0; 
    int tmp = 0;
    int k = 30;
    int nbAllumettes = 30;

    system("clear");
    printf("Vous avez choisi le mode Humain vs Ordi - Difficile!\n\n");
    printf("Quel est le nom du Joueur 1? -> ");
    scanf("%s", &J1);
    printf("\nJoueur 1: %s et Joueur 2: Ordi\nLet's play!\n\n", J1);

    for(i=0; i<=30;i++){
        nbAll[i] = 1;
    }

    while(nbAll[1] == 1){       //tant que la 2e case =1
        for(j=0;j<=30;j++){
            if(nbAll[j] == 1){
                printf("| ");
            }else{
                printf(" ");
            }
        }

        printf("\n");
        printf("%s: combien d'allumettes à enlever? ", J1);
        scanf("%d", &imputJ1);
        printf("\n");
        if(imputJ1 < 0 | imputJ1 > 3){
            printf(">> Merci de choisir un nombre entre 0 et 3.\n\n");
        }else{
            tmp = k-imputJ1;
            printf("\n>> Le joueur %s à enlevé %d allumette(s).\n\n", J1, imputJ1);
            nbAllumettes -= imputJ1;
            printf("nb allumettes = %d\n", nbAllumettes);
            while(k != tmp){
                nbAll[k] = 0;
                k--;
            }
            compteurLastPlayed++;   //=1 si le j1 joue, 0 si le j2 joue
        }       

        for(j=0;j<=30;j++){
            if(nbAll[j] == 1){
                printf("| ");
            }else{
                printf(" ");
            }
        }

        if(nbAll[1] == 0){  //pour sortir du while sans attendre la fin
            break;
        }else{
            printf("\n");
            printf("Ordi: combien d'allumettes à enlever? ");
            printf("\n");
            imputJ2 = nbAllumettes %4;
            if(imputJ2 == 0){
                imputJ2 = 3;
            }
            //scanf("%d", &imputJ2);
            if(imputJ2 < 0 | imputJ2 > 3){
                printf(">> Merci de choisir un nombre entre 0 et 3.\n\n");
            }else{
                tmp = k-imputJ2;
                printf("\n>> Le joueur Ordi à enlevé %d allumette(s).\n\n", imputJ2);
                nbAllumettes -= imputJ2;
                printf("nb allumettes = %d\n", nbAllumettes);
                while(k != tmp){
                    nbAll[k] = 0;
                    k--;
                }
                compteurLastPlayed--;   //=1 si le j1 joue, 0 si le j2 joue
            }
        }

    }
    if(compteurLastPlayed == 0){
        printf("\nla partie est finie, le joueur Ordi à gagné car il a pris l'avant dernière allumette.\n");
    }else{
        printf("\nla partie est finie, le joueur %s à gagné car il a pris l'avant dernière allumette.\n", J1);
    }
    

}

int main(){
   menuPrincipal();
   //humainHumain();
   return 0;
}