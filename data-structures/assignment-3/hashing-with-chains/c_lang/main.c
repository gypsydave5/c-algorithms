#include <stdio.h>
#include "chain-hash.h"
#include "linked-list.h"

int main() {
  unsigned long long mod, command_count, i, bucket;
  char name[16], query[5];
  chain_hash *h;
  elt *e, *next;

  scanf("%lld\n", &mod);

  h = hash_init(mod);

  scanf("%lld\n", &command_count);

  for (i = 0; i < command_count; i++) {
    scanf("%s", query);
    switch (query[0]) {
      case 'a':
        scanf("%s\n", name);
        hash_add_word(h, name);
        break;
      case 'd':
        scanf("%s\n", name);
        hash_delete_word(h, name);
        break;
      case 'f':
        scanf("%s\n", name);
        if (hash_find_word(h, name)) {
          printf("yes\n");
        } else {
          printf("no\n");
        }
        break;
      case 'c':
        scanf("%lld\n", &bucket);
        e = hash_check_bucket(h, bucket);
        if (e->next == NULL) {
          printf("\n");
          break;
        }
        while (e->next->next != NULL) {
          next = e->next;
          printf("%s ", e->string);
          e = next;
        }
        printf("%s\n", e->string);
        break;
    }
  }
}
