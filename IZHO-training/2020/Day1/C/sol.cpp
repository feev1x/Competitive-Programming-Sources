/**
 *    author:  feev1x
 *    created: 23.12.2024 09:48:59
**/
#include <bits/stdc++.h>

using i64 = long long;

std::mt19937 rng(static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()));
#define rnd(l, r) std::uniform_int_distribution<i64>(l, r)(rng)

inline void min_self(int &a, int b) {
  if (a > b) {
    a = b;
  }
}

struct SpTable {
  std::vector<std::vector<int>> sp;
  std::vector<int> lg;
  int n;
  SpTable(std::vector<int> a) : n(a.size() - 1) {
    lg.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i / 2] + 1;
    }
    sp.resize(lg[n] + 1, std::vector<int>(n + 1));
    sp[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        sp[i][j] = std::min(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
      }
    }
  }
  inline int get(int l, int r) {
    int i = lg[r - l + 1];
    return std::min(sp[i][l], sp[i][r - (1 << i) + 1]);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n);
  std::vector<std::vector<int>> ap(n + 1);
  int ind = 0, max = 0, cnt2 = 0;
  for (auto &u: a) { 
    std::cin >> u;
    max = std::max(max, u);
    if (ap[u].size() == 2) {
      cnt2--;
    }
    ap[u].emplace_back(ind++);
    if (ap[u].size() == 2) {
      cnt2++;
    }
  }
  if (max > 2 && (n & 1 || cnt2 != n / 2)) {
    i64 res = 0;
    for (int i = 0; i + 1 < n; ++i) {
      std::set<int> out;
      std::set<std::pair<int, int>> in, mx;
      std::vector<std::set<int>> st(n + 1);
      std::vector<bool> mp(n + 1);
      for (int j = 1; j <= n; ++j) {
        for (auto u: ap[j]) {
          if (u >= i) {
            out.emplace(u);
          }
        }
      }
      for (int j = i; j + 1 < n; ++j) {
        while (in.size() && in.begin()->first <= j) {
          mx.erase({*st[in.begin()->second].begin(), in.begin()->second});
          st[in.begin()->second].erase(st[in.begin()->second].begin());
          if (st[in.begin()->second].empty()) {
            goto end;
          }
          if (*st[in.begin()->second].begin() > j) {
            mx.emplace(*st[in.begin()->second].begin(), in.begin()->second);
          }
          in.erase(in.begin());
        }
        while (out.size() && *out.begin() <= j) {
          out.erase(out.begin());
        }
        if (!mp[a[j]]) {
          mp[a[j]] = true;
          for (auto u: ap[a[j]]) {
            if (u > j) {
              out.erase(u);
              st[a[j]].emplace(u);
              in.emplace(u, a[j]);
            }
          }
          if (st[a[j]].empty()) {
            goto end;
          }
          mx.emplace(*st[a[j]].begin(), a[j]);
        }
        int l = (--mx.end())->first, r = (out.empty() ? n : *out.begin());
        res += (r >= l ? r - l : 0);
      }
  end: continue;
    }
    std::cout << res << '\n';
  } else if (max <= 2) {
    i64 res = 0, sz = 0;
    bool one = a[0] == 1;
    std::array<std::vector<int>, 2> pos;
    pos[a[0] % 2].emplace_back(0);
    for (int i = 1; i < n; ++i) {
      pos[a[i] % 2].emplace_back(i);
      if (one == a[i] % 2) {
        sz++;
      } else {
        res += (sz * (sz + 1) * (sz + 2)) / 6;
        sz = 0;
        one = !one;
      }
    }
    res += (sz * (sz + 1) * (sz + 2)) / 6;
    for (int i = 1; i + 1 < n; ++i) {
      int x = (a[i] + 1) % 2;
      auto it1 = std::upper_bound(pos[a[i] % 2].begin(), pos[a[i] % 2].end(), i);
      if (it1 == pos[a[i] % 2].end()) {
        continue;
      }
      auto it = std::upper_bound(pos[x].begin(), pos[x].end(), i);
      if (it == pos[x].end()) {
        continue;
      }
      i64 r = n - std::max(*it1, *it);
      if (it == pos[x].begin()) {
        continue;
      }
      i64 l = *--it + 1;
      res += l * r;
    }
    std::cout << res << '\n';
  } else {
    std::vector<int> left(n + 1, -1), right(n + 1, -1), lpos(n), rpos(n);
    std::vector<__int128_t> z(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
      z[i] = rnd(1e17, 1e18);
    }
    for (int i = 1; i <= n; ++i) {
      b[i] = b[i - 1] + z[a[i - 1]];
    }
    for (int i = 0; i < n; ++i) {
      if (left[a[i]] == -1) {
        left[a[i]] = i;
      } else {
        right[a[i]] = i;
      }
    }
    for (int i = 0; i < n; ++i) {
      lpos[i] = left[a[i]] + 1;
      rpos[i] = right[a[i]] + 1;
    }
    lpos.emplace(lpos.begin(), 0);
    rpos.emplace(rpos.begin(), 0);
    SpTable sp(lpos);
    SpTable rp(rpos);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int mn = rp.get(i + 1, n);
      int sz = mn - i - 1;
      if (sz <= 0 || sp.get(i + 1, mn + sz - 1) < i + 1) {
        continue;
      }
      if (b[mn - 1] - b[i] == b[mn + sz - 1] - b[mn - 1]) {
        cnt++;
      }
    }
    std::cout << cnt << '\n';
  }
  return 0;
}
