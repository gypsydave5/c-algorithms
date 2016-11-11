#include <iostream>
#include <vector>
#define MAX_DIST 10001

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<int> dist(adj.size(), MAX_DIST);

  for (int i = 0; i < adj.size() - 1; i++) {
      for (int u = 0; u < adj.size(); u++) {

          for (int k = 0; k < adj[u].size(); k++) {

              int v = adj[u][k];

              if (dist[v] > dist[u] + cost[u][k]) {
                  dist[v] = dist[u] + cost[u][k];
              }
          }
      }
  }

  for (int u = 0; u < adj.size(); u++) {
      for (int k = 0; k < adj[u].size(); k++) {
          int v = adj[u][k];
          int w = cost[u][k];
          if (dist[u] + w < dist[v]) {
              return 1;
          }
      }
  }

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost) << '\n';
}
