/**
 *    author:  feev1x
 *    created: 11.11.2024 09:15:19
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
  char S[n + 1]; scanf("%s", S);
  std::string s = S;
  std::sort(s.begin(), s.end());
  printf("%s\n", s.c_str());
  return 0;
}
