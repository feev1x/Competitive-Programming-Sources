/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, m, p; cin >> n >> m >> p;
    vector<int> s(p + 1);
    vector<vector<int64_t>> a(n + 1, vector<int64_t>(n + 1, -1));
    for (int i = 1; i <= p; ++i) {
      cin >> s[i];
    }
    for (int i = 0; i <= n; ++i) a[i][i] = 0;
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      int64_t w; cin >> w;
      a[u][v] = a[v][u] = w;
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (a[i][k] != -1 && a[k][j] != -1 && (a[i][j] == -1 || a[i][j] > max(a[i][k], a[k][j]))) {
            a[i][j] = max(a[i][k], a[k][j]);
          }
        }
      }
    }
    vector<int64_t> ls(p + 1, 1e18);
    for (int k = 1; k <= n; ++k) {
      int64_t best = 1e18;
      vector<int64_t> bs(p + 1, 1e18);
      for (int i = 1; i <= n; ++i) {
        int64_t mbest = 0;
        for (int j = 1; j <= p; ++j) {
          if (ls[j] > a[i][s[j]]) {
            mbest += a[i][s[j]];
          } else {
            mbest += ls[j];
          }
        }
        if (mbest < best) {
          best = mbest;
          for (int j = 1; j <= p; ++j) {
            if (ls[j] > a[i][s[j]]) {
              bs[j] = a[i][s[j]];
            } else {
              bs[j] = ls[j];
            }
          }
        }
      }
      cout << best << " \n"[k == n];
      ls = bs;
    }
  }
}

