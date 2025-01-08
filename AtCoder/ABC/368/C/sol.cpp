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
  vector<int> a(n);
  for (auto &u: a) cin >> u;
  int64_t t = 0;
  for (int i = 0; i < n; ++i) {
    t += (a[i] / 5) * 3;
    a[i] %= 5;
    while (a[i] > 0) {
      t++;
      if (t % 3 == 0) {
        a[i] -= 3;
      } else {
        a[i]--;
      }
    }
  }
  cout << t << '\n';
}

