/**
 *    author:  feev1x
 *    created: 15.10.2024 10:37:56
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n), neg, pos;
  int mx = 0;
  int mn = 0;
  int sum = 0;
  for (auto &u: a) {
    cin >> u;
    sum += u;
    if (u > 0) {
      pos.emplace_back(u);
      mx += u;
    } else {
      neg.emplace_back(u);
      mn += u;
    }
  }
  sort(pos.begin(), pos.end(), greater<>());
  sort(neg.begin(), neg.end());
  for (int i = 0; i < pos.size(); ++i) {
    if (i < k) {
      mn += -pos[i];
    } else {
      mn += pos[i];
    }
  }
  for (int i = 0; i < neg.size(); ++i) {
    if (i < k) {
      mx += -neg[i];
    } else {
      mx += neg[i];
    }
  }
  if (abs(mx) > abs(mn)) {
    cout << mx << '\n';
  } else {
    cout << -mn << '\n';
  }
}
