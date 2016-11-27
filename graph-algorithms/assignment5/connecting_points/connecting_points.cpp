#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>

using std::vector;
using std::priority_queue;

// This is an edge, measuing the distance from a vertex in X to a vertex in P - X
// (where P is all the vertices, and X is all the vertices in our MST)
// Oddly enough, we don't need the vertex it comes from, only the one it goes to
class edge {
public:
    double distance;
    int vertex;
};

// Just for sorting the edges by distance
bool operator>(const edge &lhs, const edge &rhs) {
    return lhs.distance > rhs.distance;
}

// Distance between two vertices (which are points in this example. As the data
// we're getting is as a list of x and a list of y coordinates, we'll just pass
// both of them in with the index number of each point we're comparing.
double distance(vector<int> x, vector<int> y, int a, int b) {
    int x_diff = (x[a] - x[b]);
    int y_diff = (y[a] - y[b]);
    return std::sqrt((x_diff * x_diff) + (y_diff * y_diff));
};

// This bit does the work.
double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;

  priority_queue<edge, vector<edge>, std::greater<edge>> pq;
  vector<bool> in_set(x.size(), false);
  in_set[0] = true;

  for (size_t i = 1; i < x.size(); i++) {
      edge e;
      e.distance = distance(x, y, 0, i);
      e.vertex = i;
      pq.push(e);
  }

  while (pq.size() > 0) {
      edge e = pq.top();
      pq.pop();
      int u = e.vertex;

      if (in_set[u]) {
          continue;
      }

      in_set[u] = true;
      result += e.distance;

      for (int i = 1; i < x.size(); i++) {
          if (in_set[i]) {
              continue;
          }

          edge e;
          e.distance = distance(x, y, u, i);
          e.vertex = i;
          pq.push(e);
      }
  }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed << std::setprecision(9) << minimum_distance(x, y) << std::endl;
}
