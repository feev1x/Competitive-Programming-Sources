/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 5;
int sz[N], p[N], g[N];

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
    g[v] = min(g[v], g[u]);
  }
}
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int64_t n, x; cin >> n >> x;
    for (int i = 0; i <= n; ++i) {
      sz[i] = 1;
      p[i] = i;
      g[i] = i % x;
    }
    vector<int64_t> a(n);
    map<int, bool> mp;
    for (auto &u: a) {
      cin >> u;
    }
    for (int i = 0; i < min(x, n); ++i) {
      for (int j = i + x; j < n; j += x) {
        union_(i, j);
      }
    }
    vector<int64_t> cnt(min(n, x) + 1);
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= n) continue;
      int u = get(a[i]);
      int v = -1;
      if (cnt[g[u]] >= a[i] / x && cnt[g[u]] * x + g[u] < n) v = cnt[g[u]] * x + g[u];
      cnt[g[u]]++;
      mp[v] = true;
    }
    for (int i = 0; i < n; ++i) {
      if (!mp[i]) break;
      ans++;
    }
    cout << ans << '\n';
  }
}

