#include <bits/stdc++.h>
using namespace std;

vector<string> solve(const vector<string>& species, const vector<pair<string, string>> evolutions, const string& source, const string& target) {
  // Letakkan implementasi Anda di sini.
  // Return vector kosong jika tidak ada jalur evolusi antara source dan target.
  return {};
}

string getstring() {
  static char buffer[100];
  scanf("%s", buffer);
  return buffer;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<string, string>> evolutions(m);
  vector<string> species;
  for (int i = 0; i < m; ++i) {
    string from = getstring(), to = getstring();
    evolutions[i] = make_pair(from, to);
    species.push_back(from), species.push_back(to);
  }
  // Get unique species
  sort(species.begin(), species.end());
  species.erase(unique(species.begin(), species.end()), species.end());

  string source = getstring(), target = getstring();

  vector<string> ans = solve(species, evolutions, source, target);
  if (ans.empty()) {
    puts("TIDAK MUNGKIN");
  }
  else {
    for (const string& s : ans) {
      puts(s.c_str());
    }
  }

  return 0;
}
