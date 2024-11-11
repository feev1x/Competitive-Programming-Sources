/**
 *    author:  feev1x
 *    created: 10.11.2024 21:36:13
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;
using ld = long double;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    char s[n + 1]; scanf("%s", s);
    int x = 0, y = 0;
    bool flag = false;
    for (int mv = 0; mv < 1000; ++mv) {
      if (x == a && y == b) {
        flag = true;
      }
      for (int i = 0; i < n; ++i) {
        if (x == a && y == b) {
          flag = true;
        }
        if (s[i] == 'N') {
          y++;
        } else if (s[i] == 'E') {
          x++;
        } else if (s[i] == 'S') {
          y--;
        } else {
          x--;
        }
        if (x == a && y == b) {
          flag = true;
        }
      }
      if (x == a && y == b) {
        flag = true;
      }
    }
    if (x == a && y == b) {
      flag = true;
    }
    printf(flag ? "YES\n" : "NO\n");
  }
  return 0;
}
