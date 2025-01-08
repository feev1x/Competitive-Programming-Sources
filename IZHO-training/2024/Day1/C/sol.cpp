/**
 *    author:  feev1x
 *    created: 02.01.2025 18:46:22
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) {
    int n, d; std::cin >> n >> d;
    std::vector<int> a(n), b(n);
    for (auto &u: a) {
      std::cin >> u;
    }
    for (auto &u: b) {
      std::cin >> u;
    }
    if (d == 1) {
      bool flag = true;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (b[i] > a[i]) {
          flag = false;
        }
        if (b[i] > 0) {
          cnt++;
        }
      }
      std::cout << (flag ? cnt : -1) << '\n';
      continue;
    } else if (n <= 18) {
      int res = -1;
      for (int mask = 0; mask < (1 << n); ++mask) {
        std::deque<std::pair<int, int>> dq;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
          if (b[i]) {
            dq.emplace_back(b[i], i);
          }
          if (dq.size() && i - dq.front().second == d) {
            flag = false;
            break;
          }
          if (mask >> i & 1) {
            int cnt = a[i];
            while (dq.size() && dq.front().first <= cnt) {
              cnt -= dq.front().first;
              dq.pop_front();
            }
            if (dq.size()) {
              dq.front().first -= cnt;
            }
          }
        }
        if (dq.size()) {
          flag = false;
        }
        int cnt = __builtin_popcount(mask);
        if (flag && (res == -1 || res > cnt)) {
          res = cnt;
        }
      }
      std::cout << res << '\n';
    } else {
      {
        std::deque<std::pair<int, int>> dq;
        bool flag = true;
        for (int i = 0; i < n; ++i) {
          if (b[i]) {
            dq.emplace_back(b[i], i);
          }
          if (dq.size() && i - dq.front().second == d) {
            flag = false;
            break;
          }
          int cnt = a[i];
          while (dq.size() && dq.front().first <= cnt) {
            cnt -= dq.front().first;
            dq.pop_front();
          }
          if (dq.size()) {
            dq.front().first -= cnt;
          }
        }
        if (dq.size()) {
          flag = false;
        }
        if (flag == false) {
          std::cout << -1 << '\n';
          continue;
        }
      }
      std::deque<int> dq;
      int l = 0, cnt = 0;
      for (int i = 0; i < n; ++i) {
        while (b[i] - a[l] > 0) {
          b[i] -= a[l++];
          cnt++;
        }
        if (b[i]) {
          int mn = 1;
          while (a[std::min(i + d - mn, n - mn)] < b[i]) {
            int temp = b[i];
            b[i] -= a[std::min(i + d - mn, n - mn)];
            a[std::min(i + d - mn, n - mn)] -= temp;
            cnt++;
            mn++;
          }
          a[std::min(i + d - mn, n - mn)] = 0;
          cnt++;
        }
      }
      std::cout << cnt << '\n';
    }
  }
  return 0;
}
