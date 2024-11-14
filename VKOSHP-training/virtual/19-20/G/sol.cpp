/**
 *    author:  feev1x
 *    created: 25.10.2024 10:42:44
**/
#include "bits/stdc++.h"
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

int m;

void add_self(int &a, int b) {
  a += b;
  if (a >= m) {
    a -= m;
  }
}

int add(int a, int b) {
  return (a + b) % m;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n >> m;
  vector<int> a(n);
  for (auto &u: a) cin >> u, u %= m;
  auto Fun = [](int n, vector<int> a, int irl, int m) {
    map<int, pair<vector<int>, vector<int>>> mp;
    for (int mask1 = 1; mask1 < (1 << n); ++mask1) {
      int sm = __builtin_popcount(mask1);
      for (int mask2 = 0; mask2 < (1 << sm); ++mask2) {
        int fs = 0;
        int A = 0, B = 0;
        vector<int> A1, B1;
        for (int i = 0; i < n; ++i) {
          if (!(mask1 & (1 << i))) continue;
          if (mask2 & (1 << fs)) {
            A1.emplace_back(i + irl);
            add_self(A, a[i]);
          } else {
            B1.emplace_back(i + irl);
            add_self(B, a[i]);
          }
          fs++;
        }
        mp[A - B] = {A1, B1};
        debug(A - B, A, B);
      }
    }
    return mp;
  };
  vector<int> b;
  for (int i = n / 2; i < n; ++i) {
    b.emplace_back(a[i]);
  }
  auto mp1 = Fun(n / 2, a, 1, m);
  auto mp2 = Fun((n + 1) / 2, b, n / 2 + 1, m);
  vector<int> l, r;
  for (auto [key, val]: mp1) {
    if (val.first.size() + val.second.size() == 0) continue;
    if (mp2[m - key].first.size() + mp2[m - key].second.size() > 0) {
      for (auto u: mp2[m - key].first) {
        l.emplace_back(u);
      }
      for (auto u: val.first) {
        l.emplace_back(u);
      }
      for (auto u: mp2[m-key].second) {
        r.emplace_back(u);
      }
      for (auto u: val.second) {
        r.emplace_back(u);
      }
      break;
    } else if (mp2[-key].first.size() + mp2[-key].second.size() > 0) {
      for (auto u: mp2[-key].first) {
        l.emplace_back(u);
      }
      for (auto u: val.first) {
        l.emplace_back(u);
      }
      for (auto u: mp2[-key].second) {
        r.emplace_back(u);
      }
      for (auto u: val.second) {
        r.emplace_back(u);
      }
      break;
    }
  }
  if (mp1[0].first.size() + mp1[0].second.size() > 0) {
    l = mp1[0].first;
    r = mp1[0].second;
  }
  if (mp2[0].first.size() + mp2[0].second.size() > 0) {
    l = mp2[0].first;
    r = mp2[0].second;
  }
  if (l.empty() && r.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  cout << l.size() << '\n';
  for (auto u: l) cout << u << ' ';
  cout << '\n';
  cout << r.size() << '\n';
  for (auto u: r) cout << u << ' ';
  cout << '\n';
  return 0;
}

