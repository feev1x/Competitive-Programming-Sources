/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> r(n);
  for (auto &u: r) cin >> u;
  set<vector<int>> res;
  vector<vector<vector<int>>> v(n);
  for (int i = 0; i < n; ++i) {
    for (int k = 1; k <= r[i]; ++k) {
      vector<int> K;
      K.emplace_back(k);
      if (i > 0)
      for (auto x: v[i - 1]) {
        vector<int> nw = x;
        nw.emplace_back(k);
        v[i].emplace_back(nw);
      }
      else v[0].emplace_back(K);
    }
  }
  for (auto x: v[n - 1]) {
    int sum = 0;
    for (auto u: x) {
      sum += u;
    }
    if (sum % k == 0) res.emplace(x);
  }
  for (auto x: res) {
    for (auto u: x) {
      cout << u << ' ';
    }
    cout << '\n';
  }
}

