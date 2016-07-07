#include <stdio.h>
#include <stdlib.h>

typedef struct entry {
  int i;
  int j;
} entry;

typedef struct log {
  entry *logs;
  int size;
  int capacity;
} log;

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

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int left_child(int index) { return index * 2; }
int right_child(int index) { return index * 2 + 1; }
void sift_down(int array[], int size, int index) {
  int min_index, left, right;
  min_index = index;
  left = left_child(index);
  right = right_child(index);
  if (left <= size && array[left - 1] < array[min_index - 1]) {
    min_index = left;
  }
  if (right <= size && array[right - 1] < array[min_index - 1]) {
    min_index = right;
  }
  if (index != min_index) {
    swap(&array[index - 1], &array[min_index - 1]);
    sift_down(array, size, min_index);
  }
}

static void sift_down_log(int array[], int size, int index, log *l) {
  int min_index, left, right;
  min_index = index;
  left = left_child(index);
  right = right_child(index);
  if (left <= size && array[left - 1] < array[min_index - 1]) {
    min_index = left;
  }
  if (right <= size && array[right - 1] < array[min_index - 1]) {
    min_index = right;
  }
  if (index != min_index) {
    l->logs[l->size].i = index - 1;
    l->logs[l->size].j = min_index - 1;
    l->size++;
    swap(&array[index - 1], &array[min_index - 1]);
    sift_down_log(array, size, min_index, l);
  }
}

void build_heap(int array[], int size) {
  int i;
  for (i = size / 2; i >= 1; i--) {
    sift_down(array, size, i);
  }
}

void build_heap_log(int array[], int size, log *l) {
  int i;
  for (i = size / 2; i >= 1; i--) {
    sift_down_log(array, size, i, l);
  }
}

int main() {
  int size, i;
  scanf("%d\n", &size);

  int *input_array;
  input_array = malloc(size * sizeof(int));

  log logs;
  log_init(&logs, size * 4);

  for (i = 0; i < size; i++) {
    scanf("%d\n", &input_array[i]);
  }

  build_heap_log(input_array, size, &logs);

  printf("%d\n", logs.size);
  for (i = 0; i < logs.size; i++) {
    printf("%d %d\n", logs.logs[i].i, logs.logs[i].j);
  }

  free(input_array);
  log_destroy(&logs);
}
