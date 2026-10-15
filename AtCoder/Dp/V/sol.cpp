#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int binpow(int a, int n) {
    int res = 1;
    while (n) { if (n & 1) res = mul(res, a); a = mul(a, a), n >>= 1; }
    return res;
}

inline int divide(int a, int b) { return mul(a, binpow(b, MOD - 2)); }

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<int> p(n + 1), q(n + 1), c(n + 1), pos(n + 1), fac(n + 1, 1), inv(n + 1, 1);
    c[0] = 1;
    std::vector<bool> used(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> p[i], pos[p[i]] = i, fac[i] = mul(fac[i - 1], i);
    inv[n] = binpow(fac[n], MOD - 2);
    for (int i = n - 1; i > 1; --i) inv[i] = mul(inv[i + 1], i + 1);
    for (int i = 1; i <= n; ++i) std::cin >> q[i];
    for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;
        int u = i;
        std::vector<int> cyc;
        while (!used[u]) used[u] = true, cyc.emplace_back(u), u = q[pos[u]];
        int sz = cyc.size();
        std::vector dp(2, std::vector(2, std::vector<int>(sz + 1)));
        dp[0][0][0] = dp[1][0][1] = dp[0][1][1] = 1;
        for (int i = 1; i < sz; ++i) {
            std::vector new_dp(2, std::vector(2, std::vector<int>(sz)));
            for (int j = 0; j <= i; ++j)
                for (int k = 0; k < 2; ++k) {
                    add_self(new_dp[k][0][j + 1], dp[k][0][j]);
                    add_self(new_dp[k][1][j + 1], dp[k][0][j]);
                    add_self(new_dp[k][1][j + 1], dp[k][1][j]);
                    add_self(new_dp[k][0][j], dp[k][1][j]);
                    add_self(new_dp[k][0][j], dp[k][0][j]);
                }
            std::swap(new_dp, dp);
        }
        std::vector<int> cc(sz + 1);
        for (int i = 0; i <= sz; ++i) {
            add_self(cc[i], dp[0][1][i]);
            add_self(cc[i], dp[0][0][i]);
            add_self(cc[i], dp[1][0][i]);
        }
        for (int j = n; j >= 0; --j)
            for (int i = 1; i <= sz && i + j <= n; ++i)
                add_self(c[i + j], mul(cc[i], c[j]));
    }
    for (int i = 0; i <= n; ++i) std::cout << mul(fac[n - i], c[i]) << '\n';
    int res = 0;
    for (int i = 0; i <= n; ++i) add_self(res, (i & 1 ? -1 : 1) * mul(c[i], fac[n - i]));
    std::cout << res << '\n';
    return 0;
}
