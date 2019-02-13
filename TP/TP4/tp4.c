#include <stdio.h>
#include <stdlib.h>

// Correction par Mr Dequidt

typedef struct {
    int entier;
    int multiplicite;
} MultiEnsemble;

typedef struct Cellule {
    MultiEnsemble m;
    struct Cellule *suivant;
} Cellule;

typedef Cellule *PtrCellule;
typedef Cellule *Liste;

void ajout_tete(Liste *pl, MultiEnsemble val)
{
    PtrCellule nouveau = malloc(sizeof(Cellule));
    nouveau->m = val;
    nouveau->suivant = *pl;
    *pl = nouveau;
}

void suppr_tete(Liste *pl)
{
    PtrCellule A_supprimer = *pl;
    *pl = A_supprimer->suivant;
    free(A_supprimer);
}

void affiche_tete(Liste l)
{
    while (l != NULL) {
        printf(" (%d,%d)\n", l->m.entier, l->m.multiplicite);
        l = l->suivant;
    }
}

void insertion(int e, Liste *pl)
{
    if (*pl == NULL) {
        MultiEnsemble m;
        m.entier = e;
        m.multiplicite = 1;
        ajout_tete(pl, m);
        return;
    }
    if ((*pl)->m.entier == e) {
        (*pl)->m.multiplicite++;
        return;
    }
    if ((*pl)->m.entier > e) {
        return;
    }
    insertion(e, &((*pl)->suivant));
}


int main()
{
    printf("Hello, World!\n");
    return 0;
}
