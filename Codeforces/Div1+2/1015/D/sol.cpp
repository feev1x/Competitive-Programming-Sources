#include <bits/stdc++.h>

inline void solve() {
    int n, m, k; std::cin >> n >> m >> k;

    int x = n / (m + 1);

    for (int i = 0; i < n; ++i) {
        std::cout << i % std::max(x, k) << " \n"[i == n - 1];
    }
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
