#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    if (k > n * 2 - 1 || k < n) {
        std::cout << "NO\n";
        return;
    }

    k -= n;

    std::cout << "YES\n";
    if (k == 0) {
        for (int i = 1; i <= n; ++i) {
            std::cout << i << ' ' << i << ' ';
        }

        std::cout << '\n';
        return;
    }

    std::cout << "1 2 ";

    int ls = 1, nw = 3;
    k--;

    while (k--) {
        std::cout << nw++ << ' ' << ls++ << ' ';
    }

    std::cout << ls << ' ' << ls + 1 << ' ';

    while (nw <= n) {
        std::cout << nw << ' ' << nw << ' ';

        nw++;
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
