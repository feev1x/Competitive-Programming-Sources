/**
 *    author:  feev1x
 *    created: 25.10.2024 09:32:52
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) uniform_int_distribution<int64_t>(l, r)(rng)

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n);
  int cntm = 0;
  for (auto &u: a) cin >> u, cntm += (u == -1);
  int m = (1 << n) - 1;
  cout << m << '\n';
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ans[i] = cntm + 1;
      m -= cntm;
      m--;
    } else if (a[i] == -1) {
      ans[i] = 1;
      m++;
    } else {
      ans[i] = rnd(10000, (1 << 30) - 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      if (ans[i] + m < (1 << 30)) {
        ans[i] += m;
        break;
      }
      m -= ((1 << 30) - ans[i] - 1);
      ans[i] = (1 << 30) - 1;
    }
  }
  for (auto u: ans) cout << u << ' ';
  cout << '\n';
  return 0;
}
