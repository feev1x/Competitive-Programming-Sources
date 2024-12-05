/**
 *    author:  feev1x
 *    created: 02.12.2024 19:31:04
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 15;

char S[MXSZ];

int main() {
  std::freopen("citystate.in", "r", stdin);
  std::freopen("citystate.out", "w", stdout);
  int n; scanf("%d", &n);
  std::map<std::string, std::map<std::string, i64>> cnt;
  i64 res = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", S);
    std::string s;
    s += S[0];
    s += S[1];
    scanf("%s", S);
    std::string s1 = S;
    cnt[s][s1]++;
  }
  for (auto [key, val]: cnt) {
    for (auto [ke, va]: val) {
      if (ke > key || !va) {
        continue;
      }
      if (ke == key) {
      } else {
        res += cnt[key][ke] * cnt[ke][key];
      }
    }
  }
  printf("%lld\n", res);
  return 0;
}
