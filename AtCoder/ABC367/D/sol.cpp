/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int> a(n + 1);
  vector<int64_t> p(n * 2 + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a.emplace_back(a[i]);
  }
  vector<vector<int>> v(m);
  v[0].emplace_back(0);
  for (int i = 1; i <= 2 * n; ++i) {
    p[i] = (p[i - 1] + a[i]) % m;
    v[p[i]].emplace_back(i);
  }
  int64_t res = 0;
  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < v[k].size(); ++i) {
      int pos = v[k][i];
      if (pos >= n) break;
      int64_t cnt = (lower_bound(v[k].begin() + i + 1, v[k].end(), n + pos) - (v[k].begin() + i + 1));
      res += cnt;
    }
  }
  cout << res << '\n';
} 

