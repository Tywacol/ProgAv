#include <stdio.h>
#include <string.h>

#define NN 15
#define MAX_ELEVE 60

typedef struct {
    unsigned int annee, mois, jour;
} Date;

typedef struct {
    char nom[20], prenom[20];
    Date birthday;
    float notes[NN];
    char NIP[8];
} Eleve;

typedef struct {
    Eleve eleves[MAX_ELEVE];
    int nb_eleves;
} Classe;

typedef struct Cell* ptCellule;
struct Cell {
    int val;
    ptCellule next;
};
typedef ptCellule liste;

int cmpDate(Date d1, Date d2)
{
    if (d1.annee < d2.annee) {
        return -1;
    } else if (d2.annee < d1.annee) {
        return 1;
    }
    if (d1.mois < d2.mois) {
        return -1;
    } else if (d2.mois < d1.mois) {
        return 1;
    }
    if (d1.jour < d2.jour) {
        return -1;
    } else if (d2.jour < d1.jour) {
        return 1;
    }
    return 0;
}

float moyenne(Eleve eleve)
{
    float mean = 0;
    for (int i = 0; i < NN; ++i) {
        mean += eleve.notes[i];
    }
    return mean;
}

void affiche_classe(Classe classe)
{
    for (int i = 0; i < MAX_ELEVE; ++i) {
        printf("%s %s. %d/%d/%d. Moyenne = %f",
               classe.eleves[i].nom, classe.eleves[i].prenom,
               classe.eleves[i].birthday.annee, classe.eleves[i].birthday.mois, classe.eleves[i].birthday.jour,
               moyenne(classe.eleves[i]));
    }
}

void permuter(Eleve *e1, Eleve *e2)
{
    Eleve *tmp = e1;
    *e1 = *e2;
    *e2 = *tmp;
}

void bubble_sort(Classe classe)
{
    for (int i = 0; i < MAX_ELEVE; ++i) {
        Eleve e = classe.eleves[i];
        for (int j = 0; j < MAX_ELEVE; ++j) {
            if (cmpDate(e.birthday, classe.eleves[j].birthday) < 0) {
                permuter(&e, &classe.eleves[i]);
            }
        }
    }
}


typedef struct Cellule Cellule;
struct Cellule {
    int val;
};

int indice_eleve(Classe *classe, char NIP[8])
{
    int debut = 0;
    int fin = classe->nb_eleves;
    int mil;
    while (debut <= fin) {
        mil = (fin + debut) / 2;
        if (strcmp(classe->eleves[mil].NIP,NIP) == 0) {
            return mil;
        } else if (strcmp(classe->eleves[mil].NIP,NIP) > 0) {
            fin = mil - 1;
        } else {
            debut = mil + 1; /* + 1 pour terminaison */
        }
    }


    /* Autre version */
    /*
     * while (min != max) {
     *      switch(strcmp(classe.eleves[i].NIP,NIP) {
     *          case 0 :
     *              return i;
     *              break;
     *          case 1:
     *              max = i;
     *              i = (max+min)/2;
     *              break;
     *          case -1 :
     *              min = i;
     *              i = (max+min)/2;
     *     }
     * }
     * return -1;
     */

}

int ajout_eleve(Classe *classe, Eleve *eleve) {
    int i = classe->nb_eleves;
    while (i > -1 && strcmp(classe->eleves[i]), eleve->NIP)  {
        classe->eleves[i+1] = classe->eleves[i];
        i--;
    }
    classe->eleves[i+1] = *eleve;
    classe->nb_eleves++;
}

void concatenation(liste liste1, liste liste2) {
    liste1->next = liste2;
}



int main()
{
    printf("Hello, World!\n");
    return 0;
}
