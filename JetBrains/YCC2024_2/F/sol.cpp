/**
 *    author:  feev1x
 *    created: 29.10.2024 09:25:56
**/
#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "/debug.h"
#else
#define debug(...)
#define debugArr(...)
#endif

#define int __int128_t
#define int64_t __int128_t

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = read();
  vector<int> a(n);
  for (auto &u: a) u = read();
  map<int, int> mp;
  int64_t res = 0;
  __int128_t sum = 0, cnt = 0;
  for (int i = n - 1; i >= 0; --i) {
    mp[a[i]]++;
    sum += a[i];
    cnt++;
    __int128_t exc = (a[i] - 1) * mp[a[i] - 1] + (a[i] + 1) * mp[a[i] + 1] + a[i] * mp[a[i]];
    __int128_t c = mp[a[i] - 1] + mp[a[i] + 1] + mp[a[i]];
    assert(cnt >= c);
    res += ((sum - exc) - (cnt - c) * a[i]);
  }
  print(res);
  return 0;
}
