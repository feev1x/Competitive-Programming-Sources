/**
 *    author:  feev1x
 *    created: 03.03.2025 13:40:44
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    if (n == 1) {
        std::cout << (m % 2 == 0) << '\n';

        exit(0);
    }

    if (m == 1) {
        std::cout << (n % 2 == 0) << '\n';

        exit(0);
    }

    n++;

    std::vector<int> dp(1 << n);

    dp[0] = 1;
    for (int i = 1; i < n - 1; ++i) {
        std::vector<int> new_dp(1 << n);

        if (i + 1 < n - 1) {
            for (int mask = 0; mask < 1 << i; ++mask) {
                add_self(new_dp[mask], dp[mask]);

                if (mask >> (i - 1) & 1) {
                    continue;
                }

                mask ^= 1 << i;
                add_self(new_dp[mask ^ (1 << i - 1)], dp[mask ^ (1 << i)]);

                mask ^= 1 << i;
            }
        } else {
            for (int mask = 0; mask < 1 << i; ++mask) {
                add_self(new_dp[mask << 1], dp[mask]);

                if (mask >> (i - 1) & 1) {
                    continue;
                }

                int new_mask = mask ^ (1 << i);
                new_mask ^= (1 << i - 1);

                add_self(new_dp[new_mask << 1], dp[mask]);
            }
        }

        dp = new_dp;
    }

    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            std::vector<int> new_dp(1 << n);

            if (i + 1 < n - 1 && i) {
                for (int mask = 0; mask < 1 << n; ++mask) {
                    if (!(mask >> i & 1)) {
                        continue;
                    }

                    add_self(new_dp[mask ^ (1 << i)], dp[mask]);

                    if (mask >> (i - 1) & 1) {
                        continue;
                    }

                    add_self(new_dp[mask | (1 << i - 1)], dp[mask]);
                }

                for (int mask = 0; mask < 1 << n; ++mask) {
                    if (!(mask >> i & 1)) {
                        continue;
                    }

                    if (mask >> (i + 1) & 1) {
                        continue;
                    }

                    add_self(new_dp[mask | (1 << i + 1)], dp[mask]);
                }
            } else if (!i) {
                for (int mask = 0; mask < 1 << n; ++mask) {
                    if (mask & 1) {
                        continue;
                    }

                    add_self(new_dp[mask], dp[mask]);

                    if (mask >> 1 & 1) {
                        continue;
                    }

                    add_self(new_dp[mask | 3], dp[mask]);
                }
            } else {
                for (int mask = 0; mask < 1 << n; ++mask) {
                    if (!(mask >> i & 1)) {
                        continue;
                    }

                    if (mask >> (i + 1) & 1) {
                        int new_mask = mask ^ (1 << i);
                        new_mask ^= (1 << n - 1);

                        add_self(new_dp[new_mask << 1], dp[mask]);
                    }

                    if (mask >> (i - 1) & 1) {
                        continue;
                    }

                    if (mask >> (i + 1) & 1) {
                        int new_mask = mask | (1 << i - 1);
                        new_mask ^= (1 << n - 1);

                        add_self(new_dp[new_mask << 1], dp[mask]);
                    }
                }

                for (int mask = 0; mask < 1 << n; ++mask) {
                    if (!(mask >> i & 1)) {
                        continue;
                    }

                    if (mask >> (i + 1) & 1) {
                        continue;
                    }

                    add_self(new_dp[mask << 1], dp[mask]);
                }
            }


            dp = new_dp;
        }
    }

    std::cout << dp[((1 << n) - 1) ^ 1] << '\n';
    return 0;
}
