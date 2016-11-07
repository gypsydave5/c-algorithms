#include <iostream>
#include <queue>
#include <vector>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  vector<int> color(adj.size(), -1);
  vector<bool> visited(adj.size(), false);
  queue<int> q;

  visited[0] = true;
  q.push(0);

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (int i = 0; i < adj[current].size(); i++) {
      int adjacent = adj[current][i];
      if (!visited[adjacent]) {
        visited[adjacent] = true;
        color[adjacent] = color[current] * -1;
        q.push(adjacent);
      }

      if (visited[adjacent] && (color[adjacent] == color[current])) {
        return 0;
      }
    }
  }

  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj) << '\n';
}
