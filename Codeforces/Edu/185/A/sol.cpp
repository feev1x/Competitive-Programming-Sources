#include <bits/stdc++.h>

inline void solve() {
    int64_t n; std::cin >> n;

    if (n == 1) {
        std::cout << 1 << '\n';
        return;
    }

    if (n == 2) {
        std::cout << 9 << '\n';
        return;
    }

    std::cout << std::max(n * n * 3 - 3 + n * n - n - 1, n * (n - 1) * 3 - 3 + n * n - 2 * n - 1 + n * n - 1) << '\n';
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
