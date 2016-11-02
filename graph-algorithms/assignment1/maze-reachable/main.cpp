:|include <iostream>
#include <vector>

using std::vector;
using std::pair;

void print_array(int a[], int len) {
  std::cout << "[";
  for (int i = 0; i < len; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << "]\n";
}

void print_array(bool a[], int len) {
  std::cout << "[";
  for (int i = 0; i < len; i++) {
    std::cout << i << " " << a[i] << " ";
  }
  std::cout << "]\n";
}

void explore(int node, vector<vector<int>> &adj, bool v[], int cc[],
             int ccNum) {
  v[node] = true;
  cc[node] = ccNum;

  for (size_t i = 0; i < adj[node].size(); i++) {
    if (!v[adj[node][i]]) {
      explore(adj[node][i], adj, v, cc, ccNum);
    }
  }
}

int reach(vector<vector<int>> &adj, int x, int y) {
  bool visited[adj.size()];
  int cc[adj.size()];

  for (size_t i = 0; i < adj.size(); i++) {
    visited[i] = false;
    cc[i] = -1;
  }

  int ccNum = 0;
  for (size_t n = 0; n < adj.size(); n++) {
    if (!visited[n]) {
      explore(n, adj, visited, cc, ccNum);
    }
    ccNum++;
  }

  return cc[x] == cc[y];
}

void print_adjacency_list(vector<vector<int>> &adj) {
  for (size_t i = 0; i < adj.size(); i++) {
    std::cout << "{";

    size_t j;
    for (j = 0; j < adj[i].size() - 1; j++) {
      std::cout << adj[i][j] + 1 << ", ";
    }

    std::cout << adj[i][j] + 1;

    std::cout << "}\n";
  }
}

int main() {
  size_t n, m;

  std::cin >> n >> m;

  vector<vector<int>> adj(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }

  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1) << '\n';
}