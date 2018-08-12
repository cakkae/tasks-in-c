/* nula.c - Nalazenje nule funkcije metodom polovljenja intervala.        */

#include <math.h>
#define MAX 50

void nula (double (*f)(double), double xa, double xb, double eps,
            double *x, int *uspeh) {
  double ya = (*f) (xa), yb = (*f) (xb), y;
  int i = 1;
  while (i++<=MAX && ya*yb<0 && fabs(xb-xa)>eps) {
    y = (*f) (*x = (xa+xb)/2);
    if (ya*y > 0) { xa = *x; ya = y; }
      else        { xb = *x; yb = y; }
  }
  *x = xa;
  *uspeh = fabs(xa-xb)<=eps && fabs(ya)<=eps;
}
