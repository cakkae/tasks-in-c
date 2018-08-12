/* skup3.c - Definicije paketa za obradu skupova.                         */

#include "skup3.h"
#include <stdio.h>
#include <stdlib.h>

int sadrzi (const float *s1, int n1, float b) {
  int d = 0, g = n1-1, p;
  while (d <= g)
    if      (s1[p=(d+g)/2] == b) return 1;
    else if (s1[p] < b)          d = p + 1;
    else                         g = p - 1;
  return 0;
}

void dodaj (float **s1, int *n1, float b) {
  float *s = *s1; int n = *n1, i;
  if (! sadrzi (s, n, b)) {
    *s1 = s = realloc (s, (n+1) * sizeof(float));
    for (i=n-1; i>=0 && s[i]>b; i--) s[i+1] = s[i];
    s[i+1] = b;
    *n1 = n + 1;
  }
}

void unija   (const float *s1, int n1, const float *s2, int n2,
              float **s3, int *n3) {
  int n = 0, i1 = 0, i2 = 0;
  float *s = malloc ((n1+n2) * sizeof(float));
  while (i1<n1 || i2<n2)
    if      (i1 == n1)        s[n++] = s2[i2++];
    else if (i2 == n2)        s[n++] = s1[i1++];
    else if (s1[i1] < s2[i2]) s[n++] = s1[i1++];
    else if (s1[i1] > s2[i2]) s[n++] = s2[i2++];
    else                      s[n++] = s1[i1++], i2++;
  *s3 = realloc (s, (*n3=n) * sizeof(float));
}

void presek  (const float *s1, int n1, const float *s2, int n2,
              float **s3, int *n3) {
  int n = 0, i1 = 0, i2 = 0;
  float *s = malloc ((n1<n2 ? n1 : n2) * sizeof(float));
  while (i1<n1 && i2<n2)
    if      (s1[i1] < s2[i2]) i1++;
    else if (s1[i1] > s2[i2]) i2++;
    else                      s[n++] = s1[i1++], i2++;
  *s3 = realloc (s, (*n3=n) * sizeof(float));
}

void razlika (const float *s1, int n1, const float *s2, int n2,
              float **s3, int *n3) {
  int n = 0, i1 = 0, i2 = 0;
  float *s = malloc (n1 * sizeof(float));
  while (i1<n1)
    if      (i2 == n2)        s[n++] = s1[i1++];
    else if (s1[i1] < s2[i2]) s[n++] = s1[i1++];
    else if (s1[i1] > s2[i2]) i2++;
    else                      i1++, i2++;
  *s3 = realloc (s, (*n3=n) * sizeof(float));
}

void citaj (float **s1, int *n1) {
  int n, i; float *s;
  scanf ("%d", &n); *n1 = n;
  if (n >= 0) {
    *s1 = s = malloc (n * sizeof(float));
    for (i=0; i<n; scanf ("%f", &s[i++]));
  } else *s1 = 0;
}

void pisi (const float *s, int n, const char *f) {
  int i;
  putchar ('{');
  for (i=0; i<n; i++) {
    if (i > 0) putchar (',');
    printf (f, s[i]);
  }
  putchar ('}');
}
