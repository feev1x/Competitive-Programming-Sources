/**
 *    author:  feev1x
 *    created: 01.11.2024 21:25:50
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
    auto Ask = [&](int a, int b) {
      printf("? %d %d\n", a, b);
      fflush(stdout);
      int r; scanf("%d", &r);
      return bool(r);
    };
    int mxp = 0, cnt = 0;
    vector<int> p(n);
    p[0] = p[1] = 0;
    vector<bool> leaf(n);
    leaf[1] = true;
    for (int i = 2; i < n; ++i) {
      leaf[i] = true;
      for (int j = mxp + 1; j < i; ++j) {
        if (!leaf[j]) continue;
        if (!Ask(i, j)) {
          cnt++;
          leaf[j] = false;
          p[i] = j;
          mxp = j;
          break;
        }
        assert(cnt <= 2 * n - 6);
      }
    }
    printf("! ");
    for (int i = 1; i < n; ++i) {
      printf("%d%c", p[i], " \n"[i == n - 1]);
    }
    fflush(stdout);
  }
  return 0;
}
