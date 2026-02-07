#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    int xr = 0;
    for (int i = 0; i < k; ++i) {
        int u; std::cin >> u;

        xr ^= u;
    }

    if (xr != n) {
        std::cout << "WRONG\n";
    } else {
        std::cout << "YES\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}
