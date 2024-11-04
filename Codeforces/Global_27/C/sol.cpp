/**
 *    author:  feev1x
 *    created: 27.10.2024 21:03:17
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
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    if (n == 5) {
      cout << "5\n2 1 3 4 5\n";
      continue;
    }
    vector<int> p(n + 1);
    if (n & 1) {
      vector<bool> used(n + 1);
      p[n] = n;
      p[n - 1] = n - 1;
      int bit = log2(n);
      int num = (1 << bit) - 1;
      p[n - 2] = num;
      p[n - 3] = num - 1;
      used[n] = used[n - 1] = used[num] = used[num - 1] = true;
      for (int i = 1; i <= n; ++i) {
        if (!used[i] && i % 2 == 1) {
          used[i] = true;
          p[n - 4] = i;
          break;
        }
      }
      for (int i = 1; i <= n; ++i) {
        if (!used[i] && i % 2 == 1) {
          used[i] = true;
          p[n - 5] = i;
          break;
        }
      }
      int ind = 1;
      for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
          p[ind++] = i;
        }
      }
    } else {
      vector<bool> used(n + 1);
      p[n] = n;
      int bit = log2(n);
      int num = (1 << bit) - 1;
      p[n - 1] = num;
      p[n - 2] = num - 1;
      used[n] = used[num] = used[num - 1] = true;
      for (int i = 1; i <= n; ++i) {
        if (!used[i] && i % 2 == 1) {
          used[i] = true;
          p[n - 3] = i;
          break;
        }
      }
      for (int i = 1; i <= n; ++i) {
        if (!used[i] && i % 2 == 1) {
          used[i] = true;
          p[n - 4] = i;
          break;
        }
      }
      int ind = 1;
      for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
          p[ind++] = i;
        }
      }

    }
    int k = 0;
    for (int i = 1; i <= n; ++i) {
      if (i & 1) k &= p[i];
      else k |= p[i];
    }
    cout << k << '\n';
    for (int i = 1; i <= n; ++i) {
      cout << p[i] << " \n"[i == n];
    }
  }
  return 0;
}
