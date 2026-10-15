#include <bits/stdc++.h>

#define int int64_t

constexpr int N = 60, MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    if (a < 0) {
        a += MOD;
    }
}

inline int add(int a, int b, int mod) {
    return (a + b) % mod;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n; int a1, a2, a3; std::cin >> n >> a1 >> a2 >> a3;
    std::vector dp(a1, std::vector(a2, std::vector(a3, std::vector<int>(1 << 6))));
    dp[0][0][0][0] = 1;
    for (int i = N - 1; i >= 0; --i) {
        std::vector new_dp(a1, std::vector(a2, std::vector(a3, std::vector<int>(1 << 6))));
        for (int m1 = 0; m1 < a1; ++m1) {
            for (int m2 = 0; m2 < a2; ++m2) {
                for (int m3 = 0; m3 < a3; ++m3) {
                    for (int mask = 0; mask < 1 << 6; ++mask) {
                        {
                            int nmask = mask;
                            if (n >> i & 1) {
                                nmask |= 1;
                                nmask |= 1 << 1;
                                nmask |= 1 << 2;
                            }
                            add_self(new_dp[m1][m2][m3][nmask], dp[m1][m2][m3][mask]);
                        }
                        if ((n >> i & 1) || (mask & 1) && (mask >> 1 & 1)) {
                            int nmask = mask;
                            if (n >> i & 1) {
                                nmask |= 1 << 2;
                            }
                            nmask |= 1 << 3;
                            nmask |= 1 << 4;
                            add_self(new_dp[add(m1, 1ll << i, a1)][add(m2, 1ll << i, a2)][m3][nmask], dp[m1][m2][m3][mask]);
                        }
                        if ((n >> i & 1) || (mask & 1) && (mask >> 2 & 1)) {
                            int nmask = mask;
                            if (n >> i & 1) {
                                nmask |= 1 << 1;
                            }
                            nmask |= 1 << 3;
                            nmask |= 1 << 5;
                            add_self(new_dp[add(m1, 1ll << i, a1)][m2][add(m3, 1ll << i, a3)][nmask], dp[m1][m2][m3][mask]);
                        }
                        if ((n >> i & 1) || (mask >> 1 & 1) && (mask >> 2 & 1)) {
                            int nmask = mask;
                            if (n >> i & 1) {
                                nmask |= 1;
                            }
                            nmask |= 1 << 4;
                            nmask |= 1 << 5;
                            add_self(new_dp[m1][add(m2, 1ll << i, a2)][add(m3, 1ll << i, a3)][nmask], dp[m1][m2][m3][mask]);
                        }
                    }
                }
            }
        }
        std::swap(new_dp, dp);
    }
    int res = 0;
    for (int mask = 0; mask < 1 << 3; ++mask) {
        int nmask = (mask | (1 << 3));
        nmask |= (1 << 4);
        nmask |= (1 << 5);
        add_self(res, dp[0][0][0][nmask]);
    }
    std::cout << res << '\n';
    return 0;
}
