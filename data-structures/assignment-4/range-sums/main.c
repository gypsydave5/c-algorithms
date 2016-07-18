#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

#define MOD 1000000001

int main() {
  int commands, i, last_sum;
  last_sum = 0;

  node *root, *target;
  root = malloc(sizeof(*root));
  node_init(root);

  scanf("%d\n", &commands);

  for (i = 0; i < commands; i++) {
    char command;
    int number, number_two;
    scanf("%c ", &command);

    if (command == '+') {
      scanf("%d\n", &number);
      number = (number + last_sum) % MOD;
      target = find(root, number);
      if (!(target && target->value == number)) {
        insert(root, number);
      }
    }

    if (command == '-') {
      scanf("%d\n", &number);
      number = (number + last_sum) % MOD;
      target = find(root, number);
      if (target && target->value == number) {
        delete_node(&root, target);
      }
    }

    if (command == '?') {
      scanf("%d\n", &number);
      number = (number + last_sum) % MOD;
      target = find(root, number);
      if (target && target->value == number) {
        printf("Found\n");
      } else {
        printf("Not Found\n");
      }
    }

    if (command == 's') {
      scanf("%d %d\n", &number, &number_two);
      number = (number + last_sum) % MOD;
      number_two = (number_two + last_sum) % MOD;

      last_sum = btree_range_sum(&root, number, number_two);
      printf("%d\n", last_sum);
    }
  }
}
