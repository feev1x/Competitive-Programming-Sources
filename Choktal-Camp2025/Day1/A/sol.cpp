/**
 *    author:  feev1x
 *    created: 01.07.2025 09:13:56
**/
#include <bits/stdc++.h>

#define double long double
#define int int64_t

constexpr int N = 1e7 + 1;

inline void chmax(double &a, double b) {
    if (a < b) {
        a = b;
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k; std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> in, mp(N);
    for (int i = k; i >= 1; --i) {
        if (in.empty() || in.back() != (k + i - 1) / i) {
            mp[(k + i - 1) / i] = in.size();
            in.emplace_back((k + i - 1) / i);
        }
    }
    std::vector<std::vector<int>> g(in.size());

    int pos = 0;
    for (auto i: in) {
        int sq = std::ceil(std::sqrt(i));

        for (int j = sq; j >= 1; --j) {
            g[pos].emplace_back(mp[(i + j - 1) / j]);

            g[pos].emplace_back(mp[j]);
        }

        pos++;
    }

    std::vector<double> dp(in.size());

    dp.back() = k;
    for (int i = 1; i <= n; ++i) {
        auto new_dp = dp;

        for (int j = in.size() - 1; j >= 0; --j) {
            for (auto to: g[j]) {
                int b = (in[j] + in[to] - 1) / in[to];

                if (b > a[i]) {
                    continue;
                }

                int val = a[i] / b;
                chmax(new_dp[to], (double)dp[j] * val / a[i]);
            }
        }

        dp = new_dp;
    }


    std::cout << std::fixed << std::setprecision(10) << (double)dp[mp[1]] << '\n';
    return 0;
}

