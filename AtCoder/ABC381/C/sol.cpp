/**
 *    author:  feev1x
 *    created: 05.12.2024 09:01:51
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 2e5 + 5;

char S[MXSZ];

int main() {
  int n; scanf("%d", &n);
  scanf("%s", S);
  std::string s = S;
  int cnt1 = 0, cnt2 = 0, res = 1;
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      if (flag) {
        flag = false;
        cnt1 = 1;
        cnt2 = 0;
      } else {
        cnt1++;
      }
    } else if (s[i] == '/') {
      if (flag) {
        flag = false;
        cnt1 = 0;
        cnt2 = 0;
      } else {
        flag = cnt1;
      }
    } else {
      if (flag) {
        cnt2++;
      } else {
        cnt1 = 0;
        cnt2 = 0;
      }
    }
    if (flag) {
      res = std::max(res, 2 * std::min(cnt1, cnt2) + 1);
    }
  }
  printf("%d\n", res);
  return 0;
}
