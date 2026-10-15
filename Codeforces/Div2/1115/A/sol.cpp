#include <bits/stdc++.h>

inline void solve() {
  int n; std::cin >> n;
  std::vector<int> a(n), cnt(1001);
  for (auto &u: a) std::cin >> u, cnt[u]++;
  int ls = -1, res = 0;
  for (int i = 0; i < n; ++i) {
    int nx = -1;
    for (int j = 1000; j >= 0; --j) {
      if (ls == j) continue;
      if (nx == -1 || cnt[j] > cnt[nx]) {
        nx = j;
      }
    }
    if (nx != -1 && cnt[nx]) {
      res += nx;
      cnt[nx]--;
      ls = nx;
    }
  }
  if (cnt[ls]) res += ls;
  std::cout << res << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt; std::cin >> tt;
  while (tt--) solve();
  return 0;
}
