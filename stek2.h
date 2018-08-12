/* stek2.h - Deklaracije paketa za stekove neogranicenog kapaciteta.      */

typedef struct elem { int broj; struct elem *sled; } Elem;
typedef Elem *Stek;

Stek stvori (void);                     /* Stvaranje praznog steka.       */
void stavi (Stek *stk, int b);          /* Stavljanje broja na stek.      */
int uzmi (Stek *stk);                   /* Uzimanje broja sa steka.       */
int prazan (Stek stk);                  /* Da li je stek prazan?          */
void pisi (Stek stk);                   /* Ispisivanje sadrzaja steka.    */
void prazni (Stek *stk);                /* Praznjenje steka.              */
void unisti (Stek *stk);                /* Unistavanje steka.             */
