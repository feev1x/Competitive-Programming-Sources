#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::string s, t; std::cin >> s >> t;
  std::string ss = t + s;
  std::vector<int> z(ss.size());
  int l = 0, r = 0;
  for (int i = 1; i < ss.size(); ++i) {
    if (r > i) z[i] = std::min(z[i - l], r - i);
    while (i + 1 < ss.size() && ss[z[i]] == ss[i + z[i]]) z[i]++;
    if (i + z[i] > r) r = i + z[i], l = i;
  }
  std::vector<int> p(ss.size() + 1);
  for (int i = 0; i < ss.size(); ++i) p[i + 1] = p[i] + (z[i] >= t.size());
  while (n--) {
    int l, r; std::cin >> l >> r; --l, --r;
    int x = r - t.size() + 1;
    int res = 0;
    if (l <= x) res = p[x + 1 + t.size()] - p[l + t.size()];
    std::cout << (res ? "Yes" : "No") << '\n';
  }
  return 0;
}
