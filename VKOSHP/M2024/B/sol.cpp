/**
 *    author:  feev1x
 *    created: 05.11.2024 09:03:01
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
    int n, k; scanf("%d%d", &n, &k);
    vector<int> a(n), c(k);
    for (auto &u: a) {
      scanf("%d", &u);
    }
    for (auto &u: c) {
      scanf("%d", &u);
    }
    string s(n, '.');
    int nw = 0;
    for (int i = 0; i < n; ++i) {
      if (c[nw]) {
        s[a[i] - 1] = nw + 'a';
        c[nw]--;
      } else {
        nw++;
        i--;
      }
    }
    printf("%s\n", s.c_str());
  }
  return 0;
}
