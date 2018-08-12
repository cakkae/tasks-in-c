/* razlicit.c - Broj razlicitih elemenata niza.                           */

int razliciti (const int niz[], int n) {
  int i, j, rez=0;
  for (i=0; i<n; i++) {
    for (j=0; j<i && niz[j]!=niz[i]; j++) ;
    if (j == i) rez++;
  }
  return rez;
}

/* Ispitivanje funkcije razliciti.                                        */

#include <stdio.h>
#define N 50

main () {
  int niz[N], n, i;
  while (1) {
    printf ("Duzina niza?   "); scanf ("%d", &n);
  if (n <= 0 || n > N) break;
    printf ("Elementi niza? "); for (i=0; i<n; scanf ("%d",&niz[i++]));
    printf ("Broj razlicitih elemenata je %d\n\n", razliciti(niz,n));
  }
}
