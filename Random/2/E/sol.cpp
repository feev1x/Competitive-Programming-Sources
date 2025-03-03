/**
 *    author:  feev1x
 *    created: 15.02.2025 09:09:38
**/
#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;

int64_t dp[N];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n, b, x; std::cin >> n >> b >> x;

    std::vector<int64_t> a(n);
    for (auto &u: a) {
        std::cin >> u;

        for (int k = 1; k < u; ++k) {
            int64_t cnt = u / k, ost = u % k;

            dp[k] += b * ((k - ost) * (k - ost - 1) * cnt * cnt / 2 + ost * (ost - 1) * (cnt + 1) * (cnt + 1) / 2 + ost * (k - ost) * cnt * (cnt + 1));
            dp[k + 1] -= b * ((k - ost) * (k - ost - 1) * cnt * cnt / 2 + ost * (ost - 1) * (cnt + 1) * (cnt + 1) / 2 + ost * (k - ost) * cnt * (cnt + 1));
        }

        dp[u] += ((u * (u - 1)) / 2) * b;
    }

    int64_t val = 0, res = 0;
    for (int i = 1; i < N; ++i) {
        val += dp[i];

        res = std::max(res, val - (i - 1) * x); 
    }

    std::cout << res << '\n';
    return 0;
}
