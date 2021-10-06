#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<vector<int>> trie(1, vector<int>(10, -1));
  vector<int> mark(1, 0);

  for (int i = 0; i < n; ++i) {
    static char buffer[61];
    scanf("%s", buffer);
    string word = buffer;
    
    int node = 0;
    bool leaf = false;
    for (char c : word) {
      int x = c - 'a';
      if (trie[node][x] == -1) {
        trie[node][x] = trie.size();
        trie.push_back(vector<int>(10, -1));
        mark.push_back(0);
        leaf = true;
      } else {
        leaf = false;
      }
      node = trie[node][x];
      if (mark[node]) {
        puts("BAD SET");
        puts(word.c_str());
        return 0;
      }
    }
    if (!leaf) {
      puts("BAD SET");
      puts(word.c_str());
      return 0;
    }
    mark[node] = 1;
  }

  puts("GOOD SET");

  return 0;
}