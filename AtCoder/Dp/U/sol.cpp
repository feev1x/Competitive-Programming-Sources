#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector a(n, std::vector<int64_t>(n));
    for (auto &u: a) for (auto &v: u) std::cin >> v;
    std::vector<int64_t> cost(1 << n);
    for (int mask = 1; mask < 1 << n; ++mask) {
        int i = log2(mask & -mask);
        cost[mask] = cost[mask ^ (1 << i)];
        for (int j = 0; j < n; ++j) if (mask >> j & 1) cost[mask] += a[i][j];
    }
    std::vector<int64_t> dp(1 << n);
    for (int mask = 0; mask < 1 << n; ++mask)
        for (int smask = mask; smask; smask = (smask - 1) & mask) dp[mask] = std::max(dp[mask], dp[mask ^ smask] + cost[smask]);
    std::cout << dp.back() << '\n';
    return 0;
}
