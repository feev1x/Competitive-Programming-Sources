/**
 *    author:  feev1x
 *    created: 16.10.2024 09:30:46
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
  freopen("gcd.in", "r", stdin);
  freopen("gcd.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d; cin >> n >> d;
  vector<int> a(n), ans;
  int gc = 0;
  for (auto &u: a) {
    cin >> u;
    if (u % d == 0) {
      ans.emplace_back(u);
      gc = gcd(gc, u);
    }
  }
  if (gc == d) {
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
  } else {
    cout << -1 << '\n';
  }
}
