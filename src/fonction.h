#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
typedef struct
{

        int jour;
	int mois;
	int annee;


}date_rec;

typedef struct
{
	char Idliste [50];
        char Idreclamation[50];
         date_rec date;
        char type [100];
	char texte [1000];
	char justificatifs[20];
	char autres[1000]
	


}reclamation;

int consultation_reclamation();
void ajout_reclamation();
int afficher_reclamation();
void modification_t();
void supprimer_reclamation();
void afficher_rec_ONtreeview(GtkWidget *list,char file[20]);
void recherche_rec(char id[20]);

