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
    int ls = n - k + 1;
    int cnt = 0;
    if (ls % 2 == 0) {
      int l = n - ls;
      cnt += (l / 2) + (l % 2);
    } else {
      int l = n - ls;
      cnt += (l / 2) + 1;
    }
    if (cnt % 2 == 0) cout << "YES\n";
    else cout << "NO\n";
  }
}

