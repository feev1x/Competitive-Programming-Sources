/**
 *    author:  feev1x
 *    created: 06.03.2025 15:50:16
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1), ans(q + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<std::pair<int, int>>> qq(n + 1);
    for (int i = 1; i <= q; ++i) {
        int r, x; std::cin >> r >> x;

        qq[r].emplace_back(x, i);
    }

    std::vector<int> d(n + 3, INF);

    d[0] = -INF;
    for (int i = 1; i <= n; ++i) {
        int j = std::lower_bound(d.begin(), d.end(), a[i]) - d.begin();

        d[j] = a[i];

        for (auto [x, idx]: qq[i]) {
            ans[idx] = --std::upper_bound(d.begin(), d.end(), x) - d.begin();
        }
    }

    for (int i = 1; i <= q; ++i) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}
