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
    int n, r; cin >> n >> r;
    vector<int> a(n);
    int sr = 0;
    int cnt = 0;
    int sm = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sm += a[i];
      if (a[i] % 2 == 0) r -= a[i] / 2;
      else r -= a[i] / 2 + 1, sr++;
    }
    if (r >= 0) {
      cout << sm << '\n';
    } else {
      r = -r;
      sr -= r;
      sm -= r * 2;
      cout << sm << '\n';
    }
  }
}

