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
void insert(Liste *l, int x)
{
    Liste a = *l;
    if (*l == NULL || x < (**l).val) {
        ajouter_tete(l, x);
    } else {
        while (a->next != NULL && x >= a->next->val) {
            a = a->next;
        }
        // ajout_apres(a,x); // cours
    }
}

void ajout_apres(Liste *l1, int val)
{
    Liste new_cell = (Liste) malloc(sizeof(struct Cell));
    new_cell->val = val;
    // Raccordement à droite
    new_cell->next = (*l1)->next;
    // Raccordement à gauche
    (*l1)->next = new_cell;
}

// Moi
void inserer(Liste *l1, int new_val)
{
    Liste l_iter = *l1;
    if (*l1 == NULL || new_val > (*l1)->val) {
        ajouter_tete(l1, new_val);
    } else {
        while (l_iter->next != NULL && new_val < l_iter->next->val) {
            l_iter = l_iter->next;
        }
        ajout_apres(&l_iter, new_val);
    }
}

void inserer_sans_doublon(Liste *l1, int new_val)
{
    Liste l_iter = *l1;
    if (*l1 == NULL || new_val > (*l1)->val) {
        ajouter_tete(l1, new_val);
    } else {
        while (l_iter->next != NULL && new_val < l_iter->next->val) {
            l_iter = l_iter->next;
        }
        // Test du doublon
        if (l_iter->next != NULL && new_val != l_iter->next->val) {
            ajout_apres(&l_iter, new_val);
        }
    }
}


void affiche_l(Liste l1)
{
    printf("[ ");
    while (l1 != NULL) {
        printf("%d ", l1->val);
        l1 = l1->next;
    }
    printf("]\n");
}

int est_triee(Liste *ptr_liste)
{
    if (ptr_liste == NULL) {
        return 1;
    }
    Liste tmp = *ptr_liste;
    while (tmp->next != NULL) {
        if (tmp->val < tmp->next->val) {
            return 0; // La liste n'est pas triee
        }
        tmp = tmp->next;
    }
    return 1;
}


// Correction de Mr. Dequidt
void supprimer_tete(Liste *pl)
{
    Liste tmp = *pl;
    *pl = tmp->next;
    free(tmp);
}

void supprimer_tete_corto(Liste *liste)
{
    Liste *tmp;
    if (liste != NULL) {
        tmp = &(*liste)->next;
        free(*liste);
        *liste = *tmp;
    }
}

void supprimer_liste(Liste *liste)
{
    while (*liste != NULL) {
        supprimer_tete(liste);
    }
    free(liste);
}

void lecture_liste_fich(Liste * ptr_liste,char * name) {
    int tmp;
    FILE * fd;
    fd = fopen("entiers.txt", "r");
    if (fd == NULL) {
        printf("Erreur d'ouverture du fichier : %s\n",name);
        return;
    }

    while (!feof(fd)) {
        fscanf(fd,"%d", &tmp);
        //STOPPED WORK HERE --
        inserer(ptr_liste, tmp);
    }
    fclose(fd);
}

int main()
{
    char f_name[255];
    Liste * ptr_liste_fich = malloc(sizeof(Liste));
    Liste *ptr_l1 = malloc(sizeof(Liste));

    printf("___ DEBUT ___\n\n");

    // Insertion dans l'ordre [ 2 15 3 8 4 ]
    inserer(ptr_l1, 4);
    inserer(ptr_l1, 8);
    inserer(ptr_l1, 3);
    inserer(ptr_l1, 15);
    inserer_sans_doublon(ptr_l1, 8); // Essaye d'ajout d'un doublon
    inserer(ptr_l1, 2);

    printf("L1 = ");
    affiche_l(*ptr_l1); // L1 = [ 15 8 4 3 2 ]  La liste est triee
    printf(est_triee(ptr_l1) ? "L1 est triee\n" : "L1 n'est pas triee\n");

    inserer_sans_doublon(ptr_l1, 4);
    inserer_sans_doublon(ptr_l1, 7);

    printf("L1 après insert : ");
    affiche_l(*ptr_l1);
    supprimer_tete(ptr_l1);
    printf("L1 après supprimer tete : ");
    affiche_l(*ptr_l1);
    inserer(ptr_l1, 99);
    printf("L1 apres inserer : ");
    affiche_l(*ptr_l1);

    supprimer_tete(ptr_l1);
    printf("L1 après supprimer tete : ");
    affiche_l(*ptr_l1);

    printf("Suppresion de L1\n");
    supprimer_liste(ptr_l1);



    printf("Entrez un nom de fichier texte : ");
    scanf("%s", f_name);
    lecture_liste_fich(ptr_liste_fich,"entiers.txt");
    printf("Liste lue  : ");
    affiche_l(*ptr_liste_fich);
    supprimer_liste(ptr_liste_fich);



    printf("\n___ FIN ___\n");
    return 0;
}
