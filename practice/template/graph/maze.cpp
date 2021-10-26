#include <bits/stdc++.h>
using namespace std;

int solve(const vector<vector<int>>& grid, int start_r, int start_c) {
  // Letakkan implementasi Anda di sini.
  return -1;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &grid[i][j]);
    }
  }
  int r, c;
  scanf("%d%d", &r, &c);
  printf("%d\n", solve(grid, r-1, c-1));

  return 0;
}