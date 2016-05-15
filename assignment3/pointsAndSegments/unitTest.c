#include "pointsAndSegments.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void testOrderPointsLessThan() {
  int res;
  struct point a = {'p', 1, 0};
  struct point b = {'p', 3, 0};

  res = orderPoints(&a, &b);
  assert(res < 0);
}

void testOrderPointsGreaterThan() {
  int res;
  struct point a = {'p', 3, 0};
  struct point b = {'p', 1, 0};

  res = orderPoints(&a, &b);
  assert(res > 0);
}

void testLeftBeforePoint() {
  int res;
  struct point a = {'l', 1, 0};
  struct point b = {'p', 1, 0};

  res = orderPoints(&a, &b);
  assert(res < 0);
}

void testLeftBeforeRight() {
  int res;
  struct point a = {'r', 1, 0};
  struct point b = {'l', 1, 0};

  res = orderPoints(&a, &b);
  assert(res > 0);
}

void testPointBeforeRight() {
  int res;
  struct point a = {'p', 1, 0};
  struct point b = {'r', 1, 0};

  res = orderPoints(&a, &b);
  assert(res < 0);
}

void testEquality() {
  int res;
  struct point a = {'p', 1, 0};
  struct point b = {'p', 1, 3};

  res = orderPoints(&a, &b);
  assert(res == 0);
}

void integrationTest() {
  struct point points[] = {
      {'p', 3, 0}, {'r', 2, 0}, {'l', 1, 0}, {'p', 1, 0}, {'l', 1, 0}};

  qsort(points, 5, sizeof(struct point), orderPoints);
  assert(points[0].type == 'l');
  assert(points[4].type == 'p');
  assert(points[4].value == 3);
}

int main() {
  testOrderPointsGreaterThan();
  testOrderPointsLessThan();
  testLeftBeforePoint();
  testLeftBeforeRight();
  testPointBeforeRight();
  testEquality();
  integrationTest();
  printf("All tests passing!\n");
}
