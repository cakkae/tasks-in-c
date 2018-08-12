/* razvrst.c - Razvrstavanje elemenata niza.                              */

#include <stdio.h>
#define N 100

main () {
  int a[N], b[N], c[N], na, nb, nc, i;
  while (1) {
    printf ("\nn? "); scanf ("%d", &na);
  if (na<=0 || na>N) break;
    printf ("A? "); for (i=0; i<na; scanf ("%d", &a[i++]));
    for (nb=nc=i=0; i<na; a[i]<0 ? (b[nb++] = a[i++]) : (c[nc++] = a[i++]));
    printf ("B= "); for (i=0; i<nb; printf ("%d ", b[i++])); printf ("\n");
    printf ("C= "); for (i=0; i<nc; printf ("%d ", c[i++])); printf ("\n");
  }
}
