#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void print_array(bool a[], int len) {
  std::cout << "[";
  for (int i = 0; i < len; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << "]\n";
}

bool test_cycle(int node, vector<vector<int>> &adj, bool visited[],
                bool started[]) {
  bool is_cycle = false;

  if (started[node]) {
    return true;
  }

  started[node] = true;
  for (size_t i = 0; i < adj[node].size(); i++) {
    is_cycle = is_cycle || test_cycle(adj[node][i], adj, visited, started);

    if (is_cycle) {
      return is_cycle;
    }
  }

  started[node] = false;
  visited[node] = true;

  return is_cycle;
}

bool acyclic(vector<vector<int>> &adj) {
  bool visited[adj.size()];
  bool started[adj.size()];
  for (size_t i = 0; i < adj.size(); i++) {
    visited[i] = false;
    started[i] = false;
  }

  bool is_cycle;
  is_cycle = false;

  for (int n = 0; n < adj.size(); n++) {
    if (!visited[n]) {
      is_cycle = test_cycle(n, adj, visited, started);

      if (is_cycle) {
        return is_cycle;
      }
    }
  }

  return is_cycle;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;

  vector<vector<int>> adj(n, vector<int>());

  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }

  std::cout << acyclic(adj) << '\n';
}
