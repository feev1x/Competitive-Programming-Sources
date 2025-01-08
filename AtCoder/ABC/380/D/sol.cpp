/**
 *    author:  feev1x
 *    created: 16.11.2024 18:18:23
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 2e5 + 5;

int main() {
  char S[MXSZ]; scanf("%s", S);
  std::string s = S;
  int q; scanf("%d", &q);
  while (q--) {
    i64 k; scanf("%lld", &k); k--;
    int i = k % i64(s.size());
    bool flag = false;
    k /= i64(s.size());
    for (i64 j = 60; j >= 0; --j) {
      if (1ll << j <= k) {
        flag = !flag;
        k -= 1ll << j;
      }
    }
    if (flag) {
      if (islower(s[i])) {
        s[i] = toupper(s[i]);
        printf("%c ", s[i]);
        s[i] = tolower(s[i]);
      } else {
        s[i] = tolower(s[i]);
        printf("%c ", s[i]);
        s[i] = toupper(s[i]);
      }
    } else {
      printf("%c ", s[i]);
    }
  }
  return 0;
}
