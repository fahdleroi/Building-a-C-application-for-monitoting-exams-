#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#define null 0


void afficher_compte (Compte *T,int length)
{
    FILE *file=NULL;
    file=fopen("compte.txt","r");

    if(file==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture du fichier des comptes !!\n");
        exit(-1);
    }


    load_compte(T,&length);
    for(int i =0; i< length; i++)
    {
        printf("compte %d \n\n\n",i+1);
        printf("  nom  : \t%s \n",T[i].nom);
        printf("  prenom :\t%s\n",T[i].prenom);
        printf("  email :\t%s\n",T[i].email);
        printf("  mot de passe :\t%s\n",T[i].mdp);
        printf("  droit :\t%d\n",T[i].droits);
    }
    fclose(file);

}




void afficher_surveillance (Surveillance *T,int length)
{
    FILE *file=NULL;
    file=fopen("surveillance.txt","r");

    if(file==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture du fichier des surveillances !!\n");
        exit(-1);
    }


    load_surveillance(T,&length);
    for(int i =0; i< length; i++)
    {
        printf("  surveillance %d \n\n\n",i+1);
        printf("  nom  : \t%s \n",T[i].nom_du_surveillant);
        printf("  module :\t%s\n",T[i].module);
        printf("  filiere :\t%s\n",T[i].filiere);
        printf("  heure debut :\t %d\n",T[i].h_debut);
        printf("  heure fin :\t%d\n",T[i].h_fin);
        printf("  date :\t%s\n",T[i].date);
        printf("  salle :\t%d\n",T[i].salle);
    }
    fclose(file);

}

void modifier_surveillance(Surveillance *TS,int length)
{
    FILE *file=NULL;



    file=fopen("surveillance.txt","a+");



    load_surveillance(TS,&length);
    int choix,num_de_surveillance=0;
    afficher_surveillance(TS,length);

    while (num_de_surveillance > length || num_de_surveillance < 1 ){
    printf("\n veuillez choisir le numero de surveillance a modifier :\t");
    scanf("%d",&num_de_surveillance);}


        while(choix >7 || choix <0)
        {
            printf("donner votre choix \n");
            printf("0) ne rien modifier \n ");
            printf("1) modifier la date\n ");
            printf("2) modifier la l'heure du debut\n ");
            printf("3) modifier la l'heure de la fin \n ");
            printf("4) modifier la sale \n ");
            printf("5) modifier l'enseignant\n ");
            printf("6) modifier la filier\n ");
            printf("7) modifier le module\n ");
            scanf("%d",&choix);
        }

        switch(choix)
        {
    case 0 :
        break;

        case 1 :
            printf("donner la nouvelle date \n:");
            scanf("%s",TS[num_de_surveillance].date);
            break;
        case 2 :
            printf("donner la nouvelle heure du debut\n");
            scanf("%d",&TS[num_de_surveillance].h_debut);
            break;

        case 3 :
            printf("donner la nouvelle heure du fin\n");
            scanf("%d",&TS[num_de_surveillance].h_fin);
            break;
        case 4 :
            printf("donner le numero de la salle \n");
            scanf("%d",&TS[num_de_surveillance].salle);
            break;
        case 5 :
            printf("donner le nom du nouvel enseignant :\n");
            scanf("%s",TS[num_de_surveillance].nom_du_surveillant);
            break;
        case 6 :
            printf (" donner la nouvelle filier \n ");
            scanf("%s",TS[num_de_surveillance].filiere);
            break;
        case 7 :
            printf(" donner le nouveau module \n");
            scanf("%s",TS[num_de_surveillance].module);
            break;

        }



    store_surveillance(TS,length);

    fclose(file);

}
void load_surveillance(Surveillance* T, int* length)
{
    FILE* file;
    Surveillance surv;
    *length=0;
    file=fopen("surveillance.txt","a+");
    if(file==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture du fichier des surveillances !!\n");
        exit(-1);
    }
    while(fscanf(file,"%s %s %s %d %d %s %d\n",surv.nom_du_surveillant,surv.module,surv.filiere,&surv.h_debut,&surv.h_fin,surv.date,&surv.salle)>0)
    {
        T[(*length)++]=surv;
    }

    fclose(file);
}
void load_compte(Compte* TC, int* length)
{
    FILE* file;
    Compte compte;
    *length=0;
    file=fopen("compte.txt","a+");
    if(file==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture du fichier des comptes !!\n");
        exit(-1);
    }
    while(fscanf(file,"%s %s %s %s %d\n",compte.nom,compte.prenom,compte.email,compte.mdp,&compte.droits)>0)
    {
        TC[(*length)++]=compte;
    }

    fclose(file);
}


int creer_compte(Compte compte, Compte* T, int length)  //0 compte n'est pas creer (compte déja existant ), 1 compte bien crée
{


    FILE* file;
    int i;
    for(i=0; i<length; i++)
    {
        if(strcmp(T[i].email,compte.email)==0)
            return 0;
    }
    T[length++]=compte;
    file=fopen("compte.txt","a+");
    if(file==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture du fichier des comptes !!\n");
        exit(-1);
    }
    fprintf(file,"%s %s %s %s %d\n",compte.nom,compte.prenom,compte.email,compte.mdp,compte.droits);
    fclose(file);
    return 1;
}
int creer_surveillance(Surveillance surv, Surveillance* T, int length)  //0 surveillance n'est pas creer (surveillance déja existant ), 1 surveillance bien crée
{

    FILE* file;

    T[length++]=surv;
    file=fopen("surveillance.txt","a+");
    if(file==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture du fichier des surveillances !!\n");
        exit(-1);
    }
    printf("\n %s %s %s %d %d %s %d\n",surv.nom_du_surveillant,surv.module,surv.filiere,surv.h_debut,surv.h_fin,surv.date,surv.salle);
    fprintf(file,"%s %s %s %d %d %s %d\n",surv.nom_du_surveillant,surv.module,surv.filiere,surv.h_debut,surv.h_fin,surv.date,surv.salle);
    fclose(file);
    return 1;
}


void store_surveillance(Surveillance* T, int length)
{
    FILE* file;
    int i;
    file=fopen("surveillance.txt","w+");
    if(file==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture du fichier des surveillance !!\n");
        exit(-1);
    }
    for(i=0; i<length; i++)
    {
        fprintf(file,"%s %s %s %d %d %s %d\n",T[i].nom_du_surveillant,T[i].module,T[i].filiere,T[i].h_debut,T[i].h_fin,T[i].date,T[i].salle);
    }
    fclose(file);
}

void store_compte(Compte* T, int length)
{
    Compte compte;
    FILE* file;
    int i;
    file=fopen("compte.txt","w+");
    if(file==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture du fichier des comptes !!\n");
        exit(-1);
    }
    for(i=0; i<length; i++)
    {
        fprintf(file,"%s %s %s %s %d\n",T[i].nom,T[i].prenom,T[i].email,T[i].mdp,compte.droits);
    }
    fclose(file);
}

int supprimer_compte(Compte compte, Compte* T, int length)
{
    int i,j;
    for(i=0; i<length; i++)
    {
        if(strcmp(T[i].email,compte.email)==0)
        {
            for(j=i; j<length-1; j++)
            {
                T[j]=T[j+1];
            }
            store_compte(T,length-1);
            return 1; // compte supprimer
        }
    }
    return 0; // compte non supprimer
}




int menu()
{

    int choix=10;
    char choixTmp[30];
    while(choix>6 || choix<0)
    {
        system("cls");
        printf("\033[1;33m");
        printf("\t\t Gestion des surveillances : \n");
        printf("\033[1;33m");
        printf("\t0)\033[1;36m Quitter.... : \n");
        printf("\033[1;33m");
        printf("\t1)\033[1;36m Creer un compte.... : \n");
        printf("\033[1;33m");
        printf("\t2)\033[1;36m Supprimer un compte.... : \n");
        printf("\033[1;33m");
        printf("\t3)\033[1;36m afficher les surveillances.......:  \n");
        printf("\033[1;33m");
        printf("\t4)\033[1;36m modifier les surveillances...... : \n");
        printf("\033[1;33m");
        printf("\t5)\033[1;36m creer surveillance ...... :  \n");
        printf("\033[1;33m");
        printf("\t6)\033[1;36m afficher les comptes .... : \n");
        printf("\033[1;31m");
        printf("\n\t=>Choix : \033[0;37m");
        scanf("%s",choixTmp);
        sscanf(choixTmp,"%d",&choix);
    }
    return choix;
}





