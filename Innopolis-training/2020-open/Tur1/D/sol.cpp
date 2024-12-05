/**
 *    author:  feev1x
 *    created: 22.11.2024 10:40:24
**/
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned i64;

int main() {
  u64 k, s; scanf("%llu%llu", &k, &s);
  std::vector<u64> ans;
  u64 j = 0, num = 0;
  while (k / (1ll << j) + (k % (1ll << j)) >= 100) {
    j++;
    num += (1ll << s - j);
  }
  assert(j <= s);
  u64 cn = k / (1ll << j);
  while (cn * ((1ll << j) - 1) + (1ll << j) - 1 > k) {
    cn--;
  }
  for (u64 i = 0; i < cn; ++i) {
    ans.emplace_back(i + num);
  }
  for (u64 i = 0; i < (1ll << j) - 1; ++i) {
    ans.emplace_back((i << s - j) + (1ll << s - j) - 1);
  }
  u64 ost = k % (1ll << j);
  u64 sz = 0;
  for (i64 i = sz; i >= 0; --i) {
    if (ost >> i & 1) {
      sz = i;
      break;
    }
  }
  for (u64 i = 1; i < ost; ++i) {
    ans.emplace_back(i << s - j - sz);
  }
  std::sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (auto u: ans) {
    printf("%llu ", u);
  }
  printf("\n");
  return 0;
}
