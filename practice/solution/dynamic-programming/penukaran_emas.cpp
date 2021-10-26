#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
  }
  return dp[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", solve(n));

  return 0;
}