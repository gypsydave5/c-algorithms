#include "smallFibArray.h"
#include "smallFibRecursion.h"
#include <stdio.h>

int main() {
  int a;
  long long result;
  scanf("%d", &a);

  result = smallFibArray(a);
  printf("%lld\n", result);
}
