#include <bits/stdc++.h>
using namespace std;

bool checkPrefix(const string& s, const string& word) {
  string t = s.size() < word.size() ? s : word;
  string u = s.size() < word.size() ? word : s;
  return u.substr(0, t.size()) == t;
};

int main() {
  int n;
  scanf("%d", &n);

  set<string> words;

  for (int i = 0; i < n; ++i) {
    static char buffer[60];
    scanf("%s", buffer);
    string word = buffer;
    auto it = words.lower_bound(word);
    if (it != words.end()) {
      if (checkPrefix(*it, word)) {
        puts("BAD SET");
        puts(word.c_str());
        return 0;
      }
    }
    if (it != words.begin()) {
      it--;
      if (checkPrefix(*it, word)) {
        puts("BAD SET");
        puts(word.c_str());
        return 0;
      }
    }
    words.insert(word);
  }

  puts("GOOD SET");

  return 0;
}