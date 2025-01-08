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
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      string s; cin >> s;
      for (int j = 0; j < 4; ++j) {
        if (s[j] == '#') {
          a.emplace_back(j + 1);
          break;
        }
      }
    }
    reverse(a.begin(), a.end());
    for (auto x: a) cout << x << ' ';
    cout << '\n';
  }
}

