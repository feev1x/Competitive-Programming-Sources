#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
    int n, m, k; std::cin >> n >> m >> k;

    if (k - 1 > n - k) {
        k = n - k + 1;
    }

    int res = std::min(n - k, (m + 1) / 2) + 1;
    for (int i = 1; k - i >= 1; ++i) {
        int lc = i;
        int nd = 2 * lc - 1;

        int mx = std::min((m - nd + i) / 2, n - k);

        if (mx < i) {
            continue;
        }

        res = std::max(res, lc + mx + 1);
    }

    std::cout << res << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
