/**
 *    author:  feev1x
 *    created: 30.10.2024 08:15:26
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> a(n);
    map<int, bool> mp;
    for (auto &u: a) scanf("%d", &u), mp[u] = true;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (mp[k + a[i]]) {
        printf("YES\n");
        flag = true;
        break;
      }
    }
    if (!flag) {
      printf("NO\n");
    }
  }
  return 0;
}
