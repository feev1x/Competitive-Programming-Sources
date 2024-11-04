/**
 *    author:  feev1x
 *    created: 18.10.2024 10:47:22
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
    int n; cin >> n;
    vector<int> a(n);
    for (auto &u: a) cin >> u;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
    }
    if (sum == 0) {
      cout << n << '\n';
      for (int i = 1; i <= n; ++i) {
        cout << i << ' ' << i << '\n';
      }
      continue;
    }
    vector<pair<int, int>> ans;
    ans.emplace_back(1, 1);
    vector<bool> used(n);
    for (int i = 1; sum != 0 && i < n; ++i) {
      if (sum > 0) {
        if (a[i] == 0) {
          ans.emplace_back(i + 1, i + 1);
        } else if (a[i] == 1) {
          if (!used[i - 1]) {
            int l = ans.back().first;
            ans.pop_back();
            ans.emplace_back(l, i + 1);
            used[i] = true;
            sum -= 2;
          } else {
            ans.emplace_back(i + 1, i + 1);
          }
        } else {
          ans.emplace_back(i + 1, i + 1);
        }
      } else {
        if (a[i] == 0) {
          ans.emplace_back(i + 1, i + 1);
        } else if (a[i] == -1) {
          if (!used[i - 1]) {
            int l = ans.back().first;
            ans.pop_back();
            ans.emplace_back(l, i + 1);
            used[i] = true;
            sum += 2;
          } else {
            ans.emplace_back(i + 1, i + 1);
          }
        } else {
          ans.emplace_back(i + 1, i + 1);
        }
      }
    }
    if (sum != 0) {
      cout << "-1\n";
      continue;
    }
    int i = ans.back().second + 1;
    while (i <= n) {
      ans.emplace_back(i, i);
      i++;
    }
    cout << ans.size() << '\n';
    for (auto [l, r]: ans) {
      cout << l << ' ' << r << '\n';
    }
  }
  return 0;
}
