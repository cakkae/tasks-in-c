/* stablot.c - Ispitivanje paketa za obradu binarnih stabala.             */

#include "stablo.h"
#include <stdio.h>

int moze (Stablo stb) { /* Da li moze uredjena radnja? */
  if (! uredjeno (stb)) {
    printf ("*** Stablo nije uredjeno! ***\a\n");
    return 0;
  }
  else return 1;
}

/* Primena operacije na stablo za svaki procitani broj: */
Stablo radi (Stablo (*f)(Stablo,int), Stablo stb) {
  int b; char zn;
  printf ("Brojevi?   ");
  do { scanf ("%d%c", &b, &zn); stb = (*f) (stb, b); } while (zn != '\n');
  return stb;                                          /* do kraja reda */
}

void main () {
  Stablo stb = stvori (); int kraj = 0, broj, n; char izbor[2];
  while (!kraj) {
    printf ("\nDodavanje brojeva:       a) uredjeno     b) neuredjeno\n"
              "Izostavljanje brojeva:   c) uredjeno     d) neuredjeno\n"
              "Citanje stabla:          e) uredjeno     f) neuredjeno\n"
              "Najmanji element:        g) uredjeno     h) neuredjeno\n"
              "Najveci element:         i) uredjeno     j) neuredjeno\n"
              "Pretrazivanje:           k) uredjeno     l) neuredjeno\n"
              "Balansiranje:            m) uredjeno     n) neuredjeno\n"
              "Pisanje stabla:          p) koren-levo-desno\n"
              "                         q) levo-koren-desno (uredjeno)\n"
              "                         r) levo-desno-kren\n"
              "                         s) crtanje\n"
              "1. Velicina stabla       2. Zbir elemenata\n"
              "3. Broj pojavljivanja    4. Praznjenje stabla\n"
              "                         0. Zavrsetak rada\n\n"
              "Vas izbor? "
            );
    scanf ("%s", &izbor);
    switch (izbor[0]) {
    case 'a': case 'A': /* Dodavanje brojeva u uredjeno stablo: */
      if (moze (stb)) stb = radi (dodaj_u, stb); break;
    case 'b': case 'B': /* Dodavanje brojeva u neuredjeno stablo: */
                      stb = radi (dodaj_n, stb); break;
    case 'c': case 'C': /* Izostavljanje brojeva iz uredjenog stabla: */
      if (moze (stb)) stb = radi (izost_u, stb); break;
    case 'd': case 'D': /* Izostavljanje brojeva iz neuredjenog stabla: */
                      stb = radi (izost_n, stb); break;
    case 'e': case 'E': /* Citanje uredjenog stabla: */
      printf ("Duzina?    "); scanf ("%d", &n);
      printf ("Brojevi?   "); stb = brisi (stb); stb = citaj_u (n);
      break;
    case 'f': case 'F': /* Citanje neuredjenog stabla: */
      printf ("Duzina?    "); scanf ("%d", &n);
      printf ("Brojevi?   "); stb = brisi (stb); stb = citaj_n (n);
      break;
    case 'g': case 'G': case 'h': case 'H':
    case 'i': case 'I': case 'j': case 'J':
      if (stb) switch (izbor[0]) {
        case 'g': case 'G': /* Najmanji element uredjenog stabla: */
          if (moze (stb)) printf ("min=       %d\n", min_u (stb)); break;
        case 'h': case 'H': /* Najmanji element neuredjenog stabla: */
                          printf ("min=       %d\n", min_n (stb)); break;
        case 'i': case 'I': /* Najveci element uredjenog stabla: */
          if (moze (stb)) printf ("max=       %d\n", max_u (stb)); break;
        case 'j': case 'J': /* Najveci element neuredjenog stabla: */
                          printf ("max=       %d\n", max_n (stb)); break;
      } else printf ("*** Stablo je parzno! ***\a\n");
      break;
    case 'k': case 'K': /* Broj pojavljivanja u uredjenom stablu: */
      if (moze (stb)) {
        printf ("Broj?      "); scanf ("%d", &broj);
        printf ("Broj se%s nalazi u stablu.\n",
                (nadji_u (stb, broj) != NULL ? "" : " NE"));
      } break;
    case 'l': case 'L': /* Broj pojavljivanja u neuredjenom stablu: */
        printf ("Broj?      "); scanf ("%d", &broj);
        printf ("Broj se%s nalazi u stablu.\n",
                (nadji_n (stb, broj) != NULL ? "" : " NE"));
        break;
    case 'm': case 'M': /* Balansiranje uredjenog stabla: */
      if (moze (stb)) stb = balans_u (stb); break;
    case 'n': case 'N': /* Balansiranje neuredjenog stabla: */
                      stb = balans_n (stb); break;
    case 'p': case 'P': /* Pisanje stabla koren-levo-desno: */
      printf ("Stablo=    "); pisi_kld (stb); putchar ('\n'); break;
    case 'q': case 'Q': /* Pisanje stabla levo-koren-desno: */
      printf ("Stablo=    "); pisi_lkd (stb); putchar ('\n'); break;
    case 'r': case 'R': /* Pisanje stabla levo-desno-koren: */
      printf ("Stablo=    "); pisi_ldk (stb); putchar ('\n'); break;
    case 's': case 'S': /* Crtanje stabla: */
      crtaj (stb, 0); break;
    case '1':           /* Velicina stabla: */
      printf ("Vel=       %d\n", vel (stb)); break;
    case '2':           /* Zbir elemenata stabla: */
      printf ("Zbir=      %d\n", zbir (stb)); break;
    case '3':           /* Broj pojavljivanja datog broja: */
      printf ("Broj?      "); scanf ("%d", &broj);
      printf ("Broj se pojavljuje %d puta.\n", pojav (stb, broj));
      break;
    case '4':           /* Praznjenje stabla: */
      stb = brisi (stb); break;
    case '0':           /* Zavrsetak rada: */
      kraj = 1; break;
    default: /* Pogresan izbor: */
      printf ("*** Neozvoljeni izbor! ***\a\n"); break;
    }
  }
}
