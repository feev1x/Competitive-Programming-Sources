/**
 *    author:  feev1x
 *    created: 29.10.2024 20:21:58
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

using ll = long long;

const int N = 1e6 + 5;

signed main() {
  int n;
  char s[N]; scanf("%s%n", s, &n);
  vector<int> adds, adde;
  int ind = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      adds.emplace_back(ind++);
    } else {
      adde.emplace_back(ind++);
    }
  }
  int i = adds.size(), j = adde.size();
  i--, j--;
  int sz = 0;
  while (i >= 0 && j >= 0) {
    if (adds[i] < adde[j]) {
      sz += 2; 
      i--, j--;
    } else {
      i--;
    }
    debug(adds, adde, i, j, sz);
  }
  printf("%d\n", sz);
  return 0;
}
