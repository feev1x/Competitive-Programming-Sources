#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    if (n % 2 == 0) {
        std::cout << "-1\n";
        return;
    }

    std::cout << n << ' ';
    for (int i = 1; i < n; ++i) {
        std::cout << i << " \n"[i == n - 1];
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
