#include <stdio.h>
#include <stdlib.h>


// TP4 of Advanced C

typedef struct Cell {
    int val;
    struct Cell *next;
} Cell;

typedef Cell *Liste;

Cell* allouer()
{
    return malloc(sizeof(Cell));
}

void ajout_tete(Liste liste, int val) {
    Cell *cell = allouer();
    cell->val = val;
    cell->next = liste;
    liste = cell;
}

void afficher_liste(Liste liste) {
    printf("[ ");
    while (liste != NULL) {
        printf("%d ", liste->val);
        liste = liste->next;


    }
    printf("]\n");
}

void liberer(Cell* ptr_c) {
    free(ptr_c);
}

int main()
{
    Liste liste = allouer();
    for (int i = 0; i < 10; ++i) {
        ajout_tete(liste, i);
    }
    afficher_liste(liste);



    printf("Hello, World!\n");
    return 0;
}
