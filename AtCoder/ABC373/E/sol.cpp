/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

#define int int64_t

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  if (n == m) {
    for (int i = 0; i < n; ++i) {
      cout << 0 << " \n"[i == n - 1];
    }
    return 0;
  }
  int64_t k; cin >> k;
  vector<int64_t> a(n);
  int64_t gol = k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    gol -= a[i];
  }
  vector<int64_t> b = a;
  sort(b.begin(), b.end());
  vector<int64_t> p(n);
  p[0] = 0;
  for (int i = 1; i < n; ++i) {
    p[i] += p[i - 1];
    p[i] += (b[i] - b[i - 1]) * i;
  }
  for (int i = 0; i < n; ++i) {
    int64_t L = 0, R = gol, ans = -1;
    while (L <= R) {
      int64_t md = (L + R) >> 1ll;
      int j = (upper_bound(b.begin(), b.end(), a[i] + md) - b.begin());
      int cnt = n - j; 
      --j;
      bool flag = true;
      if (cnt < m) {
        int64_t r = p[j];
        int64_t l = j - (m - cnt - 1);
        r -= p[l];
        r -= (b[j] - b[l]) * l;
        r += (m - cnt) * ((a[i] + md + 1) - b[j]);
        if (a[i] >= b[l]) {
          r -= md;
          r += (a[i] + md) - b[l - 1];
        }
        flag = gol - md >= r;
      }
      if (flag) L = md + 1;
      else R = md - 1, ans = md;
    }
    cout << ans << " \n"[i == n - 1];
  }
}

