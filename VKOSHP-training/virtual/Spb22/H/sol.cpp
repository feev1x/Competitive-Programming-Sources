/**
 *    author:  feev1x
 *    created: 23.10.2024 11:07:37
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
  string s; cin >> s;
  vector<int> p(n + 1);
  vector<bool> used(n + 1);
  int l = 1, j = n + 1;
  int r = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      if (r > b) {
        if (p[i] == 0) p[i] = l++;
        p[i + 1] = j--;
        b++;
      } else {
        if (p[i] == 0) p[i] = j--;
        p[i + 1] = l++;
        r++;
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (p[i] == 0) p[i] = l++;
    cout << p[i] << " \n"[i == n];
  }
  return 0;
}
