/**
 *    author:  feev1x
 *    created: 08.12.2024 11:01:07
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 1e3 + 3;

char S[MXSZ];

int main() {
  scanf("%s", S);
  std::string s = S;
  int n = s.size();
  for (int i = 1; i < n; i += 2) {
    printf("%c", s[i]);
  }
  for (int i = n & 1 ? n - 1 : n - 2; i >= 0; i -= 2) {
    printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}
