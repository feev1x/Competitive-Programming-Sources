/**
 *    author:  feev1x
 *    created: 26.12.2024 10:40:20
**/
#include <bits/stdc++.h>

using i64 = long long;

struct Bit {
  std::vector<int> p;
  int n; 
  Bit(int _n) : n(_n) {
    p.resize(n + 1);
  }
  inline void modify(int r, int x) {
    for (; r <= n; r += r & -r) {
      p[r] += x;
    }
  }
  inline int get(int r) {
    int res = 0;
    for (; r > 0; r -= r & -r) {
      res += p[r];
    }
    return res;
  }
  inline int get(int l, int r) {
    return get(r) - get(l - 1);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; i64 x, y; std::cin >> n >> x >> y;  
  std::vector<int> a(n);
  std::vector<std::vector<std::pair<int, int>>> query(n + 1), rem(n + 1);
  for (auto &u: a) {
    std::cin >> u;
  }
  a.emplace(a.begin(), 0);
  int q; std::cin >> q;
  std::vector<i64> ans(q);
  for (int i = 0; i < q; ++i) {
    int l, r; std::cin >> l >> r;
    query[l].emplace_back(r, i);
  }
  std::vector<int> ls(n + 1);
  auto Dfs = [&](auto &&self, int l, int r, int add) {
    if (l >= r) {
      return;
    }
    int max_l = 0;
    for (int i = l; i <= r; i += add) {
      max_l = std::max(max_l, ls[a[i]]);
      ls[a[i]] = i;
      if (max_l) {
        rem[max_l].emplace_back(i, i + add);
      }
    }
    for (int i = l; i <= r; i += add) {
      ls[a[i]] = 0;
    }
    bool odd = ((r - l) / add + 1) & 1;
    self(self, l, r - add * (!odd), add << 1);
    self(self, l + add, r - add * odd, add << 1);
  };
  Dfs(Dfs, 1, n, 1);
  Bit bit(n);
  for (int i = 1; i <= n; ++i) {
    for (auto [l, r]: rem[i]) {
      bit.modify(l, 1);
      if (r <= n) {
        bit.modify(r, -1);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto [r, j]: query[i]) {
      i64 cnt = bit.get(i, r);
      ans[j] = (i64)y * cnt + (i64)x * (cnt + 1);
    }
    for (auto [l, r]: rem[i]) {
      bit.modify(l, -1);
      if (r <= n) {
        bit.modify(r, 1);
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}
