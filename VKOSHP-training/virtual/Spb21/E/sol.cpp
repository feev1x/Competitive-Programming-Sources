/**
 *    author:  feev1x
 *    created: 14.11.2024 17:27:24
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  int n; scanf("%d", &n);
  std::vector<i64> s(n + 1), v(n + 1);
  for (i64 i = 1; i <= n; ++i) {
    scanf("%lld%lld", &s[i], &v[i]);
  }
  if (n <= 2) {
    printf("%d\n", n);
    return 0;
  }
  std::map<std::pair<i64, i64>, std::set<i64>> any;
  std::map<std::pair<std::pair<i64, i64>, std::pair<i64, i64>>, std::set<i64>> mp;
  auto Small = [&](i64 &du, i64 &dd) {
    while (std::gcd(du, dd) > 1) {
      i64 gc = std::gcd(du, dd);
      du /= gc;
      dd /= gc;
    }
  };
  auto Fun = [&](i64 i, i64 j, i64 k) {
    if (v[k] == v[j] && v[j] == v[i]) {
      i64 du = i - j, du1 = j - k;
      i64 dd = s[i] - s[j], dd1 = s[j] - s[k];
      Small(du, dd);
      Small(du1, dd1);
      std::pair<i64, i64> sl = {du, dd}, sl1 = {du1, dd1};
      if (sl == sl1) {
        any[sl].emplace(i);
        any[sl].emplace(j);
        any[sl].emplace(k);
      }
      return true;
    }
    i64 y1 = i - j, y2 = j - k, s1 = s[i] - s[j], s2 = s[j] - s[k], v1 = v[i] + v[j], v2 = v[j] + v[k];
    if (y2 * v1 == y1 * v2) {
      return false;
    }
    i64 dut = y1 * s2 - y2 * s1, ddt = y2 * v1 - y1 * v2;
    Small(dut, ddt);
    std::pair<i64, i64> t = {dut, ddt};
    i64 du = i - j, dd = s1 * ddt + dut * v1;
    Small(du, dd);
    mp[{t, {du, dd}}].emplace(i);
    mp[{t, {du, dd}}].emplace(j);
    mp[{t, {du, dd}}].emplace(k);
    return true;
  };
  for (i64 k = 1; k <= n; ++k) {
    for (i64 j = k + 1; j <= n; ++j) {
      for (i64 i = j + 1; i <= n; ++i) {
        assert(Fun(i, j, k) || Fun(i, k, j) || Fun(j, i, k) || Fun(j, k, i) || Fun(k, i, j) || Fun(k, j, i));
      }
    }
  }
  int res = 2;
  for (auto [key, val]: mp) {
    auto [t, sl] = key;
    std::set<i64> ans = val;
    for (auto u: any[sl]) {
      ans.emplace(u);
    }
    res = std::max(res, int(ans.size()));
  }
  printf("%d\n", res);
  return 0;
}
