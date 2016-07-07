#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chain-hash.h"

void testInitializeHash() {
  chain_hash *h;
  h = hash_init(5);
  assert(h->mod == 5);

  strcpy(h->buckets[0]->string, "hello");
  assert(strcmp(h->buckets[0]->string, "hello") == 0);
}

void testAddWord() {
  chain_hash *h;
  h = hash_init(5);

  hash_add_word(h, "world");
  assert(strcmp(h->buckets[4]->string, "world") == 0);
}

void testFindWord() {
  chain_hash *h;
  h = hash_init(5);

  hash_add_word(h, "world");

  int has_world, has_foo;
  has_world = hash_find_word(h, "world");
  has_foo = hash_find_word(h, "foo");
  assert(has_world);
  assert(!has_foo);
}

void testDeleteWord() {
  int has_fooby;
  chain_hash *h;
  h = hash_init(5);

  hash_add_word(h, "fooby");
  has_fooby = hash_find_word(h, "fooby");
  assert(has_fooby);

  hash_delete_word(h, "fooby");
  has_fooby = hash_find_word(h, "fooby");
  assert(!has_fooby);
}

void testCheckBucket() {
  chain_hash *h;
  h = hash_init(5);

  hash_add_word(h, "world");
  hash_add_word(h, "HellO");

  elt *bucket;
  bucket = hash_check_bucket(h, 4);

  assert(strcmp(bucket->string, "HellO") == 0);
  assert(strcmp(bucket->next->string, "world") == 0);
}

int main() {
  testAddWord();
  testInitializeHash();
  testFindWord();
  testDeleteWord();
  testCheckBucket();
  printf("[1;32m\tChain hashing tests all pass\n[0;m");
}
