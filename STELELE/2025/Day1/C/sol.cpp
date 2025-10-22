/**
 *    author:  feev1x
 *    created: 18.10.2025 16:01:17
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1), b(n + 1), c(n + 1), fac(n + 1, 1), inv(n + 1, 1), ans(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], c[i] = i;

    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];

    for (int i = 1; i <= n; ++i)
        fac[i] = mul(fac[i - 1], i);

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i > 0; --i)
        inv[i] = mul(inv[i + 1], i + 1);

    std::sort(c.begin() + 1, c.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    std::vector<int> new_a(n + 1);
    std::vector<int> new_b(n + 1);
    for (int i = 1; i <= n; ++i)
        new_a[i] = a[c[i]], new_b[i] = b[c[i]];

    std::swap(new_a, a);
    std::swap(new_b, b);

    auto P = [&](int N, int K) {
        return mul(fac[N], inv[N - K]);
    };

    
    std::vector dp(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        int sz = 0;

        for (int j = 1; j <= n; ++j)
            if (a[i] > a[j] || b[i] > b[j])
                sz++;

        for (int j = 0; j <= sz; ++j)
            add_self(dp[i][j], P(sz, sz - j));

        for (int j = 1; j < i; ++j) {
            if (a[j] > a[i] || b[j] > b[i])
                continue;

            int sz = 0;
            for (int k = 1; k <= n; ++k)
                if (a[k] > a[j] && b[k] > b[j] && (a[i] > a[k] || b[i] > b[k]))
                    sz++;

            for (int l = sz; l <= n; ++l)
                for (int k = l - sz; k <= n; ++k)
                    add_self(dp[i][l], mul(dp[j][k], P(k + sz, (k + sz) - l)));
        }

        ans[c[i]] = dp[i][0];
    }

    for (int i = 1; i <= n; ++i) {
        bool flag = true;

        for (int j = 1; j <= n; ++j)
            if (a[c[j]] > a[c[i]] && b[c[j]] > b[c[i]])
                flag = false;

        std::cout << ans[i] * flag << " \n"[i == n];
    }

    return 0;
}
