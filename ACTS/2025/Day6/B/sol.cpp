/**
 *    author:  feev1x
 *    created: 26.07.2025 15:52:30
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<int> pos(k);
    for (auto &u: pos)
        std::cin >> u;

    int64_t res = 0;

    std::vector<std::vector<int64_t>> dp(1 << n);
    for (int mask = 0; mask < 1 << n; ++mask)
        dp[mask].resize(1 << __builtin_popcount(mask));

    std::queue<std::pair<int, int>> q;

    q.emplace(0, 0);
    dp[0][0] = 1;
    while (q.size()) {
        auto [mask, mask2] = q.front();

        q.pop();

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                cnt++;
                continue;
            }

            
        }
    }
    return 0;
}
