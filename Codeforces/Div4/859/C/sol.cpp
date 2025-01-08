/**
 *    author:  feev1x
 *    created: 15.12.2024 01:08:41
**/
#include <bits/stdc++.h>

using i64 = long long;

const std::string FL = "";

FILE *IN = std::fopen((FL + ".in").c_str(), "r");
FILE *OUT = std::fopen((FL + ".out").c_str(), "w");

constexpr int MXSZ = 2e5 + 5;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    scanf("%s", S);
    std::string s = S;
    std::array<std::array<bool, 26>, 2> a{};
    for (int i = 0; i < n; ++i) {
      a[i % 2][s[i] - 'a'] = true;
    }
    bool flag = true;
    for (int i = 0; i < 26; ++i) {
      if (a[0][i] & a[1][i]) {
        flag = false;
        break;
      }
    }
    printf(flag ? "YES\n" : "NO\n");
  }
  return 0;
}
