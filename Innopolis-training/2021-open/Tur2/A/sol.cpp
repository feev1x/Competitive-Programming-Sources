/**
 *    author:  feev1x
 *    created: 20.11.2024 09:03:27
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int SZ = 104;

char S[SZ];

int main() {
  scanf("%s", S);
  std::string s = S;
  int k; scanf("%d", &k);
  char fr = 'z', sc = 'z';
  for (int i = 1; i < s.size(); ++i) {
    char n_fr = std::min(s[i], s[i - 1]), n_sc = std::max(s[i], s[i - 1]);
    if (n_fr < fr) {
      fr = n_fr, sc = n_sc;
    } else if (n_fr == fr && n_sc < sc) {
      sc = n_sc;
    }
  }
  for (int i = 1; i + 1 <= k; i += 2) {
    printf("%c%c", fr, sc);
  }
  if (k & 1) {
    printf("%c", fr);
  }
  printf("\n");
  return 0;
}
