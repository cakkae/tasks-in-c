/* minimt2.c - Nalazenje minimuma polinoma.                               */

#include <stdio.h>

extern double poli[];                  /* Deklaracije globalnih podataka. */
extern int n;

double polinom (double);               /* Prototipovi funkcija.           */
void minim (double (*f)(double), double xa, double xb, int n, double eps,
            double *xmin, double *ymin);

void main () {                         /* Glavni program.                 */
  double xa, xb, eps, xmin, ymin; int i, k;
  printf ("\nPolinom: ");
  scanf ("%d", &n);
  for (i=n; i>=0; i--) {
    scanf ("%lf", &poli[i]);
    printf ("%8.3f", poli[i]);
  }
  putchar ('\n');
  k = printf ("\n%10s%10s%10s%10s%10s\n",
              "eps", "xa", "xb", "xmin", "ymin");
  for (i=0; i<k-2; i++) putchar ('='); putchar ('\n');
  while (1) {
    scanf ("%lf%lf%lf", &xa, &xb, &eps);
  if (eps < 0) break;
    minim (polinom, xa, xb, 10, eps, &xmin, &ymin);
    printf ("%10.2e%10.3f%10.3f%10.3f%10.3f\n", eps, xa, xb, xmin, ymin);
  }
}
