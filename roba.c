/* roba.c - Obrada datoteke o zalihama robe u skladistu *******************/

#include "reldat.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Parametri sistema =====================================================*/
#define IME_DAT "roba.dat"          /* Ime datoteke o zalihama robe.      */
#define DUZ_SIF 10                  /* Duzina sifre artikla.              */
#define DUZ_NAZ 40                  /* Duzina naziva artikla.             */

/* Struktura zapisa u datoteci ===========================================*/
typedef struct {
  unsigned char sifra[DUZ_SIF], naziv[DUZ_NAZ];
  double cena, kolicina;
} Zapis;

/* Globalni podaci =======================================================*/
RelDat *dat;
Zapis   zapis;
char    sifra[DUZ_SIF];

/* Ispisivanje poruke o grešci ===========================================*/
char *greske[] = { "*** Neuspelo otvaranje datoteke",
                   "*** Neuspelo citanje zapisa",
                   "*** Neuspelo pisanje zapisa",
                   "--- Vec postoji artikal sa tom sifrom",
                   "--- Ne postoji artikal sa tom sifrom",
                   "--- Nedozvoljena cena",
                   "--- Nedozvoljeni iznos promene kolicine",
                   "--- Nedozvoljeni izbor"
                 };
typedef enum { F_OTV, F_CIT, F_PIS,
               G_IMA, G_NEMA, G_CENA, G_KOL, G_IZB } Greske;
void greska (Greske g) {
  printf ("\n%s!\n\a", greske[g]); if (greske[g][0] == '*') exit (g+1);
}

/* Pocetak rada sistema =================================================*/
void pocetak () {
  printf ("**********************************\n"
          "*            R O B A             *\n"
          "* obrada zaliha robe u skladistu *\n"
          "**********************************\n");
  if ((dat = rd_otvori (IME_DAT)) == 0                 &&
      (dat = rd_pravi  (IME_DAT, sizeof (Zapis))) == 0
  ) greska (F_OTV);
}

/* Zavrsetak rada sistema ================================================*/
void zavrsetak () {
  rd_zatvori (dat);
  putchar ('\n');
  printf ("**********************************\n"
          "*            R O B A             *\n"
          "*     uspesan zavrsetak rada     *\n"
          "**********************************\n");
  exit (0);
}

/* Trazenje zapisa sa zadatom sifrom =====================================*/
long nadji () {
  long d = 1, g = rd_brojzap (dat), s; int k;
  while (d <= g) {
    if (rd_citaj (dat, s=(d+g)/2, &zapis) == EOF) greska (F_CIT);
    if ((k = strcmp (sifra, zapis.sifra)) == 0)
      return s;
    else if (k < 0)
      g = s - 1;
    else
      d = s + 1;
  } return 0;
}

/* Citanje sifre artikla =================================================*/
long citaj (int novi) {
  while (1) {
    long k;
    printf   ("\nSifra artikla? "); scanf ("%s", sifra);
    if (sifra[0] == '.') return -1; /* Signal kraja */
    k = nadji ();
    if (novi) {
      if (k) greska (G_IMA); else return k;
    } else {
      if (k) {
        if (rd_citaj (dat, k, &zapis) == EOF) greska (F_CIT);
        putchar ('\n');
        printf ("Naziv artikla= %s\n",   zapis.naziv);
        printf ("Cena artikla = %.2f\n", zapis.cena);
        printf ("Kolicina     = %.2f\n", zapis.kolicina);
        return k;
      } else greska (G_NEMA);
    }
  }
}

/* Dodavanje novih zapisa ================================================*/
void dodavanje () {
  while (citaj (1) != -1) {
    Zapis novi; long k;
    strcpy (novi.sifra, sifra);
    printf ("Naziv artikla? "); scanf ("%s", &novi.naziv);
    printf ("Cena artikla?  "); scanf ("%lf", &novi.cena );
    novi.kolicina = 0;
    for (k=rd_brojzap(dat); k>0; k--) {
      if (rd_citaj (dat, k, &zapis) == EOF) greska (F_CIT);
    if (strcmp (zapis.sifra, novi.sifra) < 0) break;
      if (zapis.sifra[0] != 0xff)
        if (rd_pisi (dat, k+1, &zapis) == EOF) greska (F_PIS);
    }
    if (rd_pisi (dat, k+1, &novi) == EOF) greska (F_PIS);
  }
}

/* Brisanje zapisa =======================================================*/
void brisanje () {
  long k;
  while ((k = citaj (0)) != -1) {
    char odg[2]; int i;
    printf ("\nBrisati gornji zapis? "); scanf ("%s", odg);
    if (odg[0]=='d' || odg[0]=='D') {
      for (;k<rd_brojzap(dat); k++) {
        if (rd_citaj (dat, k+1, &zapis) == EOF) greska (F_CIT);
        if (rd_pisi  (dat, k,   &zapis) == EOF) greska (F_PIS);
      }
      for (i=0; i<DUZ_SIF; zapis.sifra[i++]=0xff);
      if (rd_pisi (dat, k, &zapis) == EOF) greska (F_PIS);
    }
  }
}

/* Promena cene artikala =================================================*/
void cena () {
  long k;
  while ((k = citaj (0)) != -1) {
    printf ("\nNova cena? "); scanf ("%lf", &zapis.cena);
    if (zapis.cena >= 0) {
      if (rd_pisi (dat, k, &zapis) == EOF) greska (F_PIS);
    } else greska (G_CENA);
  }
}

/* Promena kolicine artikala u skladistu =================================*/
void kolicina () {
  long k;
  while ((k = citaj (0)) != -1) {
    double promena;
    printf ("\nPromena kolicine? "); scanf ("%lf", &promena);
    if (zapis.kolicina + promena >= 0) {
      zapis.kolicina += promena;
      if (rd_pisi (dat, k, &zapis) == EOF) greska (F_PIS);
    } else greska (G_KOL);
  }
}

/* Prikaz stanja zaliha ==================================================*/
void zalihe () {
  long k; int i, n; double vrednost, ukupno=0;
  n = printf ("\n%-11.10s%-20.20s%12s%12s%15s\n",
              "Sifra", "Naziv artikla", "Cena", "Kolicina", "Vrednost")
      - 2;
  for (i=0; i<n; i++) putchar ('='); putchar ('\n');
  for (k=1; k<=rd_brojzap(dat); k++) {
    if (rd_citaj (dat, k, &zapis) == EOF) greska (F_CIT);
    if (zapis.sifra[0] != 0xff) {
      ukupno += (vrednost = zapis.cena * zapis.kolicina);
      printf ("%-11.10s%-20.20s%12.2f%12.2f%15.2f\n", zapis.sifra,
              zapis.naziv, zapis.cena, zapis.kolicina, vrednost);

    }
  }
  for (i=0; i<n; i++) putchar ('='); putchar ('\n');
  printf ("%-*s%20.2f\n", n-20, "U K U P N O", ukupno);
}

/* Izbor operacije nad datotekom =========================================*/
typedef void (*Fun) ();
Fun izbor () {
  while (1) {
    char izb[2];
    printf ("\n"
            "Moguce operacije su:\n"
            "\n"
            "1  Uvodjenje novih artikala u evidenciju\n"
            "2  Brisanje artikala iz evidencije\n"
            "3  Pormena cene artiklima\n"
            "4  Promene kolicine artikala u skladistu\n"
            "5  Prikaz stanja zaliha\n"
            "k  Kraj rada\n"
            "\n"
            "Unesite svoj izbor: "
           );
    scanf ("%s", izb);
    switch (izb[0]) {
      case '1': return dodavanje;
      case '2': return brisanje;
      case '3': return cena;
      case '4': return kolicina;
      case '5': return zalihe;
      case 'k': case 'K': return zavrsetak;
    }
    greska (G_IZB);
  }
}

/* Glavni program ========================================================*/
void main () { pocetak (); while (1) (*izbor ()) (); }

/**************************************************************************/
