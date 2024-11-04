/**
 *    author:  feev1x
 *    created: 31.10.2024 19:27:14
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
using ld = long double;

const int mod = 1e9 + 7;

inline void add_self(ld &a, ld b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    ld n, m, k; scanf("%Lf%Lf%Lf", &n, &m, &k);
    ld sum = 0;
    vector<ld> fr;
    for (int i = 0; i < m; ++i) {
      ld a, b, f; scanf("%Lf%Lf%Lf", &a, &b, &f);
      fr.emplace_back(f);
      add_self(sum, f);
    }
    ld quan = n * (n - 1) / 2;
    ld res = 0, prob = 1;
    for (int i = 0; i < k; ++i) {
      ld pzr = (quan - m) / quan;
      ld ev = pzr / (1 - pzr) + 1;
      res += ev * prob; 
      ld nres = 0, nprob = 0;
      for (int j = 0; j < m; ++j) {
        ld pb = 1 / m;
        nprob += prob * pb;
        nres += res * pb;
      }
      res = nres;
      prob = nprob;
    }
    printf("%Lf\n", res);
  }
  return 0;
}
