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
  string sorted = bwt;
  sort(sorted.begin(), sorted.end());

  char c = '$';
  int char_num = 0;

  while (text.length() < bwt.length()) {
    for (int i = 0; i < bwt.length(); i++) {
      if (bwt[i] == c) {
        if (char_num == 0) {
          text.push_back(c);

          c = sorted[i];

          for (int j = 0; j <= i; j++) {
            if (sorted[j] == c) {
              char_num++;
            }
          }
        } else {
          char_num--;
        }
      }
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
