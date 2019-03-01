/*exo-bug.c, A.Mine, ENS Ulm*/
#include <stdio.h>
int* p;

int recherche(int* tab, int element, int nb)
{
  int min = 0, max = nb-1;
  while ( min <= max ) {
    int mid = (min+max) / 2;
    if ( tab[mid] == element ) return 1; /* found */
    if ( tab[mid] < element ) min = mid; 
    else max = mid;
  }
  return 0; /* not found :( */
}

int main()
{
  int x[] = { 1, 5, 8, 9, 12, 16 };
  printf( "%i\n", recherche( p, 1,  1 ) );
  printf( "%i\n", recherche( x, 1,  1 ) ); /* must return  1 */
  printf( "%i\n", recherche( x, 12, 6 ) ); /* must return  1 */
  printf( "%i\n", recherche( x, 3, 6 ) ); /* must return  0 */
  return 1;
}
