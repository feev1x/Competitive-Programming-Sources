/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int64_t> a(n), b(n);
  vector<pair<int64_t, int>> c(n);
  int64_t dan = 0, tal = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    c[i].first = b[i] + a[i] + a[i];
    c[i].second = i;
    dan += a[i];
  }
  sort(c.begin(), c.end(), greater<>());
  int cnt = 0;
  for (auto [dif, i]: c) {
    tal += a[i] + b[i];
    dan -= a[i];
    cnt++;
    if (tal > dan) break;
  }
  cout << cnt << '\n';
}

