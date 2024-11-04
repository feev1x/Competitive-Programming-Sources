/**
 *    author:  feev1x
 *    created: 19.10.2024 19:00:39
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
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    vector<int64_t> a(n), b(n);
    for (auto &u: a) cin >> u;
    for (auto &u: b) cin >> u;
    vector<pair<int64_t, int>> a1(n);
    for (int i = 0; i < n; ++i) {
      a1[i] = {a[i], i};
    }
    sort(a1.begin(), a1.end(), [&](pair<int64_t, int> a2, pair<int64_t, int> b2) {
      if (a2.first == b2.first) {
        return b[a2.second] < b[b2.second];
      }
      return a2.first < b2.first;
    });
    int64_t sum = 0, mn = 1e18;
    multiset<int64_t> st;
    for (int i = 0; i < k; ++i) {
      sum += b[a1[i].second];
      st.emplace(-b[a1[i].second]);
    }
    auto chmin = [](int64_t &a, int64_t b) {
      if (a > b && b > 0) {
        a = b;
      }
    };
    int64_t mx = a1[k - 1].first;
    mn = mx * sum;
    for (int i = k; i < n; ++i) {
      if (-*st.begin() > b[a1[i].second]) {
        sum += *st.begin();
        sum += b[a1[i].second];
        st.erase(st.begin());
        st.emplace(-b[a1[i].second]);
        mx = a1[i].first;
      }
      chmin(mn, mx * sum);
    }
    cout << mn << '\n';
  }
  return 0;
}
