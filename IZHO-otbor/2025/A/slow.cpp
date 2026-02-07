/**
 *    author:  feev1x
 *    created: 03.11.2025 15:05:36
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::array<int, 3>> sw(n), dem(m);
    for (auto &[a, b, cost]: sw)
        std::cin >> a >> b >> cost;

    for (auto &[c, d, profit]: dem)
        std::cin >> c >> d >> profit;

    int res = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
        int ans = 0;

        for (int i = 0; i < n; ++i)
            if (mask >> i & 1)
                ans -= sw[i][2];

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (sw[j][0] >= dem[i][0] && sw[j][1] >= dem[i][1] && (mask >> j & 1)) {
                    ans += dem[i][2];
                    break;
                }

        res = std::max(res, ans);
    }

    std::cout << res << '\n';
    return 0;
}
