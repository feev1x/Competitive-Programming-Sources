/**
 *    author:  feev1x
 *    created: 30.11.2024 18:01:01
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 102;

char S[MXSZ];

int main() {
  int n, d; scanf("%d%d", &n, &d);
  scanf("%s", S);
  std::string s = S;
  int cnt = std::count(s.begin(), s.end(), '@') - d;
  if (cnt < 0) cnt = 0;
  printf("%d\n", n - cnt);
  return 0;
}
