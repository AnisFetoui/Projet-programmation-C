#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BureauVote.h"
#include "callbacks.h"
#include <gtk/gtk.h>




//////////////////////////Fonction Ajouter//////////////////////////
void ajouterbureau(bureau bv,char *filename)
{
GtkWidget *pQuestion, *pInfo;
FILE *f;
int i=0;
gpointer user_data;
bureau b;
f=fopen(filename,"a");
if(f!=NULL)
{	while(fscanf(f,"%s %d %d %s %s\n",b.idbureau,&b.capelec,&b.capobs,b.adr,b.idagentb)!=EOF)
	{
		
	if(strcmp(bv.idbureau,b.idbureau)==0)
		i++;
	}
	if(i==0){
	fprintf(f,"%s %d %d %s %s\n",bv.idbureau,bv.capelec,bv.capobs,bv.adr,bv.idagentb);	pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Bureau ajouté avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pQuestion);
	break;
	}
	}
	if(i!=0){
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"ID doit etre unique !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	fclose(f);
}
}
//////////////////////////Fonction Modifier/////////////////////////
void modifierbureau(bureau bv, char *filename)
{
bureau b;
FILE *f, *f2;
f=fopen(filename,"r");
f2=fopen("dump1.txt","w");
if(f!=NULL && f2!=NULL)
{
	while(fscanf(f,"%s %d %d %s %s\n",b.idbureau,&b.capelec,&b.capobs,b.adr,b.idagentb)!=EOF)
	{
		if(strcmp(b.idbureau,bv.idbureau)!=0)
			fprintf(f2,"%s %d %d %s %s\n",b.idbureau,b.capelec,b.capobs,b.adr,b.idagentb);
		else
			fprintf(f2,"%s %d %d %s %s\n",bv.idbureau,bv.capelec,bv.capobs,bv.adr,bv.idagentb);
	}
	
	fclose(f);
	fclose(f2);
remove(filename);
rename("dump1.txt",filename);
}
}
//////////////////////////Fonction Supprimer//////////////////////////
void supprimerbureau(bureau bv, char *filename)
{
bureau b;

FILE *f, *g;
f=fopen(filename,"r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%s %d %d %s %s\n",b.idbureau,&b.capelec,&b.capobs,b.adr,b.idagentb)!=EOF)
	{
		if(strcmp(b.idbureau,bv.idbureau)!=0)
			fprintf(g,"%s %d %d %s %s\n",b.idbureau,b.capelec,b.capobs,b.adr,b.idagentb);
		
	}
	
	fclose(f);
	fclose(g);
remove(filename);
rename("dump.txt",filename);
}
}
//////////////////////////Fonction Affichage//////////////////////////
void afficherbureau(GtkWidget *liste)
{
bureau p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;

FILE *f=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Identifiant", renderer,"text",IDBV, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité electeurs", renderer,"text",CAPELEC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité observateurs", renderer,"text",CAPOBS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Adresse", renderer,"text",ADRESSE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID Agent", renderer,"text",IDAGENT, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("bv.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %d %d %s %s\n",p.idbureau,&(p.capelec),&(p.capobs),p.adr,p.idagentb)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,IDBV,p.idbureau,CAPELEC,p.capelec,CAPOBS,p.capobs,ADRESSE,p.adr,IDAGENT,p.idagentb,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

void chercherbureau(GtkWidget *liste, char id[])
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

bureau p;

store=NULL;

FILE* f=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Identifiant", renderer,"text",IDBV, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité electeurs", renderer,"text",CAPELEC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Capacité observateurs", renderer,"text",CAPOBS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Adresse", renderer,"text",ADRESSE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID Agent", renderer,"text",IDAGENT, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("bv.txt","r");
if(f!=NULL)
{      
while(fscanf(f,"%s %d %d %s %s\n",p.idbureau,&(p.capelec),&(p.capobs),p.adr,p.idagentb)!=EOF)
{
if(substringbureau(id,p.idbureau))
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,IDBV,p.idbureau,CAPELEC,p.capelec,CAPOBS,p.capobs,ADRESSE,p.adr,IDAGENT,p.idagentb,-1);
}
}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

int substringbureau(char str1[], char str2[])
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


