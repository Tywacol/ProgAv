/*TP GDB - DDD Programme listes*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//définition de types
typedef struct Cell {
  int key; /*integer cell*/
  struct Cell* nextC; /*ref to the next cell*/
} Cell;

typedef Cell* Liste; // alias


//insertion en tête
void insertinList(Liste* mylist, int el) 
{
  Cell* newCell=(Cell*) malloc(sizeof(Cell));
  newCell->key=el;
  *mylist=newCell;
}

//impression
void printList(Liste mylist)
{
  Cell* p=mylist;
  printf("[");
  while(p!=NULL)
    {
      printf("%d",p->key);
      if (p->nextC!=NULL) printf(",");
    }
  printf("]\n");
}

// creation
Liste creeListePositive()
{
  Liste thelist=NULL ;
  bool fini = false;
  int val;
  // initialiser !!
  while(!fini)
    {
      printf("donner un élément >=0, et <0 vous voulez arrêter\n");
      scanf("%d",&val);
      if(val>=0){
	insertinList(&thelist,val);
      }
      else fini = true;
    }
    return thelist;
}


/********* Fonction Principale *********/
int main(int argc, char *argv[])
{
  //déclaration
  Liste ltest,ltest1;
  
  //initialisation
  ltest1=creeListePositive();

  //impression
  printList(ltest1);
  return 0;
}
