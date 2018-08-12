/* reldat.h - Deklaracije paketa za obradu relativnih datoteka.           */

#ifndef _reldat_h_
#define _reldat_h_

#include <stdio.h>

typedef struct {
  FILE *dat;         /* Pokazivac na datoteku.  */
  int   duz;         /* Duzina zapisa.          */
  long  bzap;        /* Broj zapisa u datoteci. */
} RelDat;

RelDat *rd_pravi (const char *ime, int duz); /* Stvaranje nove datoteke.  */
RelDat *rd_otvori (const char *ime);         /* Otvaranje stare datoteke. */
int rd_pisi  (RelDat *dat, long k, const void *zap); /* Upisivanje zapisa.*/
int rd_citaj (RelDat *dat, long k, void *zap);       /* Citanje zapisa.   */
long rd_brojzap (RelDat *dat);               /* Broj zapisa u datoteci.   */
int rd_zatvori (RelDat *dat);                /* Zatvaranje datoteke.      */

#endif
