#include <bits/stdc++.h>

struct Node {
  std::array<int, 26> nx{};
  std::vector<int> idx;
  Node() {}
};

struct Trie {
  std::vector<Node> t;
  Trie() { t.resize(1); }
  inline void add(const std::string &s, int i, int j, int nw = 0) {
    if (i >= s.size()) {
      t[nw].idx.emplace_back(j);
      return;
    }
    int c = s[i] - 'a';
    if (t[nw].nx[c] == 0) {
      t[nw].nx[c] = t.size();
      t.emplace_back(Node());
    }
    add(s, i + 1, j, t[nw].nx[c]);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::string s; std::cin >> s;
  Trie tr;
  for (int i = 1; i <= m; ++i) {
    std::string t; std::cin >> t;
    tr.add(t, 0, i);
  }
  int nw = 0;
  m = n / m;
  for (int i = 0; i < n; ++i) {
    nw = tr.t[nw].nx[s[i] - 'a'];
    if (i % m == m - 1) {
      std::cout << tr.t[nw].idx.back() << ' ';
      tr.t[nw].idx.pop_back();
      nw = 0;
    }
  }
  std::cout << '\n';
  return 0;
}
