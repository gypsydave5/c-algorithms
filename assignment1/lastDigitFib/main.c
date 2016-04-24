#include "dumbLastDigit.h"
#include "lastDigitFib.h"
#include <stdio.h>

int main() {
  long long a;
  int result1, result2;
  scanf("%lld", &a);

  result1 = lastDigitFib(a);
  result2 = dumbLastDigit(a);
  printf("%d %d\n", result1, result2);
}
