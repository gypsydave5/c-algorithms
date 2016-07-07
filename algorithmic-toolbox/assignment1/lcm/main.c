#include <stdio.h>
unsigned long long lcmEuclid(unsigned long long a, unsigned long long b);
unsigned long long gcdEuclid(unsigned long long a, unsigned long long b);

int main() {
  unsigned long long a, b, result;
  scanf("%lld %lld", &a, &b);
  result = lcmEuclid(a, b);
  printf("%lld\n", result);
}

unsigned long long lcmEuclid(unsigned long long a, unsigned long long b) {
  return (a * b) / gcdEuclid(a, b);
}

unsigned long long gcdEuclid(unsigned long long a, unsigned long long b) {
  if (b == 0) {
    return a;
  }
  a = a % b;
  return gcdEuclid(b, a);
}
