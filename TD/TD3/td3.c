#include <stdio.h>
#include <stdlib.h>

typedef struct Cell *Liste;

struct Cell {
    int val;
    Liste next;
};


// Unsorted list
void concat(Liste *l1, Liste l2)
{
    Liste pt = *l1;
    if (*l1 == NULL) {
        *l1 = l2;
    } else {
        while (pt->next != NULL) {
            pt = pt->next;
        }
        pt->next = l2;
    }

}

void ajouter_tete(Liste *l1, int val)
{
    Liste pt = (Liste) malloc(sizeof(struct Cell));
    pt->val = val;
    pt->next = *l1;
    *l1 = pt;
}

// Correction vue en TD
void insert(int x, Liste *l) {
    Liste a = *l;
    if (*l  == NULL || x < (**l).val) {
        ajouter_tete(l, x);
    } else {
        while (a->next != NULL && x >= a->next->val) {
            a  = a->next;
        }
        // ajout_apres(a,x); // cours
    }
}

void ajout_apres(Liste l1, int val) {
    Liste new_cell = (Liste) malloc(sizeof(struct Cell));
    new_cell->val = val;
    // Raccordement à droite
    new_cell->next = l1->next;
    // Raccordement à gauche
    l1->next = new_cell;
}

// Moi
void inserer(Liste *l1, int n_val)
{
    Liste l_iter = *l1;
    if (*l1 == NULL || n_val < (*l1)->val) {
        ajouter_tete(l1, n_val);
    } else {
        while (l_iter->next != NULL && n_val > l_iter->next->val) {
            l_iter = l_iter->next;
        }
        ajout_apres(l_iter, n_val);
    }
}


void affiche_l(Liste l1)
{
    Liste pt = l1;
    printf("[ ");
    while (l1 != NULL) {
        printf("%d ", l1->val);
        l1 = l1->next;
    }
    printf("]\n");
}


int main()
{
    Liste l1 = NULL, l2 = NULL;

    // l1 = [ 4 3 2 1 ]
    /*ajouter_tete(&l1, 15);
    ajouter_tete(&l1, 8);
    ajouter_tete(&l1, 4);
    ajouter_tete(&l1, 3);*/

    inserer(&l1, 4);
    inserer(&l1, 8);
    inserer(&l1, 3);
    inserer(&l1, 15);
    inserer(&l1, 2);

    printf("L1 = ");
    affiche_l(l1);



    // l2 = -1;
    ajouter_tete(&l2, 0);
    printf("L2 = ");
    affiche_l(l2);
    //printf("CONCAT : ");
    //concat(&l1, l2);
    inserer(&l1, 4);

    printf("L1 APRES INSERT = ");
    affiche_l(l1);


    printf("\n___ FIN ___\n");
    return 0;
}
