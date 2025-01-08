/**
 *    author:  feev1x
 *    created: idk
**/
#include "bits/stdc++.h"
using namespace std;

int64_t f(int sz) {
  if (sz == 0) return 1;
  return f(sz - 1) * 10;
}

int64_t binpow(int64_t a, int n) {
  if (n == 0) return 1;
  if (n & 1) return a * binpow(a, n - 1);
  int64_t b = binpow(a, n / 2);
  return b * b;
}

string res(int64_t n, int64_t cnt, int sz, int64_t ls, bool ch) {
  if (sz == 0) return "";
  if (ch) {
    int64_t d = 1;
    while (cnt + binpow(10, sz - 1) * d + ls < n) d++;
    string s;
    s += char(d + '0');
    return s + res(n, cnt, sz - 1, ls + (d - 1) * binpow(10, sz - 1), false);
  }
  int64_t d = 0;
  while (cnt + binpow(10, sz - 1) * (d + 1) + ls < n) d++;
  string s;
  s += char(d + '0');
  return s + res(n, cnt, sz - 1, ls + d * binpow(10, sz - 1), false);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n; cin >> n;
  if (n <= 10) {
    cout << n - 1 << '\n';
    return 0;
  }
  int sz = 2;
  int64_t cnt = 10;
  string ans;
  while (true) {
    int64_t ls = cnt;
    cnt += 9 * f((sz + 1) / 2 - 1);
    if (cnt >= n) {
      cnt = ls;
      ans = res(n, cnt, (sz + 1) / 2, 0, true);
      for (int i = sz / 2 - 1; i >= 0; --i) {
        ans += ans[i];
      }
      break;
    }
    sz++;
  }
  cout << ans << '\n';
}

