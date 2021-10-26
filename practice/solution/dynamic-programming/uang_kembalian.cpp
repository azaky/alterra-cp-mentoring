#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &coins, int K) {
  vector<int> dp(K+1, -1);
  dp[0] = 0;
  for (int i = 0; i < coins.size(); ++i) {
    for (int k = coins[i]; k <= K; ++k) {
      if (dp[k-coins[i]] != -1) {
        if (dp[k] == -1) {
          dp[k] = dp[k-coins[i]]+1;
        } else {
          dp[k] = min(dp[k], dp[k-coins[i]]+1);
        }
      }
    }
  }
  return dp[K];
}

int main() {
  int N, K;
  scanf("%d", &N);
  vector<int> coins(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &coins[i]);
  }
  scanf("%d", &K);
  printf("%d\n", solve(coins, K));

  return 0;
}