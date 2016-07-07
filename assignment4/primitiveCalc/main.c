#include <stdio.h>

int min(int a, int b, int c) {
  int m;
  m = a;
  if (b < m) {
    m = b;
  }
  if (c < m) {
    m = c;
  }
  return m;
}

int whichOperation(int ops[], int i) {
  int div3, div2, sub1;
  div3 = div2 = sub1 = i;

  if (i % 3 == 0) {
    div3 = ops[i / 3] + 1;
  }

  if (i % 2 == 0) {
    div2 = ops[i / 2] + 1;
  }

  sub1 = ops[i - 1] + 1;

  return min(div3, div2, sub1);
}

void backtrack(int ops[], int n, int r[]) {
  int currentStep = n;
  while (currentStep > 0) {
    int opCount = ops[currentStep];
    if ((currentStep % 3 == 0) && ops[currentStep / 3] == (opCount - 1)) {
      r[opCount] = currentStep;
      currentStep /= 3;
    } else if ((currentStep % 2 == 0) &&
               ops[currentStep / 2] == (opCount - 1)) {
      r[opCount] = currentStep;
      currentStep /= 2;
    } else {
      r[opCount] = currentStep;
      currentStep--;
    }
  }
}

int primitiveCalc(int n, int r[]) {
  int i, ops[n];
  ops[1] = 0;
  for (i = 2; i <= n; i++) {
    ops[i] = whichOperation(ops, i);
  }
  backtrack(ops, n, r);
  return ops[n];
}

int main() {
  int number, steps, i;
  scanf("%d", &number);
  int result[number + 1];

  steps = primitiveCalc(number, result);

  printf("%d\n", steps);

  for (i = 0; i < steps; i++) {
    printf("%d ", result[i]);
  }
  printf("%d\n", result[steps]);
}