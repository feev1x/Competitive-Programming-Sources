#include <bits/stdc++.h>

struct Bit{
  std::vector<int64_t> p;
  int n;
  Bit(int n) : n(n) { p.resize(n); }
  inline void update(int r, int x) {
    for (; r < n; r = r | (r + 1)) p[r] += x;
  }
  inline int64_t get(int r) {
    int64_t res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) res += p[r];
    return res;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n), idx(n);
  for (auto &u: a) std::cin >> u;
  auto b = a;
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  for (int i = 0; i < n; ++i) idx[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  Bit bit(n), bitc(n);
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    res += bitc.get(idx[i]) * a[i] - bit.get(idx[i]);
    bit.update(idx[i], a[i]);
    bitc.update(idx[i], 1);
  }
  std::cout << res << '\n';
  return 0;
}
