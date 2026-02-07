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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }

    std::sort(a.begin() + 1, a.end());
    std::sort(b.begin() + 1, b.end());

    std::vector dp(n + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        std::vector new_dp(n + 1, std::vector<int>(n + 1));

        for (int k = 1; k <= n; ++k) {
            for (int j = 0; j <= std::min(k, i); ++j) {
                if (j && a[i] > b[j]) {
                    add_self(new_dp[j][k], dp[j - 1][k]);
                }

                if (j < i && i - j + k <= n && a[i] <= b[i - j + k]) {
                    add_self(new_dp[j][k], dp[j][k]);
                }
            }
        }

        std::swap(new_dp, dp);
    }

    for (int i = 1; i <= n; ++i) {
        add_self(dp[i][i], dp[i - 1][i - 1]);
    }

    int q; std::cin >> q;
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
