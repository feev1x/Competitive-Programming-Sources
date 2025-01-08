/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<string> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = " " + a[i];
    b[i] = a[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int op = min({i, j, n + 1 - i, n + 1 - j}) % 4;
      int x = i, y = j;
      while (op--) {
        int X = y, Y = n + 1 - x;
        x = X, y = Y;
      }
      b[x][y] = a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << b[i][j];
    }
    cout << '\n';
  }
}

