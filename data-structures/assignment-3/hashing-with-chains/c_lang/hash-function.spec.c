#include <assert.h>
#include <stdio.h>
#include "hash-function.h"

void testSimpleHashFunction() {
  int h, r;
  h = hash_function(5, "a");
  r = ('a') % 5;
  assert(h == r);

  h = hash_function(5, "aa");
  r = ('a' + ('a' * 263)) % 5;
  assert(h == r);

  h = hash_function(5, "wat");
  r = ('w' + ('a' * 263) + ('t' * 263 * 263)) % 5;
  assert(h == r);

  h = hash_function(50000000, "ZZZ");
  r = ('Z' + ('Z' * 263) + ('Z' * 263 * 263)) % 50000000;
  assert(h == r);
}

void testHashFunction() {
  int h;
  h = hash_function(5, "world");
  assert(h == 4);
}

void testThePower() {
  unsigned long long res;

  res = pow_ull(2, 2);
  assert(res == 4);

  res = pow_ull(555, 0);
  assert(res == 1);

  res = pow_ull(5, 1);
  assert(res == 5);
}

int main() {
  testThePower();
  testSimpleHashFunction();
  testHashFunction();
  printf("[1;32m\tHash function tests pass[0;m\n");
}
