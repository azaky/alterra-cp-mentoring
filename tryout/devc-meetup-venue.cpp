#include <bits/stdc++.h>
using namespace std;

const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};
const char *dir = "RLDU";

int main() {
  int n;
  scanf("%d", &n);
  int ar, ac, mr, mc;
  scanf("%d%d%d%d", &ar, &ac, &mr, &mc);
  ar--, ac--, mr--, mc--;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    static char buffer[101];
    scanf("%s", buffer);
    grid[i] = buffer;
  }

  queue<pair<int,int>> q;
  vector<vector<int>> visited(n, vector<int>(n, 0));
  vector<vector<int>> previous(n, vector<int>(n, -1));

  q.emplace(ar, ac);
  visited[ar][ac] = 1;
  while (!q.empty()) {
    auto p = q.front(); q.pop();
    int r = p.first, c = p.second;
    visited[r][c] = 2;
    if (r == mr && c == mc) break;
    for (int d = 0; d < 4; ++d) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
      if (grid[nr][nc] != '.') continue;
      if (visited[nr][nc]) continue;
      q.emplace(nr, nc);
      visited[nr][nc] = 1;
      previous[nr][nc] = d;
    }
  }

  if (!visited[mr][mc]) {
    puts("tersesat");
    return 0;
  }

  string ans = "";
  int r = mr, c = mc;
  while (r != ar || c != ac) {
    int d = previous[r][c];
    ans += dir[d];
    r -= dr[d];
    c -= dc[d];
  }
  reverse(ans.begin(), ans.end());
  puts(ans.c_str());

  return 0;
}
