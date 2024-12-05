/**
 *    author:  feev1x
 *    created: 28.11.2024 22:25:22
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("bgm.in", "r", stdin);
  std::freopen("bgm.out", "w", stdout);
  int n; scanf("%d", &n);
  std::map<char, std::map<int, i64>> mp;
  for (int i = 0; i < n; ++i) {
    char ch; int u; scanf(" %c %d", &ch, &u);
    mp[ch][u % 7]++;
  }
  i64 res{};
  auto Check = [](std::pair<int, i64> b1, std::pair<int, i64> e1, std::pair<int, i64> s1, std::pair<int, i64> i1, std::pair<int, i64> g1, std::pair<int, i64> o1, std::pair<int, i64> m1) {
    int b{b1.first}, e{e1.first}, s{s1.first}, i{i1.first}, g{g1.first}, o{o1.first}, m{m1.first};
    if ((b + e + s + s + i + e) % 7 == 0 || (g + o + e + s) % 7 == 0 || (m + o + o) % 7 == 0) {
      return true;
    }
    return false;
  };
  for (auto b: mp['B']) {
    for (auto e: mp['E']) {
      for (auto s: mp['S']) {
        for (auto i: mp['I']) {
          for (auto g: mp['G']) {
            for (auto o: mp['O']) {
              for (auto m: mp['M']) {
                if (Check(b, e, s, i, g, o, m)) {
                  res += b.second * e.second * s.second * i.second * g.second * o.second * m.second;
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%lld\n", res);
  return 0;
}
