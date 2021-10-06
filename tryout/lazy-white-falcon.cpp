#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n-1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  // DFS for Preorder & LCA
  vector<int> preL(n), preR(n), parent(n), depth(n);
  function<void(int,int)> dfs = [&](int v, int p) {
    static int counter = 0;
    preL[v] = ++counter;
    parent[v] = p;
    for (int c : adj[v]) {
      if (c == p) continue;
      depth[c] = depth[v] + 1;
      dfs(c, v);
    }
    preR[v] = counter;
  };
  depth[0] = 0;
  dfs(0, -1);

  // Precompute binary lifting for LCA
  int log = 0;
  while ((1 << log) < n) log++;
  vector<vector<int>> parentLift(n, vector<int>(log+1, -1));

  for (int i = 0; i < n; ++i) {
    parentLift[i][0] = parent[i];
  }
  for (int j = 1; j < log; ++j) {
    for (int i = 0; i < n; ++i) {
      if (parentLift[i][j-1] != -1) {
        parentLift[i][j] = parentLift[parentLift[i][j-1]][j-1];
      }
    }
  }

  function<int(int,int)> lcaFind = [&](int u, int v) -> int {
    if (depth[u] < depth[v]) swap(u, v);
    for (int j = log; j >= 0; j--) {
      if (depth[u] - (1 << j) >= depth[v]) {
        u = parentLift[u][j];
      }
    }
    if (u == v) return u;
    for (int j = log; j >= 0; --j) {
      if (parentLift[u][j] != parentLift[v][j]) {
        u = parentLift[u][j];
        v = parentLift[v][j];
      }
    }
    return parent[u];
  };

  // BIT/Fenwick Tree
  vector<int> bit(n+1, 0);
  function<void(int,int)> bitUpdate = [&](int k, int v) {
    for (int x = k; x <= n; x += (x & -x)) {
      bit[x] += v;
    }
  };
  function<int(int)> bitSum = [&](int k) -> int {
    int sum = 0;
    for (int x = k; x > 0; x -= (x & -x)) {
      sum += bit[x];
    }
    return sum;
  };

  vector<int> value(n, 0);
  for (int iq = 0; iq < q; ++iq) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      int diff = y - value[x];
      bitUpdate(preL[x], diff);
      bitUpdate(preR[x]+1, -diff);
      value[x] += diff;
    } else {
      int lca = lcaFind(x, y);
      int ans = bitSum(preL[x]) + bitSum(preL[y]) - 2 * bitSum(preL[lca]) + value[lca];
      printf("%d\n", ans);
    }
  }

  return 0;
}