/**
 *    author:  feev1x
 *    created: 17.11.2024 22:26:25
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n; scanf("%d", &n);
    auto Ask = [&](int l, int r) {
      printf("? %d %d\n", l, r);
      fflush(stdout);
      int got; scanf("%d", &got);
      return got;
    };
    auto Report = [&](std::string s) {
      printf("! %s\n", s.c_str());
      fflush(stdout);
    };
    std::string s(n, '1');
    int cnt = 0, pos = -1;
    for (int i = 2; i <= n; ++i) {
      int got = Ask(1, i);
      if (got > 0) {
        int j = i - 1;
        cnt = got;
        pos = i;
        while (got--) {
          s[--j] = '0';
        }
        break;
      }
    }
    if (cnt == 0) {
      Report("IMPOSSIBLE");
      continue;
    }
    for (int i = pos + 1; i <= n; ++i) {
      int got = Ask(1, i);
      if (got > cnt) {
        s[i - 1] = '1';
        cnt = got;
      } else {
        s[i - 1] = '0';
      }
    }
    Report(s);
  }
  return 0;
}
