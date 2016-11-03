#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
    vector<bool> distance(adj.size(), false);
    vector<int> visited(adj.size(), 0);
    queue<int> q;

    visited[s] = 1;

    q.push(s);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < adj[current].size(); i++) {
            int adjacent = adj[current][i];
            if (adjacent == t) {
                // return early now we've go what we wanted
                return distance[current] + 1;
            }

            if (!visited[adjacent]) {
                visited[adjacent] = true;
                distance[adjacent] = distance[current] + 1;
                q.push(adjacent);
            }
        }
    }

    return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t) << '\n';
}
