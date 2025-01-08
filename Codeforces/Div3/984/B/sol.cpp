/**
 *    author:  feev1x
 *    created: 02.11.2024 20:39:01
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
    int n, k; scanf("%d%d", &n, &k);
    vector<int> b(k), c(k);
    map<int, int> mp;
    int res = 0;
    for (int i = 0; i < k; ++i) {
      cin >> b[i] >> c[i];
      mp[b[i]] += c[i];
    }
    vector<int> v;
    for (auto [key, val]: mp) {
      v.emplace_back(val);
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < min(int(v.size()), n); ++i) {
      res += v[i];
    }
    printf("%d\n", res);
  }
  return 0;
}
