#include <gtk/gtk.h>
#include <string.h>
typedef struct{
char id[10];
char idtete[10];
char idm1[10];
char idm2[10];
char idm3[10];
char ori[50];
char nv[10];



}el;
void
on_radiobutton_ajout_Utilis2_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ajout_Utilis1_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_utilis_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Enregistrer_ajout_Utilis_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Annuler_ajout_Utilis_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitter12_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_17_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_modifie_Utilis1_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modifie_Utilis2_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_quitter13_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour18_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_Enregistrer_modifie_Utilis_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Annuler_modifie_Utils_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrech_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buton_retoupp_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_gest_utilis_row_collapsed           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Recherche_utilis_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Afiicher_gest_utilis_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Retour_utilis1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Quitter_utilis_1_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Supprimer_gest_utilis_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_gest_utilis_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouter_gest_utilis_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_gest_utilis_row_collapsed           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_gest_rec_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_gest_utilis_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimer_utilis_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_ajout_Utilis2_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Gestion_Utilisateur_set_focus       (GtkWindow       *window,
                                        GtkWidget       *widget,
                                        gpointer         user_data);

void
on_entry_recherche_ges_utilis_changed  (GtkEditable     *editable,
                                        gpointer         user_data);

gboolean
on_Gestion_Utilisateur_activate_focus  (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_Ajouter_ajout_Utilis_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouter_MOD_gest_utilis_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Actualiser_gest_utilis_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ajouter_aff_gest_utilis_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_ann_supp_utilis_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_Butoon_con_utilis_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gesadmin_menu_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gesobs_menu_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_geselec_menu_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ret_ges_utilis_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_geslisteelec_menu_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gesrec_menu_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gesbv_menu_clicked           (GtkButton       *button,
                                        gpointer         user_data);
void
on_button_vo_gma_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_md_gma_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_aj_gma_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_sup_gma_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_novote_gma_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_deja_gma_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_vb_gma_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_vote_gma_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_ac_gma_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_save_gma_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_dr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_ce_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_ga_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_md_gma_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_mc_gma_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_modi_gma_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supp_gma_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_mg_gma_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview2_gma_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_button1_ref_gma_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_findliste_gma_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_quitte_gma_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_retour_gma_clicked          (GtkButton       *button,
                                        gpointer         user_data);



void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button47_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data);


void
on_button53_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button52_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button50_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button51_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton22_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton23_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton24_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton32_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton31_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton33_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_rech_rec_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button54_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
void
on_ajouter_gest_bv_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour9_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitter4_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_gest_bv_clicked            (GtkButton       *button,
                                        gpointer         user_data);


void
on_Affiche_gest_BV_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_Supprimer_gest_bv_clicked           (GtkButton       *button,
                                        gpointer         user_data);


void
on_quitter10_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Annuler_ajout_BV_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_Enregistrer_ajout_BV_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour15_clicked             (GtkButton       *button,
                                        gpointer         user_data);


void
on_quitter11_clicked                   (GtkButton       *button,
                                        gpointer         user_data);


void
on_Annuler_modifie_BV_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_16_clicked            (GtkButton       *button,
                                        gpointer         user_data);


void
on_Supprimer_supp_BV_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_supp_clicked          (GtkButton       *button,
                                        gpointer         user_data);



void
on_Rechercher_gest_BV_clicked          (GtkButton       *button,
                                        gpointer         user_data);




void
on_treeview_gest_BV_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);



void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data);







void
on_entry_rechercher_gest_BV_changed    (GtkEditable     *editable,
                                        gpointer         user_data);




gboolean
on_Gestion_BV_focus_in_event           (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);


void
on_Confirmer_supp_BV_clicked           (GtkButton       *button,
                                        gpointer         user_data);



void
on_checkbutton_ajout_BV_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);




void
on_radiobutton_supp_non_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);




void
on_radiobutton_supp_oui_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);




void
on_Verifier_modifie_BV_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_Enregistrer_modifie_BV_clicked      (GtkButton       *button,
                                        gpointer         user_data);


void
on_button47_imen_retour_clicked        (GtkButton       *button,
                                        gpointer         user_data);
