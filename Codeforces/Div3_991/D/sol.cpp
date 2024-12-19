/**
 *    author:  feev1x
 *    created: 05.12.2024 21:01:06
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 2e5 + 5, INF = 1e9;

char S[MXSZ];

struct Segtree {
  std::vector<int> psh;
  std::vector<std::pair<int, int>> t;
  int n;
  inline void push(int v) {
    if (psh[v] != 0) {
      t[v << 1].first += psh[v];
      t[v << 1 | 1].first += psh[v];
      psh[v << 1] += psh[v];
      psh[v << 1 | 1] += psh[v];
      psh[v] = 0;
    }
  }
  inline std::pair<int, int> comb(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first > b.first) {
      return a;
    } else if (a.first < b.first) {
      return b;
    } else {
      if (a < b) {
        return a;
      } else {
        return b;
      }
    }
  }
  inline void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = {0, tl};
      return;
    }
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
  inline void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > tr || tl > r) {
      return;
    }
    if (l <= tl && tr <= r) {
      t[v].first += x;
      psh[v] += x;
      return;
    }
    push(v);
    int tm = tl + tr >> 1;
    update(v << 1, tl, tm, l, r, x);
    update(v << 1 | 1, tm + 1, tr, l, r, x);
    t[v] = comb(t[v << 1], t[v << 1 | 1]);
  }
  Segtree(int _n) : n(_n) {
    t.resize(n * 4 + 5);
    psh.resize(n * 4 + 5);
    build(1, 1, n);
  }
  inline void modify(int l, int r, int x) {
    update(1, 1, n, l, r, x);
  }
  inline std::pair<int, int> get() {
    return t[1];
  }
};

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    scanf("%s", S);
    std::string s = S;
    int n = s.size();
    std::set<std::pair<int, int>> a;
    Segtree t(n);
    for (int i = 0; i < n; ++i) {
      t.modify(i + 1, i + 1, s[i] - i);
    }
    std::string ans;
    for (int i = 0; i < n; ++i) {
      int gt = t.get().first, gt1 = t.get().second;
      ans += char(gt);
      t.modify(gt1, gt1, -INF);
      t.modify(gt1, n, 1);
    }
    printf("%s\n", ans.c_str());
  }
  return 0;
}
