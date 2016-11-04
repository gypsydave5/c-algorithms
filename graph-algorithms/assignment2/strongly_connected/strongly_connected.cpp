#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int>> &adj, vector<int> &used, vector<int> &order,
         int x) {
  used[x] = 1;

  for (int i = 0; i < adj[x].size(); i++) {
    if (used[adj[x][i]] == 0) {
      dfs(adj, used, order, adj[x][i]);
    }
  }

  order.push_back(x);
}

int number_of_strongly_connected_components(vector<vector<int>> adj,
                                            vector<vector<int>> adj_R) {
  int result = 0;
  vector<int> used(adj.size(), 0);
  vector<int> order;

  for (int i = 0; i < adj_R.size(); i++) {
    if (used[i] == 0) {
      dfs(adj_R, used, order, i);
    }
  }

  vector<int> assigned(adj.size(), 0);
  vector<int> order2;

  for (int i = order.size() - 1; i >= 0; i--) {
    if (assigned[order[i]] == 0) {
      dfs(adj, assigned, order2, order[i]);
      result++;
    }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> adj_R(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj_R[y - 1].push_back(x - 1);
  }
  std::cout << number_of_strongly_connected_components(adj, adj_R) << '\n';
}
