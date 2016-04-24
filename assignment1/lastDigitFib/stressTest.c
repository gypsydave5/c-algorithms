#include "dumbLastDigit.h"
#include "lastDigitfib.h"
#include <stdio.h>
#include <stdlib.h>

void stressTest(int (*f1)(long long), int (*f2)(long long));

int main() { stressTest(dumbLastDigit, lastDigitFib); }

void stressTest(int (*f1)(long long), int (*f2)(long long)) {
  while (1) {
    long long n = rand() % 100000;
    printf("%lld\n", n);

    int res1 = (f1)(n);
    int res2 = (f2)(n);

    if (res1 != res2) {
      printf("Wrong answer! dumb: %d, better: %d\n", res1, res2);
      break;
    } else {
      printf("OK\n");
    }
  }
}