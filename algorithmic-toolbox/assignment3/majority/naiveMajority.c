int naiveMajority(int list[], int listSize) {
  for (int i = 0; i < listSize; i++) {
    int candidate = list[i];
    int count = 0;

    for (int j = 0; j < listSize; j++) {
      if (list[j] == candidate) {
        count++;
      }
      if (count > listSize / 2) {
        return 1;
      }
    }
  }
  return 0;
}
