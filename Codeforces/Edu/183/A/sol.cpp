#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::cout << (3 - n % 3) % 3 << '\n';
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
