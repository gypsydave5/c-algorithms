#include <math.h>
#include <stdio.h>
#include "hash-function.h"

static int P = 1000000007;

unsigned long long hash_function(unsigned long long mod, char string[]) {
  char c;
  unsigned long long tmp, i, res, j, x;
  c = 'a';
  i = 0;
  tmp = 0;

  while (string[i] != '\0') {
    c = string[i];
    x = 1;

    for (j = 0; j < i; j++) {
      x *= 263;
      x %= P;
    }

    x *= c;
    x %= P;
    tmp += x;
    tmp = tmp % P;
    i++;
  }

  res = ((tmp % P) + P) % P;
  res = ((res % mod) + mod) % mod;
  return res;
}
