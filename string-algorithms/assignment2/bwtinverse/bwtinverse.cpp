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

vector<int> number_matching;

void construct_number_matching(const string& bwt) {
  number_matching.resize(bwt.length());

  int first_count = 0;
  int a_count = 0;
  int t_count = 0;
  int c_count = 0;
  int g_count = 0;

  for (int i = 0; i < bwt.length(); ++i) {
    char c = bwt[i];
    if (c == '$') {
      number_matching[i] = first_count;
      first_count++;
    }
    if (c == 'A') {
      number_matching[i] = a_count;
      a_count++;
    }
    if (c == 'T') {
      number_matching[i] = t_count;
      t_count++;
    }
    if (c == 'C') {
      number_matching[i] = c_count;
      c_count++;
    }
    if (c == 'G') {
      number_matching[i] = g_count;
      g_count++;
    }
  }
}

int occurance_up_to(const string& bwt, int pos) { return number_matching[pos]; }

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

int inverse(int pos, const string& bwt) {
  char c = bwt[pos];
  return rank_of(c) + occurance_up_to(bwt, pos);
}

string InverseBWT(const string& bwt) {
  rank_sorted(bwt);
  construct_number_matching(bwt);

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
