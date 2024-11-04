/**
 *    author:  feev1x
 *    created: 24.10.2024 20:56:13
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int64_t long long

const int64_t mod = 1e9 + 7;

int64_t mul(int64_t a, int64_t b) {
  return a * b % mod;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t tt; cin >> tt;
  while (tt--) {
    int64_t n, k; cin >> n >> k;
    if (k == 1) {
      cout << n % mod << '\n';
      continue;
    }
    int64_t f1 = 1, f2 = 1;
    int64_t fs = n;
    for (int64_t i = 3; ; ++i) {
      int64_t sum = (f1 + f2) % k;
      if (!sum) {
        fs = i;
        break;
      }
      f1 = f2;
      f2 = sum;
    }
    cout << ((n % mod) * fs) % mod << '\n';
  }
  return 0;
}
