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
  int n; cin >> n;
  vector<int> a(n), b(n);
  int sum = 0;
  auto chmin = [](int &a, int b) {
    if (a > b) {
      a = b;
    }
  };
  vector<int> sm(4);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    sum += b[i];
    sm[a[i]] += b[i];
  }
  vector<vector<int>> dp(sum + 1, vector<int>(sum + 1, 1e9));
  dp[sm[1]][sm[2]] = 0;
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> d(sum + 1, vector<int>(sum + 1, 1e9));
    for (int s1 = 0; s1 <= sum; ++s1) {
      for (int s2 = 0; s1 + s2 <= sum; ++s2) {
        if (dp[s1][s2] == 1e9) continue;
        if (s1 + s2 > sum) {
          continue;
        }
        chmin(d[s1][s2], dp[s1][s2]);
        if (a[i] == 1) {
          if (s1 - b[i] >= 0) {
            chmin(d[s1 - b[i]][s2], dp[s1][s2] + 1);
            if (s2 + b[i] <= sum) {
              chmin(d[s1 - b[i]][s2 + b[i]], dp[s1][s2] + 1);
            }
          }
        } else if (a[i] == 2) {
          if (s2 - b[i] >= 0) {
            chmin(d[s1][s2 - b[i]], dp[s1][s2] + 1);
            if (s1 + b[i] <= sum) {
              chmin(d[s1 + b[i]][s2 - b[i]], dp[s1][s2] + 1);
            }
          }
        } else {
          if (s1 + s2 + b[i] <= sum) {
            chmin(d[s1][s2 + b[i]], dp[s1][s2] + 1);
            chmin(d[s1 + b[i]][s2], dp[s1][s2] + 1);
          }
        }
      }
    }
    dp = d;
  }
  if (sum % 3 == 0 && dp[sum / 3][sum / 3] < 1e9) {
    cout << dp[sum / 3][sum / 3] << '\n';
  } else {
    cout << -1 << '\n';
  }
}


