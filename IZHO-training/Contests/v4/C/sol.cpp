/**
 *        author:  feev1x
 *        created: 08.01.2025 10:35:24
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (i64)a * b % MOD;
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

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

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

    std::vector<std::string> s(m);
    std::vector<std::vector<int>> sum(1 << m, std::vector<int>(m + 1));
    std::vector<int> fac(std::max(n, m) + 1, 1), move(1 << m), dp(1 << m), cnt(1 << m);

    int res = 0;
    for (auto &u: s) {
        std::cin >> u;
    }

    for (int i = 0; i < n; ++i) {
        int mask = 0;

        for (int j = 0; j < m; ++j) {
            if (s[j][i] == 'H') {
                mask |= 1 << j;
            }
        }

        cnt[mask]++;
    }

    for (int i = 1; i <= std::max(n, m); ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    auto P = [&](int n, int k) {
        return divide(fac[n], fac[n - k]);
    };
    
    for (int mask = 0; mask < 1 << m; ++mask) {
        for (int i = 1; i <= cnt[mask]; ++i) {
            add_self(move[mask], P(cnt[mask], i));
        }
    }

    for (int mask = 0; mask < 1 << m; ++mask) {
        for (int i = 1; i <= m; ++i) {
            if (mask >> i - 1 & 1) {
                sum[mask][i] = (sum[mask][i - 1] + sum[mask ^ 1 << i - 1][i - 1]) % MOD;
            } else {
                sum[mask][i] = sum[mask][i - 1];
            }
        }

        add_self(dp[mask], mul(sum[mask][m] + 1, move[mask]));
        add_self(res, dp[mask]);
        for (int i = 0; i < m; ++i) {
            add_self(sum[mask][i], dp[mask]);
        }
    }

    std::cout << res << '\n';
    return 0;
}
