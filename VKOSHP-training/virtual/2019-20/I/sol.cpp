/**
 *    author:  feev1x
 *    created: 09.12.2024 09:09:30
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 30;

char S[MXSZ];

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", S);
    std::string s = S;
    int a = 0, b = -1, c = -1;
    bool flag = false;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '.') {
        flag = true;
      }
      if (s[j] == '/' || s[j] == '.') {
        if (b == -1) {
          b = 0;
        } else {
          c = 0;
        }
        continue;
      }
      if (b == -1) {
        a *= 10;
        a += s[j] - '0';
      } else if (c == -1) {
        b *= 10;
        b += s[j] - '0';
      } else {
        c *= 10;
        c += s[j] - '0';
      }
    }
    if (flag) {
      printf("%d%d.%d%d.%d%d%d%d %d%d/%d%d/%d%d%d%d\n", a / 10, a % 10, b / 10, b % 10, c / 1000, c / 100 % 10, c / 10 % 10, c % 10, b / 10, b % 10, a / 10, a % 10, c / 1000, c / 100 % 10, c / 10 % 10, c % 10);
    } else {
      printf("%d%d.%d%d.%d%d%d%d %d%d/%d%d/%d%d%d%d\n", b / 10, b % 10, a / 10, a % 10, c / 1000, c / 100 % 10, c / 10 % 10, c % 10, a / 10, a % 10, b / 10, b % 10, c / 1000, c / 100 % 10, c / 10 % 10, c % 10);
    }
  }
  return 0;
}
