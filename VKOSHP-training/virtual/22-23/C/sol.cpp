/**
 *    author:  feev1x
 *    created: 22.10.2024 09:54:57
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int64_t> a(n);
  for (auto &u: a) cin >> u;
  sort(a.begin(), a.end());
  vector<int64_t> xmn(n), xmx(n), ymn(n), ymx(n), jmn(n), jmx(n);
  for (int i = 0, j = n - 2; i < j; ++i, --j) {
    xmn[i] = xmn[j] = xmx[i] = xmx[j] = a[i] + a[j];
  }
  for (int i = 1, j = n - 1; i < j; ++i, --j) {
    ymn[i] = ymn[j] = ymx[i] = ymx[j] = a[i] + a[j];
  }
  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    jmn[i] = jmx[j] = jmn[j] = jmx[i] = a[i] + a[j];
  }
  for (int i = n / 2 - 1, j = n / 2; i >= 0 && j < n; --i, ++j) {
    xmn[i] = xmn[j] = min(xmn[i], xmn[i + 1]);
    xmx[i] = xmx[j] = max(xmx[i], xmx[i + 1]);
  }
  for (int i = n / 2, j = n / 2 + 1; i >= 0 && j < n; --i, ++j) {
    ymn[i] = ymn[j] = min(ymn[i], ymn[i + 1]);
    ymx[i] = ymx[j] = max(ymx[i], ymx[i + 1]);
  }
  for (int i = 1, j = n - 2; i < j; ++i, --j) {
    jmn[i] = jmn[j] = min(jmn[i], jmn[i - 1]);
    jmx[i] = jmx[j] = max(jmx[i], jmx[i - 1]);
  }
  jmn[n / 2] = 1e18;
  jmx[n / 2] -1e18;
  int64_t res = min({ymx[1] - ymn[1], xmx[0] - xmn[0], jmx[n / 2 - 1] - jmn[n / 2 - 1]});
  debug(ymx[1], ymn[1], xmx[0], xmn[0], jmx[n / 2 - 1], jmn[n / 2 - 1]);
  for (int i = 1; i < n / 2; ++i) {
    int64_t mx = max(jmx[i - 1], ymx[i + 1]), mn = min(jmn[i - 1], ymn[i + 1]);
    res = min(res, mx - mn);
    debug(jmx[i - 1], ymx[i + 1], jmn[i - 1], ymn[i + 1], i);
  }
  for (int i = n / 2 + 1; i < n - 1; ++i) {
    int64_t mx = max(jmx[i + 1], xmx[i - 1]), mn = min(jmn[i + 1], xmn[i - 1]);
    res = min(res, mx - mn);
    debug(jmx[i + 1], ymx[i - 1], jmn[i + 1], ymn[i - 1], i);
  }
  cout << res << '\n';
  return 0;
}
