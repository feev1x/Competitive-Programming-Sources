/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; int64_t K; cin >> n >> K;
  vector<int> x(n + 1), a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<vector<int>> anc(64, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    anc[0][i] = x[i];
  }
  for (int k = 1; k < 64; ++k) {
    for (int i = 1; i <= n; ++i) {
      anc[k][i] = anc[k - 1][anc[k - 1][i]];
    }
  }
  for (int i = 1; i <= n; ++i) {
    int u = i;
    for (int k = 0; k < 64; ++k) {
      if (K & (1ll << k)) {
        u = anc[k][u];
      }
    }
    cout << a[u] << ' ';
  }
  cout << '\n';
}
