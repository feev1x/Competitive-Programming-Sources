/**
 *    author:  feev1x
 *    created: 03.12.2024 15:51:20
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 35;

char S[MXSZ];

int main() {
  std::freopen("cowcode.in", "r", stdin);
  std::freopen("cowcode.out", "w", stdout);
  scanf("%s", S);
  std::string s = S;
  i64 n; scanf("%lld", &n); n--;
  i64 sz = s.size();
  i64 j = n;
  for (int i = 60; i >= 0; --i) {
    if (j >= (1llu << i) * sz) {
      j--;
      j %= (1llu << i) * sz;
    }
  }
  printf("%c\n", s[j]);
  return 0;
}
