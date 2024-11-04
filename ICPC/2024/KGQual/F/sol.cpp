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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> r(n + 1), g(n + 1), d(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> r[i] >> g[i] >> d[i];
  }
  int64_t cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += a[i];
    int redg = r[i] + g[i];
    int cntt = cnt + d[i];
    cntt %= redg;
    if (cntt >= g[i]) {
      cnt += redg - cntt;  
    }
  }
  cout << cnt << '\n';
}

