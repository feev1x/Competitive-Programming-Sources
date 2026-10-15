#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::stack<int> pnd;
    int k1, k2; std::cin >> k1 >> k2;
    int n = k1 + 1;
    std::vector<std::pair<int, int>> e;
    for (int i = 2; i <= k1 + 1; ++i) e.emplace_back(1, i);
    int cn = k1 != 1;
    for (int i = 2; cn < k2; ++i) {
        e.emplace_back(i, n + 1);
        e.emplace_back(i, n + 2);
        e.emplace_back(n + 1, n + 2);
        n += 2;
        cn++;
    }
    std::cout << n << ' ' << e.size() << '\n';
    for (auto [u, v]: e) std::cout << u << ' ' << v << '\n';
    return 0;
}
