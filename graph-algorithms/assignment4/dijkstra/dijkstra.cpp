#include <iostream>
#include <queue>
#include <vector>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

class v_dist {
public:
    int distance;
    int vertex;
};

bool operator>(const v_dist &lhs, const v_dist &rhs) {
    return lhs.distance > rhs.distance;
}

int distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s,
             int t) {

  priority_queue<v_dist, vector<v_dist>, std::greater<v_dist>> pq;
  vector<int> dist(adj.size(), INT_MAX);
  vector<int> prev(adj.size(), NULL);
  dist[s] = 0;

  std::cout << "s: " << s << ", t: " << t << '\n';

  for (int i = 0; i < adj.size(); i++) {
      v_dist vd;
      vd.distance = dist[i];
      vd.vertex = i;
      pq.push(vd);
  }

  while (pq.size() > 0) {
      v_dist vd = pq.top();
      pq.pop();

      for (int i = 0; i < adj[vd.vertex].size(); i++) {
          int u = vd.vertex;
          int v = adj[u][i];
          std::cout << "u: " << u << ", v: " << v << '\n';
          if (dist[v] > dist[u] + cost[u][i]) {
              dist[v] = dist[u] + cost[u][v];
              prev[v] = u;

              v_dist vd;
              vd.distance = dist[v];
              vd.vertex = v;
              pq.push(vd);
          }
      }
  }

  // write your code her
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

  std::cout << distance(adj, cost, s, t);
}
