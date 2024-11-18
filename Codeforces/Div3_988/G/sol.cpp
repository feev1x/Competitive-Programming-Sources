/**
 *    author:  feev1x
 *    created: 17.11.2024 20:39:42
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXA = 1e6 + 1, MOD = 998244353;

inline void add_self(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline void sub_self(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

int main() {
  int n; scanf("%d", &n);
  std::vector<int> a(n);
  for (auto &u: a) {
    scanf("%d", &u);
  }
  a.emplace(a.begin(), 0);
  std::vector<std::vector<int>> prm(MXA);
  std::vector<int> val(MXA);
  int mx = 0;
  for (int i = 2; i < MXA; ++i) {
    int u = i;
    for (int j = 2; j * j <= u; ++j) {
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
    for (auto v: prm[u]) {
      prm[i].emplace_back(v);
    }
    std::sort(prm[i].begin(), prm[i].end());
  }
  std::vector<int> cnt(MXA);
  for (int mask = 1; mask < (1 << int(prm[a[n]].size())); ++mask) {
    int st = 1;
    for (int i = 0; i < prm[a[n]].size(); ++i) {
      if (mask & 1 << i) {
        st *= prm[a[n]][i];
      }
    }
    cnt[st] = 1;
  }
  for (int i = n - 1; i >= 1; --i) {
    int cn = 0;
    for (int mask = 1; mask < (1 << int(prm[a[i]].size())); ++mask) {
      int st = 1;
      for (int j = 0; j < prm[a[i]].size(); ++j) {
        if (mask & 1 << j) {
          st *= prm[a[i]][j];
        }
      }
      if (__builtin_popcount(mask) % 2 == 0) {
        sub_self(cn, cnt[st]);
      } else {
        add_self(cn, cnt[st]);
      }
    }
    if (i == 1) {
      printf("%d\n", cn);
    } else {
      for (int mask = 1; mask < (1 << int(prm[a[i]].size())); ++mask) {
        int st = 1;
        for (int j = 0; j < prm[a[i]].size(); ++j) {
          if (mask & 1 << j) {
            st *= prm[a[i]][j];
          }
        }
        add_self(cnt[st], cn);
      }
    }
  }
  return 0;
}
