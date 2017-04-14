#include "prefix.h"

void prefix(int len, char text[len], int prefix_array[len]) {
  int border = 0;
  prefix_array[0] = 0;

  for (int i = 1; i < len; ++i) {
    while ((border > 0) && (text[i] != text[border])) {
      border = prefix_array[border - 1];
    }

    if (text[i] == text[border]) {
      border = border + 1;
    } else {
      border = 0;
    }

    prefix_array[i] = border;
  }
}
