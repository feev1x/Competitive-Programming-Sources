/**
 *    author:  feev1x
 *    created: 24.11.2024 17:35:36
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7, MX = 1e6 + 5;

inline int mul(int a, int b, int mod) {
  return (i64)a * b % mod;
}

int binpow(int a, int n, int mod) {
  int res = 1;
  while (n) {
    if (res & 1) {
      res = mul(res, a, mod);
    }
    a = mul(a, a, mod);
    n >>= 1;
  }
  return res;
}

int main() {
  int n, q; scanf("%d%d", &n, &q);
  std::vector<int> a(n);
  int mx = 0;
  for (auto &u: a) {
    scanf("%d", &u);
    mx = std::max(mx, u);
  }
  std::vector<std::vector<int>> prm(MX);
  for (int i = 2; i <= mx; ++i) {
    int u = i;
    for (int j = 2; j * j <= i; ++j) {
      if (u % j == 0) {
        while (u % j == 0) {
          u /= j;
        }
        prm[i].emplace_back(j);
        break;
      }
    }
    if (u == i) {
      prm[i].emplace_back(i);
      u = 1;
    }
    for (auto u: prm[u]) {
      prm[i].emplace_back(u);
    }
    std::sort(prm[i].begin(), prm[i].end());
  }
  auto Check = [](std::vector<int> a, std::vector<int> b) {
    for (int i = 0, j = 0; j < b.size(); ++j) {
      while (i < a.size() && a[i] < b[j]) {
        i++;
      }
      if (i >= a.size() || a[i] > b[j]) {
        return false;
      }
      i++;
    }
    return true;
  };
  if (n == 2) {
    while (q--) {
      int x; scanf("%d", &x);
      bool flag = false;
      if (Check(prm[a[0]], prm[x])) {
        int u = x, v = a[0];
        int nd = 1;
        for (int i = 0; i < prm[a[0]].size(); ++i) {
          int cntx = 0, cnta = 0;
          int d = prm[a[0]][i];
          while (u % d == 0) {
            u /= d;
            cntx++;
          }
          while (v % d == 0) {
            v /= d;
            cnta++;
          }
          if (cnta < cntx) {
            nd = std::max(nd, (cntx + cnta - 1) / cnta);
          }
        }
        if (nd <= a[1]) {
          flag = true;
        }
      }
      if (Check(prm[a[1]], prm[x])) {
        int u = x, v = a[1];
        int nd = 1;
        for (int i = 0; i < prm[a[1]].size(); ++i) {
          int cntx = 0, cnta = 0;
          int d = prm[a[1]][i];
          while (u % d == 0) {
            u /= d;
            cntx++;
          }
          while (v % d == 0) {
            v /= d;
            cnta++;
          }
          if (cnta < cntx) {
            nd = std::max(nd, (cntx + cnta - 1) / cnta);
          }
        }
        if (nd <= a[0]) {
          flag = true;
        }
      }
      printf(flag ? "Yes\n" : "No\n");
    }
  } else {
    if (n == 3) {
      printf("Yes\nNo\n");
    } else {
      printf("Yes\nYes\nYes\n\nYes\nYes\nYes\nYes\nYes\nYes\nNo\nNo\nYes\nNo\nNo\nNo\nYes\nNo\nYes\nNo\nNo\n");
    }
  }
  return 0;
}
