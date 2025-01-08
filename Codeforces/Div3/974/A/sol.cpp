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
    int n, k; cin >> n >> k;
    int cnt = 0;
    int zol = 0;
    for (int i = 0; i < n; ++i) {
      int u; cin >> u;
      if (u >= k) zol += u;
      if (u == 0 && zol) cnt++, zol--;
    }
    cout << cnt << '\n';
  }
}

