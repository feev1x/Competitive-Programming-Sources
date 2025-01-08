/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;
 
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int64_t> a(n);
    int64_t sum = 0;
    for (auto &u: a) cin >> u, sum += u;
    sum -= a[n - 1];
    sum -= a[n - 2];
    a[n - 2] -= sum;
    a[n - 1] -= a[n - 2];
    cout << a[n - 1] << '\n';
  }
}

