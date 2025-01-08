/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) uniform_int_distribution<__int128_t>(l, r)(rng)
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;
  vector<__int128_t> z(n + 1);
  for (int i = 1; i <= n; ++i) {
    z[i] = rnd(1e10, 1e22);
  }
  vector<__int128_t> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    int64_t u; cin >> u;
    a[i] = a[i - 1] + z[u];
  }
  for (int i = 1; i <= n; ++i) {
    int64_t u; cin >> u;
    b[i] = b[i - 1] + z[u];
  }
  while (q--) {
    int l, r, L, R; cin >> l >> r >> L >> R;
    if (a[r] - a[l - 1] == b[R] - b[L - 1]) cout << "Yes\n";
    else cout << "No\n";
  }
}

