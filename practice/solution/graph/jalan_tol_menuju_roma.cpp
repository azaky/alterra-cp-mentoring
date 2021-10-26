#include <bits/stdc++.h>
using namespace std;

const int infinity = 1000000000;

int solve(int n, const vector<pair<int, int>>& roads, const vector<pair<int, int>>& tolls, int source, int target) {
  // Kita cari jalan terpendek antar tiap pasang kota *tanpa tol* dengan Floyd-Warshall
  vector<vector<int>> dist(n, vector<int>(n, infinity));
  for (auto e : roads) {
    dist[e.first][e.second] = 1;
    dist[e.second][e.first] = 1;
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

  // Lalu, untuk setiap jalan tol, kita coba apakah dengan melewati jalan tol tersebut
  // akan mempercepat perjalanan.
  int ans = dist[source][target];
  for (auto e : tolls) {
    ans = min(ans, dist[source][e.first] + 1 + dist[e.second][target]);
    ans = min(ans, dist[source][e.second] + 1 + dist[e.first][target]);
  }
  return ans;
}

int main() {
  int n, l, t, source, target;
  scanf("%d%d%d%d%d", &n, &l, &t, &source, &target);
  vector<pair<int,int>> roads(l), tolls(t);
  for (int i = 0; i < l; ++i) {
    scanf("%d%d",  &roads[i].first, &roads[i].second);
    roads[i].first--, roads[i].second--;
  }
  for (int i = 0; i < t; ++i) {
    scanf("%d%d",  &tolls[i].first, &tolls[i].second);
    tolls[i].first--, tolls[i].second--;
  }
  printf("%d\n", solve(n, roads, tolls, source-1, target-1));

  return 0;
}