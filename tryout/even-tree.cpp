#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int ans = 0;

  function<int(int,int)> dfs = [&](int v, int p) -> int {
    int size = 1;
    for (int c : adj[v]) {
      if (c == p) continue;
      size += dfs(c, v);
    }
    if (size % 2 == 0) ans++;
    return size;
  };

  dfs(0, -1);
  printf("%d\n", ans-1);

  return 0;
}