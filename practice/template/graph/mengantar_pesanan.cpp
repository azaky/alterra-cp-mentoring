#include <bits/stdc++.h>
using namespace std;

struct edge {
  int from, to, weight;
};

int solve(int n, const vector<edge>& edges, const vector<int> path) {
  // Letakkan implementasi Anda di sini.
  return -1;
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