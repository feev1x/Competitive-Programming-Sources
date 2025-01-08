/**
 *    author:  feev1x
 *    created: 14.10.2024 21:05:58
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &u: a) cin >> u;
    sort(a.begin(), a.end());
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      mp[a[i]]++;
    }
    vector<pair<int, int>> v;
    for (auto [key, val]: mp) {
      v.emplace_back(key, val);
    }
    sort(v.begin(), v.end());
    int res = 0;
    int sum = 0;
    int st = v.front().first;
    int ls = v.front().first;
    for (int i = 0; i < v.size(); ++i) {
      auto [x, y] = v[i];
      if (x - st < k && x - ls <= 1) {
        sum += y;
        res = max(res, sum);
        ls = x;
      } else if (x - ls <= 1) {
        res = max(res, sum);
        sum -= mp[st];
        sum += y;
        ls = x;
        st = st + 1;
      } else {
        res = max(res, sum);
        sum = y;
        st = x;
        ls = x;
      }
    }
    res = max(res, sum);
    cout << res << '\n';
  }
}
