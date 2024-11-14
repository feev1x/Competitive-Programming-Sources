/**
 *    author:  feev1x
 *    created: 18.10.2024 09:50:36
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
  int n; int64_t x; cin >> n >> x;
  vector<int64_t> a(n), cnt(x + 1);
  for (auto &u: a) cin >> u, cnt[u]++;
  bool flag = true;
  for (int i = 1; i < x; ++i) {
    if (cnt[i] % (i + 1)) {
      flag = false;
      break;
    }
    cnt[i + 1] += cnt[i] / (i + 1);
  }
  cout << (flag ? "Yes\n" : "No\n");
  return 0;
}
