#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q; std::cin >> n >> q;
  std::string s; std::cin >> s;
  int add = 0;
  while (q--) {
    int type, i; std::cin >> type >> i;
    if (type == 2) std::cout << s[(i + add - 1) % n] << '\n';
    else add = ((add - i) % n + n) % n;
  }
  return 0;
}
