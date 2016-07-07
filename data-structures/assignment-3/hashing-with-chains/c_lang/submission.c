#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct elt {
  struct elt *next;
  char string[16];
} elt;

typedef struct chain_hash {
  elt **buckets;
  unsigned long long mod;
} chain_hash;

static int P = 1000000007;

unsigned long long pow_ull(unsigned long long x, unsigned long long e) {
  unsigned long long res;
  res = 1;
  while (e > 0) {
    res *= x;
    e--;
  }
  return res;
}

unsigned long long hash_function(unsigned long long mod, char string[]) {
  char c;
  unsigned long long tmp, i, res, j, x;
  c = 'a';
  i = 0;
  tmp = 0;

  while (string[i] != '\0') {
    c = string[i];
    x = 1;

    for (j = 0; j < i; j++) {
      x *= 263;
      x %= P;
    }

    x *= c;
    x %= P;
    tmp += x;
    tmp = tmp % P;
    i++;
  }

  res = ((tmp % P) + P) % P;
  res = ((res % mod) + mod) % mod;
  return res;
}

elt *ll_init() { return NULL; }

void ll_destroy(elt **head) {
  elt *current, *next;
  current = *head;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

elt *ll_push(elt *head, char str[]) {
  elt *new_el;
  new_el = malloc(sizeof(elt));
  strcpy(new_el->string, str);
  new_el->next = head;
  return new_el;
}

elt *ll_remove(elt *e, char str[]) {
  if (e->next == NULL) {
    if (strcmp(e->string, str) == 0) {
      free(e);
      return NULL;
    }
    return e;
  }

  if (strcmp(e->string, str) == 0) {
    elt *temp;
    temp = e;
    e = e->next;
    free(temp);
    return e;
  }

  if (strcmp(e->next->string, str) == 0) {
    if (e->next->next == NULL) {
      free(e->next->next);
      e->next = NULL;
      return e;
    }

    elt *temp;
    temp = e->next;
    e->next = e->next->next;
    free(temp);
    return e;
  }

  e->next = ll_remove(e->next, str);
  return e;
}

int ll_find(elt *e, char str[]) {
  if (e == NULL) {
    return 0;
  }
  if (strcmp(e->string, str) == 0) {
    return 1;
  }
  if (e->next == NULL) {
    return 0;
  }
  return ll_find(e->next, str);
}

elt *ll_upsert(elt *head, char str[]) {
  if (ll_find(head, str)) {
    return head;
  }
  return ll_push(head, str);
}

chain_hash *hash_init(unsigned long long mod) {
  unsigned long long i;
  elt **array_of_elts = malloc(mod * sizeof(elt *));

  chain_hash *ch = malloc(sizeof(chain_hash));
  ch->mod = mod;
  ch->buckets = array_of_elts;

  for (i = 0; i < mod; i++) {
    ch->buckets[i] = malloc(sizeof(elt));
    ch->buckets[i]->string[0] = '\0';
    ch->buckets[i]->next = NULL;
  }

  return ch;
}

void hash_add_word(chain_hash *h, char string[]) {
  unsigned long long bucket;
  bucket = hash_function(h->mod, string);
  h->buckets[bucket] = ll_upsert(h->buckets[bucket], string);
}

int hash_find_word(chain_hash *h, char string[]) {
  unsigned long long bucket;
  bucket = hash_function(h->mod, string);
  return ll_find(h->buckets[bucket], string);
}

void hash_delete_word(chain_hash *h, char string[]) {
  unsigned long long bucket;
  bucket = hash_function(h->mod, string);
  h->buckets[bucket] = ll_remove(h->buckets[bucket], string);
}

elt *hash_check_bucket(chain_hash *h, unsigned long long bucket) {
  return h->buckets[bucket];
}

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
