/**
 *    author:  feev1x
 *    created: 14.10.2024 22:13:51
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

const int64_t mod = 998244353;

int64_t binpow(int64_t a, int64_t n) {
  if (n == 0) return 1;
  if (n & 1) return (a * binpow(a, n - 1)) % mod;
  int64_t b = binpow(a, n / 2);
  return (b * b) % mod;
}

int64_t divide(int64_t a, int64_t b){
 return a * binpow(b, mod - 2) % mod;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n, m; cin >> n >> m;
  int64_t fac[100001], dfac[100001];

  fac[0] = 1;
  dfac[0] = 1;
  dfac[1] = 1;
  for (int i = 1; i <= 1e5; ++i) {
    fac[i] = (fac[i - 1] * i) % mod;
    if (i >= 2) {
      dfac[i] = (dfac[i - 2] * i) % mod;
    }
  }
  auto C = [&](int64_t n) {
    return divide(fac[2 * n], (fac[n + 1] * fac[n]) % mod);
  };
  vector<array<int64_t, 2>> dp(n * m + 1);
  dp[0][0] = 1;
  int64_t res = binpow(C(m / 2), n);
  cout << res << '\n';
}
