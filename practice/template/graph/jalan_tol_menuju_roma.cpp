#include <bits/stdc++.h>
using namespace std;

int solve(int n, const vector<pair<int, int>>& roads, const vector<pair<int, int>>& tolls, int source, int target) {
  // Letakkan implementasi Anda di sini.
  return -1;
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