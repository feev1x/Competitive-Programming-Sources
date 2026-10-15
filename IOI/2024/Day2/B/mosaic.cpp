#include "mosaic.h"

#include <bits/stdc++.h>

inline void chmin(int &a, int b) { if (a > b) a = b; }

struct Segtree {
  std::vector<int> mu, ml, vls;
  std::vector<std::vector<int>> tru, trl;
  std::vector<std::vector<int64_t>> pu, pl;
  int n, add;
  inline void build(int v, int tl, int tr) {
    if (tl == tr) {
      tru[v].emplace_back(mu[vls[tl] + add]);
      trl[v].emplace_back(ml[vls[tl] + add]);
      pu[v].emplace_back(mu[vls[tl] + add]);
      pl[v].emplace_back(ml[vls[tl] + add]);
      return;
    }
    int tm = tl + tr >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    {
      int l = 0, r = 0;
      while (l < tru[v << 1].size() && r < tru[v << 1 | 1].size()) {
        if (tru[v << 1][l] < tru[v << 1 | 1][r]) tru[v].emplace_back(tru[v << 1][l++]);
        else tru[v].emplace_back(tru[v << 1 | 1][r++]);
      }
      while (l < tru[v << 1].size()) tru[v].emplace_back(tru[v << 1][l++]);
      while (r < tru[v << 1 | 1].size()) tru[v].emplace_back(tru[v << 1 | 1][r++]);
    }
    int l = 0, r = 0;
    while (l < trl[v << 1].size() && r < trl[v << 1 | 1].size()) {
      if (trl[v << 1][l] < trl[v << 1 | 1][r]) trl[v].emplace_back(trl[v << 1][l++]);
      else trl[v].emplace_back(trl[v << 1 | 1][r++]);
    }
    while (l < trl[v << 1].size()) trl[v].emplace_back(trl[v << 1][l++]);
    while (r < trl[v << 1 | 1].size()) trl[v].emplace_back(trl[v << 1 | 1][r++]);
    pu[v].emplace_back(tru[v][0]);
    for (int i = 1; i < tru[v].size(); ++i) pu[v].emplace_back(pu[v].back() + tru[v][i]);
    pl[v].emplace_back(trl[v][0]);
    for (int i = 1; i < trl[v].size(); ++i) pl[v].emplace_back(pl[v].back() + trl[v][i]);
  }
  Segtree(std::vector<int> mu, std::vector<int> ml, int _n, std::vector<int> vls) : vls(vls), mu(mu), ml(ml), add(_n - 1) {
    n = vls.size();
    if (n) {
      tru.resize(4 * n);
      trl.resize(4 * n);
      pl.resize(4 * n);
      pu.resize(4 * n);
      build(1, 0, n - 1);
    }
  }

  inline int64_t getu(int v, int tl, int tr, int l, int r, int val) {
    if (tl > r || l > tr) return 0;
    if (l <= tl && tr <= r) {
      int i = std::upper_bound(tru[v].begin(), tru[v].end(), val) - tru[v].begin() - 1;
      return (i + 1) * 1LL * (val + 1) - (i >= 0 ? pu[v][i] : 0LL);
    }
    int tm = tl + tr >> 1;
    return getu(v << 1, tl, tm, l, r, val) + getu(v << 1 | 1, tm + 1, tr, l, r, val);
  }
  inline int64_t getl(int v, int tl, int tr, int l, int r, int val) {
    if (tl > r || l > tr) return 0;
    if (l <= tl && tr <= r) {
      int i = std::upper_bound(trl[v].begin(), trl[v].end(), val) - trl[v].begin() - 1;
      return (i + 1) * 1LL * (val + 1) - (i >= 0 ? pl[v][i] : 0LL);
    }
    int tm = tl + tr >> 1;
    return getl(v << 1, tl, tm, l, r, val) + getl(v << 1 | 1, tm + 1, tr, l, r, val);
  }
  inline int64_t getu(int l, int r, int val) {
    if (vls.empty() || l > r) return 0LL;
    l = std::lower_bound(vls.begin(), vls.end(), l) - vls.begin();
    r = std::upper_bound(vls.begin(), vls.end(), r) - vls.begin() - 1;
    if (l > r) return 0LL;
    return getu(1, 0, n - 1, l, r, val);
  }
  inline int64_t getl(int l, int r, int val) {
	  if (vls.empty() || l > r) return 0LL;
    l = std::lower_bound(vls.begin(), vls.end(), l) - vls.begin();
    r = std::upper_bound(vls.begin(), vls.end(), r) - vls.begin() - 1;
    return getl(1, 0, n - 1, l, r, val);
  }
};

std::vector<long long> mosaic(std::vector<int> X, std::vector<int> Y,
                              std::vector<int> T, std::vector<int> B,
                              std::vector<int> L, std::vector<int> R) {
  int n = X.size(), add = n - 1;
  std::vector<int> mu(2 * n - 1, n + 1), ml(2 * n - 1, n + 1);
  std::vector<int> X2(n), X3(n), Y2(n), Y3(n), vls;
  if (n > 1) X2[0] = Y[1];
  for (int i = 1; i < n; ++i) {
    if (X2[i - 1] == 0 && X[i] == 0) {
      X2[i] = 1;
      chmin(mu[1 - i + add], 1);
      chmin(ml[1 - i + add], i);
    }
  }
  if (n > 2) X3[0] = Y[2];
  for (int i = 1; i < n; ++i) {
    if (X3[i - 1] == 0 && X2[i] == 0) {
      X3[i] = 1;
      chmin(mu[2 - i + add], 2);
      chmin(ml[2 - i + add], i);
    }
  }
  if (n > 1) Y2[0] = X[1];
  for (int i = 1; i < n; ++i) {
    if (Y2[i - 1] == 0 && Y[i] == 0) {
      Y2[i] = 1;
      chmin(mu[i - 1 + add], i);
      chmin(ml[i - 1 + add], 1);
    }
  }
  if (n > 2) Y3[0] = X[2];
  for (int i = 1; i < n; ++i) {
    if (Y3[i - 1] == 0 && Y2[i] == 0) {
      Y3[i] = 1;
      chmin(mu[i - 2 + add], i);
      chmin(ml[i - 2 + add], 2);
    }
  }
  for (int i = 1; i < n; ++i) X[i] += X[i - 1];
  for (int i = 1; i < n; ++i) Y[i] += Y[i - 1];
  for (int i = -add; i <= add; ++i) {
    if (mu[i + add] == n + 1 || ml[i + add] == n + 1) continue;
    vls.emplace_back(i);
  }
  Segtree t(mu, ml, n, vls);
  auto Pos = [&](int i, int j) {
    int idx = i - j + add;
    if (mu[idx] > i) return 0;
    return i - mu[idx] + 1;
  };
  auto Row = [&](int i, int l, int r) {
//    int64_t res = 0;
//    for (int j = l; j <= r; ++j) res += Pos(i, j);
    return t.getu(i - r, i - l, i);
  };
  auto Col = [&](int i, int l, int r) {
//    int64_t res = 0;
//    for (int j = l; j <= r; ++j) res += Pos(j, i);
    return t.getl(l - i, r - i, i);
  };
  int q = T.size();
  std::vector<long long> ans(q);
  for (int k = 0; k < q; ++k) {
    // +B[k] - [L[k], R[k]]
    // +R[k] - [T[k], B[k]]
    // -(T[k] - 1) - [L[k], R[k]]
    // -(L[k] - 1) - [T[k], B[k]]
    // -(T[k] - 1], L[k] - 1)
    int64_t res = 0;
    if (T[k] == 0) {
      if (L[k] == 0) res += X[R[k]] + Y[B[k]] - X[0];
      else res += X[R[k]] - X[L[k] - 1];
    } else if (L[k] == 0) res += Y[B[k]] - Y[T[k] - 1];
    if (T[k] == 0) T[k] = 1;
    if (L[k] == 0) L[k] = 1;
    res += Row(B[k], L[k], R[k]);
    res += Col(R[k], T[k], B[k]);
    res -= Row(T[k] - 1, L[k], R[k] - 1);
    res -= Col(L[k] - 1, T[k], B[k] - 1);
    res -= Pos(T[k] - 1, L[k] - 1);
    res -= Pos(B[k], R[k]);
    ans[k] = res;
  }
  return ans;
}

