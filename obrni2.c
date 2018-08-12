/* obrni2.c - Obrtanje redosleda elemenata niza.                          */

#include <stdio.h>
#define NMAX 100

main () {
  int a[NMAX], *p, *q, n;
  while (1) {
    printf ("n? "); scanf ("%d", &n);
  if (n<=0 || n>NMAX) break;
    printf ("A? "); for (p=a; p<a+n; scanf ("%d", p++));
    for (p=a, q=a+n-1; p<q; p++, q--) {
      int b = *p; *p = *q; *q = b;
    }
    printf ("A="); for (p=a; p<a+n; printf (" %d", *p++)); printf("\n\n");
  }
}
