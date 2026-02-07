#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a > MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n > 0) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int mod(int a) {
    return (a % MOD + MOD) % MOD;
}

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::vector<int> fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i >= 2; --i) {
        inv[i] = mul(inv[i + 1], i + 1);
    }

    auto C = [&](int n, int k) {
        return mul(fac[n], mul(inv[k], inv[n - k]));
    };

    std::vector<std::pair<int, int>> s(m);
    for (auto &[l, r]: s) {
        std::cin >> l >> r;
    }

    std::sort(s.begin(), s.end(), [&](std::pair<int, int> x, std::pair<int, int> y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }

        return x.first > y.first;
    });

    std::vector<std::pair<int, int>> new_s;

    int mnr = n + 5;
    for (auto [l, r]: s) {
        if (r >= mnr) {
            continue;
        }

        std::cout << l << ' ' << r << '\n';

        mnr = r;
        new_s.emplace_back(l, r);
    }

    std::sort(new_s.begin(), new_s.end());

    std::swap(new_s, s);

    m = s.size();
    std::vector<std::array<int, 4>> dp(m + 1, {0, 0, 0, 0});

    dp[0][3] = 1;
    for (int i = 1; i <= m; ++i) {
        int l = 0, mid = 0, r = 0, sz = s[i - 1].second - s[i - 1].first + 1;

        if (i > 1) {
            l = std::max(0, s[i - 2].second - s[i - 1].first + 1);
        }

        if (i < m) {
            r = std::max(0, s[i - 1].second - s[i].first + 1);
        }

        mid = sz - l - r;
        if (l) {
            if (r) {
                add_self(dp[i][0], mul(dp[i - 1][0], mod(binpow(2, mid) - 1)));
                add_self(dp[i][0], mul(dp[i - 1][1], binpow(2, mid)));
                add_self(dp[i][0], mul(dp[i - 1][2], binpow(2, mid)));

                add_self(dp[i][1], mul(dp[i - 1][0], binpow(2, mid)));
                add_self(dp[i][1], mul(dp[i - 1][1], mod(binpow(2, mid) - 1)));
                add_self(dp[i][1], mul(dp[i - 1][2], binpow(2, mid)));

                add_self(dp[i][2], mul(mul(dp[i - 1][0], binpow(2, mid)), mod(binpow(2, r) - 2)));
                add_self(dp[i][2], mul(mul(dp[i - 1][1], binpow(2, mid)), mod(binpow(2, r) - 2)));
                add_self(dp[i][2], mul(mul(dp[i - 1][2], binpow(2, mid)), mod(binpow(2, r) - 2)));
            } else {
                add_self(dp[i][3], mul(dp[i - 1][0], mod(binpow(2, mid) - 1)));
                add_self(dp[i][3], mul(dp[i - 1][1], mod(binpow(2, mid) - 1)));
                add_self(dp[i][3], mul(dp[i - 1][2], binpow(2, mid)));
            }
        } else {
            if (r) {
                dp[i][0] = mul(dp[i - 1][3], mod(binpow(2, mid) - 1));
                dp[i][1] = mul(dp[i - 1][3], mod(binpow(2, mid) - 1));
                dp[i][2] = mul(mul(dp[i - 1][3], binpow(2, mid)), mod(binpow(2, r) - 2));
            } else {
                dp[i][3] = mul(dp[i - 1][3], mod(binpow(2, mid) - 2));
            }
        }

        std::cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << '\n';
    }

    int ml = mul(binpow(2, s[0].first - 1), binpow(2, n - s.back().second));
    for (int i = 1; i < m; ++i) {
        ml = mul(ml, binpow(2, s[i].first - s[i - 1].second - 1));
    }

    std::cout << mul(dp[m][3], ml) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
