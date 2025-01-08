/**
 *    author:  feev1x
 *    created: 09.11.2024 18:02:16
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
  int n, k; scanf("%d%d", &n, &k);
  char *S; scanf("%ms", &S);
  string s = S;
  free(S);
  int cnt = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'O') {
      cnt++;
    } else {
      res += cnt / k;
      cnt = 0;
    }
  }
  res += cnt / k;
  printf("%d\n", res);
  return 0;
}
