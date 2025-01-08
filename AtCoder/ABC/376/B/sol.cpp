/**
 *    author:  feev1x
 *    created: 19.10.2024 18:12:36
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  int l = 0, r = 1;
  int dis = 0;
  while (q--) {
    char h; int t; cin >> h >> t;
    t--;
    if (h == 'L') {
      int tl = l;
      bool flag = true;
      int res = 0;
      while (tl != t) {
        res++;
        tl++;
        if (tl == n) tl = 0;
        if (tl == r) {
          flag = false;
          break;
        }
      }
      if (flag) {
        dis += res;
        l = t;
        debug(dis);
        continue;
      }
      tl = l;
      res = 0;
      while (tl != t) {
        res++;
        tl--;
        if (tl == -1) tl = n - 1;
      }
      dis += res;
      l = t;
    } else {
      int tl = r;
      bool flag = true;
      int res = 0;
      while (tl != t) {
        res++;
        tl++;
        if (tl == n) tl = 0;
        if (tl == l) {
          flag = false;
          break;
        }
      }
      if (flag) {
        dis += res;
        r = t;
        debug(dis);
        continue;
      }
      tl = r;
      res = 0;
      while (tl != t) {
        res++;
        tl--;
        if (tl == -1) tl = n - 1;
      }
      dis += res;
      r = t;
    }
    debug(dis);
  }
  cout << dis << '\n';
  return 0;
}
