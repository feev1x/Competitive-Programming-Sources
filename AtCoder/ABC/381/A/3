/**
 *    author:  feev1x
 *    created: 05.12.2024 08:54:04
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 102;

char S[MXSZ];

int main() {
  int n; scanf("%d", &n);
  scanf("%s", S);
  std::string s = S, t;
  for (int i = 1; i <= n; ++i) {
    if (i == (n + 1) / 2) {
      t += "/";
    } else if (i < (n + 1) / 2) {
      t += "1";
    } else {
      t += "2";
    }
  }
  printf(t == s && n % 2 == 1 ? "Yes\n" : "No\n");
  return 0;
}
