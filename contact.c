#include <stdio.h>
#include <string.h>
// creation structure de contact

struct Contact {
    char nom[50];
    char telephone[15];
    char email[50];
};

//creation de tableau de structure  pour les contact
struct Contact carnet[100];
int nbrContacts = 0; // Variable pour compter le nombre de contacts ajoutés

//sturcure sans parametre et sans retour pour ajouter un contact
void ajouterContact() {
    if (nbrContacts < 100) {
        printf("nom: ");
        scanf("%s", carnet[nbrContacts].nom);
        printf("telephone: ");
        scanf("%s", carnet[nbrContacts].telephone);
        printf("e-mail: ");
        scanf("%s", carnet[nbrContacts].email);
        nbrContacts++;
    } else {
        printf("carnet de contacts plein !\n");
    }
}

//sturcure sans parametre et sans retour pour afficher un contact
void affichContacts() {
    if (nbrContacts == 0) {
        printf("aucun contact pour afficher.\n");
    } else {
        for (int i = 0; i < nbrContacts; i++) {
            printf("contact %d\n", i+1);
            printf("nom: %s\n", carnet[i].nom);
            printf("telephone: %s\n", carnet[i].telephone);
            printf("e-mail: %s\n\n", carnet[i].email);
        }
    }
}

//sturcure avec parametre et sans retour pour rechercher un contact
void recherContact(char* nom) {
    for (int i = 0; i < nbrContacts; i++) {
        if (strcmp(carnet[i].nom, nom) == 0) {
            printf("nom: %s\n", carnet[i].nom);
            printf("telephone: %s\n", carnet[i].telephone);
            printf("e-mail: %s\n", carnet[i].email);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

//sturcure avec parametre et sans retour pour modifier un contact
void modiContact(char* nom) {
    for (int i = 0; i < nbrContacts; i++) {
        if (strcmp(carnet[i].nom, nom) == 0) {
            printf("entrez le nouveau telephone: ");
            scanf("%s", carnet[i].telephone);
            printf("entrez le nouveau e-mail: ");
            scanf("%s", carnet[i].email);
            printf("contact mis a jour.\n");
            return;
        }
    }
    printf("contact non trouve.\n");
}

//sturcure avec parametre et sans retour pour suprimer un contact
void suppContact(char* nom) {
    for (int i = 0; i < nbrContacts; i++) {
        if (strcmp(carnet[i].nom, nom) == 0) {
            for (int j = i; j < nbrContacts - 1; j++) {
                carnet[j] = carnet[j + 1]; // Décale les contacts
            }
            nbrContacts--;
            printf("contact supprime.\n");
            return;
        }
    }
    printf("contact non trouve.\n");
}

//creation de menu 
int main() {
    int choix;
    char nom[50];

    do {
        printf("1. ajouter un contact\n");
        printf("2. afficher tous les contacts\n");
        printf("3. rechercher un contact\n");
        printf("4. modifier un contact\n");
        printf("5. supprimer un contact\n");
        printf("6. quitter\n");
        printf("votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterContact();
                break;
            case 2:
                affichContacts();
                break;
            case 3:
                printf("entrez le nom pour rechercher: ");
                scanf("%s", nom);
                recherContact(nom);
                break;
            case 4:
                printf("entrez le nom du contact pour modifier: ");
                scanf("%s", nom);
                modiContact(nom);
                break;
            case 5:
                printf("entrez le nom du contact pour supprimer: ");
                scanf("%s", nom);
                suppContact(nom);
                break;
            case 6:
                printf("merci byby !\n");
                break;
            default:
                printf("choix entre 1 et 6.\n");
        }
    } while (choix != 6);

    return 0;
}




