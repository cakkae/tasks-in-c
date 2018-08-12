/* razmak.c - Izostavljanje suvisnih razmaka izmedju reci
              u tekstualnoj datoteci.                                     */

#include <stdio.h>
#include <ctype.h>

void razmak (char *ul_ime, char *izl_ime) {
  FILE *ul_dat  = fopen (ul_ime,  "r"), *izl_dat = fopen (izl_ime, "w");
  if (ul_dat && izl_dat) {
    int zn, ima = 1;
    while ((zn = fgetc (ul_dat)) != EOF) {
      if (! isspace (zn)) {
        fputc (zn, izl_dat); ima = 0;
      } else {
        if (zn == '\n') fputc ('\n', izl_dat);
        else if (! ima) fputc (' ',  izl_dat);
        ima = 1;
      }
    }
  }
  if (izl_dat) fclose (izl_dat); if (ul_dat) fclose (ul_dat);
}

void main () {
  char ulaz[20], izlaz[20];
  while (1) {
    printf ("Ime ulazne  datoteke? "); scanf ("%s", ulaz);
  if (ulaz[0] == '.') break;
    printf ("Ime izlazne datoteke? "); scanf ("%s", izlaz);
  if (izlaz[0] == '.') break;
    razmak (ulaz, izlaz);
  }
}
