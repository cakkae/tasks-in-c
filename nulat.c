/* nulat.c - Ispitivanje funkcije nula.                                   */

#include <stdio.h>

double oscil (double x);               /* Prototipovi funkcija.           */
void nula (double (*f)(double), double xa, double xb, double eps,
            double *x, int *uspeh);

void main () {                         /* Glavni program.                 */
  int i;
  printf ("\n%8s%8s%12s%23s%8s\n",
          "xa", "xb", "eps", "x", "uspeh");
  for (i=0; i<59; i++) putchar ('='); putchar ('\n');
  while (1) {
    double xa, xb, eps, x; int uspeh;
    scanf ("%lf%lf%lf", &xa, &xb, &eps);
  if (xa == 1e38) break;
    nula (oscil, xa, xb, eps, &x, &uspeh);
    printf ("%8.3f%8.3f%12.3e%23.18f%8s\n",
            xa, xb, eps, x, (uspeh ? "da" : "ne"));
  }
}
