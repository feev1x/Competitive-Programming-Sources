/**
 *    author:  feev1x
 *    created: 10.11.2024 22:43:12
**/
#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;
using ld = long double;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> q(n + 1), k(n + 1), j(n + 1);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &q[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &j[i]);
    }
    std::set<std::pair<int, int>> sq, sk, sj;
    sq.emplace(q[1], 1);
    sk.emplace(k[1], 1);
    sj.emplace(j[1], 1);
    std::vector<bool> dp(n + 1);
    std::vector<int> p(n + 1, -1);
    std::vector<char> ch(n + 1);
    dp[1] = true;
    for (int i = 2; i <= n; ++i) {
      if (sq.upper_bound({q[i], n}) != sq.end()) {
        dp[i] = true;
        p[i] = sq.upper_bound({q[i], n})->second;
        ch[i] = 'q';
        sj.emplace(j[i], i);
        sq.emplace(q[i], i);
        sk.emplace(k[i], i);
      } else if (sk.upper_bound({k[i], n}) != sk.end()) {
        dp[i] = true;
        p[i] = sk.upper_bound({k[i], n})->second;
        ch[i] = 'k';
        sj.emplace(j[i], i);
        sq.emplace(q[i], i);
        sk.emplace(k[i], i);
      } else if (sj.upper_bound({j[i], n}) != sj.end()) {
        dp[i] = true;
        p[i] = sj.upper_bound({j[i], n})->second;
        ch[i] = 'j';
        sj.emplace(j[i], i);
        sq.emplace(q[i], i);
        sk.emplace(k[i], i);
      }
    }
    printf(dp[n] ? "YES\n" : "NO\n");
    if (dp[n]) {
      std::vector<std::pair<char, int>> ans;
      for (int v = n; v != 1; v = p[v]) {
        ans.emplace_back(ch[v], v);
      }
      std::reverse(ans.begin(), ans.end());
      printf("%d\n", int(ans.size()));
      for (auto [u, v]: ans) {
        printf("%c %d\n", u, v);
      }
    }
  }
  return 0;
}
