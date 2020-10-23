
typedef struct Enseignant
{
    char nom[30];
    char prenom[30];
    char email[30];
    char tel[15];
    char Cin[30];
} Enseignant;


typedef struct Surveillance
{
    char date[30];
    int h_debut;
    int h_fin;
    int salle;
    char module[30];
    char filiere[30];
    char nom_du_surveillant[30];
}Surveillance;

typedef struct Compte
{
    char nom[30];
    char prenom[30];
    char email[30];
    char mdp[30];
    int droits;
} Compte;


int creer_compte(Compte compte, Compte* T, int length);

void store_surveillance(Surveillance* T, int length);

int supprimer_compte(Compte compte, Compte* T, int length);

void load_surveillance(Surveillance* T, int* length);

void store_compte(Compte* T, int length);

void load_compte(Compte*T, int *length);

void afficher_surveillance (Surveillance *T,int length);

void modifier_surveillance(Surveillance *TS, int compteur_surveillance);

int creer_surveillance(Surveillance surv, Surveillance* T, int length);

void afficher_compte (Compte *T,int length);

int menu();




