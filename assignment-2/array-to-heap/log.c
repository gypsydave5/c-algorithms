#include <stdlib.h>
#include "log.h"

void log_init(log *l, int capacity) {
  l->capacity = capacity;
  l->logs = malloc(capacity * sizeof(entry));
  l->size = 0;
}
