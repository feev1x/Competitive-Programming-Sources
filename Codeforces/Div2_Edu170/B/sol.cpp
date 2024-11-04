/**
 *    author:  feev1x
 *    created: 14.10.2024 20:39:58
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int mod = 1e9 + 7;

int64_t binpow(int64_t a, int64_t n) {
  if (n == 0) return 1;
  if (n & 1) return (a * binpow(a, n - 1)) % mod;
  int64_t b = binpow(a, n / 2);
  return (b * b) % mod;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t t; cin >> t;
  vector<int> n(t), k(t);
  for (auto &u: n) cin >> u;
  for (auto &u: k) cin >> u;
  for (int i = 0; i < t; ++i) {
    if (n[i] == k[i]) {
      cout << 1 << '\n';
    } else {
      cout << binpow(int64_t(2), k[i]) << '\n';
    }
  }
}
