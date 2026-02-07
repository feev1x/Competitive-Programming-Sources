#include <bits/stdc++.h>

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::cout << (n == 1 || m == 1 || n == 2 && m == 2 ? "NO" : "YES") << '\n';
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
