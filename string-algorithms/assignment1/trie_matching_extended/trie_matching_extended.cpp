#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters = 4;
struct Node {
  struct Node *next[Letters];
  bool patternEnd;

  Node() {
    for (int i = 0; i < Letters; i++) {
      next[i] = NULL;
    }
    patternEnd = false;
  }
};

int letterToIndex(char letter) {
  switch (letter) {
    case 'A':
      return 0;
      break;
    case 'C':
      return 1;
      break;
    case 'G':
      return 2;
      break;
    case 'T':
      return 3;
      break;
    default:
      assert(false);
      return -1;
  }
}

struct Node *newNode() {
  struct Node *n = NULL;
  n = (struct Node *)malloc(sizeof(struct Node));

  for (int i = 0; i < Letters; i++) {
    n->next[i] = NULL;
  }

  n->patternEnd = false;
  return n;
}

void insert(Node *root, string pattern) {
  struct Node *current_node;
  int current_char;

  current_node = root;

  for (int i = 0; i < pattern.length(); i++) {
    current_char = letterToIndex(pattern[i]);

    if (!current_node->next[current_char]) {
      current_node->next[current_char] = newNode();
    }
    current_node = current_node->next[current_char];
  }

  current_node->patternEnd = true;
}

bool search(Node *root, string text) {
  struct Node *current_node;
  int current_char;

  current_node = root;

  for (int i = 0; i < text.length(); i++) {
    current_char = letterToIndex(text[i]);

    if (current_node->patternEnd) {
      return true;
    }

    if (!current_node->next[current_char]) {
      return false;
    }
    current_node = current_node->next[current_char];
  }
  return (current_node != NULL && current_node->patternEnd);
}

vector<int> solve(string text, int n, vector<string> patterns) {
  vector<int> result;

  struct Node root = *newNode();

  for (int i = 0; i < n; i++) {
    insert(&root, patterns[i]);
  }

  for (int i = 0; i < text.length(); i++) {
    string sub_string = text.substr(i, string::npos);
    bool matches = search(&root, text.substr(i, string::npos));
    if (matches) {
      result.push_back(i);
    }
  }

  return result;
}

int main(void) {
  string text;
  cin >> text;

  int n;
  cin >> n;

  vector<string> patterns(n);

  for (int i = 0; i < n; i++) {
    cin >> patterns[i];
  }

  vector<int> ans;
  ans = solve(text, n, patterns);

  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i];
    if (i + 1 < (int)ans.size()) {
      cout << " ";
    } else {
      cout << endl;
    }
  }

  return 0;
}
