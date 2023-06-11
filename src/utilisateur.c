#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "utilisateur.h"
#include "callbacks.h"
#include <gtk/gtk.h>



enum
{ 
	EID,
	ENOM,
	EPRENOM,
	EMDP,
	EJOUR,
	EMOIS,
	EANNEE,
	ETYPEUTILISATEUR,
	ESEXE,
	COLUMNS,
};
void ajouter (utilisateur u )
{
    FILE * f=fopen("Utilisateur.txt", "a+");
    if(f!=NULL)
    {
      fprintf(f,"%s %s %s %s %s %d  %d  %d %s\n",u.nom,u.prenom,u.mdp,u.sexe,u.id,u.date.jour,u.date.mois,u.date.annee,u.typeutilisateur);
        fclose(f);
}
}
void affichageutilisateur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[30];
        char prenom[30];
	char mdp[30];	
	char jour[10];
	char mois[10];
	char annee[10];
        char id[8];
        char typeutilisateur[100];
	char sexe[20];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	f=fopen("utilisateur.txt","a+");
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mdp", renderer, "text",EMDP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
  
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type Utilisateur", renderer, "text",ETYPEUTILISATEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
	}
	f=fopen("Utilisateur.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("Utilisateur.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s  \n",nom,prenom,mdp,sexe,id,jour,mois,annee,typeutilisateur)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID,id, ENOM,nom, EMDP,mdp, ESEXE,sexe ,EPRENOM,prenom, EJOUR,jour, EMOIS,mois, EANNEE,annee,ETYPEUTILISATEUR,typeutilisateur , -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}


void modifier_utilis(utilisateur u1 )
{
    utilisateur u;
    FILE *f1;
    FILE *f2;
    f1=fopen("Utilisateur.txt", "r");
    f2=fopen("UTILIS.txt", "a");
    if((f1!=NULL) && (f2!=NULL))
    {
        while(fscanf(f1,"%s %s %s %s %s %d  %d  %d %s \n",u.nom,u.prenom,u.mdp,u.sexe,u.id,&u.date.jour,&u.date.mois,&u.date.annee,u.typeutilisateur)!=EOF)
        {
            if(strcmp(u.id,u1.id)==0)
            {
 fprintf(f2,"%s %s %s %s %s %d  %d  %d %s\n",u1.nom,u1.prenom,u1.mdp,u1.sexe,u1.id,u1.date.jour,u1.date.mois,u1.date.annee,u1.typeutilisateur);
                
            }
            else
{
                fprintf(f2,"%s %s %s %s %s %d  %d  %d %s\n",u.nom,u.prenom,u.mdp,u.sexe,u.id,u.date.jour,u.date.mois,u.date.annee,u.typeutilisateur);
}
        }
    }

    fclose(f1);
    fclose(f2);
    remove("Utilisateur.txt");
    rename("UTILIS.txt", "Utilisateur.txt");

}
void supprimer(  char id[])
{
utilisateur u;
GtkWidget *pInfo;
gpointer user_data;
FILE *f1, *f2;
f1=fopen("Utilisateur.txt","r");
f2=fopen("supprimer.txt","w");
if(f1!=NULL&&f2!=NULL){
	while(fscanf(f1,"%s %s %s %s %s %d  %d  %d %s \n",u.nom,u.prenom,u.mdp,u.sexe,u.id,&(u.date.jour),&(u.date.mois),&(u.date.annee),u.typeutilisateur)!=EOF)
	       {
		if((strcmp(id,u.id)!=0))
			fprintf(f2,"%s %s %s %s %s %d  %d  %d %s \n",u.nom,u.prenom,u.sexe,u.mdp,u.id,u.date.jour,u.date.mois,u.date.annee,u.typeutilisateur);
	        }
	

	fclose(f1);
	fclose(f2);
remove("Utilisateur.txt");
rename("supprimer.txt","Utilisateur.txt");
}
}




void chercherutilisateur(GtkWidget *liste, char id4[])
{

GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
        char nom[30];
        char prenom[30];
	char mdp[30];
	char jour[10];
	char mois[10];
	char annee[10];
        char id[8];
        char typeutilisateur[100];
	char sexe[20];
	


utilisateur u;

store=NULL;

FILE* f=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mdp", renderer, "text",EMDP,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
  
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type Utilisateur", renderer, "text",ETYPEUTILISATEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("Utilisateur.txt","r");
	if(f!=NULL)
	
	{
		
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s  \n",nom,prenom,mdp,sexe,id,jour,mois,annee,typeutilisateur)!=EOF)
		{if(substringutilis(id4,id))
{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID,id, ENOM,nom, EMDP,mdp, ESEXE,sexe ,EPRENOM,prenom, EJOUR,jour, EMOIS,mois, EANNEE,annee,ETYPEUTILISATEUR,typeutilisateur , -1);
		}
		}
fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
int substringutilis(char str1[], char str2[])
{
	int n1,n2,i,cmp = 0;
	n1 = strlen(str1);
	n2= strlen(str2);
	if (n1<=n2){
	for (i=0;i<n1;i++){
		if (str1[i] == str2[i]){
			cmp +=1;			
}
	}
	if (cmp == n1){
		return 1;
	}else{
		return 0;
	}
}else{
	return 0;
}
}

int utilisateur_chercher(char id1[])
{
	utilisateur u;
	int tr;
	FILE *f1;
	f1=fopen("Utilisateur.txt", "r");
	tr=0;
	if(f1!=NULL )
	{
		while(tr==0 && fscanf(f1,"%s %s %s %s %s %d %d %d %s  \n",u.nom,u.prenom,u.mdp,u.sexe,u.id,&u.date.jour,&u.date.mois,&u.date.annee,u.typeutilisateur)!=EOF){
			if(strcmp(u.id,id1)==0) tr=1; 
			else tr=0; }
	}
	fclose(f1);
	return tr;

}

int checkRequiredAndAlpha(char *ch){
    int i;
    if (strlen(ch) == 0) {
        return 0;
    }
    for (i = 0; i < strlen(ch); i++) {
        if (isalpha(ch[i]) == 0) return 0;
	  	    
}
 return 1;
}


int checkid(char *ch){
int i;
   if (strlen(ch) == 0) {
        return 0;
    }
    for (i = 0; i < strlen(ch); i++) {
        if (isdigit(ch[i]) == 0) {
            return 0;
        }
	}
   return 1;
}

int checkPassword(char *mdp){
    int i;
    int upper = 0;
    int lower = 0;
    int digit = 0;
    if (strlen(mdp)< 8 ) {
        return 0;
    }
    for (i = 0; i < strlen(mdp); i++) {
        if (isupper(mdp[i]) != 0) {
            upper = 1;
        }
        if (islower(mdp[i]) != 0) {
            lower = 1;
        }
        if (isdigit(mdp[i]) != 0) {
            digit = 1;
        }
    }
    if (upper == 1 && lower == 1 && digit == 1) {
        return 1;
    }
    return 0;
}

int verif(char id[], char Pw[])
{
int trouve=0;
FILE* f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
int d1[20];
int d2[20];
int d3[20];
char ch6[20];
f=fopen("Utilisateur.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %d %d %d %s  \n",ch1,ch2,ch3,ch4,ch5,d1,d2,d3,ch6)!=EOF)
{
if((strcmp(ch5,id)==0) && (strcmp(ch3,Pw)==0))
{
trouve=1;
break;
}
}
fclose(f);
}
return trouve;
}












