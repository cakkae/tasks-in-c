/* velcelit.c - Ispitivanje paketa za obradu velikih celih brojeva.       */

#include "velceli.h"
#include <stdio.h>
#define N 30

void main () {
  char a[N], b[N], c[2*N], d[N]; int na, nb, nc, nd;
  while (citaj (a, &na) && citaj (b, &nb)) {
    printf ("a=   "); pisi (a, na, N, DA); putchar ('\n');
    printf ("b=   "); pisi (b, nb, N, DA); putchar ('\n');
    printf ("a+b= "); zbir (a, na, b, nb, c, &nc);
                      pisi (c, nc, N, DA); putchar ('\n');
    printf ("a-b= ");
    if (razlika (a, na, b, nb, c, &nc))
                    { pisi (c, nc, N, DA); putchar ('\n'); }
      else            printf ("ne moze\n");
    printf ("a*b= "); proizvod (a, na, b, nb, c, &nc);
                      pisi (c, nc, N, DA); putchar ('\n');
    printf ("a/b= ");
    if (kolicnik (a, na, b, nb, c, &nc, d, &nd)) {
                      pisi (c, nc, N, DA); putchar ('\n');
      printf ("a%%b= "); pisi (d, nd, N, DA); putchar ('\n');
    } else               printf ("ne moze\n");
    putchar ('\n');
  }
}
