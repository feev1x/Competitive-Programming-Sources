#include <bits/stdc++.h>

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::vector<int> a(m);
    for (auto &u: a) {
        std::cin >> u;
    }

    if (a[m - 1] != m + a[0] - 1) {
        std::cout << "1\n";
    } else {
        std::cout << n - a[m - 1] + 1 << '\n';
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
