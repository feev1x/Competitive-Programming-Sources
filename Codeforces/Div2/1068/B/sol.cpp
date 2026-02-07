#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n), b(n);
    for (auto &u: a) {
        std::cin >> u;
    }
    
    for (auto &u: b) {
        std::cin >> u;
    }

    int64_t mx = 0, mn = 0;
    for (int i = 0; i < n; ++i) {
        int64_t new_mx, new_mn;

        new_mx = std::max(mx - a[i], b[i] - mn);
        new_mn = std::min(mn - a[i], b[i] - mx);

        mx = new_mx;
        mn = new_mn;
    }

    std::cout << mx << '\n';
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
