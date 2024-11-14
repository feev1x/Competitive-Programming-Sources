/**
 *    author:  feev1x
 *    created: 23.10.2024 09:54:06
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> ans(5001);
  ans[0] = 0;
  ans[1] = 0;
  ans[2] = 1;
  ans[3] = 1;
  ans[4] = 3;
  ans[5] = 4;
  for (int i = 6; i <= n; ++i) {
    ans[i] = i * (i - 1) / 2;
    for (int j = i - 1; j >= (i + 1) / 2; --j) {
      ans[i] = min(ans[i], j * (j - 1) / 2 + ans[i - j]); 
      debug(i, j);
    }
  }
  cout << ans[n] << '\n';
  return 0;
}
