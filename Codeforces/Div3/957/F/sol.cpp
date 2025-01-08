/**
 *    author:  feev1x
 *    created: 01.11.2024 11:33:36
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
    int n, x; scanf("%d%d", &n, &x);
    int cnt = 1;
    set<int> st;
    st.emplace(x);
    for (int i = 0; i < n; ++i) {
      int u; scanf("%d", &u);
      if (x % u) continue;
      if (st.count(u)) {
        cnt++;
        set<int>{x}.swap(st);
      } 
      vector<int> nd;
      for (auto v: st) {
        if (v % u == 0) {
          nd.emplace_back(v / u);
        }
      }
      for (auto nx: nd) {
        st.emplace(nx);
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
