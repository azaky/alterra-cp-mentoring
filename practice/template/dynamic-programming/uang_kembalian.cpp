#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& coins, int K) {
  // Letakkan implementasi Anda di sini.
  return -1;
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