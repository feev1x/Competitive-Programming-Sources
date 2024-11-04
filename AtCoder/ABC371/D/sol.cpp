/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

#define int int64_t

const int inf = 1e9;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int64_t> p(n + 1), x(n + 1), c(n + 1);
  x[0] = -inf;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    p[i] = c[i] + p[i - 1];
  }
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    int L = lower_bound(x.begin(), x.end(), l) - x.begin();
    int R = --upper_bound(x.begin(), x.end(), r) - x.begin();
    if (L == 0) {
      cout << p[R] << '\n';
    } else {
      cout << p[R] - p[L - 1] << '\n';
    }
  }
}

