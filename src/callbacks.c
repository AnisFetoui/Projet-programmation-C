#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include "fon.h"
#include <gtk/gtk.h>
#include "utilisateur.h"
#include "fonction.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdlib.h>
#include <string.h>
#include "BureauVote.h"
int x;
int xx=1;
int yy=1;
int y=1;
int z,k=1,l=1,m=1,w=1;
int aa=1,zz=1,ee=1;
int x1,t,z1;

int affichage_init=0;
int affichage_tree = 0;
char ID[50]="";
int affichage_tree5 = 0;
char Idbureau[50]="";
int accept;
int choix=0;


//////////////////////anis/////////////////////

void
on_radiobutton_ajout_Utilis1_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=0;}
}

void
on_radiobutton_ajout_Utilis2_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}

void
on_checkbutton_utilis_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=0;}
}


void
on_Annuler_ajout_Utilis_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowajout;
windowajout=lookup_widget(button,"Ajout_gest_Utilis");
gtk_widget_destroy(windowajout);
}


void
on_quitter12_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"Ajout_gest_Utilis");
gtk_widget_destroy(windowsup);
window2=create_Connexion();
gtk_widget_show (window2);
}

void
on_Supprimer_gest_utilis_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup;
windowsup=create_Supprimer_gest_Utilis();
gtk_widget_show (windowsup);
}

void
on_radiobutton_modifie_Utilis1_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=0;}
}


void
on_radiobutton_modifie_Utilis2_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_quitter13_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"Modifie_gest_Utilis");
gtk_widget_destroy(windowsup);
window2=create_Connexion();
gtk_widget_show (window2);
}




void
on_Enregistrer_modifie_Utilis_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

utilisateur u1;
GtkWidget *windowmodif, *windowaffich,*label_modi,*label_nom1,*label_pre1,*label_mdp1,*nom1,*prenom1,*jour1,*mois1,*annee1,*typeutilis1,*sexe1,*id1,*mdp1;
windowmodif= create_Modifie_gest_Utilis();
windowaffich= create_Gestion_Utilisateur();
typeutilis1= lookup_widget(button,"combobox_modifie_Utils");
mdp1= lookup_widget(button,"entry_mdp_modifie_Utilis");
nom1= lookup_widget(button,"entry_Nom_modifie_Utilis");
prenom1= lookup_widget(button,"entry_prenom_modifie_Utilis");
id1= lookup_widget(button,"entry_ID_modifie_Utilis");
jour1= lookup_widget(button,"jour_modifie_Utilis");
mois1= lookup_widget(button,"mois_modifie_Utilis");
annee1= lookup_widget(button,"annee_modifie_Utilis");
label_modi =lookup_widget(button,"label_modi");
label_nom1 =lookup_widget(button,"label_nom1");
label_pre1 =lookup_widget(button,"label_pre1");
label_mdp1 =lookup_widget(button,"label_mdp1");
strcpy(u1.typeutilisateur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(typeutilis1)));
strcpy(u1.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(u1.mdp,gtk_entry_get_text(GTK_ENTRY(mdp1)));
strcpy(u1.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(u1.id,gtk_entry_get_text(GTK_ENTRY(id1)));
u1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
u1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
u1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
if(z==1 )
{strcpy(u1.sexe,"Femme");} 
else
{strcpy(u1.sexe,"Homme");} 
z=0;

if(utilisateur_chercher(u1.id)==1){
	aa=checkRequiredAndAlpha(u1.nom);
	zz=checkRequiredAndAlpha(u1.prenom);
	ee=checkPassword(u1.mdp);
	if (aa == 0) {
     gtk_label_set_text(GTK_LABEL(label_nom1),"Veuillez réessayer");
        }
	else if (aa == 1) {
	
     gtk_label_set_text(GTK_LABEL(label_nom1),"");
	
        }
	if (zz == 0) {
	
     gtk_label_set_text(GTK_LABEL(label_pre1),"Veuillez réessayer");
	
        }
	else if (zz == 1) {
	
     gtk_label_set_text(GTK_LABEL(label_pre1),"");
	
        }
	
	
	if(ee==0){
	gtk_label_set_text(GTK_LABEL(label_mdp1),"mdp n'est pas fort");}
	else if(ee==1){
	gtk_label_set_text(GTK_LABEL(label_mdp1),"");}
	
	if(aa==1 && zz==1 && ee==1 ){
	modifier_utilis(u1);
	gtk_label_set_text(GTK_LABEL(label_modi),"Modifcation avec succes");
	}
	else if(aa==0 || zz==0 || ee==0 ) {gtk_label_set_text(GTK_LABEL(label_modi),"");}

	
	
}
else
	{gtk_label_set_text(GTK_LABEL(label_modi),"utilisateur n'existe pas");}

windowmodif=lookup_widget(button,"Modifie_gest_Utilis");
gtk_widget_show(windowmodif);

}


void
on_Annuler_modifie_Utils_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup;
windowsup=lookup_widget(button,"Modifie_gest_Utilis");
gtk_widget_destroy(windowsup);
}


void
on_Recherche_utilis_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Quitter_utilis_1_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"Gestion_Utilisateur");
gtk_widget_destroy(windowsup);
window2=create_Connexion();
gtk_widget_show (window2);
}


void
on_Modifier_gest_utilis_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowaffich;
windowaffich=create_Modifie_gest_Utilis();
gtk_widget_show (windowaffich);
}


void
on_treeview_gest_utilis_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* prenom;
gchar* mdp;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* typeutilis;
gchar* sexe;
utilisateur u;


GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(GTK_LIST_STORE(model),&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&mdp,4,&jour,5,&mois,6,&annee,7,&typeutilis,8,&sexe,-1);
}
}
void
on_supprimer_utilis_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
char idutilis2[20];
GtkTreeIter iter;
GtkWidget *windowsupprim, *windowaffich,*id2,*pInfo,*tree;
id2 = lookup_widget(button,"entry_supp_utilis");
windowsupprim=create_Supprimer_gest_Utilis();
windowaffich=create_Gestion_Utilisateur();

	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer utilisateur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	{gtk_widget_destroy(pInfo);
        strcpy(idutilis2,gtk_entry_get_text(GTK_ENTRY(id2)));
        supprimer(idutilis2);
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
windowsupprim=lookup_widget(button,"Supprimer_gest_Utilis");
gtk_widget_destroy(windowsupprim);
windowaffich=create_Gestion_Utilisateur();
}

void
on_entry_recherche_ges_utilis_changed  (GtkEditable     *editable,
                                        gpointer         user_data)
{
GtkWidget *rech;
char id2[20];

GtkWidget *tree3;
tree3=  lookup_widget(editable,"treeview_gest_utilis");
rech= lookup_widget(GTK_WIDGET(editable),"entry_recherche_ges_utilis");
strcpy(id2,gtk_entry_get_text(GTK_ENTRY(rech)));
chercherutilisateur(tree3,id2);
}

gboolean
on_Gestion_Utilisateur_activate_focus  (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{if (affichage_tree==0)
{
strcpy(ID,"");
GtkWidget *tree;
tree =  lookup_widget(widget,"treeview_gest_utilis");
affichageutilisateur(tree);

}
affichage_tree = 1;
  return FALSE;
}


void
on_Ajouter_ajout_Utilis_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

utilisateur u;
GtkWidget *windowajout,*tree, *windowaffich,*id,*nom,*prenom,*mdp,*jour,*mois,*annee,*typeutilis,*Sexe,*label_aj,*label_nom,*label_pre,*label_id,*label_mdp;
windowajout=create_Ajout_gest_Utilis();
windowaffich=create_Gestion_Utilisateur();
typeutilis = lookup_widget(button,"combobox_ajout_utilis");
mdp = lookup_widget(button,"mdp_ajout_utilis");
nom = lookup_widget(button,"nom_ajout_utilis");
prenom = lookup_widget(button,"prenom_ajout_utilis");
id = lookup_widget(button,"id_ajout_utilis");
jour = lookup_widget(button,"jour_ajout_utilis");
mois = lookup_widget(button,"mois_ajout_utilis");
annee = lookup_widget(button,"annee_ajout_utilis");
label_aj =lookup_widget(button,"label_aj");
label_nom =lookup_widget(button,"label_nom");
label_pre =lookup_widget(button,"label_pre");
label_id =lookup_widget(button,"label_id");
label_mdp =lookup_widget(button,"label_mdp");
strcpy(u.typeutilisateur,gtk_combo_box_get_active_text(GTK_COMBO_BOX(typeutilis)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(id)));
u.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
u.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
u.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
if(x==1)
{strcpy(u.sexe,"Femme");} 
else
{strcpy(u.sexe,"Homme");} 

x=0;
tree=lookup_widget(windowaffich,"treeview_gest_utilis");
if (y==0)
{
	if(utilisateur_chercher(u.id)==1)  {
	gtk_label_set_text(GTK_LABEL(label_aj),"Nom d'utilisateur existe déjà");
	}
	else if (utilisateur_chercher(u.id)==0)
	{
	k=checkRequiredAndAlpha(u.nom);
	l=checkRequiredAndAlpha(u.prenom);
	m=checkid(u.id);
	w=checkPassword(u.mdp);
	if (k == 0) {
     gtk_label_set_text(GTK_LABEL(label_nom)," Veuillez réessayer");
        }
	else if (k == 1) {
	
     gtk_label_set_text(GTK_LABEL(label_nom),"");
	
        }
	if (l == 0) {
	
     gtk_label_set_text(GTK_LABEL(label_pre),"Veuillez réessayer");
	
        }
	else if (l == 1) {
	
     gtk_label_set_text(GTK_LABEL(label_pre),"");
	
        }
	if (m == 0){

	gtk_label_set_text(GTK_LABEL(label_id),"l'id doit contenir des chiffres");
	}
	else if (m == 1){
	gtk_label_set_text(GTK_LABEL(label_id),"");
	}
	
	if(w==0){
	gtk_label_set_text(GTK_LABEL(label_mdp),"mdp n'est pas fort");}
	else if(w==1){
	gtk_label_set_text(GTK_LABEL(label_mdp),"");}
	
	if(k==1 && l==1 && m==1 && w==1){
	ajouter(u);
	gtk_label_set_text(GTK_LABEL(label_aj),"ajout reussit");
	}
	else if(k==0 || l==0 || m==0 || w==0) {gtk_label_set_text(GTK_LABEL(label_aj),"");}
	
}

}

	else if(y==1){ gtk_label_set_text(GTK_LABEL(label_aj),"Il faut d'abord accepter les termes");}

windowajout=lookup_widget(button,"Ajout_gest_Utilis");
gtk_widget_show(windowajout);
}



void
on_Actualiser_gest_utilis_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *tree,*windowaffich;
windowaffich=lookup_widget(button,"Gestion_Utilisateur");
gtk_widget_destroy(windowaffich);
windowaffich=create_Gestion_Utilisateur();
tree=lookup_widget(windowaffich,"treeview_gest_utilis");

affichageutilisateur(tree);

gtk_widget_hide(windowaffich);
gtk_widget_show(windowaffich);

}


void
on_Ajouter_aff_gest_utilis_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout ;
windowajout=create_Ajout_gest_Utilis();
gtk_widget_show (windowajout);
}


void
on_ann_supp_utilis_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup;
windowsup=lookup_widget(button,"Supprimer_gest_Utilis");
gtk_widget_destroy(windowsup);

}


void
on_Butoon_con_utilis_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*password,*window2, *windowAdmin , *label_con;
char id1[20];
char pasw[20];
int trouve =0 ;
id = lookup_widget (button, "entry_id_con");
password = lookup_widget (button, "entry_mdp_con");

strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(id1,pasw);

if (trouve==1)
{

window2=create_Menu();
gtk_widget_show (window2);
}
else if (trouve ==0) 
{

label_con =lookup_widget(button,"label_con");
gtk_label_set_text(GTK_LABEL(label_con),"Utilisateur non trouvé");
}


}


void
on_button_gesadmin_menu_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"Menu");
gtk_widget_destroy(windowsup);
window2=create_Gestion_Utilisateur();
gtk_widget_show (window2);
}


void
on_button_gesobs_menu_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"gestionobservateur");
gtk_widget_destroy(windowsup);
window2=create_Menu();
gtk_widget_show (window2);*/
}


void
on_button_geselec_menu_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"election");
gtk_widget_destroy(windowsup);
window2=create_Menu();
gtk_widget_show (window2);*/
}


void
on_button_ret_ges_utilis_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"Gestion_Utilisateur");
gtk_widget_destroy(windowsup);
window2=create_Menu();
gtk_widget_show (window2);
}


void
on_button_geslisteelec_menu_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"Menu");
gtk_widget_destroy(windowsup);
window2=create_LE_acceuil_gma();
gtk_widget_show (window2);
}


void
on_button_gesrec_menu_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"Menu");
gtk_widget_destroy(windowsup);
window2=create_I1_R__clamation();//tee imen
gtk_widget_show (window2);
}


void
on_button_gesbv_menu_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsup, *window2;
windowsup=lookup_widget(button,"Menu");
gtk_widget_destroy(windowsup);
window2=create_Gestion_BV();//tee amine
gtk_widget_show (window2);
}


////////////////////aziz//////////////////////////////

void
on_button_vo_gma_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *LE_acceuil_gma;
  GtkWidget *LE_pagevote_gma;
  LE_acceuil_gma = lookup_widget(button, "LE_acceuil_gma");
  gtk_widget_hide (LE_acceuil_gma);
  LE_pagevote_gma = create_LE_pagevote_gma ();
  gtk_widget_show (LE_pagevote_gma);
}


void
on_button_md_gma_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *LE_acceuil_gma;
  GtkWidget *LE_Pmodifier_gma;
  LE_acceuil_gma = lookup_widget(button, "LE_acceuil_gma");
  gtk_widget_hide (LE_acceuil_gma);
  LE_Pmodifier_gma = create_LE_Pmodifier_gma ();
  gtk_widget_show (LE_Pmodifier_gma);
}


void
on_button_aj_gma_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *LE_acceuil_gma;
  GtkWidget *Le_Pajout_gma;
  LE_acceuil_gma = lookup_widget(button, "LE_acceuil_gma");
  gtk_widget_hide (LE_acceuil_gma);
  Le_Pajout_gma = create_Le_Pajout_gma ();
  gtk_widget_show (Le_Pajout_gma);
}


void
on_button_sup_gma_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *LE_acceuil_gma;
  GtkWidget *LE_Psupp_gma;
  LE_acceuil_gma = lookup_widget(button, "LE_acceuil_gma");
  gtk_widget_hide (LE_acceuil_gma);
  LE_Psupp_gma = create_LE_Psupp_gma ();
  gtk_widget_show (LE_Psupp_gma);
}


void
on_button_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton_novote_gma_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_deja_gma_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton_vb_gma_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button_vote_gma_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int a;
int tr=0;
int valeur;
char ch[50]="vote enregistrer avec succée pour La liste ";
char ch1[10];
el nouv;
el anc;
GtkWidget *nour=lookup_widget(objet_graphique,"spinbutton_num_gma");
GtkWidget *label = lookup_widget(GTK_WIDGET(objet_graphique), "label42_gma");
GtkWidget *label2 = lookup_widget(GTK_WIDGET(objet_graphique), "label1011_gma");
valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (nour));
if(valeur==-1)
	{gtk_label_set_text( GTK_LABEL(label),"aucun vote enregistrer");}
else{
sprintf(ch1,"%d",valeur);
strcat(ch,ch1);



    FILE *f=fopen("listes_electorales.txt","r");
    FILE *f2=fopen("nouv.txt","w");
	    if(f!=NULL )
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n",anc.id,anc.idtete,anc.idm1,anc.idm2,anc.idm3,anc.ori,anc.nv)!=EOF)
        {
            if(strcmp(anc.id,ch1)==0)
            {  
		
		a=atoi(anc.nv);
		a=a+1;
		sprintf(nouv.nv,"%d",a);
		fprintf(f2,"%s %s %s %s %s %s %s\n",anc.id,anc.idtete,anc.idm1,anc.idm2,anc.idm3,anc.ori,nouv.nv);
		tr=1;
		


		
            }
	    else{
		fprintf(f2,"%s %s %s %s %s %s %s\n",anc.id,anc.idtete,anc.idm1,anc.idm2,anc.idm3,anc.ori,anc.nv);
		
                }

        }
if(tr==1){gtk_label_set_text( GTK_LABEL(label),ch);}
else{gtk_label_set_text( GTK_LABEL(label),"veuiller verifier numer de la liste ");}
    
    }
    fclose(f);
    fclose(f2);
    remove("listes_electorales.txt");
    rename("nouv.txt","listes_electorales.txt");
}


}

void
on_button_ac_gma_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *LE_pagevote_gma;
  GtkWidget *Le_Pajout_gma;
  GtkWidget *LE_Pmodifier_gma;
  GtkWidget *LE_Psupp_gma;
  GtkWidget *LE_recherche_gma;
  LE_pagevote_gma = lookup_widget(button, "LE_pagevote_gma");
  Le_Pajout_gma = lookup_widget(button, "Le_Pajout_gma");
  LE_Pmodifier_gma = lookup_widget(button, "LE_Pmodifier_gma");
  LE_Psupp_gma = lookup_widget(button, "LE_Psupp_gma");
  LE_recherche_gma = lookup_widget(button, "LE_recherche_gma");
  
  gtk_widget_hide (LE_pagevote_gma);
  gtk_widget_hide (Le_Pajout_gma);
  gtk_widget_hide (LE_Pmodifier_gma);
  gtk_widget_hide (LE_Psupp_gma);
  gtk_widget_hide (LE_recherche_gma);
  	
  GtkWidget *LE_acceuil_gma;
  LE_acceuil_gma = create_LE_acceuil_gma ();
  gtk_widget_show (LE_acceuil_gma);
}


void
on_button_save_gma_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  el l;
  gchar ch[45]="liste ajouter avec succée!!!";
  
  GtkWidget *label = lookup_widget(GTK_WIDGET(button), "label37_gma");
  GtkWidget *entry = lookup_widget(GTK_WIDGET(button), "entry_id_gma");
  strcpy(l.id,gtk_entry_get_text(GTK_ENTRY(entry)) );
  GtkWidget *entry1 = lookup_widget(GTK_WIDGET(button), "entry_idt_gma");
  strcpy(l.idtete,gtk_entry_get_text(GTK_ENTRY(entry1)) );
  GtkWidget *entry2 = lookup_widget(GTK_WIDGET(button), "entry_m1_gma");
  strcpy(l.idm1,gtk_entry_get_text(GTK_ENTRY(entry2)) );
  GtkWidget *entry3 = lookup_widget(GTK_WIDGET(button), "entry_m2_gma");
  strcpy(l.idm2,gtk_entry_get_text(GTK_ENTRY(entry3)) );
  GtkWidget *entry4 = lookup_widget(GTK_WIDGET(button), "entry_m3_gma");
  strcpy(l.idm3,gtk_entry_get_text(GTK_ENTRY(entry4)) );
  


strcpy(l.nv,"0");
 if(xx==1)
{strcpy(l.ori,"gauche");}
else if(xx==2)
{strcpy(l.ori,"centre");}
else if(xx==3)
{strcpy(l.ori,"droite");}

	


FILE *f=fopen("listes_electorales.txt","a");
    if(f!=NULL)
    {
	fprintf(f,"%s %s %s %s %s %s %s\n",l.id,l.idtete,l.idm1,l.idm2,l.idm3,l.ori,l.nv);
        fclose(f);}
	gtk_label_set_text( GTK_LABEL(label),ch);
}


void
on_radiobutton3_dr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{xx=3;}
}


void
on_radiobutton2_ce_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{xx=2;}
}


void
on_radiobutton1_ga_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{xx=1;}
}


void
on_radiobutton_md_gma_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{yy=3;}
}


void
on_radiobutton_mc_gma_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{yy=2;}
}


void
on_button_modi_gma_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  int tr=0;
  char id[10];
  el nouv;
  el anc;
    
  GtkWidget *output =lookup_widget(button, "label40_gma");
  GtkWidget *entry = lookup_widget(GTK_WIDGET(button), "entry_idlm_gma");
  GtkWidget *entry1 = lookup_widget(GTK_WIDGET(button), "entry_idtm_gma");
  GtkWidget *entry2 = lookup_widget(GTK_WIDGET(button), "entry_m1m_gma");
  GtkWidget *entry3 = lookup_widget(GTK_WIDGET(button), "entry_m2m_gma");
  GtkWidget *entry4 = lookup_widget(GTK_WIDGET(button), "entry_m3m_gma");
  
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));
 if(yy==1)
{strcpy(nouv.ori,"gauche");}
else 
if(yy==2)
{strcpy(nouv.ori,"centre");}
else 
if(yy==3)
{strcpy(nouv.ori,"droite");}

strcpy(nouv.id,gtk_entry_get_text(GTK_ENTRY(entry)));
strcpy(nouv.idtete,gtk_entry_get_text(GTK_ENTRY(entry1)));
strcpy(nouv.idm1,gtk_entry_get_text(GTK_ENTRY(entry2)));
strcpy(nouv.idm2,gtk_entry_get_text(GTK_ENTRY(entry3)));
strcpy(nouv.idm3,gtk_entry_get_text(GTK_ENTRY(entry4)));
strcpy(nouv.nv,"0");

    FILE *f=fopen("listes_electorales.txt","r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL )
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n",anc.id,anc.idtete,anc.idm1,anc.idm2,anc.idm3,anc.ori,anc.nv)!=EOF)
        {
            if(strcmp(anc.id,id)==0)
            {  
		fprintf(f2,"%s %s %s %s %s %s %s\n",nouv.id,nouv.idtete,nouv.idm1,nouv.idm2,nouv.idm3,nouv.ori,nouv.nv); 
		tr=1;
            }
	    else{
		fprintf(f2,"%s %s %s %s %s %s %s\n",anc.id,anc.idtete,anc.idm1,anc.idm2,anc.idm3,anc.ori,anc.nv);
                }

        }
    }
    fclose(f);
    fclose(f2);
    remove("listes_electorales.txt");
    rename("nouv.txt","listes_electorales.txt");
  if(tr==1)
  {gtk_label_set_text( GTK_LABEL(output),"liste modifié avec succée");}
  else
  {gtk_label_set_text( GTK_LABEL(output),"veuillez verifié id de la liste");}


}


void
on_button_supp_gma_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  char id[10];
  int tr=0;
  el l;
  GtkWidget *output =lookup_widget(button, "label41_gma");
  GtkWidget *entry = lookup_widget(GTK_WIDGET(button), "entry_idlsupp_gma");
  
   strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));
   FILE *f=fopen("listes_electorales.txt","r");
   FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {	
	while(fscanf(f,"%s %s %s %s %s %s %s\n",l.id,l.idtete,l.idm1,l.idm2,l.idm3,l.ori,l.nv)!=EOF)
        {
            if(strcmp(l.id,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %s %s\n",l.id,l.idtete,l.idm1,l.idm2,l.idm3,l.ori,l.nv);
        }
    }
    fclose(f);
    fclose(f2);
    remove("listes_electorales.txt");
    rename("nouv.txt","listes_electorales.txt");
  if(tr==1)
  {gtk_label_set_text( GTK_LABEL(output),"liste supprimé avec succée");}
  else
  {gtk_label_set_text( GTK_LABEL(output),"veuillez verifié id de la liste");}
}


void
on_radiobutton_mg_gma_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{yy=1;}
}


void
on_treeview2_gma_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* idtete;
gchar* idm1;
gchar* idm2;
gchar* idm3;
gchar* ori;
gchar* nv;
el l;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&idtete,2,&idm1,3,&idm2,4,&idm3,5,&ori,6,&nv,-1);

afficher(treeview);
}
}


void
on_button1_ref_gma_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *LE_recherche_gma;
GtkWidget *w;
GtkWidget *treeview2_gma;

w=lookup_widget(objet,"LE_recherche_gma");
LE_recherche_gma=create_LE_recherche_gma();

gtk_widget_show(LE_recherche_gma);
gtk_widget_hide(w);

treeview2_gma=lookup_widget(LE_recherche_gma,"treeview2_gma");

afficher(treeview2_gma);
}


void
on_button_findliste_gma_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *LE_acceuil_gma;
GtkWidget *LE_recherche_gma;
GtkWidget *treeview2_gma;
LE_acceuil_gma=lookup_widget(objet,"LE_acceuil_gma");
gtk_widget_destroy(LE_acceuil_gma);

LE_recherche_gma=lookup_widget(objet,"LE_recherche_gma");
LE_recherche_gma=create_LE_recherche_gma();
gtk_widget_show(LE_recherche_gma);

treeview2_gma=lookup_widget(LE_recherche_gma,"treeview2_gma");
afficher(treeview2_gma);

}


void
on_button1_quitte_gma_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *LE_acceuil_gma;
GtkWidget *window2;
LE_acceuil_gma=lookup_widget(button,"LE_acceuil_gma");
gtk_widget_destroy(LE_acceuil_gma);
window2=create_Connexion();
gtk_widget_show(window2);
}


void
on_button2_retour_gma_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *LE_acceuil_gma;
GtkWidget *window2;
LE_acceuil_gma=lookup_widget(button,"LE_acceuil_gma");
gtk_widget_destroy(LE_acceuil_gma);
window2=create_Menu();
gtk_widget_show(window2);

}

/////////////callbacks imen///////////////////////////
void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdisplay,*windowadd;
	windowadd=lookup_widget(button,"I2_R__clamation");
	windowdisplay=lookup_widget(button,"I1_R__clamation");
	gtk_widget_destroy(windowdisplay);
	windowadd=create_I2_R__clamation();
	gtk_widget_show(windowadd);
}


void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdisplay,*windowadd,*treeview;
	windowadd=lookup_widget(button,"I1_R__clamation");
	windowdisplay=lookup_widget(button,"I3_R__clamation");
	gtk_widget_destroy(windowadd);
	windowdisplay=create_I3_R__clamation();
	gtk_widget_show(windowdisplay);
	treeview=lookup_widget(windowdisplay,"treeview4");
	afficher_rec_ONtreeview(treeview,"rec.txt");
}


void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdisplay,*windowadd;
	windowadd=lookup_widget(button,"I1_R__clamation");
	windowdisplay=lookup_widget(button,"I3_R__clamation");
	gtk_widget_destroy(windowdisplay);
	windowadd=create_I1_R__clamation();
	gtk_widget_show(windowadd);
}


void
on_button47_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdisplay,*windowadd;
	windowadd=lookup_widget(button,"I5_R__clamation");
	windowdisplay=lookup_widget(button,"I3_R__clamation");
	gtk_widget_destroy(windowdisplay);
	windowadd=create_I5_R__clamation();
	gtk_widget_show(windowadd);
}


void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdisplay,*windowadd;
	windowadd=lookup_widget(button,"I6_R__clamation");
	windowdisplay=lookup_widget(button,"I3_R__clamation");
	gtk_widget_destroy(windowdisplay);
	windowadd=create_I6_R__clamation();
	gtk_widget_show(windowadd);
}



void
on_button53_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdisplay,*windowadd,*treeview;
	windowadd=lookup_widget(button,"I3_R__clamation");
	windowdisplay=lookup_widget(button,"I6_R__clamation");
	gtk_widget_destroy(windowdisplay);
	windowadd=create_I3_R__clamation();
	gtk_widget_show(windowadd);
	treeview=lookup_widget(windowadd,"treeview4");
	afficher_rec_ONtreeview(treeview,"rec.txt");
}


void
on_button52_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char id[30];
char type[30];
GtkWidget *input1;
GtkWidget *input2;
input1= lookup_widget(button, "entry_supp_rec");
strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
if (x1==1)
supprimer_reclamation(id);
}


void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdisplay,*windowadd;
	windowadd=lookup_widget(button,"I1_R__clamation");
	windowdisplay=lookup_widget(button,"I2_R__clamation");
	gtk_widget_destroy(windowdisplay);
	windowadd=create_I1_R__clamation();
	gtk_widget_show(windowadd);
}


void
on_button50_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdisplay,*windowadd,*treeview;
	windowadd=lookup_widget(button,"I3_R__clamation");
	windowdisplay=lookup_widget(button,"I5_R__clamation");
	gtk_widget_destroy(windowdisplay);
	windowadd=create_I3_R__clamation();
	gtk_widget_show(windowadd);
	treeview=lookup_widget(windowadd,"treeview4");
	afficher_rec_ONtreeview(treeview,"rec.txt");
}


void
on_button51_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *id,*m,*d,*day,*month,*year,*autre,*type;
	reclamation k;
	id=lookup_widget(button,"rec_modif_idliste");
	m=lookup_widget(button,"rec_modif_idrec");
	d=lookup_widget(button,"entry14");
 	autre=lookup_widget(button,"entry15");
	day=lookup_widget(button,"spinbutton16");
	month=lookup_widget(button,"spinbutton17");
	year=lookup_widget(button,"spinbutton18");
	type=lookup_widget(button,"comboboxentry18");
	strcpy(k.Idliste,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(k.Idreclamation,gtk_entry_get_text(GTK_ENTRY(m)));
	strcpy(k.texte,gtk_entry_get_text(GTK_ENTRY(d)));
	strcpy(k.autres,gtk_entry_get_text(GTK_ENTRY(autre)));
	k.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
	k.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
	k.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
	if(strcmp("contester",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
	strcpy(k.type,"contester");
	else 		  
	if(strcmp("correction",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
	strcpy(k.type,"correction");
	else 		  
	if(strcmp("rejet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
	strcpy(k.type,"rejet");
	else
	strcpy(k.type,"autres");
	if (t==2)
        strcpy(k.justificatifs,"photos");
        else if (t==1)
        strcpy(k.justificatifs,"Témoignages");
        else 
        strcpy(k.justificatifs,"autres");

       
	modification_t(k.Idliste,k);
	

}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*m,*d,*day,*month,*year,*autre,*type;
	reclamation h;
	id=lookup_widget(button,"rec_id_liste");
	m=lookup_widget(button,"rec_id_rec");
	d=lookup_widget(button,"entry12");
 	autre=lookup_widget(button,"entry16");
	day=lookup_widget(button,"spinbutton13");
	month=lookup_widget(button,"spinbutton14");
	year=lookup_widget(button,"spinbutton15");
	type=lookup_widget(button,"comboboxentry15");
	strcpy(h.Idliste,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(h.Idreclamation,gtk_entry_get_text(GTK_ENTRY(m)));
	strcpy(h.texte,gtk_entry_get_text(GTK_ENTRY(d)));
	strcpy(h.autres,gtk_entry_get_text(GTK_ENTRY(autre)));
	h.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
	h.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
	h.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
	if(strcmp("contester",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
	strcpy(h.type,"contester");
	else 		  
	if(strcmp("correction",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
	strcpy(h.type,"correction");
	else 		  
	if(strcmp("rejet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
	strcpy(h.type,"rejet");
	else
	strcpy(h.type,"autres");

	if (z1==2)
        strcpy(h.justificatifs,"photos");
        else if (z1==1)
        strcpy(h.justificatifs,"Témoignages");
        else 
        strcpy(h.justificatifs,"autres");

       
	ajout_reclamation(h);
	
}

void
on_checkbutton22_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
z1 = 2;
}

void
on_checkbutton23_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
z1 = 1;
}

void
on_checkbutton24_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
z1 = 3;
}



void
on_checkbutton32_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
t = 1;
}


void
on_checkbutton31_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
t = 2;
}


void
on_checkbutton33_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
t= 3;
}


void
on_radiobutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{ if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	x1=1;

}


void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{ if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	x1=2;

}


void
on_button_rech_rec_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *id;
	char id1[30];
	id=lookup_widget (button,"entry_rech_rec");
	strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
	GtkWidget *windowdisplay;
	GtkWidget *treeview;
	windowdisplay=lookup_widget(button,"I3_R__clamation");	
	treeview=lookup_widget(windowdisplay,"treeview4");
	if(strcmp(id1,"")!=0)
	{
		recherche_rec(id1);
		afficher_rec_ONtreeview(treeview,"search.txt");
		remove("search.txt");
	}
	else
		afficher_rec_ONtreeview(treeview,"rec.txt");
}


void
on_button54_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{}

////////////////////////amin////////////////////////////



void
on_Enregistrer_ajout_BV_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{
bureau p;

GtkWidget* input1 ;
GtkWidget* input2 ;
GtkWidget* input3 ;
GtkWidget* input4 ;
GtkWidget* input5 ;
GtkWidget* checkbutton_ajout_BV ;
GtkWidget *Ajout_gest_BV;
GtkWidget *pInfo;


Ajout_gest_BV=lookup_widget(objet,"Ajout_gest_BV");

input1= lookup_widget(objet,"entry_id_AB_ajout_BV") ;
input2= lookup_widget(objet,"spinbutton_nB_ajout_BV") ;
input3= lookup_widget(objet,"spinbutton_cO_ajout_BV") ;
input4= lookup_widget(objet,"combobox_ajout_BV");
input5= lookup_widget(objet,"entry_id_ajout_BV");

checkbutton_ajout_BV= lookup_widget(objet,"checkbutton_ajout_BV");

strcpy(p.idbureau,gtk_entry_get_text(GTK_ENTRY(input1)));
p.capelec= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
p.capobs= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
strcpy(p.adr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(p.idagentb,gtk_entry_get_text(GTK_ENTRY(input5)));

if(gtk_toggle_button_get_active(GTK_CHECK_BUTTON(checkbutton_ajout_BV)))
ajouterbureau(p,"bv.txt");
else
{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Confirmation requise");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_Annuler_ajout_BV_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_BV;
GtkWidget *Ajout_gest_BV;
GtkWidget *tree;
GtkWidget *pInfo;

pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"L'opération d'ajout a échoué");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);

	Ajout_gest_BV=lookup_widget(button,"Ajout_gest_BV");
	gtk_widget_destroy(Ajout_gest_BV);
	Ajout_gest_BV=lookup_widget(button,"Gestion_BV");
	Ajout_gest_BV=create_Gestion_BV();
	gtk_widget_show(Ajout_gest_BV);
	tree=lookup_widget(Ajout_gest_BV,"treeview_gest_BV");
	afficherbureau(tree);
	break;
	}


}



void
on_button_retour15_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajout_gest_BV, *tree;
Ajout_gest_BV=lookup_widget(button,"Ajout_gest_BV");
gtk_widget_destroy(Ajout_gest_BV);
Ajout_gest_BV=lookup_widget(button,"Gestion_BV");
Ajout_gest_BV=create_Gestion_BV();
gtk_widget_show(Ajout_gest_BV);
tree=lookup_widget(Ajout_gest_BV,"treeview_gest_BV");
afficherbureau(tree);
} 


void
on_checkbutton_ajout_BV_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){ 
	accept = 1;
}else{
	accept = 0;

}
}







void
on_Enregistrer_modifie_BV_clicked      (GtkButton       *objet,
                                        gpointer         user_data)
{
bureau p;
GtkWidget* input1;
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* Modifie_gest_BV;



Modifie_gest_BV=lookup_widget(objet,"Modifie_gest_BV");



input1= lookup_widget(objet,"entry_id_modifie_BV") ;
input2= lookup_widget(objet,"spinbutton_cb_modifie_BV") ;
input3= lookup_widget(objet,"spinbutton_nb_modifie_BV") ;
input4= lookup_widget(objet,"combobox_modifie_BV");
input5= lookup_widget(objet,"entry_id_AB_modifie_BV") ;


strcpy(p.idbureau,gtk_entry_get_text(GTK_ENTRY(input1)));
p.capelec= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
p.capobs= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
strcpy(p.adr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(p.idagentb,gtk_entry_get_text(GTK_ENTRY(input5)));

modifierbureau(p,"bv.txt");

}




void
on_Annuler_modifie_BV_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_BV;
GtkWidget *Modifie_gest_BV;
GtkWidget *tree;




	Modifie_gest_BV=lookup_widget(button,"Modifie_gest_BV");
	gtk_widget_destroy(Modifie_gest_BV);
	Modifie_gest_BV=lookup_widget(button,"Gestion_BV");

	Modifie_gest_BV=create_Gestion_BV();
	gtk_widget_show(Modifie_gest_BV);
	tree=lookup_widget(Modifie_gest_BV,"treeview_gest_BV");
	afficherbureau(tree);
	
}




void
on_Verifier_modifie_BV_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
}




void
on_button_retour_16_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifie_gest_BV, *tree;
Modifie_gest_BV=lookup_widget(button,"Modifie_gest_BV");
gtk_widget_destroy(Modifie_gest_BV);
Modifie_gest_BV=lookup_widget(button,"Gestion_BV");
Modifie_gest_BV=create_Gestion_BV();
gtk_widget_show(Modifie_gest_BV);
tree=lookup_widget(Modifie_gest_BV,"treeview_gest_BV");
afficherbureau(tree);
}





void
on_Affiche_gest_BV_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_gest_BV;
GtkWidget *Gestion_BV;
Gestion_BV=lookup_widget(objet,"Gestion_BV");
gtk_widget_destroy(Gestion_BV);
Gestion_BV=lookup_widget(objet,"Gestion_BV");
Gestion_BV=create_Gestion_BV();
gtk_widget_show(Gestion_BV);
treeview_gest_BV=lookup_widget(Gestion_BV,"treeview_gest_BV");
afficherbureau(treeview_gest_BV);
}



void
on_ajouter_gest_bv_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_BV;
GtkWidget *Ajout_gest_BV;

Ajout_gest_BV=create_Ajout_gest_BV();
gtk_widget_show(Ajout_gest_BV);

Gestion_BV=lookup_widget(button,"Gestion_BV");
gtk_widget_destroy(Gestion_BV);
}



void
on_Modifier_gest_bv_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{ 
GtkWidget *Gestion_BV;
GtkWidget *Modifie_gest_BV;

Modifie_gest_BV=create_Modifie_gest_BV();
gtk_widget_show(Modifie_gest_BV);

Gestion_BV=lookup_widget(button,"Gestion_BV");
gtk_widget_destroy(Gestion_BV);

}



void
on_Rechercher_gest_BV_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_Supprimer_gest_bv_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprime_gest_BV;

Supprime_gest_BV = create_Supprime_gest_BV();
gtk_widget_show (Supprime_gest_BV);

}




void
on_treeview_gest_BV_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}




void
on_entry_rechercher_gest_BV_changed    (GtkEditable     *editable,
                                        gpointer         user_data)
{
GtkWidget *entry_rechercher_gest_BV;
char id[20]= "", fich[20]="bv.txt";

GtkWidget *tree;
tree =  lookup_widget(editable,"treeview_gest_BV");

entry_rechercher_gest_BV = lookup_widget(GTK_WIDGET(editable),"entry_rechercher_gest_BV");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry_rechercher_gest_BV)));

chercherbureau(tree,id);
}




gboolean
on_Gestion_BV_focus_in_event           (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
if (affichage_tree5==0)
{
strcpy(Idbureau,"");
GtkWidget *tree;

tree =  lookup_widget(widget,"treeview_gest_BV");

afficherbureau(tree);
}
affichage_tree5 = 1;
  return FALSE;
}




void
on_Supprimer_supp_BV_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprime_gest_BV, *tree;
GtkWidget *entry_id_BV_supp_BV;
GtkWidget *pInfo;
GtkWidget *radiobutton_supp_oui;

bureau p;
entry_id_BV_supp_BV=lookup_widget(button,"entry_id_BV_supp_BV");
radiobutton_supp_oui= lookup_widget(button,"radiobutton_supp_oui");
strcpy(p.idbureau,gtk_entry_get_text(GTK_ENTRY(entry_id_BV_supp_BV)));

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_supp_oui)))
supprimerbureau(p,"bv.txt");
else
{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Confirmation requise");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}


void
on_button_retour_supp_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprime_gest_BV, *tree;
Supprime_gest_BV=lookup_widget(button,"Supprime_gest_BV");
gtk_widget_destroy(Supprime_gest_BV);
Supprime_gest_BV=lookup_widget(button,"Gestion_BV");
Supprime_gest_BV=create_Gestion_BV();
gtk_widget_show(Supprime_gest_BV);
tree=lookup_widget(Supprime_gest_BV,"treeview_gest_BV");
afficherbureau(tree);
}




void
on_radiobutton_supp_non_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}




void
on_radiobutton_supp_oui_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}














void
on_quitter4_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}




void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *LE_acceuil_gma;
GtkWidget *window2;
LE_acceuil_gma=lookup_widget(button,"Gestion_BV");
gtk_widget_destroy(Gestion_BV);
window2=create_Connexion();
gtk_widget_show(window2);*/
}




void
on_button_retour9_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *LE_acceuil_gma;
GtkWidget *window2;
LE_acceuil_gma=lookup_widget(button,"Gestion_BV");
gtk_widget_destroy(Gestion_BV);
window2=create_Menu();
gtk_widget_show(window2);*/
}




void
on_quitter10_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *LE_acceuil_gma;
GtkWidget *window2;
LE_acceuil_gma=lookup_widget(button,"Modifie_gest_BV");
gtk_widget_destroy(Modifie_gest_BV);
window2=create_Connexion();
gtk_widget_show(window2);*/
}



void
on_quitter11_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button47_imen_retour_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
window1=lookup_widget(button,"I1_R__clamation");
gtk_widget_destroy(window1);
window2=create_Menu();
gtk_widget_show(window2);
}

