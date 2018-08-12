/* tabela2.c - Tabeliranje vrednosti izraza.                              */

#include <stdio.h>

main () {
  double xmin, xmax, dx, x, s, p; int n, i;
  printf ("n? "); scanf ("%d", &n);
  printf ("xmin, xmax, dx? ");
  scanf ("%lf%lf%lf", &xmin, &xmax, &dx);
  printf ("\n      x         s\n====================\n");
  for (x=xmin; x<=xmax; x+=dx) {
    for (s=0, p=i=1; i<=n; i++) s += (p *= x);
    printf ("%10.3f%10.3f\n", x, s);
  }
}
