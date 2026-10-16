#include <stdio.h>

#define NB_VALEURS 3
#define MAX_LONGUEUR 50
#define MAX_LIGNES 15

/* Etape 3 : affiche une ligne de l'histogramme vertical pour la hauteur y */
void afficher_ligne_histov(int valeurs[], int taille, float y)
{
    printf("| ");
    for (int j = 0; j < taille; j++)
    {
        if (valeurs[j] >= y)
        {
            printf("xxx ");
        }
        else
        {
            printf("    ");
        }
    }
    printf("\n");
}

int main(void)
{
    int valeurs[NB_VALEURS] = { 8, 4, 12 };

    /* Etape 2 : recherche du maximum */
    int maximum = valeurs[0];
    for (int i = 1; i < NB_VALEURS; i++)
    {
        if (valeurs[i] > maximum)
        {
            maximum = valeurs[i];
        }
    }

    /* Etape 1 et 2 : histogramme horizontal avec echelle */
    float echelle = (float)MAX_LONGUEUR / maximum;
    for (int i = 0; i < NB_VALEURS; i++)
    {
        int nb_croix = valeurs[i] * echelle;
        printf("| ");
        for (int j = 0; j < nb_croix; j++)
        {
            printf("x");
        }
        printf(" %d\n", valeurs[i]);
    }
    printf("+-------------------------------------------------------\n");

    printf("\n");

    /* Etape 3 : histogramme vertical */
    for (int i = 0; i < MAX_LIGNES; i++)
    {
        float y = maximum - (float)i * maximum / MAX_LIGNES;
        afficher_ligne_histov(valeurs, NB_VALEURS, y);
    }
    printf("+---------------------------------------\n");

    return 0;
}
