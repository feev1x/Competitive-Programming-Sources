/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int64_t inf = 1e18;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int64_t>> e(m + 1);
  vector<vector<int64_t>> a(n + 1, vector<int64_t>(n + 1, inf));
  for (int i = 1; i <= m; ++i) {
    auto &[u, v, t] = e[i]; cin >> u >> v >> t;
    a[u][v] = a[v][u] = min(a[u][v], t);
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i][k] == inf) {
          break;
        }
        if (a[k][j] == inf) {
          continue;
        }
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    a[i][i] = 0;
  }
  int q; cin >> q;
  while (q--) {
    int k; cin >> k;
    vector<int> b(k);
    for (auto &u: b) cin >> u;
    int64_t res = inf;
    sort(b.begin(), b.end());
    do {
      for (int mask = 0; mask < (1 << k); ++mask) {
        int64_t cost = 0;
        int nw = 1;
        for (int i = 0; i < k; ++i) {
          auto [u, v, t] = e[b[i]];
          if (mask & (1 << i)) {
            cost += a[nw][v] + t;
            nw = u;
          } else {
            cost += a[nw][u] + t;
            nw = v;
          }
        }
        cost += a[nw][n];
        res = min(res, cost);
      }
    } while (next_permutation(b.begin(), b.end()));
    cout << res << '\n';
  }
}

