/* lista3.c - Jos funkcija za obradu lista.                               */

#include "lista.h"
#include <stdio.h>

Elem *obrni (Elem *lst) {          /* Obrtanje redosleda elemenata.       */
  Elem *tek = lst, *pret = NULL;
  while (tek) {
    Elem *sled = tek->sled;
    tek->sled = pret;
    pret = tek;
    tek = sled;
  }
  return pret;
}

void uredi (Elem *lst) {           /* Uredjivanje liste.                  */
  Elem *i, *j;
  for (i=lst; i; i=i->sled)
    for (j=i->sled; j; j=j->sled)
      if (j->broj < i->broj) {
        int b = i->broj; i->broj = j->broj; j->broj = b;
      }
}

Elem *fuzija (Elem *lst1, Elem *lst2) { /* Fuzija dve uredjene liste.     */
  Elem *lst = NULL, *posl=NULL, *tek;
  while (lst1 && lst2) {
    if (lst1->broj < lst2->broj) { tek = lst1; lst1 = lst1->sled; }
      else                       { tek = lst2; lst2 = lst2->sled; }
    tek->sled = NULL;
    if (!lst) lst = tek; else posl->sled = tek;
    posl = tek;
  }
  if (lst1) { if (!lst) lst = lst1; else posl->sled = lst1; }
    else    { if (!lst) lst = lst2; else posl->sled = lst2; }
  return lst;
}

void main () {                     /* Glavni program.                     */
  while (1) {
    Elem *lst1, *lst2, *lst3; int n;
    printf ("Duzina prve liste?    "); scanf ("%d", &n);
  if (n <0) break;
    printf ("Elementi prve liste?  "); lst1 = citaj2 (n);
    if (n == 0) putchar ('\n');
    printf ("Duzina druge liste?   "); scanf ("%d", &n);
  if (n <0) break;
    printf ("Elementi druge liste? "); lst2 = citaj2 (n);
    if (n == 0) putchar ('\n');
    lst1 = obrni (lst1);
    printf ("Obrnuta prva lista:   "); pisi (lst1); putchar ('\n');
    lst2 = obrni (lst2);
    printf ("Obrnuta druga lista:  "); pisi (lst2); putchar ('\n');
    uredi (lst1);
    printf ("Uredjena prva lista:  "); pisi (lst1); putchar ('\n');
    uredi (lst2);
    printf ("Uredjena druga lista: "); pisi (lst2); putchar ('\n');
    lst3 = fuzija (lst1, lst2);
    printf ("Fuzija obe liste:     "); pisi (lst3); printf ("\n\n");
    brisi (lst3);
  }
}


    