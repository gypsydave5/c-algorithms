#include "segment.h"
#include <stdio.h>

int factorial(int n);
int binomial(int n, int k);
void getMaxMinSeg(int l, struct segment segs[l], int *max, int *min);
void getCombinations(int combSize, int cl, int combs[cl][combSize], int pl,
                     int points[pl]);
void combHelper(int combSize, int combsLen, int combs[combsLen][combSize],
                int pointsLen, int points[pointsLen], int curr[combSize],
                int start, int end, int index, int *count);

int main() {
  /*int segCount, i;*/
  /*scanf("%d", &segCount);*/

  /*struct segment segs[segCount];*/
  /*for (i = 0; i < segCount; i++) {*/
    /*struct segment s;*/
    /*scanf("%d %d", &s.start, &s.end);*/
    /*segs[i] = s;*/
  /*}*/

  /*int max, min = 0;*/
  /*getMaxMinSeg(segCount, segs, &max, &min);*/

  int noOfPoints = 5;
  int points[noOfPoints];

  for (int i = 0; i < noOfPoints; i++) {
    points[i] = i + 1;
  }

  int cn = binomial(5, 3);
  int combinations[cn][3];
  getCombinations(3, cn, combinations, noOfPoints, points);

  /*for (i = 1; i <= noOfPoints; i++) {*/
    /*int cn = binomial(noOfPoints, i);*/
    /*int combinations[cn][i];*/
    /*getCombinations(i, cn, combinations, noOfPoints, points);*/
    /*for (int j = 0; j < cn; j++) {*/
      /*for (int y = 0; y < i; y++) {*/
        /*printf("%d ", combinations[j][y]);*/
      /*}*/
      /*printf("\n");*/
    /*}*/
  /*}*/

  /*for (i = 0; i < segCount; i++) {*/
    /*printf("%d || %d\n", segs[i].start, segs[i].end);*/
    /*printf("%d\n", binomial(segs[i].start, segs[i].end));*/
  /*}*/
}

void getMaxMinSeg(int l, struct segment segs[l], int *max, int *min) {
  *max = 0;
  *min = 0;

  for (int i = 0; i < l; i++) {
    if (segs[i].end > *max) {
      *max = segs[i].end;
    }
    if (*min == 0 || segs[i].start < *min) {
      *min = segs[i].start;
    }
  }
}

void getCombinations(int combSize, int combsLen, int combs[combsLen][combSize],
                     int pointsLen, int points[pointsLen]) {
  int curr[combSize];
  int count = 0;

  combHelper(combSize, combsLen, combs, pointsLen, points, curr, 0,
             pointsLen - 1, 0, &count);
}

void copy(int arr1[], int arr2[], int l) {
  for (int i = 0; i < l; i++) {
    arr2[i] = arr1[i];
  }
}

void combHelper(int combSize, int combsLen, int combs[combsLen][combSize],
                int pointsLen, int points[pointsLen], int curr[combSize],
                int start, int end, int index, int *count) {
  if (index == combSize) {
    copy(combs[*count], curr, combSize);
    *count = *count + 1;
    return;
  }

  for (int i = start; i < combSize && end - i >= combSize - index; i++) {
    curr[index] = points[i];
    combHelper(combSize, combsLen, combs, pointsLen, points, curr, i + 1, end,
               index + 1, count);
  }
}

int binomial(int n, int k) {
  int num, den;
  if (k == 0) {
    return 1;
  }

  num = n;
  den = k;

  while (k > 1) {
    k--;
    num *= (n - k);
    den *= k;
  }

  return num / den;
}
