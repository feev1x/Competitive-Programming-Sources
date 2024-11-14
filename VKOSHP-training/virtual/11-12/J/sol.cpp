/**
 *    author:  feev1x
 *    created: 16.10.2024 17:37:42
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
//  freopen("trains.in", "r", stdin);
//  freopen("trains.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int64_t> C(n + 1);
  C[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int k = 0; k < i; ++k) {
      C[i] += C[k] * C[i - 1 - k];
    }
  }
  int64_t k; cin >> k;
  if (C[n] < k) {
    cout << -1 << '\n';
    return 0;
  }
  function<void(int, int, int64_t)> rec = [&](int l, int r, int64_t k) {
    int n = r - l + 1;
    if (n <= 0) {
      return;
    }
    for (int i = l; i <= r; ++i) {
      int64_t a = C[i - l];
      int64_t b = C[r - i];
      int64_t cur = a * b;
      if (cur > k) {
        cout << i << ' ';
        rec(l, i - 1, k / b);
        rec(i + 1, r, k % b);
        return;
      }
      k -= cur;
    }
  };
  rec(1, n, k - 1);
  cout << '\n';
  return 0;
}
