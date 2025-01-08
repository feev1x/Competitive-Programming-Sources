/**
 *    author:  feev1x
 *    created: 16.11.2024 18:12:40
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  char S[101]; scanf("%s", S);
  std::string s = S;
  int cnt = 0;
  std::vector<int> a;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == '|') {
      a.emplace_back(cnt);
      cnt = 0;
    } else {
      cnt++;
    }
  }
  for (auto u: a) {
    printf("%d ", u);
  }
  printf("\n");
  return 0;
}
