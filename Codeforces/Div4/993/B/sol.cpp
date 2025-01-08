/**
 *    author:  feev1x
 *    created: 15.12.2024 20:37:40
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

constexpr int MXSZ = 105;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    scanf("%s", S);
    std::string s = S;
    std::reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'p') {
        s[i] = 'q';
      } else if (s[i] == 'q') {
        s[i] = 'p';
      }
    }
    printf("%s\n", s.c_str());
  }
  return 0;
}
