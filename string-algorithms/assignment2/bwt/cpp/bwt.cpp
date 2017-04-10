#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";
  int size = text.length();

  vector<string> matrix;

  for (int i = 0; i < size; i++) {
      string rotated = "";
      for (int j = i; j < size; j++) {
          rotated.push_back(text[j]);
      }
      for (int k = 0; k < i; k++) {
          rotated.push_back(text[k]);
      }
      matrix.push_back(rotated);
  }

  std::sort(matrix.begin(), matrix.end());

  for (int i = 0; i < size; i++) {
      result.push_back(matrix[i][size-1]);
  }

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}