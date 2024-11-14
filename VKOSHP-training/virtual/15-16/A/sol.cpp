/**
 *    author:  feev1x
 *    created: 16.10.2024 19:55:02
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
//  freopen("atoms.in", "r", stdin);
//  freopen("atoms.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (auto &u: a) cin >> u;
  int m; cin >> m;
  segtree tree(a);
  while (m--) {
    char type; cin >> type;
    if (type == '?') {
      int l, r; cin >> l >> r;

    } else {
    }
  }
  return 0
}
