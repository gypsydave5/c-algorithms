#include "fibModNaive.h"
#include "fibModPisano.h"
#include <stdio.h>
#include <stdlib.h>

void stressTest(unsigned long long (*f1)(unsigned long long,
                                         unsigned long long),
                unsigned long long (*f2)(unsigned long long,
                                         unsigned long long));

int main() { stressTest(fibModNaive, fibModPisano); }

void stressTest(unsigned long long (*f1)(unsigned long long,
                                         unsigned long long),
                unsigned long long (*f2)(unsigned long long,
                                         unsigned long long)) {
  while (1) {
    unsigned long long n = (rand() % 1000000000000000000) + 1;
    unsigned long long m = (rand() % 100000) + 2;
    printf("%lld %lld\n", n, m);

    int res1 = (f1)(n, m);
    int res2 = (f2)(n, m);

    if (res1 != res2) {
      printf("Wrong answer! naive: %d, pisano: %d\n", res1, res2);
      break;
    } else {
      printf("OK\n");
    }
  }
}