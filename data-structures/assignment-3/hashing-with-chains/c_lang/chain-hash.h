#pragma once
#include "linked-list.h"

typedef struct chain_hash {
  elt **buckets;
  unsigned long long mod;
} chain_hash;

chain_hash *hash_init(unsigned long long mod);
void hash_add_word(chain_hash *h, char string[]);
void hash_delete_word(chain_hash *h, char string[]);
int hash_find_word(chain_hash *h, char string[]);
elt *hash_check_bucket(chain_hash *h, unsigned long long bucket);
