/**
 *    author:  feev1x
 *    created: 02.11.2024 20:36:11
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    vector<int> a(n);
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i) {
        if (abs(a[i] - a[i - 1]) != 5 && abs(a[i] - a[i - 1]) != 7) {
          flag = false;
        }
      }
    }
    printf(flag ? "YES\n" : "NO\n");
  }
  return 0;
}
