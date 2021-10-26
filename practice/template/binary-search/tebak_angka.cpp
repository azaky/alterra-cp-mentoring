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
  // Letakkan implementasi Anda di sini.
  // Anda dapat memanggil fungsi guess(x), yang akan mengembalikan string "selamat", "terlalu kecil", atau "terlalu besar".
}

int main() {
  char input[100];
  fgets(input, 100, stdin);
  int A, B;
  sscanf(input, "%d%d", &A, &B);
  solve(A, B);

  return 0;
}