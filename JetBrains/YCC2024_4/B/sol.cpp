/**
 *    author:  feev1x
 *    created: 29.10.2024 19:52:00
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

signed main() {
  vector<int> cnt(5);
  for (int i = 1; i <= 4; ++i) {
    scanf("%lld", &cnt[i]);
  }
  if (cnt[1] != cnt[4] || cnt[3] > 0 && cnt[1] == 0) {
    printf("0");
  } else {
    printf("1");
  }
  printf("\n");
  return 0;
}
