/**
 *    author:  feev1x
 *    created: 17.10.2024 20:23:25
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
  int n; cin >> n;
  vector<int64_t> l(n), r(n), x(n);
  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    x[i] = l[i];
    sum += l[i];
  }
  for (int i = 0; sum != 0 && i < n; ++i) {
    debug(sum, x);
    if (sum < 0) {
      if ((r[i] - x[i]) + sum >= 0) {
        x[i] += (-sum);
        sum = 0;
        break;
      }
      sum += (r[i] - x[i]);
      x[i] = r[i];
    } else {
      if ((l[i] - x[i]) + sum <= 0) {
        x[i] -= sum;
        sum = 0;
        break;
      }
      sum -= (x[i] - l[i]);
      x[i] = l[i];
    }
  }
  debug(sum, x);
  if (sum == 0) {
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
      cout << x[i] << " \n"[i == n - 1];
    }
  } else {
    cout << "No\n";
  }
  return 0;
}
