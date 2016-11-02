#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(int node, vector<vector<int>> &adj, bool v[]) {
  v[node] = true;

  for (size_t i = 0; i < adj[node].size(); i++) {
    if (!v[adj[node][i]]) {
      explore(adj[node][i], adj, v);
    }
  }
}

int component_count(vector<vector<int>> &adj) {
  bool visited[adj.size()];

  for (size_t i = 0; i < adj.size(); i++) {
    visited[i] = false;
  }

  int ccNum = 0;
  for (size_t n = 0; n < adj.size(); n++) {
    if (!visited[n]) {
      explore(n, adj, visited);
      ccNum++;
    }
  }

  return ccNum;
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
  std::cout << component_count(adj) << '\n';
}