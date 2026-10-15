#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &u: a) std::cin >> u;
  std::sort(a.begin(), a.end());
  std::vector<int> val;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      val.emplace_back(a[i]);
      ++i;
    }
  }
  if (val.size() < 2) {
    std::cout << "0\n";
    return 0;
  }
  std::sort(val.begin(), val.end(), std::greater<>());
  std::cout << val[0] * 1LL * val[1] << '\n';
  return 0;
}
