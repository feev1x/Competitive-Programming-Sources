/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q; cin >> n >> m >> q;
  vector<int> a(m + 1), b(m + 1), type(q);
  vector<int64_t> c(m + 1), ans(q);
  vector<pair<int, int>> qu(q);
  vector<bool> del(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < q; ++i) {
    cin >> type[i] >> qu[i].first;
    if (type[i] == 2) {
      cin >> qu[i].second;
    } else {
      del[qu[i].first] = true;
    }
  }
  vector<vector<int64_t>> d(n + 1, vector<int64_t>(n + 1, -1));
  for (int i = 1; i <= n; ++i) {
    d[i][i] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    if (!del[i]) {
      d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (d[i][k] != -1 && d[k][j] != -1 && (d[i][j] == -1 || d[i][j] > d[i][k] + d[k][j])) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  for (int i = q - 1; i >= 0; --i) {
    if (type[i] == 1) {
      int u = a[qu[i].first];
      int v = b[qu[i].first];
      int w = c[qu[i].first];
      if (d[u][v] != -1 && d[u][v] < w) continue;
      d[u][v] = w;
      for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
          if (d[x][u] != -1 && d[v][y] != -1 && (d[x][y] == -1 || d[x][y] > d[x][u] + w + d[v][y])) {
            d[x][y] = d[x][u] + w + d[v][y];
          }
          swap(u, v);
          if (d[x][u] != -1 && d[v][y] != -1 && (d[x][y] == -1 || d[x][y] > d[x][u] + w + d[v][y])) {
            d[x][y] = d[x][u] + w + d[v][y];
          }
        }
      }
    } else {
      ans[i] = d[qu[i].first][qu[i].second];
    }
  }
  for (int i = 0; i < q; ++i) {
    if (type[i] == 2) {
      cout << ans[i] << '\n';
    }
  }
}

