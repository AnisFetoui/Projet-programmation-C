#include<gtk/gtk.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;
typedef struct
{
    char nom[20];
    char prenom[20];
	char mdp[20];
    char sexe [20];
    char id[20];
    Date date;
    char typeutilisateur[100];
} utilisateur;

void ajouter (utilisateur u );
void affichageutilisateur (GtkWidget *liste);
void modifier_utilis(utilisateur u1 );
void supprimer( char id[20]);
void affichage_recherche_utilis(GtkWidget *liste);
int substringutilis(char str1[], char str2[]);
void chercherutilisateur(GtkWidget *liste, char id4[]);
int utilisateur_chercher(char id[]);

utilisateur chercher_id(char id[]);
int checkRequiredAndAlpha(char *ch);
int checkid(char *ch);
int checkPassword(char *mdp);

