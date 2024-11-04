/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t a, b, C; cin >> a >> b >> C;  
  int64_t x = 0, y = 0, cy = 0, cx = 0;
  int64_t cnt = 0;
  for (int64_t i = 0; i < 60; ++i) {
    if (C & (1ll << i)) {
      cnt++;
      continue;
    }
    cx++;
    cy++;
  }
  bool flag = true;
  while (true) {
    if (cnt < (a - cx) + (b - cy)) {
      flag = false;
      break;
    }
    if (cnt == (a - cx) + (b - cy) && (a - cx) >= 0 && (b - cy) >= 0) {
      break;
    }
    cx--;
    cy--;
  }
  int64_t cnx = a - cx, cny = b - cy;
  if (!flag) {
    cout << -1 << '\n';
  } else {
    for (int64_t i = 0; i < 60; ++i) {
      if (C & (1ll << i)) {
        if (cnx) {
          cnx--;
          x |= (1ll << i);
        } else if (cny) {
          cny--;
          y |= (1ll << i);
        }
      } else {
        if (cx) {
          x |= (1ll << i);
          y |= (1ll << i);
          cx--;
        }
      }
    }
    assert(__builtin_popcountll(y) >= b);
    cout << x << ' ' << y << '\n';
  }
}

