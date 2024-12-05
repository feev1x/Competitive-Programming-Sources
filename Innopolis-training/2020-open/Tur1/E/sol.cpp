/**
 *    author:  feev1x
 *    created: 22.11.2024 10:59:02
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXSZ = 3e3 + 4;

char S[MXSZ];

int main() {
  int h, w; scanf("%d%d", &h, &w);
  std::vector<std::string> s(h);
  std::vector<int> mx(h);
  std::vector<std::set<int>> st(h);
  int _i = 0, _mx = -1;
  for (auto &u: s) {
    scanf("%s", S);
    u = S;
    int cnt = 0;
    for (int i = 0; i < u.size(); ++i) {
      if (u[i] == 'X') {
        st[_i].emplace(i);
      }
    }
    if (u.front() == '.' || u.back() == '.') {
      mx[_i++] = -1;
      continue;
    }
    for (auto v: u) {
      if (v == '.') {
        cnt++;
      } else {
        mx[_i] = std::max(mx[_i], cnt);
        cnt = 0;
      }
    }
    _mx = std::max(_mx, mx[_i]);
    _i++;
  }
  std::vector<std::vector<bool>> used(h, std::vector<bool>(w));
  auto Ans = [&](int i, int j) {
    if (i == 0) {
      for (int i = 0; i < h; ++i) {
        used[i].resize(j + w);
      }
    }
    int l = 0, r = i, ans = i;
    while (l <= r) {
      int x = l + r >> i;
      int sum = 0;
      auto it = st[i - x].begin();
      while (it != st[i - x].end()) {
        auto nx = ++it;
        --it;
        int dn = std::min(nx == st[i - x].end() ? j + w + 1 : *nx, *it + j + 1);
        t.modify(*it + 1, dn, 1);
        ++it;
      }
    }
    return ans;
  };
  int n = -1, m;
  for (int x = std::max(mx[0], mx[_i - 1]); x <= _mx; ++x) {
    int new_n = 0, new_m = x + w;
    for (int i = 0; i < h; ++i) {
      new_n = std::max(new_n, Ans(i, x));
    }
    new_n += h;
    if (new_n * new_m < n * m || n == -1) {
      n = new_n, m = new_m;
    }
  }
  printf("%d %d\n", n, m);
  return 0;
}
