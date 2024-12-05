/**
 *    author:  feev1x
 *    created: 21.11.2024 13:30:32
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int SZ = 205;

char S[SZ];

int main() {
  scanf("%s", S);
  std::string s = S, s1;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      s1 += ' ';
    }
    s1 += s[i];
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      s1 += ' ';
    }
  }
  if (s1.back() == ' ') s1.pop_back();
  printf("%s\n", s1.c_str());
  return 0;
}
