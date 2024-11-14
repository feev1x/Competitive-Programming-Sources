/**
 *    author:  feev1x
 *    created: 18.10.2024 09:43:55
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  auto Mod = [&](int64_t a) {
    return a = (a % m + m) % m;
  };
  vector<int64_t> a(n), b(n);
  for (auto &u: a) {
    cin >> u;
  }
  for (auto &u: b) {
    cin >> u;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int l = 0, r = n - 1;
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    if (Mod(a[i] - b[l]) > Mod(a[i] - b[r])) {
      res += Mod(a[i] - b[r--]);
    } else {
      res += Mod(a[i] - b[l++]);
    }
  }
  cout << res << '\n';
  return 0;
}
