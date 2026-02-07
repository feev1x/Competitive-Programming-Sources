#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int64_t> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end());

    int64_t gcd = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] % a[0] == 0) {
            gcd = std::gcd(a[i], gcd);
        }
    }

    std::cout << (gcd == a[0] ? "Yes" : "No") << '\n';
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
