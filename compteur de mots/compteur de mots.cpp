
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int size = 300;
    char* tab = (char*)malloc(size * sizeof(char));

    if (tab == NULL) {
        printf("Allocation de mémoire échouée");
        return 1;  // Arrêt du programme en cas d'échec d'allocation mémoire
    }

    printf("Entrez une phrase : ");
    if (fgets(tab, size, stdin) == NULL) {
        printf("Erreur lors de la lecture de la phrase");
        free(tab);  // Libération de la mémoire avant de quitter le programme
        return 1;
    }

    // Supprimer le caractère de nouvelle ligne ajouté par fgets
    tab[strcspn(tab, "\n")] = '\0';

    if (strlen(tab) == 0) {
        printf("Veuillez entrer quelque chose");
        free(tab);  // Libération de la mémoire avant de quitter le programme
        return 1;
    }

    int count = 0;
    char* token = strtok(tab, " ");
    while (token != NULL) {
        if (ispunct((unsigned char)*token)) {
            // Correction : utiliser *token au lieu de token pour obtenir le caractère actuel
            token = strtok(NULL, " ");
            continue;
        }
        else {
            count += 1;
            token = strtok(NULL, " ");
        }
    }

    printf("Il y a %d mots dans la phrase\n", count);

    free(tab);  // Libération de la mémoire avant de quitter le programme
    return 0;
}
