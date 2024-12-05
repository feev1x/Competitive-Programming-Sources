/**
 *    author:  feev1x
 *    created: 19.11.2024 11:10:07
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7, N = 1e6 + 1;

int main() {
  std::vector<int> a(N), p(N), cnt(N);
  a[1] = 1;
  cnt[1] = 1;
  a[2] = 2;
  cnt[2] = 1;
  int nw = 2;
  p[1] = a[1], p[2] = p[1] + a[2];
  for (int i = 3; i < N; ++i) {
    assert(nw != i); 
    if (cnt[nw] == a[nw]) {
      nw++;
    }
    a[i] = nw;
    p[i] = (p[i - 1] + a[i]) % MOD;
    cnt[nw]++;
  }
  int tt; scanf("%d", &tt);
  while (tt--) {
    int l, r; scanf("%d%d", &l, &r);
    printf("%d\n", (((p[r] - p[l - 1]) % MOD) + MOD) % MOD);
  }
  return 0;
}
