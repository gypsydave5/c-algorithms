#include "gcdEuclid.h"
#include "gcdNaive.h"
#include <stdio.h>
#include <stdlib.h>

void stressTest(unsigned long long (*f1)(unsigned long long,
                                         unsigned long long),
                unsigned long long (*f2)(unsigned long long,
                                         unsigned long long));

int main() { stressTest(gcdNaive, gcdEuclid); }

void stressTest(unsigned long long (*f1)(unsigned long long,
                                         unsigned long long),
                unsigned long long (*f2)(unsigned long long,
                                         unsigned long long)) {
  while (1) {
    unsigned long long n = rand() % 1000000;
    unsigned long long m = rand() % 1000000;
    printf("%lld\n", n);

    unsigned long long res1 = (f1)(n, m);
    unsigned long long res2 = (f2)(n, m);

    if (res1 != res2) {
      printf("Wrong answer! naive: %lld, euclid: %lld\n", res1, res2);
      break;
    } else {
      printf("OK\n");
    }
  }
}