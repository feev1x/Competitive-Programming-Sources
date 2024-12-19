/**
 *    author:  feev1x
 *    created: 10.12.2024 09:42:14
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 2e5 + 5;

char S[MXSZ];

int main() {
  int n; scanf("%d", &n);  
  std::string s, t;
  scanf("%s", S);
  s = S;
  scanf("%s", S);
  t = S;
  int j = n - 1, mx = 0, cnt = 0;
  for (int i = n - 1; i >= 0; --i, --j) {
    while (j >= 0 && s[i] != t[j]) {
      j--;
    }
    if (j < 0) {
      break;
    }
    mx = std::max(mx, ++cnt);
  }
  std::sort(t.begin(), t.end());
  std::sort(s.begin(), s.end());
  if (s == t) {
    printf("%d\n", n - mx);
  } else {
    printf("-1\n");
  }
  return 0;
}
