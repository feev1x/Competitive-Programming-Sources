/**
 *    author:  feev1x
 *    created: 21.10.2024 09:32:26
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> p(n + 1);
  cout << 1 << ' ';
  map<int, bool> mp;
  int cnt = 0;
  int end = 0, pos = n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    cnt++;
    mp[p[i]] = true;
    while (mp[pos]) {
      pos--;
      end++;
      cnt--;
    }
    cout << cnt + 1 << ' ';
  }
  cout << '\n';
  return 0;
}
