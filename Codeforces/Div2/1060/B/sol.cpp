#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    int mx = 0;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        mx = std::max(mx, a[i]);

        if (i % 2 == 0) {
            a[i] = mx;
        }
    }

    int64_t res = 0;
    for (int i = 1; i <= n; i += 2) {
        int diff = std::max({0, i > 1 ? a[i] - a[i - 1] + 1 : 0, i < n ? a[i] - a[i + 1] + 1 : 0});

        res += diff;
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
