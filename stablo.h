/* stablo.h - Deklaracije paketa za obradu binarnih stabala.              */

typedef struct cvor { int broj; struct cvor *levo, *desno; } Cvor;
typedef Cvor *Stablo;

Stablo stvori (void);                  /* Stavaranje praznog stabla.      */
int vel (Stablo stb);                  /* Broj cvorova u stablu.          */
int zbir (Stablo stb);                 /* Zbir brojeva u stablu.          */
void pisi_kld (Stablo stb);            /* Prefiksno ispisivanje.          */
void pisi_lkd (Stablo stb);            /* Infiksno ispisivanje.           */
void pisi_ldk (Stablo stb);            /* Postfiksno ispisivanje.         */
void crtaj (Stablo stb, int nivo);     /* Graficki prikaz stabla.         */
int pojav (Stablo stb, int b);         /* Broj pojavljivanja u stablu.    */
int min_u (Stablo stb);                /* Najmanji u uredjenom stablu.    */
int max_u (Stablo stb);                /* Najveci u uredjenom stablu.     */
int min_n (Stablo stb);                /* Najmanji u neuredjenom stablu.  */
int max_n (Stablo stb);                /* Najveci u neuredjenom stablu.   */
int uredjeno (Stablo stb);             /* Da li je stablo uredjeno?       */
Cvor *nadji_u (Stablo stb, int b);     /* Trazenje u uredjenom stablu.    */
Cvor *nadji_n (Stablo stb, int b);     /* Trazenje u neuredjenom stablu.  */
Stablo dodaj_u (Stablo stb, int b);    /* Dodavanje u uredjeno stablo.    */
Stablo dodaj_n (Stablo stb, int b);    /* Dodavanje u neuredjeno stablo.  */
Stablo citaj_u (int n);                /* Citanje uredjenog stabla.       */
Stablo citaj_n (int n);                /* Citanje neuredjenog stabla.     */
Stablo brisi (Stablo stb);             /* Brisanje celog stabla.          */
Stablo izost_u (Stablo stb, int b);    /* Izost. iz uredjenog stabla.     */
Stablo izost_n (Stablo stb, int b);    /* Izost. iz neuredjenog stabla.   */
Stablo balans_u (Stablo stb);          /* Balansiranje uredjenog stabla.  */
Stablo balans_n (Stablo stb);          /* Balansiranje neuredjenog satbla.*/
