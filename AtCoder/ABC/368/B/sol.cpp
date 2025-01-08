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
  int res = 0;
  while (true) {
    sort(a.begin(), a.end(), greater<>());
    if (a[1] <= 0) {
      break;
    }
    a[0]--;
    a[1]--;
    res++;
  }
  cout << res << '\n';
}

