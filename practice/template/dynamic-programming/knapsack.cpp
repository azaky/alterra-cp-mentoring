#include <bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<int> &w, const vector<int> &h, const int n) {
  // Letakkan implementasi Anda di sini.
  return {};
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> w(k), h(k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &w[i], &h[i]);
  }

  vector<int> ans = solve(w, h, n);

  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i] + 1);
  }

  return 0;
}
