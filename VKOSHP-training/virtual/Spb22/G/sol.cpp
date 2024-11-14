/**
 *    author:  feev1x
 *    created: 23.10.2024 11:58:10
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

int64_t binpow(int64_t a, int64_t n) {
  if (n <= 0) return 1ll;
  if (n & 1) return a * binpow(a, n - 1);
  int64_t b = binpow(a, n >> 1);
  return b * b;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto Size = [&](int64_t l, int64_t r) {
    int64_t sz = to_string(l).size();
    int64_t rsz = to_string(r).size();
    if (sz == rsz) {
      return (r - l + 1) * sz;
    }
    int64_t cnt = (binpow(10ll, sz) - l) * sz;
    sz++;
    while (sz < rsz) {
      cnt += (binpow(10ll, sz) - binpow(10ll, sz - 1)) * sz;
      sz++;
    }
    cnt += (r - binpow(10ll, rsz - 1) + 1) * rsz;
    return cnt;
  };
  int64_t s; cin >> s;
  int64_t resl = -1, resr = -1;
  for (int64_t i = 0; i <= 1e5; ++i) {
    int64_t l = i, r = 1e18, j = i;
    while (l <= r) {
      int64_t m = l + r >> 1;
      if (Size(i, m) > s) {
        r = m - 1;
      } else {
        l = m + 1;
        j = m;
      }
    }
    if (Size(i, j) == s) {
      resl = i;
      resr = j;
      break;
    }
  }
  if (resl != -1) {
    cout << (resr - resl + 1) << '\n' << resl << ' ' << resr << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
