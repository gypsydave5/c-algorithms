#include "editDistance.h"

int min(int a, int b, int c) {
  int m = a;
  if (m > b) {
    m = b;
  }
  if (m > c) {
    m = c;
  }
  return m;
}

