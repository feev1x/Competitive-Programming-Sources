/**
 *    author:  feev1x
 *    created: 02.11.2024 20:57:07
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using ld = long double;

signed main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m; scanf("%d%d", &n, &m);
    vector<string> s(n);
    for (auto &u: s) {
      char *S; scanf("%ms", &S);
      u = S;
      free(S);
    }
    int i = 0, j = 0;
    auto Check = [&](int i, int j, int k) {
      return k <= i && i < n - k && k <= j && j < m - k;
    };
    map<pair<int, int>, pair<int, int>> nx;
    nx[{1, 0}] = {0, -1};
    nx[{-1, 0}] = {0, 1};
    nx[{0, 1}] = {1, 0};
    nx[{0, -1}] = {-1, 0};
    auto Sbs = [&](int i, int j, int dx, int dy, int k) {
      string str;
      int cnt = 4;
      while (cnt--) {
        str += s[i][j];
        if (!Check(i + dx, j + dy, k)) {
          tie(dx, dy) = nx[{dx, dy}];
        }
        i += dx;
        j += dy;
      }
      return str == "1543";
    };
    ll res = 0;
    for (int k = 0; k < min(n, m) / 2; ++k) {
      int i = k, j = k;
      res += Sbs(i, j, 0, 1, k);
      int dx = 0, dy = 1;
      j++;
      while (i != k || j != k) {
        res += Sbs(i, j, dx, dy, k);
        if (!Check(i + dx, j + dy, k)) {
          tie(dx, dy) = nx[{dx, dy}];
        }
        i += dx;
        j += dy;
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
