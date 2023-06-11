#include "fonction.h"

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include <time.h>

enum {
  HID,
  HFN,
  HLN,
  HG,
  HRN,
  HRF,
  HRT,
  HCL,
  HCK,
  COLUMNSS
};

void ajout_reclamation(reclamation re) {
  int v = 0;

  FILE * f = fopen("rec.txt", "a");
  if (f != NULL) {
    fprintf(f, "Idliste:\"%s\" Idreclamation:\"%s\" dateJour:%d dateMois:%d dateAnne:%d type:\"%s\" texte:\"%s\" justificatifs:\"%s\" autres:\"%s\"\n", re.Idliste, re.Idreclamation, re.date.jour, re.date.mois, re.date.annee,
      re.type, re.texte, re.justificatifs, re.autres);
    fclose(f);
    v = 1;
  }

}
void modification_t(char id[10], reclamation e) {
  reclamation r;
  int jourr, anneee, moiss;
  char Idrec[50];
  char textee[50];
  char typee[50];
  char justificatifss[50];
  char autress[50];

  FILE * f = fopen("rec.txt", "rb");
  FILE * fb = fopen("temp.txt", "ab+");
  if (f != NULL && fb != NULL) {

    while (fscanf(f, "Idliste:\"%[^\"]\"  Idreclamation:\"%[^\"]\"  dateJour:%d dateMois:%d dateAnne:%d type:\"%[^\"]\"  texte:\"%[^\"]\"  justificatifs:\"%[^\"]\"  autres:\"%[^\"]\"\n",
        r.Idliste, r.Idreclamation, & r.date.jour, & r.date.mois, & r.date.annee,
        r.type, r.texte, r.justificatifs, r.autres) != EOF) {

      if (strcmp(r.Idliste, id) != 0) {
        fprintf(fb, "Idliste:\"%s\" Idreclamation:\"%s\" dateJour:%d dateMois:%d dateAnne:%d type:\"%s\" texte:\"%s\" justificatifs:\"%s\" autres:\"%s\"\n",
          r.Idliste, r.Idreclamation, r.date.jour, r.date.mois, r.date.annee, r.type, r.texte, r.justificatifs, r.autres);

      } else
        fprintf(fb, "Idliste:\"%s\" Idreclamation:\"%s\" dateJour:%d dateMois:%d dateAnne:%d type:\"%s\" texte:\"%s\" justificatifs:\"%s\" autres:\"%s\"\n",
          r.Idliste, e.Idreclamation, e.date.jour, e.date.mois, e.date.annee, e.type, e.texte, e.justificatifs, e.autres);

    }
  }
  fclose(f);
  fclose(fb);
  remove("rec.txt");
  rename("temp.txt", "rec.txt");

}
void supprimer_reclamation(char id[20]) {

  reclamation re;
  FILE * f = fopen("rec.txt", "r");
  FILE * fb = fopen("temp.txt", "a+");
  if (f != NULL && fb != NULL) {
    while (fscanf(f, "Idliste:\"%[^\"]\"  Idreclamation:\"%[^\"]\"  dateJour:%d dateMois:%d dateAnne:%d type:\"%[^\"]\"  texte:\"%[^\"]\"  justificatifs:\"%[^\"]\"  autres:\"%[^\"]\"\n", re.Idliste,
        re.Idreclamation, & re.date.jour, & re.date.mois, & re.date.annee,
        re.type, re.texte, re.justificatifs, re.autres) != EOF) {
      if (strcmp(re.Idreclamation, id) != 0) {

        fprintf(fb, "Idliste:\"%s\" Idreclamation:\"%s\" dateJour:%d dateMois:%d dateAnne:%d type:\"%s\" texte:\"%s\" justificatifs:\"%s\" autres:\"%s\"\n", re.Idliste,
          re.Idreclamation, re.date.jour, re.date.mois, re.date.annee,
          re.type, re.texte, re.justificatifs, re.autres);
      }
    }
  }
  fclose(f);
  fclose(fb);
  remove("rec.txt");
  rename("temp.txt", "rec.txt");

}

void afficher_rec_ONtreeview(GtkWidget * list, char file[20]) {
  GtkCellRenderer * renderer;
  GtkTreeViewColumn * column;
  GtkTreeIter iter;
  GtkListStore * store;
  reclamation h;

  store = NULL;
  FILE * f;
  store = gtk_tree_view_get_model(list);
  if (store == NULL) {

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Idliste", renderer, "text", HID, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Idrec", renderer, "text", HFN, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", HLN, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", HG, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text", HRN, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", HRF, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("texte", renderer, "text", HRT, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("justificatifs", renderer, "text", HCL, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("autres", renderer, "text", HCK, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

  }

  store = gtk_list_store_new(COLUMNSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
  f = fopen(file, "r");
  if (f == NULL) {
    return;
  } else {
    while (fscanf(f, "Idliste:\"%[^\"]\"  Idreclamation:\"%[^\"]\"  dateJour:%d dateMois:%d dateAnne:%d type:\"%[^\"]\"  texte:\"%[^\"]\"  justificatifs:\"%[^\"]\"  autres:\"%[^\"]\"\n", h.Idliste,
        h.Idreclamation, & h.date.jour, & h.date.mois, & h.date.annee,
        h.type, h.texte, h.justificatifs, h.autres) != EOF) {

      gtk_list_store_append(store, & iter);

      gtk_list_store_set(store, & iter, HID, h.Idliste, HFN, h.Idreclamation, HLN, h.date.jour, HG, h.date.mois, HRN, h.date.annee, HRF, h.type, HRT, h.texte, HCL, h.justificatifs, HCK, h.autres, -1);
    }
    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
    g_object_unref(store);
  }

}

void recherche_rec(char id[20]) {
  reclamation re;
  FILE * f, * g;
  f = fopen("rec.txt", "r");
  g = fopen("search.txt", "a+");
  while (fscanf(f, "Idliste:\"%[^\"]\"  Idreclamation:\"%[^\"]\"  dateJour:%d dateMois:%d dateAnne:%d type:\"%[^\"]\"  texte:\"%[^\"]\"  justificatifs:\"%[^\"]\"  autres:\"%[^\"]\"\n", re.Idliste,
      re.Idreclamation, & re.date.jour, & re.date.mois, & re.date.annee,
      re.type, re.texte, re.justificatifs, re.autres) != EOF) {
    if (strcmp(re.Idliste, id) == 0) {
      fprintf(g, "Idliste:\"%s\" Idreclamation:\"%s\" dateJour:%d dateMois:%d dateAnne:%d type:\"%s\" texte:\"%s\" justificatifs:\"%s\" autres:\"%s\"\n", re.Idliste,
        re.Idreclamation, re.date.jour, re.date.mois, re.date.annee,
        re.type, re.texte, re.justificatifs, re.autres);
    }
  }
  fclose(f);
  fclose(g);
}
