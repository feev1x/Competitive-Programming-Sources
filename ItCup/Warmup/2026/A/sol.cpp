#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, a; std::cin >> n >> m >> a; std::swap(n, m);
    std::vector<std::string> s(n);
    a = (a % 360 + 360) % 360;
    for (auto &u: s) std::cin >> u;
    if (a == 0) std::cout << m << ' ' << n << '\n';
    if (a == 90) std::cout << n << ' ' << m << '\n';
    if (a == 180) std::cout << m << ' ' << n << '\n';
    if (a == 270) std::cout << n << ' ' << m << '\n';
    if (a == 0) for (int i = 0; i < n; ++i) std::cout << s[i] << '\n';
    if (a == 90) for (int j = 0; j < m; ++j) { for (int i = n - 1; i >= 0; --i) { std::cout << s[i][j]; } std::cout << '\n'; }
    if (a == 180) for (int i = n - 1; i >= 0; --i) { for (int j = m - 1; j >= 0; --j) { std::cout << s[i][j]; } std::cout << '\n'; }
    if (a == 270) for (int j = m - 1; j >= 0; --j) { for (int i = 0; i < n; ++i) { std::cout << s[i][j]; } std::cout << '\n'; }
    return 0;
}
