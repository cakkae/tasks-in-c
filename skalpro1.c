/* skalpro1.c - Skalarni proizvod dva vektora.                            */

#include <stdio.h>
#define DIM 50

main () {
  double a[DIM], b[DIM], skal_pro;
  int    i, n;
  while (1) {
    printf ("\nDuzina vektora (najvise %d)? ", DIM);
    scanf ("%d", &n);
  if (n <= 0 || n > DIM) break;
    printf ("Komponente vektora A? ");
    for (i=0; i<n; scanf ("%lf", &a[i++]));
    printf ("Komponente vektora B? ");
    for (i=0; i<n; scanf ("%lf", &b[i++]));
    for (skal_pro=i=0; i<n; i++) skal_pro += a[i] * b[i];
    printf ("Skalarni proizvod A*B= %10.3f\n", skal_pro);
  }
}
