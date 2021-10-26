#include <bits/stdc++.h>
using namespace std;

string getstring() {
  static char buffer[100];
  scanf("%s", buffer);
  return buffer;
}

vector<string> solve(const vector<string>& species, const vector<pair<string, string>> evolutions, const string& source, const string& target) {
  int n = species.size();

  // Menggunakan binary search untuk mendapatkan indeks suatu species.
  auto get_index = [&](const string& name) -> int {
    return lower_bound(species.begin(), species.end(), name) - species.begin();
  };

  // Ubah edge list menjadi adjacency list.
  vector<vector<int>> adj(n);
  for (auto& e : evolutions) {
    int from = get_index(e.first), to = get_index(e.second);
    adj[from].push_back(to);
  }

  // BFS
  auto bfs = [&](const int &source, const int &target) -> vector<string> {
    queue<int> q;
    vector<int> previous(n, -1), visited(n);

    q.emplace(source);
    visited[source] = 1;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (v == target) break;
      for (int u : adj[v]) {
        if (!visited[u]) {
          visited[u] = 1;
          q.emplace(u);
          previous[u] = v;
        }
      }
    }

    if (!visited[target]) {
      return {};
    }

    // Backtrack untuk mendapatkan garis evolusi.
    vector<string> ans = { species[target] };
    int v = target;
    while (v != source) {
      v = previous[v];
      ans.push_back(species[v]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  };

  int source_index = get_index(source), target_index = get_index(target);
  auto ans = bfs(source_index, target_index);
  // Kalau tidak ada jalurnya, mungkin garis evolusinya terbalik.
  // Ulangi BFS dengan menukar source dan targetnya.
  if (ans.empty()) {
    ans = bfs(target_index, source_index);
  }
  return ans;
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
