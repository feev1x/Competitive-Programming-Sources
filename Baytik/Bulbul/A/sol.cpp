/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

#define int int64_t

const int mod = 1e9 + 7, inf = 1e4;

int dp[101][101][1001][3];
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l; cin >> n >> l;
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  sort(a.begin(), a.end());
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  a.emplace_back(inf);
  if (a[1] - a[0] <= l) dp[1][1][a[1] - a[0]][1] = 2;
  if (2 * (a[1] - a[0]) <= l) dp[1][1][2 * (a[1] - a[0])][0] = 1;
  for (int i = 1; i < n; ++i) {
    int dif = a[i + 1] - a[i];
    for (int j = 1; j <= i; ++j) {
      for (int k = 0; k <= l; ++k) {
        for (int z = 0; z < 3; ++z) {
          if (!dp[i][j][k][z]) continue;
          // filling ends
          if (z < 2 && k + dif * (2 * j - z - 1) <= l) {
            int val = k + dif * (2 * j - z - 1);
            // add to comp and move to end
            if (i == n - 1) {
              dp[i + 1][j][val][z + 1] = (dp[i + 1][j][val][z + 1] + dp[i][j][k][z] * (2 - z) * j) % mod;
            } else if (z == 0 || j > 1) {
              dp[i + 1][j][val][z + 1] = (dp[i + 1][j][val][z + 1] + dp[i][j][k][z] * (2 - z) * (j - z)) % mod;
            }
            // just add to end
            if (k + dif * (2 * j - z + 1) <= l) {
              val = k + dif * (2 * j - z + 1);
              dp[i + 1][j + 1][val][z + 1] = (dp[i + 1][j + 1][val][z + 1] + dp[i][j][k][z] * (2 - z)) % mod;
            }
          }
          // new comp
          if (k + dif * (2 * j - z + 2) <= l) {
            dp[i + 1][j + 1][k + dif * (2 * j - z + 2)][z] = (dp[i + 1][j + 1][k + dif * (2 * j - z + 2)][z] + dp[i][j][k][z]) % mod;
          }
          // add to comp
          if (k + dif * (2 * j - z) <= l) {
            dp[i + 1][j][k + dif * (2 * j - z)][z] = (dp[i + 1][j][k + dif * (2 * j - z)][z] + dp[i][j][k][z] * (2 * j - z)) % mod;
          }
          // merge comp
          if ((k + dif * (2 * j - z - 2) <= l) && (j >= 2) && (i == n - 1 || j > 2 || z < 2)) {
            int val = k + dif * (2 * j - z - 2);
            // merging only regular components
            if (z == 0) {
              dp[i + 1][j - 1][val][z] = (dp[i + 1][j - 1][val][z] + dp[i][j][k][z] * j * (j - 1)) % mod;
            }
            // merging regular components and end component
            if (z == 1) { 
              dp[i + 1][j - 1][val][z] = (dp[i + 1][j - 1][val][z] + dp[i][j][k][z] * (j - 1) * (j - 1)) % mod;
            }
            if (z == 2) {
              // merging all two end components
              if (i == n - 1) {
                dp[i + 1][j - 1][val][z] = (dp[i + 1][j - 1][val][z] + dp[i][j][k][z]) % mod; 
              } else { // merging regular components and end components
                dp[i + 1][j - 1][val][z] = (dp[i + 1][j - 1][val][z] + dp[i][j][k][z] * (j - 2) * (j - 1)) % mod;
              }
            }
          }
        }
      }
    }
  }
  // result
  int res = 0;
  for (int i = 0; i <= l; ++i) {
    res = (res + dp[n][1][i][2]) % mod;
  }
  cout << res << '\n';
}

