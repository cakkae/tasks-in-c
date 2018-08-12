/* sort4t.c - Ispitivanje algoritama uredjivanja nizova.                  */

#include "uredi4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Ispisivanje niza.                                                      */
void pisi (const char *nasl, Niz a, int n) {
  int i;
  printf ("\n%s\n\n", nasl);
  for (i=0; i<n; i++) {
    printf (FMTI, 7, 1, a[i]);
    if (i%10==9 || i==n-1) putchar ('\n');
  }
}

/* Glavni program.                                                        */
void main () {
  int duzina=1000, algoritam = 0;
  Elem *niz = malloc ((long)duzina*sizeof(Elem));
  int izbor, d, i;
  clock_t t1, t2;

  while (1) { /* Ispisivanje menija: */
    printf ("\n1. Zadavanje duzine niza\n"
              "2. Postavljanje generatora slucajnih brojeva\n"
              "3. Izbor algoritma\n"
              "4. Primena algoritma\n"
              "9. Kraj programa\n"
              "Vas izbor? ");
    scanf ("%d", &izbor);
    switch (izbor) {
      case 1: /* Zadavanje duzine niza: */
        printf ("Duzina niza? "); scanf ("%d", &d);
        if (d > 0){
          duzina = d;
          free (niz);
          niz = malloc ((long)duzina*sizeof(Elem));
        } else printf ("*** Nedozvoljena duzina!\n");
        break;
      case 2: /* Postavljanje generatora slucajnih brojeva: */
        printf ("Pocetna vrednost generatora? ");
        scanf ("%d", &d);
        srand (d);
        break;
      case 3: /* Izbor algoritma: */
        putchar ('\n');
        for (i=0; i<br_alg; i++)
          printf ("%d. %s\n", i+1, nazivi[i]);
        printf ("Vas izbor? "); scanf ("%d", &izbor);
        if (izbor>0 && izbor<=br_alg) algoritam = izbor - 1;
          else printf ("*** Nedozvoljeni izbor!\n");
        break;
      case 4: /* Primena algoritma: */
        for (i=0; i<duzina; niz[i++]=rand()/(RAND_MAX+1.)*1000);
        if (duzina <= 100) pisi ("Pocetni niz:", niz, duzina);
        t1 = clock ();
        (*metode[algoritam]) (niz, duzina);
        t2 = clock ();
        if (duzina <= 100)
          pisi ("Uredjeni niz:", niz, duzina);
        else
          printf ("%s (%d): %.3f\n", nazivi[algoritam],
                  duzina, (double)(t2-t1)/CLOCKS_PER_SEC);
        break;
      case 9: /* Kraj programa: */
        free (niz); exit (0);
      default: /* Pogresan izbor. */
        printf ("*** Nedozvoljeni izbor!\n");
        break;
    }
  }
}
