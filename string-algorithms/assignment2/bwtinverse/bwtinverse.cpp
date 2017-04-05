#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int first_start = -1;
int a_start = -1;
int t_start = -1;
int c_start = -1;
int g_start = -1;

void rank_sorted(const string& bwt) {
  string sorted = bwt;
  std::sort(sorted.begin(), sorted.end());

  for (int i = 0; i < sorted.length(); ++i) {
    if (first_start == -1 && sorted[i] == '$') {
      first_start = i;
    }
    if (a_start == -1 && sorted[i] == 'A') {
      a_start = i;
    }
    if (t_start == -1 && sorted[i] == 'T') {
      t_start = i;
    }
    if (c_start == -1 && sorted[i] == 'C') {
      c_start = i;
    }
    if (g_start == -1 && sorted[i] == 'G') {
      g_start = i;
    }
  }
}

int rank_of(char c) {
  switch (c) {
    case 'A':
      return a_start;
    case 'T':
      return t_start;
    case 'C':
      return c_start;
    case 'G':
      return g_start;
    default:
      return first_start;
  }
}

int occurance_up_to(char c, const string& bwt, int pos) {
  int count = 0;
  for (int i = 0; i < pos; ++i) {
    if (bwt[i] == c) {
      count++;
    }
  }
  return count;
}

int inverse(int pos, const string& bwt) {
  char c = bwt[pos];
  return rank_of(c) + occurance_up_to(c, bwt, pos);
}

string InverseBWT(const string& bwt) {
  rank_sorted(bwt);

  string text = "$";

  int pos = 0;

  for (int i = 1; i < bwt.length(); ++i) {
    text = bwt[pos] + text;
    pos = inverse(pos, bwt);
  }

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
