/**
 *    author:  feev1x
 *    created: 02.12.2024 21:01:51
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 2e5 + 5, INF = 1e9;

char S[MXSZ];

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    int n, k; scanf("%d%d", &n, &k);
    scanf("%s", S);
    std::string s = S;
    std::vector<int> dif(n + 1);
    for (int i = n - 1; i > 0; --i) {
      dif[i] = dif[i + 1] + (s[i] == '0' ? -1 : 1);
    }
    dif[0] = dif[n] = -INF;
    std::sort(dif.begin(), dif.end(), std::greater<>());
    i64 sum = 0, res = 1;
    for (auto u: dif) {
      sum += u;
      res++;
      if (sum >= k) {
        printf("%d\n", res);
        goto end;
      }
    }
    printf("-1\n");
end:
    continue;
  }
  return 0;
}

