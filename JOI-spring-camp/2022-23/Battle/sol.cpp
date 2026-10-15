#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 64;
  std::vector<int> p(n);
  for (int i = 0; i < 8; ++i)
    p[n - i - 1] = i * 8 + i;
  for (int i = 0, j = 0; i < n - 8; ++i, ++j) {
    while (j / 8 == j % 8) ++j;
    p[i] = j;
  }
  shuffle(p.begin(), p.begin() + 64 - 8, rng);
  shuffle(p.begin() + 64 - 8, p.end(), rng);
  std::cout << "std::vector<int> p{";
  for (int i = 0; i + 1 < n; ++i) std::cout << p[i] << ", ";
  std::cout << p.back() << "};\n";
  return 0;
}
