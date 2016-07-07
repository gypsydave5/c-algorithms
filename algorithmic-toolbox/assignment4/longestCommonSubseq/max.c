#include <stdio.h>
#include "max.h"

int max_int_seven(int a, int b, int c, int d, int e, int f, int g) {
  int result = a;
  result = b > result ? b : result;
  result = c > result ? c : result;
  result = d > result ? d : result;
  result = e > result ? e : result;
  result = f > result ? f : result;
  result = g > result ? g : result;
  return result;
}

int max(int a, int b, int c) {
  int r = a;
  r = b > r ? b : r;
  r = c > r ? c : r;
  return r;
}
