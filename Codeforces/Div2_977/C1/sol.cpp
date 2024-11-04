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
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    map<int, char> mp;
    for (auto &u: a) cin >> u, mp[u] = 'r';
    bool flag = true;
    int i = 0;
    
    for (auto &u: b) {
      cin >> u;
      if (i < n)
      mp[a[i]] = 'l';
      if (mp[u] == 'r') {
        flag = false;
      }
      if (i < n && u == a[i]) {
        i++;
      }
    }
    if (flag) cout << "YA\n";
    else cout << "TIDAK\n";
    
  }
}

