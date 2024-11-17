/**
 *    author:  feev1x
 *    created: 16.11.2024 12:54:22
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  char S[5]; scanf("%s", S);
  std::string s = S;
  while (s.size() < 4) {
    s = '0' + s;
  }
  if (s[0] == s[3] && s[1] == s[2]) {
    printf("1\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
