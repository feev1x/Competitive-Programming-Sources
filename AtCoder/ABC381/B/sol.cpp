/**
 *    author:  feev1x
 *    created: 05.12.2024 08:57:37
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 105;

char S[MXSZ];

int main() {
  scanf("%s", S);
  std::string s = S;
  std::map<char, int> mp;
  int n = s.size();
  if (n & 1) {
    printf("No\n");
    exit(0);
  }
  for (int i = 0; i < n; ++i) {
    mp[s[i]]++;
  }
  for (int i = 0; i < n / 2; ++i) {
    if (s[i << 1] != s[i << 1 | 1]) {
      printf("No\n");
      exit(0);
    }
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    if (mp[c] != 0 && mp[c] != 2) {
      printf("No\n");
      exit(0);
    }
  }
  printf("Yes\n");
  return 0;
}
