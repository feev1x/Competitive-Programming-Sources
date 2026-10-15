#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k; std::cin >> n >> k;
  std::vector<int> a(n);
  std::multiset<int> st;
  for (auto &u: a) std::cin >> u;
  int l = 1, r = 1e9, ans = 1e9;
  while (l <= r) {
    int m = l + r >> 1;
    int cnt = 0;
    for (auto u: a) cnt += (u + m - 1) / m - 1;
    if (cnt > k) l = m + 1;
    else r = m - 1, ans = m;
  }
  std::cout << ans << '\n';
  return 0;
}
