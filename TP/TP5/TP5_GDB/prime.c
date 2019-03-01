/* prime-number finding program  
will (after bugs are fixed) report a list of all primes which are
less than or equal to the user-supplied upper bound riddled with errors! */
#include <stdio.h>

#define MaxPrimes 50

int Prime[MaxPrimes],  /* Prime[I] will be 1 if I is prime, 0 otherwise */
  UpperBound;  /* we will check all number up through this one for
		  primeness */


void CheckPrime(int K)
{  int J;
  /* the plan:  see if J divides K, for all values J which are
     (a) themselves prime (no need to try J if it is nonprime), and
     (b) less than or equal to sqrt(K) (if K has a divisor larger
     than this square root, it must also have a smaller one,
     so no need to check for larger ones) */
  J = 2;
  while (1)  {
    if (Prime[J] == 1)
      if (K % J == 0)  {
	Prime[K] = 0;
	return;
      }
    J++;
  }
  
  /* if we get here, then there were no divisors of K, so it is
       prime */
  Prime[K] = 1; 
}

int main()
{  
  int N;
  printf("enter upper bound\n");
  scanf("%d",&UpperBound);
  
  Prime[2] = 1;
  for (N = 3; N <= UpperBound; N += 2)
    {
      CheckPrime(N);
      if (Prime[N]) printf("%d is a prime\n",N);
    }
}
