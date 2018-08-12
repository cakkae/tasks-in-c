/* red2.h - Deklaracije paketa za redove neogranicenog kapaciteta.        */

typedef struct elem { int broj; struct elem *sled; } Elem;
typedef struct { Elem *prvi, *posl; } Red;

Red stvori (void);                      /* Stvaranje praznog reda.        */
void stavi (Red *rd, int b);            /* Stavljanje broja u red.        */
int uzmi (Red *rd);                     /* Uzimanje broja iz reda.        */
int prazan (Red rd);                    /* Da li je red prazan?           */
void pisi (Red rd);                     /* Ispisivanje sadrzaja reda.     */
void prazni (Red *rd);                  /* Praznjenje reda.               */
void unisti (Red *rd);                  /* Unistavanje reda.              */
