/* pozpravi.c - Stvaranje pocetne datoteke.                               */

#include <stdio.h>

typedef struct {
  char citalac[21], naslov[31], autor[21];
  long inv_br, uzeta, rok;
} Pozajm;

void main () {
  FILE *ul  = fopen("pozajm.pod", "r"),
       *izl = fopen("pozajm.dat", "wb");
  Pozajm pozajm={0}, prazno={0};
  while (fscanf (ul, "%s%ld%s%s%ld%ld",
                 &pozajm.citalac, &pozajm.inv_br, &pozajm.naslov,
                 &pozajm.autor, &pozajm.uzeta, &pozajm.rok) != EOF) {
    fwrite (&pozajm, sizeof(Pozajm), 1, izl);
    pozajm = prazno;
  }
}
