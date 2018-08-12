/* skup1.c - Obrada skupova realnih brojeva.                              */

#include <stdio.h>
#include <stdlib.h>

main () {

  float *s1, *s2, *s3;
  int n1, n2, n3, i, j;

  while (1) {

    /* Citanje podataka: */
    printf ("\nn1?    "); scanf ("%d", &n1);
  if (n1<0) break;
    s1 = malloc (n1*sizeof(float));
    printf ("S1?    "); for (i=0; i<n1; scanf ("%f", &s1[i++]));
    if (n1 == 0) printf ("\n");
    printf ("n2?    "); scanf("%d", &n2);
  if (n2<0) break;
    s2 = malloc (n2*sizeof(float));
    printf ("S2?    "); for (i=0; i<n2; scanf ("%f", &s2[i++]));
    if (n2 == 0) printf ("\n");

    /* Unija dva skupa: */
    s3 = malloc ((n1+n2)*sizeof(float));
    for (n3=0; n3<n1; n3++) s3[n3] = s1[n3];
    for (j=0; j<n2; j++) {
      for (i=0; i<n1 && s1[i]!=s2[j]; i++);
      if (i == n1) s3[n3++] = s2[j];
    }
    s3 = realloc (s3, n3*sizeof(float));
    printf ("s1+s2= "); for (i=0; i<n3; printf ("%.2f ", s3[i++]));
    printf ("\n");
    free (s3);

    /* Presek dva skupa: */
    s3 = malloc ((n1<n2?n1:n2)*sizeof(float));
    for (n3=i=0; i<n1; i++) {
      for (j=0; j<n2 && s1[i]!=s2[j]; j++);
      if (j < n2) s3[n3++] = s1[i];
    }
    s3 = realloc (s3, n3*sizeof(float));
    printf ("s1*s2= "); for (i=0; i<n3; printf ("%.2f ", s3[i++]));
    printf ("\n");
    free (s3);

    /* Razlika dva skupa: */
    s3 =  malloc (n1*sizeof(float));
    for (n3=i=0; i<n1; i++) {
      for (j=0; j<n2 && s1[i]!=s2[j]; j++);
      if (j == n2) s3[n3++] = s1[i];
    }
    s3 =  realloc (s3, n3*sizeof(float));
    printf ("s1-s2= "); for (i=0; i<n3; printf ("%.2f ", s3[i++]));
    printf ("\n");
    free (s3);

    free (s1); free (s2);
  }
}
