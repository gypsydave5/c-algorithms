#include "lastDigitFib.h"
#include <stdio.h>

int lastDigitFib(long long x) {
  int toggle = 0;
  int a = 0;
  int b = 1;
  for (; x > 0; --x) {
    if (toggle == 0) {
      toggle = 1;
      /*printf("%d %d\n", a, b);*/
      b = (a + b) % 10;
    } else {
      toggle = 0;
      /*printf("%d %d\n", a, b);*/
      a = (a + b) % 10;
    }
  }
  if (toggle == 0) {
    return a;
  } else {
    return b;
  }
}
