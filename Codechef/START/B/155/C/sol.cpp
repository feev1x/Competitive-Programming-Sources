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
    int n; cin >> n;
    vector<int> b(n);
    for (auto &u: b) cin >> u;
    vector<int> a(n);
    a[0] = 0;
    int mx = 0;
    int sum = 0;
    for (int i = 1; i < n; ++i) {
      a[i] = b[i] - b[i - 1];
      mx = max(mx, a[i]);
    }
    a[0] = mx;
    for (auto u: a) cout << u << ' ';
    cout << '\n';
  }
}

