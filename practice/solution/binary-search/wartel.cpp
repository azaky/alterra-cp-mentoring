#include <bits/stdc++.h>
using namespace std;

string solve(const vector<pair<string,string>> &directories, const string &name) {
  int L = 0, R = directories.size()-1;
  while (L <= R) {
    int mid = (L + R) / 2;
    if (directories[mid].first == name) {
      return directories[mid].second;
    } else if (directories[mid].first < name) {
      L = mid+1;
    } else {
      R = mid-1;
    }
  }
  return "NIHIL";
}

int main() {
  int N, Q;
  scanf("%d%d", &N, &Q);

  vector<pair<string,string>> directories(N);
  for (int i = 0; i < N; ++i) {
    static char name_buffer[100], number_buffer[100];
    scanf("%s%s", name_buffer, number_buffer);
    directories[i].first = name_buffer;
    directories[i].second = number_buffer;
  }
  for (int i = 0; i < Q; ++i) {
    static char name_buffer[100];
    scanf("%s", name_buffer);
    puts(solve(directories, name_buffer).c_str());
  }

  return 0;
}