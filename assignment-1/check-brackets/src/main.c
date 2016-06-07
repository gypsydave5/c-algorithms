#include <stdio.h>
#include "is_balanced.h"

int main() {
  char str[1000000];
  int res;
  scanf("%s", str);

  res = is_balanced_array_stack(str);

  if (res < 0) {
    printf("Success\n");
  } else {
    printf("%d\n", res);
  }
}