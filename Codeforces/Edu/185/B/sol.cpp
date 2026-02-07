#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    int64_t sum = 0, cnt0 = 0;
    std::vector<int> b(n);
    for (auto &u: b) {
        std::cin >> u, sum += u, cnt0 += !u;
    }

    if (sum - (n - cnt0) < n - 1) {
        std::cout << (n - cnt0) - ((n - 1) - (sum - (n - cnt0))) << '\n';
    } else {
        std::cout << (n - cnt0) << '\n';
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
