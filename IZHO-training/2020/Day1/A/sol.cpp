/**
 *    author:  feev1x
 *    created: 23.12.2024 09:09:17
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> a(n), b(n), cnt_a(n + 1), cnt_b(n + 1);
  int mx = 0;
  for (auto &u: a) {
    std::cin >> u;
    cnt_a[u]++;
    mx = std::max(mx, u);
  }
  for (auto &u: b) {
    std::cin >> u;
    cnt_b[u]++;
    mx = std::max(mx, u);
  }
  int place = 0, need = 0;
  int ca = 0, cb = 0;
  i64 cnt = 0;
  for (int i = 1; i < mx; ++i) {
    if (cnt_a[i] > need) {
      cnt_a[i] -= need;
      cnt_b[i] += need;
      need = 0;
    } else {
      need -= cnt_a[i];
      cnt_b[i] += cnt_a[i];
      cnt_a[i] = 0;
    }
    if (cnt_b[i] > place) {
      cnt_b[i] -= place;
      place = 0;
    } else {
      place -= cnt_b[i];
      cnt_b[i] = 0;
    }
    if (cnt_a[i] < cnt_b[i]) {
      need += (cnt_b[i] - cnt_a[i] + 1) / 2;
      cnt += (cnt_b[i] - cnt_a[i] + 1) / 2;
      if ((cnt_b[i] - cnt_a[i]) & 1) {
        place++;
      }
    } else {
      place += cnt_a[i] - cnt_b[i];
    }
  }
  std::cout << cnt << '\n';
  return 0;
}
