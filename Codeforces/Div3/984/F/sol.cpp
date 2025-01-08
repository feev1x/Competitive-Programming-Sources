/**
 *    author:  feev1x
 *    created: 02.11.2024 22:38:18
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
    ll l, r; int i, k; scanf("%lld%lld%d%d", &l, &r, &i, &k);
    auto Count = [&](int ind, ll sm) {
      int cnt = 0;
      for (int bit = 0; bit < 61; ++bit) {
        if (!(sm & (1ll << bit))) continue;
        if (bit > ind) {
          cnt = (cnt + (1ll << (bit - 1))) % 2;  
        } else if (bit < ind && (sm & (1ll << ind))) {
          cnt = (cnt + (1ll << bit)) % 2;
        }
      }
      if (sm & (1ll << ind)) cnt = (cnt + 1) % 2;
      return cnt;
    };
    auto Cnt = [&](ll sm) {
      int cnt = k <= sm;
      ll num = k;
      for (int bit = 60; bit >= i; --bit) {
        if ((num | (1ll << bit)) <= sm) {
          num |= (1ll << bit);
          cnt = (cnt + (1ll << (bit - i))) % 2;
        }
      }
      return cnt;
    };
    auto Cnn = [&](ll sm) {
      ll nm = 0;
      ll new_num = k;
      for (int bit = 60; bit >= i; --bit) {
        if ((new_num | (1ll << bit)) <= sm) {
          new_num |= (1ll << bit);
        }
      }
      for (int ind = 60; ind >= i; --ind) {
        int cnt = 0;
        for (ll bit = 60; bit >= i; --bit) {
          if (!(new_num & (1ll << bit))) continue;
          if (bit > ind) {
            cnt = (cnt + (1ll << (bit - i - 1))) % 2;
          } else if (bit < ind && (new_num & (1ll << ind))) {
            cnt = (cnt + (1ll << (bit - i))) % 2; 
          }
        }
        if (new_num & (1ll << ind)) cnt = (cnt + 1) % 2;
        if (cnt) nm |= (1ll << ind);
      }
      return nm;
    };
    ll res = 0;
    for (int bit = 0; bit < 61; ++bit) {
      int cnt = ((Count(bit, r) - Count(bit, l - 1)) % 2 + 2) % 2;
      if (cnt) res |= (1ll << bit);
    }
    int cnt = ((Cnt(r) - Cnt(l - 1)) % 2 + 2) % 2;
    if (cnt) res ^= k;
    res ^= (Cnn(r) ^ Cnn(l - 1));
    printf("%lld\n", res);
  }
  return 0;
}
