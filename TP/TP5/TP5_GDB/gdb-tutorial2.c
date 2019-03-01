/*gdb-tutorial.c, Matthieu Moy pour ENSIMAG - Modif by LG pour Polytech Lille*/
#include <stdio.h>

void f(void);
void calcul_et_imprime_fact(int n);
int fact(int n);

/*  Ce fichier est un tutorial pas-�-pas pour utiliser le d�boggeur gdb.
  Un d�bogueur est un outil pr�cieux pour comprendre ce qui ne va pas
  dans vos programmes. Les quelques minutes que vous allez passer �
  apprendre � l'utiliser seront largement rentabilis�es par la suite !

  Commencez par le compiler. Pour pouvoir utiliser gdb, il faut
  utiliser l'option -g de votre compilateur � la compilation :
  
  $ clang -g gdb-tutorial3.c -o gdb-tutorial
  (clang vous met un warning que vous ignorerez).

  Vous pouvez lancer l'ex�cutable gdb-tutorial dans gdb en ligne de 
  commande comme ceci :

  $ gdb ./gdb-tutorial

  Commen�ons par quelque chose de simple : d�marrer le programme. On
  tape "run", ou simplement la lettre "r" dans la ligne de commande
  gdb (dans votre terminal) L'ex�cution s'arrete sur un "segmentation
  fault � la ligne 50 de ce fichier, on d'y retrouve !*/

int main (int argc, char ** argv) {
  unsigned i;
  int j;
  int * ptr = NULL; /* NULL est une adresse invalide, on n'a pas le
                       droit de d�r�f�rencer un pointeur NULL */
  //printf ("Bonjour\n");
  //printf ("Je vais faire un acces memoire interdit\n");
  /* 
     La ligne suivante va faire un "Segmentation fault".
     
     Le d�boggeur va s'arr�ter sur cette ligne.
  */
  //*ptr = 0;
  /*
    Bon, le bug �tait facile � trouver. Mettez la ligne ci-dessus en
    commentaire pour �liminer le probl�me, recompilez, et lisez la
    suite.
    On va maintenant faire une execution pas-�-pas. Il faut commencer
    par donner � gdb un endroit du code o� on veut
    s'arr�ter : un point d'arr�t.

    Dans la ligne de commande gdb : "break gdb-tutorial3.c:55"

    puis "run"

  */
  printf ("On avance ...\n"); /* mettre le point d'arr�t ici */
  /*
    Maintenant, vous devriez avoir votre programme arr�t� sur la ligne
    qui pr�c�de. Tapez "next", ou simplement "n" pour avancer dans
    l'execution du programme, plusieurs fois. Petite astuce, apr�s
    avoir tap� "n" une fois, il suffit d'appuyer sur Entr�e pour
    refaire un "next".
  */
  printf ("On avance encore ...\n");
  printf ("On avance encore un peu ...\n");
  printf ("On avance encore un peu ...\n");
  printf ("On avance une derniere fois ...\n");
  printf ("Et voila !\n");
  /*
    Il y a deux commandes pour executer un programme pas � pas :
    - next, pour ex�cuter compl�tement l'instruction suivante
    - step, "rentre" dans la fonction si l'instruction suivante est un
    appel de fonction.
    Essayez successivement "step" et "next" sur les lignes suivantes.
    Au passage "up" permet de revenir un cran plus haut dans la pile d'exec
   */
  f();  /*step 1 fois, puis next pour avancer a l'interieur de f*/
  f();
  f();
  /*
    Bon, l'execution pas � pas, c'est bien, mais c'est p�nible quand
    il y a beaucoup de code � ex�cuter. Par exemple, la boucle
    suivante prendrait trop de temps, on veut la sauter.  Pour cela,
    poser un point d'arr�t sur la ligne qui suit la boucle (98), puis
    faites "continue" (ou juste "c") dans gdb.
  */
  j = 0;
  for (i = 0; i <= 1000; ++i) {
    j = j + i;
  }
  printf ("Fin de la boucle\n"); /* mettre le point d'arr�t ici */
  /*
    On peut bien s�r visualiser le contenu d'une variable,
    avec la commande "print", ou simplement "p". On peut
    maintenir l'affichage d'une variable avec "display".

    Par exemple, faites maintenant "display i", puis ex�cutez la
    boucle suivante pas � pas. Faites "p j" pour connaitre la valeur
    de j. Ensuite mettez un breakpoint apres la boucle (ligne 130)
    et "c" pour y aller.
  */

  for (i = 1; i <= 1000; i = i * 2) {
    j = j + i;
  }
  /*
    On peut aussi afficher des expressions C un peu plus complexes.
    Essayez par exemple
    (gdb) p i+j
    (gdb) p &i
    (gdb) p &j
    (gdb) p dire_bonjour("Monsieur")

    (dans le dernier cas, gdb va effectivement appeler la fonction
    dire_bonjour, d�finie plus bas)

    On peut aussi s'amuser un peu avec les pointeurs. Faites:

    (gdb) p &i
    $2 = (unsigned int *) 0xbf9bfde8
    
    La valeur 0xbf9bfde8, adresse de i, sera a priori diff�rente chez
    vous. Affichez maintenant l'expression *(unsigned int *)0xbf9bfde8
    (en rempla�ant 0xbf9bfde8 par la valeur que vous avez eu ci-dessus).
    Vous devriez avoir 1024, qui est bien la valeur de i.
    
    Avant de passer � la suite, on va supprimer cette impression de i
    display, puis undisplay n avec n le num�ro du display concernant i

  */
  printf ("i=%d\n", i);

  /*
    Tout �a se complique un peu quand on a des appels de fonctions.
    Entrez dans la fonction fact appel�e � la ligne suivante avec la
    commande "s", on se retrouve l� bas !
   */
  calcul_et_imprime_fact(10);

  /*
    Une derni�re chose : il arrive que le programme parte dans une
    boucle infinie, et on voudrait savoir o� est cette boucle.

    Rien de plus simple : lancez le programme ("c" pour "continue"),
    puis tapez Control-c pour arr�ter son execution et reprendre la
    main dans gdb (dans votre terminal)

    Utilisez cette technique pour voir la(les)quelle(s) de ces boucles
    est/sont une(des) boucle(s) infinie(s). Commentez les boucles infinies et
    recompilez avant de passer � la suite.
  */
  j = 1;
  while (j > 0) {
    ++j;
    }
 
 /* Boucle infine : i est unsigned et ne peux donc pas �tre negatif!
  i = 10;
  while (i >= 0) {
    --i;
  }
  */
  
 /* Boucle infinie 
  i = 0; j = 0;
  while (i == j) {
    ++i; ++j;
  }
  */
  /*    Voil�, vous avez termin� et vous savez � peu pr�s tout ce que vous
    devez savoir pour une utilisation courante. Les plus curieux
    pourront lire le manuel de gdb :
    http://sourceware.org/gdb/download/onlinedocs/  */
}

void f(void) {
  printf ("Appel de f()\n");
  printf ("Fin de f()\n");
}

void calcul_et_imprime_fact(int n) {
  /*
    Re-bonjour,
    
    � ce stade, n doit �tre �gal � 10. V�rifiez avec un "p n". Entrez
    dans la fonction fact avec un "step", on s'y retrouve. 
  */
  int res = fact(n);
  printf ("fact(%d) = %d\n", n, res);  
}

int fact(int n) {
  //printf ("Calcul de fact(%d)\n", n);
  /*
    Si c'est la premi�re fois que vous passez ici, n doit �tre �gal �
    10. V�rifiez avec un "p n". Continuez l'ex�cution pas � pas avec
    "step" (et non "next", pour rentrer dans les appels r�cursifs
    successifs de fact). Faites par exemple 5 appels puis lisez le
    commentaire suivant.
  */

  /*
    Voil�, je suppose que vous en �tes au 5�me appel r�cursif. Donc,
    "n" doit valoir 5. V�rifiez avec "p n".

    Mais dans la pile, il y a toujours les autres appels, avec les
    valeurs de "n" comprises entre 10 et 5. Faites "where" pour voir
    l'�tat de la pile.

    Pour naviguer dans la pile, utilisez les commandes "up" et "down".
    Par exemple, faites deux fois "up", puis "p n". Vous voyez la
    valeur de "n" au 3�me appel, c'est � dire 7.

    Faites deux fois "down", et vous voil� revenu o� vous �tiez.
    Faites maintenant "finish" pour terminer
    l'appel de fonction courant, plusieurs fois, jusqu'� revenir � la fonction
    "main" (ligne 167)
  */
  if (n <= 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

void dire_bonjour(char * nom) {
  printf("Bonjour, %s\n", nom);
}
