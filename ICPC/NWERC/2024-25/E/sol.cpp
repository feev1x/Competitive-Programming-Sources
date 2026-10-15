#include <bits/stdc++.h>

constexpr int N = 61;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; int64_t k; std::cin >> n >> k;
  std::string s; std::cin >> s;
  std::vector<std::array<int, N>> nx(n);
  int nw = 0;
  if (n & 1) {
    for (int i = 0; i < n; i += 2) nx[nw++][0] = i;
    for (int i = 1; i < n; i += 2) nx[nw++][0] = i;
  } else {
    for (int i = 0; i < n; i += 2) nx[nw++][0] = i;
    for (int i = 0; i < n; i += 2) nx[nw++][0] = i;
  }
  for (int j = 1; j < N; ++j) for (int i = 0; i < n; ++i) nx[i][j] = nx[nx[i][j - 1]][j - 1];
  std::string res(n, '.');
  for (int i = 0; i < n; ++i) {
    int nw = i;
    for (int j = 0; j < N; ++j) if (k >> j & 1) nw = nx[nw][j];
    res[i] = s[nw];
  }
  std::cout << res << '\n';
  return 0;
}
