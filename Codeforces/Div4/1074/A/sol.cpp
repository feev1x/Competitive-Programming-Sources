#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cout << i * i << " \n"[i == n];
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
