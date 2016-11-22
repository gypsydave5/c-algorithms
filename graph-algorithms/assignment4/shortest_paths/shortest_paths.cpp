#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(
    vector<vector<int> > &adj,
    vector<vector<int> > &cost,
    int s,
    vector<long long> &distance,
    vector<int> &reachable,
    vector<int> &shortest
    ) {

  distance[s] = 0;
  reachable[s] = 1;
  bool changed = true;

  for (int i = 0; i < adj.size(); i++) {
      for (int u = 0; u < adj.size(); u++) {

          if (distance[u] == std::numeric_limits<long long>::max()) {
              continue;
          }

          for (int k = 0; k < adj[u].size(); k++) {

              int v = adj[u][k];
              int w = cost[u][k];

              if (distance[v] > distance[u] + w) {
                  reachable[v] = 1;
                  distance[v] = distance[u] + w;
              }
          }
      }
  }

  while (changed) {
      changed = false;

      for (int u = 0; u < adj.size(); u++) {

          if (distance[u] == std::numeric_limits<long long>::max()) {
              continue;
          }

          for (int k = 0; k < adj[u].size(); k++) {
              int v = adj[u][k];
              int w = cost[u][k];

              if (distance[v] < distance[u] + w) {
                  if (shortest[v]) {
                      distance[v] = distance[u] + w;
                      changed = true;
                  }
                  shortest[v] = 0;
              }
          }
      }
  }
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());

  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }

  std::cin >> s;
  s--;

  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);

  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
