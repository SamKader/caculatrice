#include <gtk/gtk.h>

#include <math.h> // Pour fmod()

double calcul_modulo(double valeur1, double valeur2); // Déclaration

// Variables globales
GtkBuilder *builder;

GtkWidget *champ_saisie,*label_resultat; // Déclaration globale du champ de saisie et label

// Fonction appelée lorsqu'on clique sur un bouton , pour les operateur
void bouton_plus_clicker(GtkWidget *widget, gpointer data) {
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[50];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s + ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage
}
void bouton_div_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton division cliquer\n");
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    //operation = '/';  // Sauvegarder l'opération

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[50] ;
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s / ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage
}
void bouton_modulo_clicker(GtkWidget *widget, gpointer data) {
    g_print("bouton modulo cliqué\n");

    // Récupérer le champ d'entrée (champ_saisie doit être accessible ici)
    GtkEntry *champ = GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(champ);

    // Ajouter le "%" au texte actuel sans vider le champ
    char texte_nouveau[20];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s %%", texte_courant);

    // Mettre à jour l'affichage avec le nouveau texte
    gtk_entry_set_text(champ, texte_nouveau);
}

void bouton_moins_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton moins cliquer\n");
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    //operation = '+';  // Sauvegarder l'opération

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[50];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s - ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage

}

void bouton_mult_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton multiplication cliquer\n");
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    //operation = '*';  // Sauvegarder l'opération

    // Ajouter le "+" au texte actuel au lieu de vider le champ
    char texte_nouveau[50];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s * ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage
}
        // les fonction afficher des synbole
void bouton_virgule_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton virgule cliquer\n");
    GtkEntry *champ= GTK_ENTRY(champ_saisie);
    const char *texte_courant = gtk_entry_get_text(GTK_ENTRY(champ));

    char texte_nouveau[50];
    snprintf(texte_nouveau, sizeof(texte_nouveau), "%s . ", texte_courant);

    gtk_entry_set_text(GTK_ENTRY(champ_saisie), texte_nouveau); // Mettre à jour l'affichage
}

    // les fonctions pour effacer dans le champ d'ecriture

void bouton_c_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton clear cliquer\n");
    GtkEntry *entrer = GTK_ENTRY(champ_saisie);
    //donnee="";
    gtk_entry_set_text(entrer, ""); // Met un texte vide dans l'entrée
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
       // donnee=nouveau_texte;


        gtk_entry_set_text(entrer, nouveau_texte); // Mettre à jour l'entrée avec le nouveau texte
    }
}


         // les fonctions pour afficher des chiffre dans le champd'ecriture

void bouton7_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 7 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text =gtk_entry_get_text(entrer);
   // donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf(("%s7"),text));
}
void bouton8_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 8 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    //donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf(("%s8"),text));
}
void bouton9_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 9 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    //donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf(("%s9"),text));
}

void bouton4_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 4 cliquer\n");
    GtkEntry *champ = GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(champ);
    //donnee=text;
    gtk_entry_set_text(champ,g_strdup_printf("%s4",text));
}
void bouton5_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 5 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    //donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf("%s5",text));
}
void bouton6_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 6 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    //donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf(("%s6"),text));
}

void bouton1_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 1 cliquer\n");
    // convertir
    GtkEntry *n=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(n);
    //affichage
    //donnee=text;
    gtk_entry_set_text(n,g_strdup_printf("%s1",text));
}
void bouton2_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 2 cliquer\n");
    // convertion
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    //donnee=text;
    gtk_entry_set_text(entrer,g_strdup_printf("%s2",text));
}
void bouton3_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 3 cliquer\n");

    // Convertir champ_saisie en GtkEntry *
    GtkEntry *entry = GTK_ENTRY(champ_saisie);

    // Récupérer le texte actuel du champ de saisie
    const char *texte_actuel = gtk_entry_get_text(entry);
    // stocker dans la variable global donnee
    //donnee=texte_actuel;

    // Mettre à jour le texte du champ de saisie en ajoutant "0" à la fin
    gtk_entry_set_text(entry, g_strdup_printf("%s3", texte_actuel));
}
void bouton0_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton 0 cliquer\n");
    GtkEntry *entrer=GTK_ENTRY(champ_saisie);
    const char *text=gtk_entry_get_text(entrer);
    gtk_entry_set_text(entrer,g_strdup_printf(("%s0"),text));
}

       // fonction pour caculer et affiche dans le champ

void bouton_egale_clicker(GtkWidget *widget, gpointer data){
    g_print("bouton egale cliquer\n");
    // Récupérer les widgets passés en paramètre
    GtkEntry *entry = GTK_ENTRY(champ_saisie);
    GtkLabel *label = GTK_LABEL(label_resultat);

    // Récupérer le texte de l'Entry
    const gchar *saisie = gtk_entry_get_text(entry);

    // Variables pour stocker les opérandes et l'opérateur
    double valeur1, valeur2, resultat;
    char operateur;

    // Scanner la chaîne pour identifier les nombres et l'opérateur
    if (sscanf(saisie, "%lf %c %lf", &valeur1, &operateur, &valeur2) == 3) {
        // Effectuer l'opération selon l'opérateur trouvé
        switch (operateur) {
            case '+': resultat = valeur1 + valeur2; break;
            case '-': resultat = valeur1 - valeur2; break;
            case '*': resultat = valeur1 * valeur2; break;
            case'%' :resultat = calcul_modulo(valeur1,valeur2); break;//calcule du modulo
            case '/':
                if (valeur2 != 0) resultat = valeur1 / valeur2;
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
        char text[50];
        snprintf(text, sizeof(text), "%.2f", resultat);
        gtk_label_set_text(label, text);
    } else {
        gtk_label_set_text(label, "Expression invalide !");
    }
}

                 // fonction pour calculer le modulo d'un entier et de float

double calcul_modulo(double valeur1, double valeur2) {
    if (valeur2 == 0) {
        //printf("Erreur : division par zéro !\n");
        return NAN; // Retourne NaN (Not a Number) en cas d'erreur
    }

    if (valeur1 == (int)valeur1 && valeur2 == (int)valeur2) {   // verifier que les valeur sont des entiers
        // Si les deux sont des entiers, utiliser %
        return (int)valeur1 % (int)valeur2;
    } else {
        // Sinon, utiliser fmod() pour le modulo flottant
        return fmod(valeur1, valeur2);
    }
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

