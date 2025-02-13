#include <gtk/gtk.h>

// Variables globales
GtkBuilder *builder;
//double dernier_nombre = 0.0;
char operation = 0;
const gchar *donnee;
GtkWidget *champ_saisie,*label_resultat; // Déclaration globale du champ de saisie et label

// Fonction appelée lorsqu'on clique sur "button_plus"


void bouton_c_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton clear cliquer\n");
    GtkEntry *entrer = GTK_ENTRY(champ_saisie);
    donnee="";
    gtk_entry_set_text(entrer, ""); // Met un texte vide dans l'entrée
}


void bouton_div_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton division cliquer\n");
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    //g_print("texte courant: %s\n", texte_courant); // Afficher le texte avant conversion
    //dernier_nombre = atof(texte_courant);  // Convertir en nombre
    //g_print("dernier nombre : %f\n", dernier_nombre); // Afficher le nombre

    operation = '+';  // Sauvegarder l'opération

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[50] ;
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s / ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage
}
void bouton_mult_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton multiplication cliquer\n");
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    operation = '+';  // Sauvegarder l'opération

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[50];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s * ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage
}
void bouton_effacer_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton effacer cliquer\n");
    GtkEntry *entrer = GTK_ENTRY(champ_saisie);
    const gchar *texte = gtk_entry_get_text(entrer); // Récupérer le texte actuel
    int longueur = strlen(texte); // Obtenir la longueur du texte
    g_print("%d",longueur);
    if (longueur > 0) {
        // Copier le texte sans le dernier caractère
        char nouveau_texte[longueur];
        strncpy(nouveau_texte, texte, longueur - 1);
        nouveau_texte[longueur - 1] = '\0';
        donnee=nouveau_texte;


        gtk_entry_set_text(entrer, donnee); // Mettre à jour l'entrée avec le nouveau texte
    }
}


void bouton7_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 7 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text =gtk_entry_get_text(entrer);
    donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf(("%s7"),donnee));
}
void bouton8_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 8 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf(("%s8"),donnee));
}
void bouton9_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 9 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf(("%s9"),donnee));
}
void bouton_moins_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton moins cliquer\n");
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    operation = '+';  // Sauvegarder l'opération

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[50];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s - ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage

}
void bouton4_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 4 cliquer\n");
    GtkEntry *champ = GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(champ);
    donnee=text;
    gtk_entry_set_text(champ,g_strdup_printf("%s4",donnee));
}
void bouton5_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 5 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf("%s5",donnee));
}
void bouton6_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 6 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf(("%s6"),donnee));
}

void bouton1_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 1 cliquer\n");
    // convertir
    GtkEntry *n=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(n);
    //affichage
    donnee=text;
    gtk_entry_set_text(n,g_strdup_printf("%s1",donnee));
}
void bouton2_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 2 cliquer\n");
    // convertion
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf("%s2",donnee));
}
void bouton3_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 3 cliquer\n");

    // Convertir champ_saisie en GtkEntry *
    GtkEntry *entry = GTK_ENTRY(champ_saisie);

    // Récupérer le texte actuel du champ de saisie
    const char *texte_actuel = gtk_entry_get_text(entry);
    // stocker dans la variable global donnee
    donnee=texte_actuel;

    // Mettre à jour le texte du champ de saisie en ajoutant "0" à la fin
    gtk_entry_set_text(entry, g_strdup_printf("%s3", donnee));
}
void bouton_egale_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton egale cliquer\n");
    // Récupérer les widgets passés en paramètre
    GtkEntry *entry = GTK_ENTRY(champ_saisie);
    GtkLabel *label = GTK_LABEL(label_resultat);

    // Récupérer le texte de l'Entry
    const gchar *saisie = gtk_entry_get_text(entry);

    // Variables pour stocker les opérandes et l'opérateur
    double op1, op2, resultat;
    char operateur;

    // Scanner la chaîne pour identifier les nombres et l'opérateur
    if (sscanf(saisie, "%lf %c %lf", &op1, &operateur, &op2) == 3) {
        // Effectuer l'opération selon l'opérateur trouvé
        switch (operateur) {
            case '+': resultat = op1 + op2; break;
            case '-': resultat = op1 - op2; break;
            case '*': resultat = op1 * op2; break;
            case '/':
                if (op2 != 0) resultat = op1 / op2;
                else {
                    gtk_label_set_text(label, "Erreur!");
                    return;
                }
                break;
            default:
                gtk_label_set_text(label, "Opérateur invalide !");
                return;
        }

        // Convertir le résultat en texte et l'afficher dans le label
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%.2f", resultat);
        gtk_label_set_text(label, buffer);
    } else {
        gtk_label_set_text(label, "Expression invalide !");
    }
}
void bouton_modulo_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton modulo cliquer\n");
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    operation = '+';  // Sauvegarder l'opération

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[20];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s % ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage
}

void bouton0_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 0 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    gtk_entry_set_text(entrer,g_strdup_printf(("%s0"),text));
}
void bouton_virgule_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton virgule cliquer\n");
}

void bouton_plus_clicker(GtkWidget *widget, gpointer data) {
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    //g_print("texte courant: %s\n", texte_courant); // Afficher le texte avant conversion
    //dernier_nombre = atof(texte_courant);  // Convertir en nombre
    //g_print("dernier nombre : %f\n", dernier_nombre); // Afficher le nombre

    operation = '+';  // Sauvegarder l'opération

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[50];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s + ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Charger l'interface depuis le fichier Glade
    builder = gtk_builder_new_from_file("interface.ui");
    if (!builder) {
        g_print("Erreur : Impossible de charger le fichier interface.ui\n");
        return 1;
    }

    // Récupérer la fenêtre principale
    GtkWidget *fenetre = GTK_WIDGET(gtk_builder_get_object(builder, "fenetre_principale"));
    if (!fenetre) {
        g_print("Erreur : fenetre_principale non trouvée.\n");
        g_object_unref(builder);
        return 1;
    }
    // initialisation du champ de saisie
    champ_saisie = GTK_WIDGET(gtk_builder_get_object(builder, "champ_saisie"));
    label_resultat = GTK_WIDGET(gtk_builder_get_object(builder, "label_resultat"));


    // Connecter les signaux définis dans Glade
    gtk_builder_connect_signals(builder, NULL);

    // Afficher la fenêtre
    gtk_widget_show(fenetre);

    // Lancer la boucle principale GTK
    gtk_main();

    // Nettoyage
    g_object_unref(builder);
    return 0;
}

