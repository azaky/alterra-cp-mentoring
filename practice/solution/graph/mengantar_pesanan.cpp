#include <bits/stdc++.h>
using namespace std;

struct edge {
  int from, to, weight;
};

const int infinity = 1000000000;

int solve(int n, const vector<edge> &edges, const vector<int> path) {
  // Floyd-Warshall
  vector<vector<int>> dist(n, vector<int>(n, infinity));
  for (const edge &e : edges) {
    dist[e.from][e.to] = min(dist[e.from][e.to], e.weight);
    dist[e.to][e.from] = min(dist[e.to][e.from], e.weight);
  }
  for (int i = 0; i < n; ++i) {
    dist[i][i] = 0;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  // Tambahkan distance untuk tiap pasang rumah yang berurutan.
  int total_dist = 0;
  for (int i = 0; i < path.size()-1; ++i) {
    total_dist += dist[path[i]][path[i + 1]];
    if (total_dist >= infinity) {
      total_dist = infinity;
      break;
    }
  }
  if (total_dist >= infinity) {
    return -1;
  }
  return total_dist;
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  vector<edge> edges(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].weight);
    edges[i].from--, edges[i].to--;
  }
  vector<int> path(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d", &path[i]);
    path[i]--;
  }
  printf("%d\n", solve(n, edges, path));

  return 0;
}