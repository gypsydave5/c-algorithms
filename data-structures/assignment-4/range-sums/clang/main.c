#include <stdio.h>
#include "btree.h"

#define MOD 1000000001

int main() {
  unsigned long long commands, i, number, upper, lower, last_sum;
  last_sum = 0;

  node *root;
  root = 0;

  scanf("%lld\n", &commands);

  for (i = 0; i < commands; i++) {
    char command;
    scanf("%c ", &command);

    if (command == '+') {
      scanf("%lld\n", &number);
      number = (number + last_sum) % MOD;
      treeInsert(&root, number);
    }

    if (command == '-') {
      scanf("%lld\n", &number);
      number = (number + last_sum) % MOD;
      treeRemove(&root, number);
    }

    if (command == '?') {
      scanf("%lld\n", &number);
      number = (number + last_sum) % MOD;

      if (treeContains(&root, number)) {
        printf("Found\n");
      } else {
        printf("Not found\n");
      }
    }

    if (command == 's') {
      scanf("%lld %lld\n", &lower, &upper);
      lower = (lower + last_sum) % MOD;
      upper = (upper + last_sum) % MOD;

      last_sum = treeSumRange(&root, lower, upper);

      printf("%lld\n", last_sum);
    }
  }
}
