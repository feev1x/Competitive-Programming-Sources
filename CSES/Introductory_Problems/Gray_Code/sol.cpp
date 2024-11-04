/**
 *    author:  feev1x
 *    created: 04.11.2024 21:36:22
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
  int n; scanf("%d", &n);
  vector<bool> used((1 << n));
  int nw = 0;
  auto PrintBin = [&]() {
    string res;
    int num = nw;
    while (res.size() < n) {
      res += (num & 1) + '0';
      num >>= 1;
    }
    reverse(res.begin(), res.end());
    printf("%s\n", res.c_str());
  };
  used[0] = true;
  PrintBin();
  while (true) {
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (!used[nw ^ (1 << i)]) {
        flag = true;
        nw ^= (1 << i);
        break;
      }
    }
    if (!flag) {
      break;
    }
    used[nw] = true;
    PrintBin();
  }
  return 0;
}
