/**
 *    author:  feev1x
 *    created: 17.10.2024 10:43:03
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
//  freopen("chaotic.in", "r", stdin);
//  freopen("chaotic.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  vector<int> ans;
  for (int i = 0; i + 2 < n; ++i) {
    if (a[i] < a[i + 1] && a[i + 1] < a[i + 2]) {
      ans.emplace_back(i + 2);
      swap(a[i + 1], a[i + 2]);
    }
    if (a[i] > a[i + 1] && a[i + 1] > a[i + 2]) {
      ans.emplace_back(i + 2);
      swap(a[i + 1], a[i + 2]);
    }
  }
  if (int(ans.size()) > n) {
    cout << -1 << '\n';
  }
  n = ans.size();
  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}
