#include <stdio.h>
#include <strings.h>
#include "is_balanced.h"

int main() {
  char str[1000000];
  int res;
  scanf("%s\n", str);

  res = is_balanced_array_stack(str);

  printf("%s", str);
}