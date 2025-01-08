/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

inline int max(int a, int b) {
  if (a > b) return a;
  return b;
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int64_t n; cin >> n;
    vector<int64_t> a(n);
    vector<int64_t> cn(1000001);
    vector<vector<int>> mp(1000001, vector<int>(22));
    int64_t res = 0;
    for (auto &u: a) cin >> u, cn[u]++;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int xr = a[i] ^ a[j];
        int c = 0;
        int c1 = 0;
        for (int k = 0; k < 21; ++k) {
          if (xr & (1 << k)) {
            if (a[i] & (1 << k)) {
              c1++;
            } else {
              c++;
            }
          }
        }
        mp[xr][max(c1, c)]++;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!(a[i] ^ a[j])) continue;
        int64_t cnt = -cn[a[i]] * cn[a[j]] * 2, xr = a[i] ^ a[j];
        int c1 = 0, c = 0;
        for (int k = 0; k < 21; ++k) {
          if (xr & (1 << k)) {
            if (a[i] & (1 << k)) {
              c1++;
            } else {
              c++;
            }
          }
        }
        c = max(c, c1);
        cnt += mp[xr][c] * 2;
        res += cnt * 2;
      }
    }
    cout << res << '\n';
  }
}

