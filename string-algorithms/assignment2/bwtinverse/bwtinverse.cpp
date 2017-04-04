#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string InverseBWT(const string& bwt) {
  string text = "";
  vector<string> matrix(bwt.length(), "");

  for (int i = 0; i < bwt.length(); i++) {
    for (int j = 0; j < bwt.length(); j++) {
      matrix[j] = bwt[j] + matrix[j];
    }
    std::sort(matrix.begin(), matrix.end());
  }

  for (string s : matrix) {
    if (s.back() == '$') {
      text = s;
    }
  }

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
