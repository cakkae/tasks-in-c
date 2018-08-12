/* magpisi.c - Ispisivanje sadrzaja datoteke.                             */

#include <stdio.h>

void main () {
  typedef struct { char naziv[30]; float kolicina, cena; } Zapis;
  Zapis zapis; int sifra = 0;
  FILE *dat = fopen ("magacin.dat", "rb");
  while (fread (&zapis, sizeof(Zapis), 1, dat) > 0)
    printf ("%2d %-20.20s %10.2f %10.2f\n",
            ++sifra, zapis.naziv, zapis.kolicina, zapis.cena);
}
