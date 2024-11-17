/**
 *    author:  feev1x
 *    created: 16.11.2024 18:14:21
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n, k; scanf("%d%d", &n, &k);
  char S[n + 1]; scanf("%s", S);
  std::string s = S;
  int cnt = 0, ind = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1' && (!i || s[i - 1] == '0')) {
      cnt++;
      if (cnt == k) {
        for (int j = i; j < n; ++j) {
          if (s[j] == '0') {
            break;
          }
          s[ind++] = '1';
          s[j] = '0';
        }
        break;
      }
    } else {
      if (s[i] == '0' && cnt == k - 1 && ind == -1) {
        ind = i;
      }
    }
  }
  printf("%s\n", s.c_str());
  return 0;
}
