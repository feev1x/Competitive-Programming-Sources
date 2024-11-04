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
  int64_t cnt = n;
  int64_t ls = (1ll << k - 1);
  for (int i = 0; i < k; ++i) {
    int u; cin >> u;
    cnt += u * (ls / (1ll << i));
  }
  cout << cnt << '\n';
}

