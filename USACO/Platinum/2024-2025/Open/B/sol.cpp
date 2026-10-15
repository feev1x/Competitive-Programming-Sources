#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, N = 5e6 + 5;

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; std::cin >> n >> q;
    std::vector<int> fac(N, 1), inv(N, 1), c(q), v(q);
    for (int i = 0; i < q; ++i) std::cin >> c[i] >> v[i];
    for (int i = 2; i < N; ++i) fac[i] = mul(fac[i - 1], i);
    inv[N - 1] = binpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i > 1; --i) inv[i] = mul(inv[i + 1], i + 1);
    std::map<std::pair<int, int>, int> mp;
    auto C = [&](int n, int k) {
        if (mp.count({n, k})) return mp[{n, k}];
        return mul(fac[n], mul(inv[n - k], inv[k]));
    };
    auto Get = [&](int n, int k) {
        std::vector<int> ar(k + 1);
        if (k < 0) return ar;
        int res = 1;
        for (int i = 0; i <= k; ++i) ar[i] = mul(res, inv[i]), res = mul(res, n - i);
        return ar;
    };
    std::vector<int> dp(2);
    dp[0] = 1;
    for (int i = 1; i < q; ++i) {
        std::vector<int> new_dp(2);
        if (v[i] >= v[i - 1]) { // 0 0
            int n = c[i] - c[i - 1] - 1, sz = v[i] - v[i - 1];
            auto csz = Get(sz, std::min(sz, n));
            auto cn = Get(n, std::min(sz, n));
            for (int k = std::min(sz, n); k >= 0; --k)
                add_self(new_dp[0], mul(dp[0], mul(binpow(2, n - k), mul(csz[k], cn[k]))));
        }
        if (v[i] - v[i - 1] >= -1) { // 0 1
            int n = c[i] - c[i - 1] - 1, sz = std::max(v[i] - v[i - 1], 0);
            if (v[i] == v[i - 1] - 1) add_self(new_dp[1], mul(dp[0], binpow(2, n)));
            auto csz = Get(sz, std::min((v[i] + 1) - v[i - 1], n) - 1);
            auto cn = Get(n, std::min((v[i] + 1) - v[i - 1], n));
            for (int k = std::min((v[i] + 1) - v[i - 1], n); k >= 1; --k)
                add_self(new_dp[1], mul(dp[0], mul(binpow(2, n - k), mul(csz[k - 1], cn[k]))));
        }
        v[i - 1]++;
        if (v[i] >= v[i - 1]) { // 1 0
            int n = c[i] - c[i - 1] - 1, sz = v[i] - v[i - 1];
            auto csz = Get(sz, std::min(sz, n));
            auto cn = Get(n, std::min(sz, n));
            for (int k = std::min(sz, n); k >= 0; --k)
                add_self(new_dp[0], mul(dp[1], mul(binpow(2, n - k), mul(csz[k], cn[k]))));
        }
        if (v[i] - v[i - 1] >= -1) { // 1 1
            int n = c[i] - c[i - 1] - 1, sz = std::max(v[i] - v[i - 1], 0);
            if (v[i] == v[i - 1] - 1) add_self(new_dp[1], mul(dp[1], binpow(2, n)));
            auto csz = Get(sz, std::min((v[i] + 1) - v[i - 1], n) - 1);
            auto cn = Get(n, std::min((v[i] + 1) - v[i - 1], n));
            for (int k = std::min((v[i] + 1) - v[i - 1], n); k >= 1; --k)
                add_self(new_dp[1], mul(dp[1], mul(binpow(2, n - k), mul(csz[k - 1], cn[k]))));
        }
        std::swap(new_dp, dp);
    }
    add_self(dp[0], dp[1]);
    std::cout << dp[0] << '\n';
    return 0;
}
