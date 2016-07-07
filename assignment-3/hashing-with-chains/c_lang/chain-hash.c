#include <stdio.h>
#include <stdlib.h>
#include "chain-hash.h"
#include "hash-function.h"
#include "linked-list.h"

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
