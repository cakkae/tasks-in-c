/* krug.c - Izracunavanje obima i povrsine kruga.                         */

#include <stdio.h>
#define PI 3.14159265359

main () {
  double r;
  printf ("Poluprecnik? ");
  scanf ("%lf", &r);
  printf ("Obim     = %.3f\n", 2*r*PI);
  printf ("Povrsina = %.3f\n", r*r*PI);
}
