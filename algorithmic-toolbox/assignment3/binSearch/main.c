#include <stdio.h>

int binarySearch(int array[], int low, int high, int key);

void binarySearchList(int list[], int listSize, int query[], int querySize,
                      int results[]) {
  int i;
  for (i = 0; i < querySize; i++) {
    results[i] = binarySearch(list, 0, listSize - 1, query[i]);
  }
}

int binarySearch(int array[], int low, int high, int key) {
  if (low > high) {
    return -1;
  }

  int m = (low + high) / 2;

  if (array[m] < key) {
    return binarySearch(array, m + 1, high, key);
  }

  if (array[m] > key) {
    return binarySearch(array, low, m - 1, key);
  }

  return m;
}

int main() {
  int listSize, i;
  scanf("%d", &listSize);
  int list[listSize];

  for (i = 0; i < listSize; i++) {
    scanf("%d", &list[i]);
  }

  int querySize;
  scanf("%d", &querySize);
  int query[querySize];
  int results[querySize];

  for (i = 0; i < querySize; i++) {
    scanf("%d", &query[i]);
  }

  binarySearchList(list, listSize, query, querySize, results);

  for (i = 0; i < querySize - 1; i++) {
    printf("%d ", results[i]);
  }
  printf("%d\n", results[i]);
}
