#include <bits/stdc++.h>

inline void solve() {
  int n; std::cin >> n;
  std::vector<std::pair<std::string, std::string>> s(n);
  std::map<std::string, int> cnt1, cnt2;
  for (int i = 0; i < n; ++i) std::cin >> s[i].first >> s[i].second, cnt1[s[i].first]++, cnt2[s[i].second]++;
  for (int i = 1; i < n; ++i) {
    cnt1[s[i - 1].first]--, cnt2[s[i - 1].second]--;
    if (s[i].first != s[i - 1].first && s[i].second != s[i - 1].second)
      if (cnt1[s[i - 1].first] || cnt2[s[i - 1].second]) return std::cout << "No\n", void();
  }
  std::cout << "Yes\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
