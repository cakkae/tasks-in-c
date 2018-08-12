/* skup3.h - Deklaracije paketa za obradu skupova.                        */

int sadrzi (const float *s1, int n1, float b);
void dodaj (float **s1, int *n1, float b);
void unija   (const float *s1, int n1, const float *s2, int n2,
              float **s3, int *n3);
void presek  (const float *s1, int n1, const float *s2, int n2,
              float **s3, int *n3);
void razlika (const float *s1, int n1, const float *s2, int n2,
              float **s3, int *n3);
void citaj (float **s, int *n);
void pisi (const float *s, int n, const char *f);
