#include <bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<int> &w, const vector<int> &h, const int n) {
  int k = w.size();

  // dp[indeks min batu][total berat] = max harga
  vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
  dp[k][0] = 0;
  for (int i = k - 1; i >= 0; --i) {
    // Jangan gunakan batu ke-i
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = dp[i + 1][j];
    }
    // Gunakan batu ke-i
    for (int j = w[i]; j <= n; ++j) {
      if (dp[i + 1][j - w[i]] != -1) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j - w[i]] + h[i]);
      }
    }
  }

  // Backtrack.
  // Pertama, cari berat minimum dengan harga maksimum.
  int price = 0;
  int weight = 0;
  for (int i = 0; i <= n; ++i) {
    if (dp[0][i] > price) {
      price = dp[0][i];
      weight = i;
    }
  }

  // Kemudian, backtrack untuk cari konfigurasinya.
  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    // Coba menggunakan batu dengan indeks i.
    assert(dp[i][weight] == price);
    if (weight >= w[i] && dp[i + 1][weight - w[i]] + h[i] == price) {
      ans.push_back(i);
      price -= h[i];
      weight -= w[i];
    }
  }
  assert(weight == 0);

  return ans;
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
