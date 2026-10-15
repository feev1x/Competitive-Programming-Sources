#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> p(n);
    for (auto &u: p) {
        std::cin >> u;

        if (u == n) {
            std::swap(u, p.front());
        }
    }

    for (auto u: p) {
        std::cout << u << ' ';
    }

    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
