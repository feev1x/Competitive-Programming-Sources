#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    bool fl = true;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        fl = fl && a[i] == 2 * i - 1;
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];

        fl = fl && b[i] == 2 * i;
    }

    std::sort(a.begin() + 1, a.end());
    std::sort(b.begin() + 1, b.end());

    int q; std::cin >> q;
        std::vector dp(n + 1, std::vector<int>(n + 1));

        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 1;
        }

        std::vector new_dp(n + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= n; ++k) {
                for (int j = 1; j <= std::min(k, i) && a[i] > b[j]; ++j) {
                    add_self(new_dp[j][k], dp[j - 1][k]);
                }

                for (int j = std::min(k, i - 1); j >= 0 && i - j + k <= n && a[i] <= b[i - j + k]; --j) {
                    add_self(new_dp[j][k], dp[j][k]);
                }
            }

            for (int k = 1; k <= n; ++k) {
                for (int j = 1; j <= std::min(k, i) && a[i] > b[j]; ++j) {
                    add_self(dp[j][k], new_dp[j][k]);
                    new_dp[j][k] = 0;
                }

                for (int j = std::min(k, i - 1); j >= 0 && i - j + k <= n && a[i] <= b[i - j + k]; --j) {
                    add_self(dp[j][k], new_dp[j][k]);
                    new_dp[j][k] = 0;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            add_self(dp[i][i], dp[i - 1][i - 1]);
        }

        while (q--) {
            int l, r; std::cin >> l >> r;

            int res = dp[r][r];

            if (l) {
                add_self(res, -dp[l - 1][l - 1]);
            }

            std::cout << res << '\n';
        }

    return 0;
}
