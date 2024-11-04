/**
 *    author:  feev1x
 *    created: 28.10.2024 21:15:01
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    int64_t sum = n * (n + 1) / 2;
    deque<int> dq;
    for (int i = n; i >= 1; --i) {
      if (s[i] == '1') {
        dq.emplace_back(i);
      } else {
        if (!dq.empty()) {
          sum -= dq.front();
          dq.pop_front();
        }
      }
    }
    while (dq.size() > 1) {
      sum -= dq.front();
      dq.pop_front();
      dq.pop_back();
    }
    cout << sum << '\n';
  }
  return 0;
}
