/**
 *    author:  feev1x
 *    created: 05.11.2024 15:03:59
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
  vector<string> s(8);
  for (auto &u: s) {
    char *S; scanf("%ms", &S);
    u = S;
    free(S);
  }
  function<int(int, map<int, bool>, map<int, bool>, map<int, bool>)> Count = [&](int i, map<int, bool> used, map<int, bool> d1, map<int, bool> d2) {
    if (i == 8) {
      return 1;
    }
    int cnt = 0;
    for (int j = 0; j < 8; ++j) {
      if (used[j] || d1[i + j] || d2[i - j] || s[i][j] == '*') continue;
      used[j] = true;
      d1[i + j] = true;
      d2[i - j] = true;
      cnt += Count(i + 1, used, d1, d2);
      used[j] = false;
      d1[i + j] = false;
      d2[i - j] = false;
    }
    return cnt;
  };
  map<int, bool> sm;
  printf("%d\n", Count(0, sm, sm, sm));
  return 0;
}
