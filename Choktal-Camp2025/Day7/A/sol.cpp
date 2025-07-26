/**
 *    author:  feev1x
 *    created: 07.07.2025 09:08:06
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

inline void chmin(int64_t &a, int64_t b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    
    std::vector<int> a(n + 1), val;

    std::map<int, bool> mp;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        if (!mp.count(a[i])) {
            val.emplace_back(a[i]);
            mp[a[i]] = true;
        }
        for (int j = 1; j <= 1000; j += 4) {
            if (!mp.count(a[i] + j)) {
                val.emplace_back(a[i] + j);
                mp[a[i] + j] = true;
            }
            if (!mp.count(a[i] - j)) {
                val.emplace_back(a[i] - j);
                mp[a[i] + j] = true;
            }
        }
    }


    std::sort(val.begin(), val.end());

    int cnt = val.size();

    std::vector dp(n + 1, std::vector(3, std::vector<int64_t>(cnt, INF)));

    dp[1][0][a[1]] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < cnt; ++j) {
            for (int k = 0; k < cnt; ++k) {
                if (val[k] == val[j] || i == 1) {
                    chmin(dp[i + 1][0][j], dp[i][0][k] + std::abs(a[i] - val[j]));
                    chmin(dp[i + 1][1][j], dp[i][1][k] + std::abs(a[i] - val[j]));
                    chmin(dp[i + 1][2][j], dp[i][2][k] + std::abs(a[i] - val[j]));
                }

                if (val[k] > val[j] || i == 1) {
                    chmin(dp[i + 1][1][j], dp[i][0][k] + std::abs(a[i] - val[j]));
                    chmin(dp[i + 1][1][j], dp[i][2][k] + std::abs(a[i] - val[j]));
                }

                if (val[k] < val[j] || i == 1) {
                    chmin(dp[i + 1][2][j], dp[i][0][k] + std::abs(a[i] - val[j]));
                    chmin(dp[i + 1][2][j], dp[i][1][k] + std::abs(a[i] - val[j]));
                }
            }
        }
    }

    int64_t res = 1e18;
    for (int j = 0; j < cnt; ++j) {
        for (int k = 0; k < cnt; ++k) {
            if (val[k] == val[j]) {
                chmin(res, dp[n][0][k] + std::abs(a[n] - val[j]));
                chmin(res, dp[n][1][k] + std::abs(a[n] - val[j]));
                chmin(res, dp[n][2][k] + std::abs(a[n] - val[j]));
            }

            if (val[k] > val[j]) {
                chmin(res, dp[n][0][k] + std::abs(a[n] - val[j]));
                chmin(res, dp[n][2][k] + std::abs(a[n] - val[j]));
            }

            if (val[k] < val[j]) {
                chmin(res, dp[n][0][k] + std::abs(a[n] - val[j]));
                chmin(res, dp[n][1][k] + std::abs(a[n] - val[j]));
            }
        }
    }

    assert(res >= 0);
    std::cout << res << '\n';
    return 0;
}
