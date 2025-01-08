/**
 *    author:  feev1x
 *    created: 31.10.2024 10:08:06
**/
#include "bits/stdc++.h"
using namespace std;

using i64 = long long;
using u64 = unsigned i64;
using i128 = __int128_t;
using u128 = __uint128_t;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) uniform_int_distribution<i64>(l, r)(rng)

signed main() {
  int n = rnd(1, 10), q = rnd(1, 10);
  cout << n << ' ' << q << '\n';
  vector<int> a(n);
  for (auto &u: a) {
    u = rnd(1, 50);
  }
  sort(a.begin(), a.end());
  for (auto u: a) {
    cout << u << ' ';
  }
  cout << '\n';
  while (q--) {
    int l = rnd(1, n - 1), r = rnd(l + 1, n), k = rnd(0, 50);
    cout << l << ' ' << r << ' ' << k << '\n';
  }
  return 0;
}
