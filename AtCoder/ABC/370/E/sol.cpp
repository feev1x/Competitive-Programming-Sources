/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

const int64_t MOD = 998244353;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n, k; cin >> n >> k;
  vector<int64_t> a(n);
  for (auto &u: a) cin >> u;
  vector<int64_t> dp(n + 1);
  map<int64_t, int64_t> m;
  int64_t all = 1, sum = 0;
  function<int64_t(int64_t)> mod = [&](int64_t num) {
    return (num + MOD) % MOD;
  };
  dp[0] = 1;
  m[0] = 1;
  for (int i = 1; i <= n; ++i) {
    sum = sum + a[i - 1];
    int64_t d = sum - k;
    int64_t c = mod(all - m[d]);
    dp[i] = c;
    all = mod(all + dp[i]);
    m[sum] = mod(m[sum] + dp[i]);
  }
  cout << dp[n] << '\n';
}

