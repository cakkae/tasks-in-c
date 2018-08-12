/* velceli.c - Definicije paketa za obradu velikih celih brojeva.         */

#include "velceli.h"
#include <stdio.h>
#include <ctype.h>

Log nula (const char a[], int na) { return na==1 && a[0]==0; }

int uporedi  (const char a[], int na, const char b[], int nb) {
  int i;
  if (na != nb) return na - nb;
  for (i=na-1; i>0 && a[i]==b[i]; i--);
  return a[i] - b[i];
}

void kopiraj (const char a[], int na, char b[], int *nb) {
  int i;
  for (i=0; i<na; i++) b[i] = a[i];
  *nb = na;
}

Log zbir     (const char a[], int na, const char b[], int nb,
              char c[], int *nc) {
  int i, p;
  for (p=i=0; i<na || i<nb; i++) {
    int d = p;
    if (i < na) d += a[i];
    if (i < nb) d += b[i];
    if (d >= 10) { p = 1; d -= 10; } else p = 0;
    c[i] = d;
  }
  if (p) c[i++] = p;
  * nc = i;
  return DA;
}

Log razlika  (const char a[], int na, const char b[], int nb,
              char c[], int *nc) {
  int i, p;
  if (uporedi (a, na, b, nb) < 0) return NE;
  for (p=i=0; i<na; i++) {
    int d = a[i] + p;
    if (i <nb) d -= b[i];
    if (d < 0) { p = -1; d += 10; } else p = 0;
    c[i] = d;
  }
  for (i=na-1; i>0 && c[i]==0; i--);
  *nc = i + 1;
  return DA;
}

Log proizvod (const char a[], int na, const char b[], int nb,
              char c[], int *nc) {
  if (!nula(a,na) && !nula(b,nb)) {
    int i, j, p;
    *nc = na + nb;
    for (i=0; i<*nc; c[i++]=0);
    for (i=0; i<na; i++)
      for (p=j=0; j<nb || p; j++) {
        int d = c[i+j] + p;
        if (j < nb) d += a[i] * b[j];
        c[i+j] = d % 10; p = d / 10;
      }
    if (c[*nc-1] == 0) (*nc)--;
  } else { *nc = 1; c[0] = 0; }
  return DA;
}

Log kolicnik (const char a[], int na, const char b[], int nb,
              char c[], int *nc, char d[], int *nd) {
  int i, j, nn;
  if (nula (b, nb)) return NE;
  kopiraj (a, na, d, nd);
  nn = na - nb + 1;
  if (nn > 0) {
    *nc = nn; *nd = nb;
    for (i=*nc-1, j=na-nb; i>=0; i--, j--, (*nd)++) {
      c[i] = 0;
      while (uporedi (d+j, *nd, b, nb) >= 0) {
        razlika (d+j, *nd, b, nb, d+j, nd);
        c[i]++;
      }
    }
    if (*nc > 1 && c[*nc-1] == 0) (*nc)--;
    while (*nd>1 && d[*nd-1]==0) (*nd)--;
  } else {
    *nc = 1; c[0] = 0;
  }
  return DA;
}

Log  citaj   (char a[], int *n) {
  char broj[80]; int i, j;
  scanf ("%s", broj);
  for (i=0; broj[i]; i++)
    if (! isdigit (broj[i])) return NE;
  *n = i;
  for (i=*n-1, j=0; i>=0; a[i--]=broj[j++]-'0');
  while (*n>1 && a[*n-1] == 0) (*n)--;
  return DA;
}

void pisi    (const char a[], int n, int sir, Log grupe) {
  int i;
  printf ("%*s", (sir - n - (n-1)/3*grupe), "");
  for (i=n-1; i>=0; i--) {
    putchar (a[i] + '0');
    if (grupe && i % 3 == 0) putchar (' ');
  }
}
