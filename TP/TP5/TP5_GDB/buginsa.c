/* bug.c, source:  Christian NGUYEN */

#include <stdio.h>
#include <stdlib.h>

void place( int *t, int i, int j)
{
  t [ i ] =  j;
}

void traitement( int  n )
{ int *t;
  unsigned int i;
  t = (int*) malloc(n * sizeof(int ));
  for( i = n-1; i >= 0 ; i--)
      place( t, i  , i*i ) ;
  free( t );
}

int main ( int argc, char *argv[] )
{ int n;
  
  if (argc == 2)
    {n = atoi( argv[1] ); 
      printf("\nbug du -1\n");
      traitement( n );
      printf("done...\n");
    }
  else
    {
      printf("nb arguments should be one");
    }
  return 0;
}
