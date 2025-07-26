/**
 *    author:  feev1x
 *    created: 08.07.2025 09:17:26
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

inline void chmin(int64_t &a, int64_t b) {
    if (a > b) {
        a = b;
    }
}

std::vector<long long> calculate_costs(std::vector<int> w, std::vector<int> a, std::vector<int> b, std::vector<int> e) {
    std::vector<long long> ans;
    int n = a.size();

    std::vector<int> idx(n);

    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return w[i] < w[j];
    });

    for (auto d: e) {
        std::vector<int64_t> dp(n, INF);

        for (int i = 0; i < n; ++i) {
            chmin(dp[i], (i ? dp[i - 1] : 0) + a[idx[i]]);

            if (i > 0 && w[idx[i]] - w[idx[i - 1]] <= d)
                chmin(dp[i], (i - 2 >= 0 ? dp[i - 2] : 0) + b[idx[i - 1]] + b[idx[i]]);

            if (i > 1 && w[idx[i]] - w[idx[i - 2]] <= d)
                chmin(dp[i], (i - 3 >= 0 ? dp[i - 3] : 0) + b[idx[i - 2]] + b[idx[i]] + a[idx[i - 1]]);
        }

        std::cerr << '\n';

        ans.emplace_back(dp.back());
    }


    return ans;
}
