#include <bits/stdc++.h>

inline void solve() {
    int n, mx = 0, res = 0; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
        if (u >= mx) mx = u, res++;
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
