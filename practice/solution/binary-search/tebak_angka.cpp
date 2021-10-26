#include <bits/stdc++.h>
using namespace std;

string guess(int x) {
  printf("%d\n", x);
  fflush(stdout);
  char response[100];
  fgets(response, 100, stdin);
  response[strcspn(response, "\r\n")] = 0; // remove trailing newline
  return response;
}

void solve(int A, int B) {
  while (A <= B) {
    int mid = (A + B) / 2;
    string response = guess(mid);
    if (response == "selamat") {
      return;
    } else if (response == "terlalu kecil") {
      A = mid+1;
    } else if (response == "terlalu besar") {
      B = mid-1;
    } else assert(false);
  }
}

int main() {
  char input[100];
  fgets(input, 100, stdin);
  int A, B;
  sscanf(input, "%d%d", &A, &B);
  solve(A, B);

  return 0;
}