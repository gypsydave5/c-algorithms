#include "prefix.h"
#include <assert.h>

void test_prefix_function_aaa() {
  int len = 3;
  char text[] = {'a', 'a', 'a'};
  int prefix_array[len];

  prefix(len, text, prefix_array);
  for (int i = 0; i < len; i++) {
    assert(prefix_array[i] == i);
  }
}

void test_prefix_function_aba() {
  int len = 3;
  char text[] = {'a', 'b', 'a'};
  int prefix_array[len];

  prefix(len, text, prefix_array);

  assert(prefix_array[0] == 0);
  assert(prefix_array[1] == 0);
  assert(prefix_array[2] == 1);
}

void test_prefix_function_abababcaab() {
  int len = 10;
  char text[] = {'a', 'b', 'a', 'b', 'a', 'b', 'c', 'a', 'a', 'b'};
  int prefix_array[len];

  prefix(len, text, prefix_array);

  int expected[] = {0, 0, 1, 2, 3, 4, 0, 1, 1, 2};

  for (int i = 0; i < len; ++i) {
    assert(prefix_array[i] == expected[i]);
  }
}

int main() {
  test_prefix_function_aaa();
  test_prefix_function_aba();
}
