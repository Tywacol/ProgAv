/*Source Code From Laure Gonnord*/
/*int list - C implementation*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// définition du type liste d'entiers.
typedef struct Cell{
  int el;
  struct Cell* suivant;
} Cell;

typedef Cell* Liste;

void insereEnTete(Liste* pL,int elem)
{
  //creation de la cellule avec l'élément.
  Cell* pc = (Cell*) malloc(sizeof(Cell));
  (*pc).el = elem;
  (*pc).suivant = *pL;
  *pL = pc;
}

void imprimeListe(Liste l)
{
  Cell* pc = l;
  while(pc != NULL) {
    printf("%d,",(*pc).el);
    pc = (*pc).suivant ;
  }
  printf("\n");
}

int main(){
  Liste maliste;

  insereEnTete(&maliste,4);
  insereEnTete(&maliste,42);
  insereEnTete(&maliste,2);
  
  imprimeListe(maliste);

  return 0;
}
