/* sekradi.c - Obrada sekvencijalne binarne datoteke.                     */

#include <stdio.h>
#include <stdlib.h>

int main (int bpar, char *vpar[]) {
  FILE *ulaz, *poz, *neg; double x[100], s; int n, i, g;
  if      ((ulaz = fopen (vpar[1], "rb")) == NULL) g = 1;
  else if ((poz  = fopen (vpar[2], "wb")) == NULL) g = 2;
  else if ((neg  = fopen (vpar[3], "wb")) == NULL) g = 3;
  else {
    g = 0;
    while (fread (&n, sizeof n, 1, ulaz) != 0) {
      fread (x, sizeof (double), n, ulaz);
      for (s=i=0; i<n; s+=x[i++]);
      if (s) {
        fwrite (&n, sizeof n, 1, (s>0 ? poz : neg));
        fwrite (x, sizeof (double), n, (s>0 ? poz : neg));
      }
    }
  }
  if (g) printf ("*** Greska %d pri otvaranju datoteke %d\n", errno, g);
  return g;
}
