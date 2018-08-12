/* stablo.c - Definicije paketa za obradu binarnih stabala.               */

#include "stablo.h"
#include <stdio.h>
#include <stdlib.h>

Stablo stvori (void) { return NULL; }  /* Stavaranje praznog stabla.      */

int vel (Stablo stb)                   /* Broj cvorova u stablu.          */
  { return stb ? 1 + vel (stb->levo) + vel (stb->desno) : 0; }

int zbir (Stablo stb)                  /* Zbir brojeva u stablu.          */
  { return stb ? stb->broj + zbir (stb->levo) + zbir (stb->desno) : 0; }

void pisi_kld (Stablo stb) {           /* Prefiksno ispisivanje.          */
  if (stb) {
    printf ("%d ", stb->broj); pisi_kld (stb->levo); pisi_kld (stb->desno);
  }
}

void pisi_lkd (Stablo stb) {           /* Infiksno ispisivanje.           */
  if (stb) {
    pisi_lkd (stb->levo); printf ("%d ", stb->broj); pisi_lkd (stb->desno);
  }
}

void pisi_ldk (Stablo stb) {           /* Postfiksno ispisivanje.         */
  if (stb) {
    pisi_ldk (stb->levo); pisi_ldk (stb->desno); printf ("%d ", stb->broj);
  }
}

void crtaj (Stablo stb, int nivo) {    /* Graficki prikaz stabla.         */
  if (stb) {
    crtaj (stb->desno, nivo+1);
    printf ("%*s%d\n", 4*nivo, "", stb->broj);
    crtaj (stb->levo,  nivo+1);
  }
}

int pojav (Stablo stb, int b)          /* Broj pojavljivanja u stablu.    */
  { return stb ? (stb->broj==b)+pojav(stb->levo,b)+pojav(stb->desno,b) : 0;}

int min_u (Stablo stb)                 /* Najmanji u uredjenom stablu.    */
  { return stb->levo  ? min_u (stb->levo ) : stb->broj; }

int max_u (Stablo stb)                 /* Najveci u uredjenom stablu.     */
  { return stb->desno ? max_u (stb->desno) : stb->broj; }

int min_n (Stablo stb) {               /* Najmanji u neuredjenom stablu.  */
  int m = stb->broj, k;
  if (stb->levo ) { k = min_n (stb->levo ); if (k < m) m = k; }
  if (stb->desno) { k = min_n (stb->desno); if (k < m) m = k; }
  return m;
}

int max_n (Stablo stb) {               /* Najveci u neuredjenom stablu.   */
  int m = stb->broj, k;
  if (stb->levo ) { k = max_n (stb->levo ); if (k > m) m = k; }
  if (stb->desno) { k = max_n (stb->desno); if (k > m) m = k; }
  return m;
}

int uredjeno (Stablo stb) {            /* Da li je stablo uredjeno?       */
  if (! stb) return 1;
  if (stb->levo  && (! uredjeno (stb->levo ) ||
                     max_u (stb->levo)  > stb->broj)) return 0;
  if (stb->desno && (! uredjeno (stb->desno) ||
                     min_u (stb->desno) < stb->broj)) return 0;
  return 1;
}

Cvor *nadji_u (Stablo stb, int b) {    /* Trazenje u uredjenom stablu.    */
  if (! stb)          return NULL;
  if (stb->broj == b) return stb;
  if (stb->broj >  b) return nadji_u (stb->levo,  b);
                      return nadji_u (stb->desno, b);
}

Cvor *nadji_n (Stablo stb, int b) {    /* Trazenje u neuredjenom stablu.  */
  if (! stb)          return NULL;
  if (stb->broj == b) return stb;
  { Cvor *cvr = nadji_n (stb->levo, b); if (cvr) return cvr; }
  return nadji_n (stb->desno, b);
}

Stablo dodaj_u (Stablo stb, int b) {   /* Dodavanje u uredjeno stablo.    */
  if (! stb) {
    stb = malloc (sizeof(Cvor));
    stb->broj = b; stb->levo = stb->desno = NULL;
  } else if (stb->broj > b)
    stb->levo  = dodaj_u (stb->levo,  b);
  else if (stb->broj < b)
    stb->desno = dodaj_u (stb->desno, b);
  else if (rand() / (RAND_MAX+1.) < 0.5)
    stb->levo  = dodaj_u (stb->levo,  b);
  else
    stb->desno = dodaj_u (stb->desno, b);
  return stb;
}

Stablo dodaj_n (Stablo stb, int b) {   /* Dodavanje u neuredjeno stablo.  */
  if (! stb) {
    stb = malloc (sizeof(Cvor));
    stb->broj = b; stb->levo = stb->desno = NULL;
  } else if (rand() / (RAND_MAX+1.) < 0.5)
    stb->levo  = dodaj_u (stb->levo,  b);
  else
    stb->desno = dodaj_u (stb->desno, b);
  return stb;
}

Stablo citaj_u (int n) {               /* Citanje uredjenog stabla.       */
  Stablo stb = NULL; int i, b;
  for (i=0; i<n; i++) { scanf ("%d", &b); stb = dodaj_u (stb, b); }
  return stb;
}

Stablo citaj_n (int n) {               /* Citanje neuredjenog stabla.     */
  Stablo stb = NULL; int i, b;
  for (i=0; i<n; i++) { scanf ("%d", &b); stb = dodaj_n (stb, b); }
  return stb;
}

Stablo brisi (Stablo stb) {            /* Brisanje celog stabla.          */
  if (stb) {
    stb->levo = brisi (stb->levo); stb->desno = brisi (stb->desno);
    free (stb); stb = NULL;
  }
  return stb;
}

Stablo izost_u (Stablo stb, int b) {   /* Izost. iz uredjenog stabla.     */
  if (stb) {
    if      (stb->broj > b) stb->levo  = izost_u (stb->levo,  b);
    else if (stb->broj < b) stb->desno = izost_u (stb->desno, b);
    else if (stb->levo) {
      int m = max_u (stb->levo);
      stb->broj = m; stb->levo  = izost_u (stb->levo,  m);
    } else if (stb->desno) {
      int m = min_u (stb->desno);
      stb->broj = m; stb->desno = izost_u (stb->desno, m);
    } else {
      free (stb); stb = NULL;
    }
  }
  return stb;
}

Stablo izost_n (Stablo stb, int b) {   /* Izost. iz neuredjenog stabla.   */
  if (stb) {
    if (stb->broj == b) {
      if        (stb->levo ) {
        stb->broj  = stb->levo->broj;
        stb->levo  = izost_n (stb->levo, stb->broj);
      } else if (stb->desno) {
        stb->broj  = stb->desno->broj;
        stb->desno = izost_n (stb->desno, stb->broj);
      } else { free (stb); stb = NULL; }
    } else {
      int v = vel (stb->levo);  stb->levo  = izost_n (stb->levo,  b);
      if (v == vel (stb->levo)) stb->desno = izost_n (stb->desno, b);
    }
  }
  return stb;
}

Stablo balans_u (Stablo stb) {         /* Balansiranje uredjenog stabla.  */
  if (stb) {
    int k = vel (stb->levo) - vel (stb->desno);
    for (; k>1; k-=2) {
      stb->desno = dodaj_u (stb->desno, stb->broj);
      stb->broj  = max_u (stb->levo );
      stb->levo  = izost_u (stb->levo , stb->broj);
    }
    for (; k<-1; k+=2) {
      stb->levo  = dodaj_u (stb->levo , stb->broj);
      stb->broj  = min_u (stb->desno);
      stb->desno = izost_u (stb->desno, stb->broj);
    }
    stb->levo  = balans_u (stb->levo );
    stb->desno = balans_u (stb->desno);
  }
  return stb;
}

Stablo balans_n (Stablo stb) {         /* Balansiranje neuredjenog satbla.*/
  if (stb) {
    int k = vel (stb->levo) - vel (stb->desno);
    for (; k>1; k-=2) {
      stb->desno = dodaj_n (stb->desno, stb->broj);
      stb->broj  = stb->levo ->broj;
      stb->levo  = izost_n (stb->levo , stb->broj);
    }
    for (; k<-1; k+=2) {
      stb->levo  = dodaj_n (stb->levo , stb->broj);
      stb->broj  = stb->desno->broj;
      stb->desno = izost_n (stb->desno, stb->broj);
    }
    stb->levo  = balans_n (stb->levo );
    stb->desno = balans_n (stb->desno);
  }
  return stb;
}
