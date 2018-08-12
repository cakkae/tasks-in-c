/* stek1t.c - Ispitivanje paketa za stekove ogranicenog kapacieta.        */

#include "stek1.h"
#include <stdio.h>

int main () {
  Stek stk = stvori (10); int k, b, izbor, kraj = 0;
  while (! kraj) {
    printf ("\n1. Stavaranje steka\n"
              "2. Stavljanje podatka na stek\n"
              "3. Uzimanje podatka sa steka\n"
              "4. Ispisivanje sadrzaja steka\n"
              "5. Praznjenje steka\n"
              "0. Zavrsetak rada\n\n"
              "Vas izbor? "
            );
    scanf ("%d", &izbor);
    switch (izbor) {
    case 1: /* Stvaranje novog steka: */
      printf ("Kapacitet? "); scanf ("%d", &k);
      if (k > 0) { unisti (&stk); stk = stvori (k); }
        else printf ("*** Nedozvoljeni kapacitet! ***\a\n");
      break;
    case 2: /* Stavljanje podatka na stek: */
      if (! pun (stk)) {
        printf ("Broj?      "); scanf ("%d", &b); stavi (&stk, b);
      } else printf ("*** Stek je pun! ***\a\n");
      break;
    case 3: /* Uzimanje broja sa steka: */
      if (! prazan (stk))
        printf ("Broj=      %d\n", uzmi (&stk));
      else printf ("*** Stek je prazan! ***\a\n");
      break;
    case 4: /* Ispisivanje sadrzaja steka: */
      printf ("Stek=      "); pisi (stk); putchar ('\n');
      break;
    case 5: /* Praznjenje steka: */
      prazni (&stk); break;
    case 0: /* Zavrsetak rada: */
      kraj = 1; break;
    default: /* Pogresan izbor: */
      printf ("*** Neozvoljeni izbor! ***\a\n"); break;
    }
  }
  return 0;
}
