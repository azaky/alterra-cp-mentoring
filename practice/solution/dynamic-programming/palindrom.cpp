#include <bits/stdc++.h>
using namespace std;

int solve(const string &s) {
  int n = s.size();
  // dp[a][b] = max palindrom dari indeks a..b
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // Kita harus mengisi tabel dp menarik berdasarkan b-a, atau panjang substring.
  for (int len = 1; len <= n; ++len) {
    for (int a = 0; a < n - len + 1; ++a) {
      int b = a + len - 1;
      // Kasus a == b: dp = 1
      if (a == b) {
        dp[a][b] = 1;
      }
      // Kasus s[a] == s[b]: dp = 2 + dp[a+1][b-1]
      else if (s[a] == s[b]) {
        dp[a][b] = 2 + dp[a+1][b-1];
      }
      // Kasus lainnya: dp = max(dp[a+1][b], dp[a][b-1])
      else {
        dp[a][b] = max(dp[a+1][b], dp[a][b-1]);
      }
    }
  }
  return dp[0][n-1];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    static char buffer[100];
    scanf("%s", buffer);
    printf("%d\n", solve(buffer));
  }

  return 0;
}
