/**
 *    author:  feev1x
 *    created: 29.10.2024 08:57:29
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
  int n, k; cin >> n >> k;
  vector<int> p(2 * n);
  iota(p.begin(), p.end(), 1);
  int cnt = n;
  int ind = -2;
  for (int i = 0; i < 2 * n - 1; i += 2) {
    if (cnt == 2 * k) break;
    swap(p[i], p[i + 1]);
    ind = i;
    cnt--;
  }
  bool flag = true;
  ind += 2;
  for (int i = ind; i < 2 * n - 1; i += 4) {
    swap(p[i], p[i + 1]);
  }
  for (int i = 0; i < 2 * n; ++i) {
    cout << p[i] << " \n"[i == 2 * n - 1];
  }
  return 0;
}
