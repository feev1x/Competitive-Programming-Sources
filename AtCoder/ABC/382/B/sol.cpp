/**
 *    author:  feev1x
 *    created: 30.11.2024 18:03:21
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 102;

char S[MXSZ];

int main() {
  int n, d; scanf("%d%d", &n, &d);
  scanf("%s", S);
  std::string s = S;
  for (int i = n - 1; d && i >= 0; --i) {
    if (s[i] == '@') {
      s[i] = '.';
      d--;
    }
  }
  printf("%s\n", s.c_str());
  return 0;
}
