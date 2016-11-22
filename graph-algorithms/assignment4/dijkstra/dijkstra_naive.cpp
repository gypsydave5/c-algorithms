#include <iostream>
#include <vector>
#define MAX_DIST 10001

using std::vector;
using std::pair;

int distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s,
             int t) {

  vector<int> dist(adj.size(), MAX_DIST);
  vector<bool> visited(adj.size(), false);
  dist[s] = 0;

  for (int i = 0; i < adj.size(); i++) {
      for (int u = 0; u < adj.size(); u++) {

          for (int k = 0; k < adj[u].size(); k++) {

              int v = adj[u][k];

              if (dist[v] > dist[u] + cost[u][k]) {
                  dist[v] = dist[u] + cost[u][k];
              }
          }
      }
  }

  if (dist[t] == MAX_DIST) {
      return -1;
  }

  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());

  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }

  int s, t;
  std::cin >> s >> t;
  s--, t--;

  std::cout << distance(adj, cost, s, t) << '\n';
}
