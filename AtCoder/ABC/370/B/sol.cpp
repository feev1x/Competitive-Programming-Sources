/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<vector<int>> a(n + 1, vector<int> (n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> a[i][j];
    }
  }
  int nw = 1;
  for (int i = 1; i <= n; ++i) {
    nw = a[max(nw, i)][min(nw, i)];
  }
  cout << nw << '\n';
}

