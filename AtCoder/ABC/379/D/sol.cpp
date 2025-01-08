/**
 *    author:  feev1x
 *    created: 09.11.2024 18:47:47
**/
#include "bits/stdc++.h"
using namespace std;

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

#define orset tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

signed main() {
  int q; scanf("%d", &q);
  orset st;
  ll mus = 0;
  while (q--) {
    int type; scanf("%d", &type);
    if (type == 1) {
      st.insert(0 - mus);
    } else if (type == 2) {
      ll t; scanf("%lld", &t);
      mus += t;
    } else {
      ll h; scanf("%lld", &h);
      h -= mus;
      printf("%d\n", (int)st.size() - (int)st.order_of_key(h));
      while (!st.empty() && *--st.end() >= h) {
        st.erase(--st.end());
      }
    }
  }
  return 0;
}
