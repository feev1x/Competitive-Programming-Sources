/**
 *    author:  feev1x
 *    created: 23.10.2024 09:02:56
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  n--;
  m--;
  int M = m + 14;
  for (int i = 28; i <= 31; ++i) {
    if (M % i == n) {
      cout << (m + 7) % i + 1 << '\n';
      return 0;
    }
  }
  return 0;
}
