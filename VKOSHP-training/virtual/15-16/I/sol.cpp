/**
 *    author:  feev1x
 *    created: 15.10.2024 10:24:41
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int mul = (n / 6) * 6;
  cout << (mul / 3) * 2 << '\n';
}
