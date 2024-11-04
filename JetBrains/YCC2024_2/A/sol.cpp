/**
 *    author:  feev1x
 *    created: 29.10.2024 08:40:09
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
  double l, p, q; cin >> l >> p >> q;
  double time = l / (p + q);
  double dot = p * time;
  cout << dot << '\n';
  return 0;
}
