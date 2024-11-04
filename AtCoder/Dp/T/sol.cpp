/**
 *    author:  feev1x
 *    created: 23.10.2024 17:36:03
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

inline void add_self(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}

inline int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  string s; cin >> s;
  s = " " + s;
  vector dp(n + 1, vector<int>(n + 1)), pref(n + 1, vector<int>(n + 1));
  dp[1][1] = 1;
  pref[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int b = 1; b <= i; ++b) {
      int l = (s[i - 1] == '<' ? 1 : b), r = (s[i - 1] == '<' ? b - 1 : i - 1);
      add_self(dp[i][b], sub(pref[i - 1][r], pref[i - 1][l - 1]));
      add_self(pref[i][b], add(dp[i][b], pref[i][b - 1]));
//      for (int a = 1; a < i; ++a) {
//        int ch_a = a;
//        if (a >= b) {
//          ch_a++;
//        }
//        if ((ch_a < b) ^ (s[i - 1] == '<')) {
//          continue;
//        }
//        add_self(dp[i][b], dp[i - 1][a]);
//      }
    }
  }
  cout << accumulate(dp[n].begin(), dp[n].end(), 0ll) % mod << '\n';
  return 0;
}
