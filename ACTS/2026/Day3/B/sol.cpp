#include <bits/stdc++.h>

constexpr int N = 1e6 + 5;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::string s(n, '0');
  std::vector<int> x(n), y(n), idx(n);
  std::vector<std::vector<int>> p(N), b(N);
  for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i], p[x[i]].emplace_back(i);;
  for (int i = 0; i < N; ++i) {
    std::sort(p[i].begin(), p[i].end(), [&](int i, int j) { return y[i] < y[j]; });
    for (int j = 0; j < p[i].size(); ++j) idx[p[i][j]] = j;
  }
  auto Rec = [&](auto &&self, int i, bool r) -> void {
    if (s[i] != '0') return;
    if (b[y[i]].size() == 2) {
      if (x[b[y[i]][0]] > x[i]) {
        int idx = b[y[i]][0];
        b[y[i]] = std::vector{i, b[y[i]][1]};
        int val = s[idx] - '0';
        s[idx] = '0';
        if (r) s[i] = '1';
        else s[i] = '2';
        self(self, idx, val == 1);
      } else if (x[b[y[i]][1]] < x[i]) {
        int idx = b[y[i]][1];
        b[y[i]] = std::vector{b[y[i]][0], i};
        int val = s[idx] - '0';
        s[idx] = '0';
        if (r) s[i] = '1';
        else s[i] = '2';
        self(self, idx, val == 1);
      } else {
        if (r) {
          if (idx[i] + 1 == p[x[i]].size()) return;
          self(self, p[x[i]][idx[i] + 1], r);
        } else {
          if (idx[i] == 0) return;
          self(self, p[x[i]][idx[i] - 1], r);
        }
      }
    } else {
      assert(b[y[i]].size() < 2);
      if (r) s[i] = '1';
      else s[i] = '2';
      b[y[i]].emplace_back(i);
      std::sort(b[y[i]].begin(), b[y[i]].end(), [&](int i, int j) { return x[i] < x[j]; });
      return;
    }
  };
  for (int i = 0; i < N; ++i) if (p[i].size()) Rec(Rec, p[i][0], 1);
  for (int i = 0; i < N; ++i) if (p[i].size()) Rec(Rec, p[i].back(), 0);
  for (int i = 0; i < n; ++i) if (s[i] == '2') s[i] = '1';
  std::cout << s << '\n';
  return 0;
}
