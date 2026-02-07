#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    int res = 0;
    while (n > 2) {
        res += n / 3;

        n = n / 3 + n % 3;
    }

    std::cout << res << '\n';
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
