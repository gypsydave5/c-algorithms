#include <stdlib.h>
#include "log.h"

void log_init(log *l, int capacity) {
  l->capacity = capacity;
  l->logs = malloc(capacity * sizeof(entry));
  l->size = 0;
}

void log_destroy(log *l) {
  free(l->logs);
  l->logs = NULL;
  l->capacity = -1;
  l->size = -1;
}
