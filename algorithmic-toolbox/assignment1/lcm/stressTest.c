#include "gcdEuclid.h"
#include "lcmEuclid.h"
#include "lcmNaive.h"
#include <stdio.h>
#include <stdlib.h>

void stressTest(unsigned long long (*f1)(unsigned long long,
                                         unsigned long long),
                unsigned long long (*f2)(unsigned long long,
                                         unsigned long long));

int main() { stressTest(lcmNaive, lcmEuclid); }

void stressTest(unsigned long long (*f1)(unsigned long long,
                                         unsigned long long),
                unsigned long long (*f2)(unsigned long long,
                                         unsigned long long)) {
  while (1) {
    unsigned long long n = ((rand() % 1000) * 2) + 1;
    unsigned long long m = ((rand() % 1000) * 2) + 1;
    printf("%lld %lld\n", n, m);

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