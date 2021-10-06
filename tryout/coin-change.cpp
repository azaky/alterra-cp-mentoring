#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<long long> dp(n+1, 0);
  dp[0] = 1;

  for (int i = 0; i < m; ++i) {
    int c;
    scanf("%d", &c);
    for (int j = c; j <= n; ++j) {
      dp[j] += dp[j-c];
    }
  }

  printf("%lld\n", dp[n]);

  return 0;
}