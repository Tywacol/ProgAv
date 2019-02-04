#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MAX_PERSONNES 100

typedef struct {
    int annee, mois, jour;
} Date;

typedef struct {
    char nom[SIZE], prenom[SIZE], tel[SIZE];
    Date Naissance;
} Personne;

typedef Personne Annuaire[MAX_PERSONNES];


/* On devrait utiliser malloc pour passer les structs et eviter les copies mais
 * nous ne sommes pas (?) encore au cours 3.
 * */
Date lire_date()
{
    Date d;
    scanf("%d%d%d",
          &d.jour,
          &d.mois,
          &d.annee);
    return d;
}

int cmpDate(Date d1, Date d2)
{
    if (d1.annee < d2.annee) {
        return -1;
    }
    if (d2.annee < d1.annee) {
        return 1;
    }
    if (d1.mois < d2.mois) {
        return -1;
    }
    if (d2.mois < d1.mois) {
        return 1;
    }
    if (d1.jour < d2.jour) {
        return -1;
    }
    if (d2.jour < d1.jour) {
        return 1;
    }
    return 0;
}

void afficher_date(Date date)
{
    printf("%02d/%02d/%d\n",
           date.jour,
           date.mois,
           date.annee);
}


int lire_personne(Personne *ptr_pers)
{
    if (scanf("%s%s%d%d%d%s",
              ptr_pers->nom,
              ptr_pers->prenom,
              &ptr_pers->Naissance.jour,
              &ptr_pers->Naissance.mois,
              &ptr_pers->Naissance.annee,
              ptr_pers->tel) == EOF) {
        return 1;
    }
    return 0;
}

int construire_annuaire(Annuaire annuaire, int current_pos)
{
    while (lire_personne(&annuaire[current_pos]) == 0) {
        current_pos++;
    }
    return current_pos;
}

void affiche_personne(Personne p)
{
    printf("%s %s. %02d/%02d/%d. Tel. %s\n",
           p.nom,
           p.prenom,
           p.Naissance.jour,
           p.Naissance.mois,
           p.Naissance.annee,
           p.tel);
}


void affiche_annaire(Annuaire annuaire, int last_pos)
{
    for (int i = 0; i < last_pos; ++i) {
        printf("Personne %d : ", i);
        affiche_personne(annuaire[i]);
    }

}


void permuter_pers(Personne *p1, Personne *p2)
{
    Personne tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void bubble_sort(Annuaire annuaire, int nb_personnes)
{
    for (int i = 0; i < nb_personnes; ++i) {
        for (int j = 0; j < nb_personnes-i-1; ++j) {
            if (cmpDate(annuaire[j].Naissance, annuaire[j+1].Naissance) > 0) {
                permuter_pers(&annuaire[j], &annuaire[j+1]);
            }
        }
    }
}

void bubble_sort_nom(Annuaire annuaire, int nb_personnes)
{
    for (int i = 0; i < nb_personnes; ++i) {
        for (int j = 0; j < nb_personnes-i-1; ++j) {
            if (strcmp(annuaire[j].nom, annuaire[j+1].nom) > 0) {
                permuter_pers(&annuaire[j], &annuaire[j+1]);
            }
        }
    }
}



int main()
{
    //Date d = lire_date();
    //afficher_date(d);
    //Personne *ptr_pers = malloc(sizeof(Personne));
    //lire_personne(ptr_pers);
    //affiche_personne(*ptr_pers);
    Annuaire annuaire;
    int size = construire_annuaire(annuaire, 0);
    printf("Avant tri : \n");
    affiche_annaire(annuaire, size);
    printf("Apres tri : \n");
    bubble_sort_nom(annuaire, size);
    //bubble_sort_nom(annuaire, size);
    affiche_annaire(annuaire, size);


    return 0;
}
