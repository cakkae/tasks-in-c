/* redosled.c - Znacaj redosleda sabiranja realnih brojeva.               */

#include <stdio.h>

main () {
  long n, i;
  float s1, s2;
  while (1) {
    scanf ("%ld", &n);
  if (n <= 0) break;
    s1 = 0; for (i=1; i<=n; i++) s1 += 1. / i / i;
    s2 = 0; for (i=n; i>=1; i--) s2 += 1. / i / i;
    printf ("%7ld %10.6f %10.6f\n", n, s1, s2);
  }
}
