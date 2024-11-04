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
    vector<int> zero, one;
    map<int, bool> nul, on;
    for (int i = 0; i < n; ++i) {
      int x, y; cin >> x >> y;
      if (y == 0) zero.emplace_back(x), nul[x] = true;
      else one.emplace_back(x), on[x] = true;
    }
    int64_t res = 0;
    sort(zero.begin(), zero.end());
    sort(one.begin(), one.end());
    int pos = 0;
    for (int i = 0; i < zero.size(); ++i) {
      int x = zero[i];
      if (on[x]) {
        res += one.size() + zero.size() - 2; 
      }
      res += (on[x - 1] && on[x + 1]);
    }
    for (int i = 0; i < one.size(); ++i) {
      int x = one[i];
      res += (nul[x - 1] && nul[x + 1]);
    }
    cout << res << '\n';
  }
}

