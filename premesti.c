/* premesti.c - Zamena najmanjeg i najveceg elementa matrice.             */

#include <stdio.h>
#define N 30

void main () {
  int i, j, m, n, a[N][N], min, max, imin, jmin, imax, jmax, b;
  FILE *dat; char ime[20];

  /* Citanje matrice: */
  printf ("Ime ulazne datoteke?  "); scanf ("%s", ime);
  dat = fopen (ime, "r");
  fscanf (dat, "%d%d", &m, &n);
  for (i=0; i<m; i++)
    for (j=0; j<n; fscanf (dat, "%d", &a[i][j++]));
  fclose (dat);

  /* Nalazenje mesta najmanjeg i najveæeg elementa: */
  min = max = a[0][0]; imin = jmin = imax = jmax = 0;
  for (i=0; i<m; i++)
    for (j=0; j<n; j++)
      if (a[i][j] < min) {
        min  = a[i][j]; imin = i; jmin = j;
      } else if (a[i][j] > max) {
        max  = a[i][j]; imax = i; jmax = j;
      }

  /* Medjusobna zamena dve vrste i dve kolone: */
  for (i=0; i<m; i++)
    { b = a[i][jmin]; a[i][jmin] = a[i][jmax]; a[i][jmax] = b; }
  for (j=0; j<n; j++)
    { b = a[imin][j]; a[imin][j] = a[imax][j]; a[imax][j] = b; }

  /* Upisivanje rezulatat u datoteku: */
  printf ("Ime izlazne datoteke? "); scanf ("%s", ime);
  dat = fopen (ime, "w");
  fprintf (dat, "%d %d\n", m, n);
  for (i=0; i<m; i++) {
    for (j=0; j<n; fprintf (dat, "%d ", a[i][j++]));
    fputc ('\n', dat);
  }
}
