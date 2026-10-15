#include <bits/stdc++.h>

inline int points(std::string a, std::string b) {
  if (std::abs((int)a.size() - (int)b.size()) > 1) return 0;
  if (a == b) return 10;
  if (a.size() == b.size()) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) if (a[i] != b[i]) cnt++;
    return (cnt == 1) * 9;
  } else {
    int pref = 0, suff = 0;
    for (int i = 0; i < std::min(a.size(), b.size()); ++i) {
      if (a[i] == b[i]) pref++;
      else break;
    }
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    for (int i = 0; i < std::min(a.size(), b.size()); ++i) {
      if (a[i] == b[i]) suff++;
      else break;
    }
    return (pref + suff >= std::min(a.size(), b.size())) * 9;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt, res = 0; std::cin >> tt;
  while (tt--) {
    std::string a, b; std::cin >> a >> b;
    res += points(a, b);
  }
  std::cout << res << '\n';
  return 0;
}
