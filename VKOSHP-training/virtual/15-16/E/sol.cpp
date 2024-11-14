/**
 *    author:  feev1x
 *    created: 15.10.2024 11:39:38
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

int64_t binpow(int64_t a, int n) {
  if (n == 0) return 1;
  if (n & 1) return a * binpow(a, n - 1);
  int64_t b = binpow(a, n / 2);
  return b * b;
}

signed main() {
  freopen("division.in", "r", stdin);
  freopen("division.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n, m; cin >> n >> m;
  string s = to_string(n);
  string s1 = to_string(m);
  if (n % m == 0) {
    cout << n << '\n';
    return 0;
  }
  if (s.size() == 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (s.size() < s1.size()) {
    cout << -1 << '\n';
    return 0;
  }
  if (sqrt(n) < m) {
    // ((10^sz - 1) / m + 1) * m
    int64_t res = n;
    int cnt = 13;
    for (int64_t sn = ((binpow(10, s.size() - 1) - 1) / m + 1) * m; to_string(sn).size() == s.size(); sn += m) {
      string t = to_string(sn);
      int c = 0;
      for (int i = 0; i < t.size(); ++i) {
        c += (s[i] != t[i]);
      }
      if (c < cnt) {
        res = sn;
        cnt = c;
      }
    }
    cout << res << '\n';
    return 0;
  }
  vector<vector<int>> dp(s.size() + 1, vector<int>(m, 1e9)), bk(s.size() + 1, vector<int>(m));
  vector<vector<int>> lst(s.size() + 1, vector<int>(m));
  reverse(s.begin(), s.end());
  dp[0][0] = 0;
  for (int i = 1; i <= s.size(); ++i) {
    // i - 1
    for (int j = 0; j < m; ++j) {
      for (int d = 0; d < 10; ++d) {
        if (i == s.size() && d == 0) continue;
        if (dp[i - 1][j] + (d != s[i - 1] - '0') < dp[i][(j + (d * binpow(10, i - 1))) % m]) {
          dp[i][(j + (d * binpow(10, i - 1))) % m] = dp[i - 1][j] + (d != s[i - 1] - '0');
          bk[i][(j + (d * binpow(10, i - 1))) % m] = d;
          lst[i][(j + (d * binpow(10, i - 1))) % m] = j;
        }
      }
    }
  }
  string res;
  int ls = 0;
  for (int i = s.size(); i >= 1; --i) {
    int d = bk[i][ls];
    ls = lst[i][ls];
    res += char(d + '0');
  }
  cout << res << '\n';
  debug(dp[s.size()][0]);
  return 0;
}
