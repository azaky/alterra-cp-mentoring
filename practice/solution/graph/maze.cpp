#include <bits/stdc++.h>
using namespace std;

const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {-1, 1, 0, 0};

int solve(const vector<vector<int>> &grid, int start_r, int start_c) {
  int n = grid.size(), m = grid[0].size();
  // BFS
  queue<pair<int, int>> q;
  vector<vector<int>> dist(n, vector<int>(m, -1));
  q.emplace(start_r, start_c);
  dist[start_r][start_c] = 1;
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int nr = r + dr[d], nc = c + dc[d];
      // Kalau keluar, maka (r, c) ini sudah di pinggir maze.
      if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
        return dist[r][c];
      }
      // Cek tembok atau yang sudah divisit sebelumnya.
      if (grid[nr][nc] == -1 || dist[nr][nc] != -1) {
        continue;
      }
      dist[nr][nc] = dist[r][c] + 1;
      q.emplace(nr, nc);
    }
  }
  // Kalau keluar dari BFS tanpa return, berarti tidak ada jalan keluar.
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