/**
 *    author:  feev1x
 *    created: 03.12.2024 12:30:38
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 15;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    std::vector<int> ch(26);
    scanf("%s", S);
    std::string s = S;
    int mx = -1, pmx = 0, mn = 1e9, pmn = 0;
    for (int i = 0; i < n; ++i) {
      ch[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      if (ch[i] == 0) continue;
      if (ch[i] < mn) {
        mn = ch[i];
        pmn = i;
      }
      if (ch[i] > mx) {
        mx = ch[i];
        pmx = i;
      }
    }
    if (pmx == pmn) {
      for (int i = 0; i < 26; ++i) {
        if (ch[i] == 0) continue;
        if (ch[i] == mn && pmn != i) {
          pmn = i;
          break;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] - 'a' == pmn) {
        s[i] = char('a' + pmx);
        break;
      }
    }
    printf("%s\n", s.c_str());
  }
  return 0;
}
