/**
 *    author:  feev1x
 *    created: 30.11.2024 20:40:28
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 2e5 + 5;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    scanf("%s", S);
    std::string s = S;
    int sz = 0, res = 0;
    std::vector<int> a;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        sz++;
      } else {
        sz = 0;
      }
      if (sz == m) {
        res++;
        sz = 0;
        i += k - 1;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
