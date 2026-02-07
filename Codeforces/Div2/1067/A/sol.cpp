#include <bits/stdc++.h>

inline void solve() {
    int n, y, r; std::cin >> n >> y >> r;

    std::cout << std::min(n, y / 2 + r) << '\n';
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
