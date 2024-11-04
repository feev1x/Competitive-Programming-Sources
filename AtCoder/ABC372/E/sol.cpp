/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

const int N = 2e5 + 5;
int sz[N], p[N];
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st[N];

int get(int v) {
  return v == p[v] ? v : p[v] = get(p[v]);
}

void union_(int u, int v) {
  u = get(u);
  v = get(v);
  if (u != v) {
    if (sz[u] > sz[v]) swap(u, v);
    p[u] = v;
    sz[v] += sz[u];
    for (auto x: st[u]) {
      st[v].insert(x);
    }
    st[u].clear();
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < N; ++i) {
    sz[i] = 1;
    p[i] = i;
    st[i].insert(i);
  }
  int n, q; cin >> n >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int u, v; cin >> u >> v;
      union_(u, v);
    } else {
      int v, k; cin >> v >> k;
      v = get(v);
      k = (st[v].size()) - k + 1;
      if (st[v].size() >= k && k > 0)
        cout << *st[v].find_by_order(k - 1) << '\n';
      else 
        cout << -1 << '\n';
    }
  }
}

