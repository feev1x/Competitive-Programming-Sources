/**
 *    author:  feev1x
 *    created: 01.05.2025 16:31:51
**/
#include <bits/stdc++.h>

#define int int64_t

constexpr int MOD = 1e9 + 7, N = 10, CN = 1001;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> c(n + 1), f(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> c[i];
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> f[i];
    }

    std::map<int, int> dp, dp1;
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            auto new_dp = dp;

            for (auto [key, val]: dp) {
                for (int sm = 1; sm < N; ++sm) {
                    int k1 = key + (-2 * c[i] + 2 * c[j]) * sm; 
                    int k2 = key + (2 * c[i] + -2 * c[j]) * sm;


                    if (std::abs(k1) < CN)
                    if (new_dp.count(k1)) {
                        new_dp[k1] = std::min(new_dp[k1], std::max(val, std::abs(f[i] - f[j])));   
                    } else {
                        new_dp[k1] = std::max(val, std::abs(f[i] - f[j]));
                    }

                    if (std::abs(k2) < CN)
                    if (new_dp.count(k2)) {
                        new_dp[k2] = std::min(new_dp[k2], std::max(val, std::abs(f[i] - f[j])));   
                    } else {
                        new_dp[k2] = std::max(val, std::abs(f[i] - f[j]));
                    }
                }
            }

            dp = new_dp;
        }
    }

    while (q--) {
        int a, b, l, r; std::cin >> a >> b >> l >> r;

        if (l == 1 && r == 1e9) {
            int res = -1;

            if (dp.count(a - b) && (res == -1 || res > dp[a - b])) {
                res = dp[a - b];
            }

            if (dp.count(b - a) && (res == -1 || res > dp[b - a])) {
                res = dp[b - a];
            }

            std::cout << res << ' ';
        } else {
            dp1.clear();
            dp1[0] = 0;
            for (int i = 1; i <= n; ++i) {
                if (f[i] < l || r < f[i]) {
                    continue;
                }

                for (int j = i + 1; j <= n; ++j) {
                    if (f[j] < l || r < f[j]) {
                        continue;
                    }

                    auto new_dp = dp1;

                    for (auto [key, val]: dp1) {
                        for (int sm = 1; sm < N; ++sm) {
                            int k1 = key + (-2 * c[i] + 2 * c[j]) * sm; 
                            int k2 = key + (2 * c[i] + -2 * c[j]) * sm;

                            if (std::abs(k1) < CN)
                            if (new_dp.count(k1)) {
                                new_dp[k1] = std::min(new_dp[k1], std::max(val, std::abs(f[i] - f[j])));   
                            } else {
                                new_dp[k1] = std::max(val, std::abs(f[i] - f[j]));
                            }

                            if (std::abs(k2) < CN)
                            if (new_dp.count(k2)) {
                                new_dp[k2] = std::min(new_dp[k2], std::max(val, std::abs(f[i] - f[j])));   
                            } else {
                                new_dp[k2] = std::max(val, std::abs(f[i] - f[j]));
                            }
                        }
                    }

                    dp1 = new_dp;
                }
            }

            int res = -1;

            if (dp1.count(a - b) && (res == -1 || res > dp1[a - b])) {
                res = dp1[a - b];
            }

            if (dp1.count(b - a) && (res == -1 || res > dp1[b - a])) {
                res = dp1[b - a];
            }

            std::cout << res << ' ';
        }
    }
    return 0;
}
