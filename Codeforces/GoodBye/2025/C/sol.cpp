#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    int64_t ls = 0, res = -1e18, sum = 0, suml = 0;
    std::vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        if (i > 0) {
            suml += std::abs(a[i]);
        }
    }
    
    suml += a.front();

    for (int i = n - 1; i >= 0; --i) {
        if (i > 0) {
            suml -= std::abs(a[i]);
        } else {
            suml -= a.front();
        }

        res = std::max(res, suml + sum);
        sum -= a[i];
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
