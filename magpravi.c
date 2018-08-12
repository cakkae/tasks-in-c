/* magpravi.c - Stvaranje pocetne datoteke.                               */

#include <stdio.h>

void main () {
  typedef struct { char naziv[30]; float kolicina, cena; } Zapis;
  Zapis zapis;
  FILE *pod = fopen ("magacin.pod", "r"),
       *dat = fopen ("magacin.dat", "wb");
  while (fscanf (pod, "%s%f%f", &zapis.naziv, &zapis.kolicina,
                                &zapis.cena) != EOF)
    fwrite (&zapis, sizeof(Zapis), 1, dat);
}
