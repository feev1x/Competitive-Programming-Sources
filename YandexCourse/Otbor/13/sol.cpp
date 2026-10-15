#include <bits/stdc++.h>

inline int fr(int a) {
  while (a > 9) a /= 10;
  return a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::map<std::pair<int, int>, int> mp;
  for (int i = 1; i <= n; ++i) mp[{fr(i), i % 10}]++;
  int64_t res = 0;
  for (auto [key, val]: mp) {
    auto rkey = key;
    std::swap(rkey.first, rkey.second);
    int val2 = 0;
    if (mp.count(rkey)) val2 += mp[rkey];
    res += val * 1LL * val2;
  }
  std::cout << res << '\n';
  return 0;
}
