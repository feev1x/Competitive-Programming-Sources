/**
 *    author:  feev1x
 *    created: 04.01.2025 11:20:48
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s; std::cin >> s;
  i64 res = 0;
  for (int r = 0; r < s.size(); ++r) {
    int cnt_g = 0, cnt_h = 0;
    for (int l = r; l >= 0; --l) {
      if (s[l] == 'G') {
        cnt_g++;
      } else {
        cnt_h++;
      }
      if ((cnt_g & 1) & (cnt_h & 1)) {
        res--;
        continue;
      }
      std::string str = s.substr(l, r - l + 1);
      std::deque<int> G, H; 
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') {
          G.emplace_back(i);
        } else {
          H.emplace_back(i);
        }
      }
      }
    }
  }
  std::cout << res << '\n';
  return 0;
}
