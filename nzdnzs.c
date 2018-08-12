/* nzdnzs.c - Najveci zajednicki delilac i
              najmanji zajednicki sadrzalac dva broja.                    */

unsigned nzd (unsigned a, unsigned b) {
  while (b != 0) {
    unsigned c = b;
    b = a % b;
    a = c;
  }
  return a;
}

unsigned nzs (unsigned a, unsigned b) { return a * b / nzd (a, b); }
