/**
 *    author:  feev1x
 *    created: 27.02.2025 21:09:33
**/
#include <bits/stdc++.h>

constexpr int MOD = 998244353;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> p(n + 1), dp(n + 1), dep(n + 1);
        std::vector<int64_t> sum(n + 5);
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 2; i <= n; ++i) {
            std::cin >> p[i];

            g[p[i]].emplace_back(i);
            g[i].emplace_back(p[i]);
        }

        std::queue<int> q;

        q.emplace(1);

        while (q.size()) {
            int v = q.front();

            q.pop();

            dep[v] = dep[p[v]] + 1;

            if (p[v] == 1 || v == 1) {
                dp[v] = 1;
            } else {
                dp[v] = ((sum[dep[v] - 1] - dp[p[v]]) % MOD + MOD) % MOD;
            }

            sum[dep[v]] += dp[v];
            sum[dep[v]] %= MOD;
            for (auto to: g[v]) {
                if (to == p[v]) {
                    continue;
                }

                q.emplace(to);
            }
        }

        std::cout << accumulate(dp.begin(), dp.end(), 0ll) % MOD << '\n';
    }
    return 0;
}
