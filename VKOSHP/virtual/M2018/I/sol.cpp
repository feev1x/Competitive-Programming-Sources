/**
 *    author:  feev1x
 *    created: 11.11.2024 10:35:25
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
  int n; scanf("%d", &n);
  int l = 0, r = 1e9;
  int cnt = 0;
  char S[100];
  auto Ask = [&](int x, int y) {
    printf("%d %d\n", x, y);
    fflush(stdout);
    scanf("%s", S);
    std::string s = S;
    return s;
  };
  auto Ln = [&](int x1, int y1, int x2, int y2) {
    printf("%d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
  };
  std::map<int, bool> mp;
  bool flag = false;
  int bl = -1, wh = -1, num;
  int md, fst = -1;
  for (int i = 0; i < n; ++i) {
    int m = l + r >> 1;
    if (mp[m] || flag) {
      flag = true;
      num = i;
      break;
    }
    mp[m] = true;
    if (Ask(m, 1) == "white") {
      wh = m;
      r = m;
    } else {
      if (fst == -1) fst = m;
      bl = m;
      l = m;
    }
  }
  printf("%
  return 0;
}
