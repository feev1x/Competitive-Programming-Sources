/**
 *    author:  feev1x
 *    created: 13.11.2024 10:53:08
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::freopen("i.in", "r", stdin);
  std::freopen("i.out", "w", stdout);
  int n; scanf("%d", &n);
  std::vector<int> a(n);
  std::vector<std::vector<int>> mp(n + 1);
  std::map<int, int> val;
  int cn = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (!val[a[i]]) {
      val[a[i]] = cn++;
    }
    a[i] = val[a[i]];
    mp[a[i]].emplace_back(i);
  }
  auto Mod = [](int a, int n) {
    return (a % n + n) % n;
  };
  auto Dis = [&](int fs, int sc) {
    if (fs < sc) {
      std::swap(fs, sc);
    }
    return std::min(fs - sc, n - (fs - sc));
  };
  int i1, i2, dis = -1;
  auto Solve = [&](int fs, int sc) {
    if (dis < Dis(fs, sc)) {
      i1 = fs, i2 = sc;
      dis = Dis(fs, sc);
    }
  };
  for (int i = 0; i < n; ++i) {
    auto it = std::lower_bound(mp[a[i]].begin(), mp[a[i]].end(), Mod(i + n / 2, n));
    if (it == mp[a[i]].end()) {
      it = mp[a[i]].begin();
    }
    auto l = (it == mp[a[i]].begin() ? --mp[a[i]].end() : it - 1);
    auto r = (it + 1 == mp[a[i]].end() ? mp[a[i]].begin() : it + 1);
    Solve(i, *l);
    Solve(i, *r);
    Solve(i, *it);
  }
  assert(dis != -1);
  printf("%d %d\n", ++i1, ++i2);
  return 0;
}
