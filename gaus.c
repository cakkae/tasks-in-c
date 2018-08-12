/* gaus.c - Gausova eliminaciona metoda.                                  */

#include <stdio.h>
#include <stdlib.h>

main () {
  while (1) {
    float **a, *b, *x, c;
    int n, i, j, k;

    /* Citanje reda sistema jednacina: */
    scanf ("%d", &n);
  if (n <= 0) break;

    /* Citanje koeficijenata sistema: */
    printf ("Sistem linearnih jednacina:\n\n");
    a = malloc (n * sizeof(float *));
    b = malloc (n * sizeof(float));
    x = malloc (n * sizeof(float));
    for (i=0; i<n; i++) {
      a[i] = malloc (n * sizeof(float));
      for (j=0; j<n; j++) {
        scanf ("%f", &a[i][j]);
        printf ("%7.3f", a[i][j]);
      }
      scanf ("%f", &b[i]);
      printf (" | %7.3f\n", b[i]);
    }

    /* Eliminacija unapred: */
    for (i=0; i<n-1; i++)
      for (j=i+1; j<n; j++) {
        c = a[j][i] / a[i][i];
        for (k=i; k<n; k++) a[j][k] -= a[i][k] * c;
        b[j] -= b[i] * c;
      }

    /* Zamenjivanje unazad: */
    for (j=n-1; j>=0; j--) {
      c = b[j];
      for (k=j+1; k<n; k++) c -= a[j][k] * x[k];
      x[j] = c / a[j][j];
    }

    /* Ispisivanje rezultata: */
    printf ("\nResenja sistema:\n\n");
    for (i=0; i<n; printf ("%7.3f", x[i++]));
    putchar ('\n');

    /* Oslobadanje dinamicki dodeljene memorije: */
    for (i=0; i<n; free (a[i++]));
    free (a); free (b); free (x);
  }
}
