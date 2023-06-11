#include "fon.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum
{
	ID,
	IDTETE,
	IDM1,
	IDM2,
	IDM3,
	ORI,
	NV,
	COLUMNS

};
void afficher(GtkWidget *liste)
{
	
             GtkCellRenderer *renderer;
	     GtkTreeViewColumn *column;
	     GtkTreeIter    iter;
	     GtkListStore *store;

	
	char id[10];
	char idtete[10];
	char idm1[10];
	char idm2[10];
	char idm3[10];
	char ori[50];
	char nv[10];
	store=NULL;
	store=gtk_tree_view_get_model(liste);
 if(store==NULL){
renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("idtete",renderer,"text",IDTETE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("idm1",renderer,"text",IDM1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("idm2",renderer,"text",IDM2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("idm3",renderer,"text",IDM3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("ori",renderer,"text",ORI,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	column=gtk_tree_view_column_new_with_attributes("nv",renderer,"text",NV,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

FILE *f=fopen("listes_electorales.txt","r");
if(f==NULL)
	{return;}
	else
	{
		f=fopen("listes_electorales.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s\n",id,idtete,idm1,idm2,idm3,ori,nv)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID,id,IDTETE,idtete,IDM1,idm1,IDM2,idm2,IDM3,idm3,ORI,ori,NV,nv,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}//hedhi te3 lvoid
