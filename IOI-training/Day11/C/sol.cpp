#include <bits/stdc++.h>

constexpr int INF = 1e9;

struct Segtree {
  std::vector<int> t, a;
  int n;
  inline void build(int v, int tl, int tr) {
    if (tl == tr) return t[v] = a[tl], void();
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = std::gcd(t[v << 1], t[v << 1 | 1]);
  }
  Segtree(std::vector<int> a) : a(a), n(a.size()) {
    t.resize(4 * n);
    build(1, 0, n - 1);
  }
  inline std::pair<int, int> comb(std::pair<int, int> a, std::pair<int, int> b) {
    std::pair<int, int> res;
    res.first = std::min(a.first, b.first);
    res.second = std::max(a.second, b.second);
    return res;
  }
  inline int getl(int v, int tl, int tr, int i) {
    if (i < tl) return INF;
    if (tr <= i && t[v] % a[i] == 0) return tl;
    if (tl == tr) return INF;
    int tm = tl + tr >> 1;
    auto r = getl(v << 1 | 1, tm + 1, tr, i);
    if (r == tm + 1 || i < tm + 1) {
      auto l = getl(v << 1, tl, tm, i);
      return std::min(l, r);
    }
    return r;
  }
  inline int getr(int v, int tl, int tr, int i) {
    if (i > tr) return -INF;
    if (tl >= i && t[v] % a[i] == 0) return tr;
    if (tl == tr) return -INF;
    int tm = tl + tr >> 1;
    auto l = getr(v << 1, tl, tm, i);
    if (l == tm || i > tm) {
      auto r = getr(v << 1 | 1, tm + 1, tr, i);
      return std::max(l, r);
    }
    return l;
  }
  inline int getl(int i) { return getl(1, 0, n - 1, i); }
  inline int getr(int i) { return getr(1, 0, n - 1, i); }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &u: a) std::cin >> u;
  std::stack<int> stk;
  Segtree t(a);
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    while (stk.size() && a[i] < a[stk.top()]) stk.pop();
    int l = t.getl(i), r = t.getr(i);
    if (stk.size()) l = std::max(l, stk.top() + 1);
    res += (i - l + 1) * 1LL * (r - i + 1);
    stk.emplace(i);
  }
  std::cout << res << '\n';
  return 0;
}
