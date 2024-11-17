/**
 *    author:  feev1x
 *    created: 15.11.2024 09:25:39
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int mxN = 1e6 + 5;

int main() {
  char S[mxN]; scanf("%s", S);
  std::string s = S;
  int cnt = std::count(s.begin(), s.end(), 'A');
  int res = 0;
  for (int i = 1; ; ++i) {
    if (cnt - i < 0) {
      break;
    }
    cnt -= i;
    res++;
  }
  printf("%d\n", res);
  return 0;
}
