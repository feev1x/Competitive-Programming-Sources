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
    vector<int> a(n);
    set<int> st;
    for (auto &u: a) cin >> u, st.emplace(u);
    sort(a.begin(), a.end());
    int64_t res = a[0];
    for (int i = 1; i < n; ++i) {
      res = (res + a[i]) / 2;
    }
    cout << res << '\n';
  }
}

