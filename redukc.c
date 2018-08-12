/* redukc.c - Izostavljanje uzastopno jednakih elemenata niza.            */

#include <stdio.h>
#define N 30

void redukcija (float a[], int *n) {
  int i, j;
  for (i=1, j=0; i<*n; i++) if (a[j] != a[i]) a[++j] = a[i];
  *n = j + 1;
}

/* Ispitivanje funkcije redukcija. */

void main () {
  float a[N];  int n, i;
  while (1) {
    printf ("n? "); scanf ("%d", &n);
  if (n <= 0 || n > N) break;
    printf ("A? "); for (i=0; i<n; scanf ("%f", &a[i++]));
    redukcija (a, &n);
    printf ("A= "); for (i=0; i<n; printf ("%f ", a[i++]));
    printf ("\n\n");
  }
}
