#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int viewers = 0, maxViewers = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    scanf("%d", &d);
    viewers += d;
    maxViewers = max(maxViewers, viewers);
  }
  printf("%d\n", maxViewers);

  return 0;
}