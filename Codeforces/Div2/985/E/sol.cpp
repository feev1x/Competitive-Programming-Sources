/**
 *    author:  feev1x
 *    created: 10.11.2024 02:35:08
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
  vector<bool> prime(400001, true);
  vector<int> div(400001);
  prime[1] = prime[0] = false;
  for (int i = 2; i * i <= 4e5; i = i + (i == 2 ? 1 : 2)) {
    if (!prime[i]) continue;
    div[i] = i;
    for (int j = 2 * i; j <= 4e5; j += i) {
      prime[j] = false;
      if (!div[j])
        div[j] = i;
    }
  }
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    vector<int> a(n);
    int gcd_ = 0, cnt = 0, pr = 0;
    for (auto &u: a) {
      scanf("%d", &u);
      gcd_ = gcd(gcd_, u);
      if (prime[u]) {
        pr = u;
      }
    }
    if (!pr) {
      printf("%d\n", 2);
      continue;
    }
    bool flag = true;
    for (auto u: a) {
      if (pr == u) continue;
      if (prime[u]) {
        flag = false;
        break;
      }
      if (u & 1) {
        if (u - div[u] < 2 * pr) {
          flag = false;
          break;
        }
      } else {
        if (u < 2 * pr) {
          flag = false;
          break;
        }
      }
    }
    if (!flag) {
      printf("-1\n");
    } else {
      printf("%d\n", pr);
    }
  }
  return 0;
}
