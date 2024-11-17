/**
 *    author:  feev1x
 *    created: 16.11.2024 18:11:16
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  char S[7]; scanf("%s", S);
  std::string s = S;
  int c1 = std::count(s.begin(), s.end(), '1');
  int c2 = std::count(s.begin(), s.end(), '2');
  int c3 = std::count(s.begin(), s.end(), '3');
  if (c1 == 1 && c2 == 2 && c3 == 3) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
