/**
 *    author:  feev1x
 *    created: 09.11.2024 20:44:39
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
    char S[n + 1]; scanf("%s", S);
    string s;
    for (int i = 0; i < n; ++i) {
      s += S[i];
    }
    scanf("%s", S);
    string r;
    for (int i = 0; i < n - 1; ++i) {
      r += S[i];
    }
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') c0++;
      else c1++;
    }
    bool flag = true;
    for (int i = 0; i < n - 1; ++i) {
      if (r[i] == '0') {
        if (!c0 || !c1) {
          flag = false;
        }
        c1--;
      } else {
        if (!c0 || !c1) {
          flag = false;
        }
        c0--;
      }
      if (c1 < 0 || c0 < 0) {
        flag = false;
      }
    }
    printf(flag ? "YES\n" : "NO\n");
  }
  return 0;
}
