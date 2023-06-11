#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<gtk/gtk.h>

typedef struct 
{
char idbureau[20];
int capelec;
int capobs;
char adr[30];  
char idagentb[20];
} bureau ;

enum
{
	IDBV,
	CAPELEC,
	CAPOBS,
	ADRESSE,
	IDAGENT,
	COLUMNS,
};



void ajouterbureau(bureau bv,char *filename);
void modifierbureau(bureau bv,char *filename);
void supprimerbureau(bureau bv,char *filename);


int substringbureau(char str1[], char str2[]);
void chercherbureau(GtkWidget *liste, char id[]);
void afficherbureau(GtkWidget *liste);

