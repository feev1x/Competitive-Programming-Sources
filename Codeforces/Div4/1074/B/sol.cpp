#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;
    
    std::vector<int> a(n);
    int mx = 0;
    for (auto &u: a) {
        std::cin >> u;

        mx = std::max(mx, u);
    }

    std::cout << mx * n << '\n';
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
