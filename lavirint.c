/* lavirint.c - Pronalazenje izlaza iz lavirinta.                         */

#include <stdio.h>

char a[20][51]; int m, n;     /* Matrica za definisanje lavirinta.        */
enum {ZID=':', PRAZNO=' ', START='@', KORAK='S'};

void pisi ()                  /* Ispisivanje lavirinta.                   */
  { int i; putchar ('\n'); for (i=0; i<m; puts (a[i++])); }

int moze (int i, int j)       /* Da li polje [i][j] prihvatljivo?         */
  { return i>=0 && i<m && j>=0 && j<n && a[i][j]==PRAZNO; }

void nadji (int i, int j) {   /* Pretrazivanje lavirinta.                 */
  if (a[i][j] != START) a[i][j] = KORAK;
  if (i==0 || i==m-1 || j==0 || j==n-1) pisi (); /* Pronadjen put.        */
  else {
    if (moze (i+1, j)) nadji (i+1, j);           /* Korak nagore.         */
    if (moze (i-1, j)) nadji (i-1, j);           /* Korak nadole.         */
    if (moze (i, j+1)) nadji (i, j+1);           /* Korak udesno.         */
    if (moze (i, j-1)) nadji (i, j-1);           /* Korak ulevo.          */
  }
  if (a[i][j] != START) a[i][j] = PRAZNO;
}

void main () {               /* Glavni program.                           */
  int i, j, i0, j0;
  scanf ("%d%d\n", &m, &n);
  for (i=0; i<m; i++) {
    gets (a[i]);
    for (j=0; j<n; j++) if (a[i][j] == START) { i0 = i; j0 = j; }
  }
  printf ("LAVIRINT:\n");   pisi ();
  printf ("\nRESENJA:\n");  nadji (i0, j0);
}