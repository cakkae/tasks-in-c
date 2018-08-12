/* sekpravi.c - Stvaranje sekvencijalne binarne datoteke.                 */

#include <stdio.h>
#include <stdlib.h>

void main (int bpar, char *vpar[]) {
  FILE *ulaz, *izlaz; double x[100]; int n, i;
  ulaz  = fopen (vpar[1], "r");
  izlaz = fopen (vpar[2], "wb");
  if (ulaz!=NULL && izlaz!=NULL) {
    while (fscanf(ulaz,"%d",&n) != EOF) {
      for (i=0; i<n; fscanf(ulaz,"%lf",&x[i++])) ;
      fwrite (&n, sizeof n, 1, izlaz);
      fwrite (x, sizeof (double), n, izlaz);
    }
  } else
    printf ("*** Greska %d pri otvaranju ***\a\n", errno);
}
