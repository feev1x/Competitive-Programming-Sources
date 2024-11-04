/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, q; cin >> n >> q;
    vector<int64_t> x(n);
    for (auto &u: x) cin >> u;
    map<int64_t, int64_t> mp;
    for (int i = 0; i < n; ++i) {
      if (i) {
        int64_t l = i, r = n - i;
        mp[l * r] += (x[i] - x[i - 1] - 1);
      }
      int64_t l = i, r = n - i - 1;
      mp[l * r + l + r]++;
    }
    while (q--) {
      int64_t k; cin >> k;
      cout << mp[k] << ' ';
    }
    cout << '\n';
  }
}

