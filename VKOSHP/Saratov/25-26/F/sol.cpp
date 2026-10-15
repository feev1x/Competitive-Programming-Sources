#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first;
    a[i].second = i;
  }
  std::sort(a.begin(), a.end());
  std::vector<int> ans(n);
  int c = 0, cc = 1;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i].first == a[i + 1].first) cc++;
    else c += cc, cc = 1;
    ans[a[i].second] = c;
  }
  for (int i = 0; i < n; ++i) std::cout << ans[i] << " \n"[i == n - 1];
  return 0;
}
