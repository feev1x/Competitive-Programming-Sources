#include <bits/stdc++.h>

constexpr int MOD = 998244353;

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
    int n; std::cin >> n;
    std::vector<int> r(n), c(n);
    std::vector<int> fac(2 * n + 1, 1);
    for (int i = 2; i <= 2 * n; ++i) fac[i] = mul(fac[i - 1], i);
    int cnt = 0, sum = 0;
    for (auto &u: r) std::cin >> u;
    for (auto &u: c) std::cin >> u, cnt += u == 2, sum += u;
    std::vector<int> dp(cnt + 1);
    dp[cnt] = 1;
    int used = 0;
    for (auto u: r) {
        if (!u) continue;
        std::vector<int> new_dp(cnt + 1);
        int cn = sum - used;
        used += u;
        if (u == 2) {
            for (int i = 0; i + 1 < cnt; ++i) add_self(new_dp[i], mul(dp[i + 2], mul(mul(i + 2, i + 1), (MOD + 1) / 2)));
            for (int i = 0; i < cnt; ++i) if (cn - (i + 1) * 2 >= 0) add_self(new_dp[i], mul(cn - (i + 1) * 2 + 1, mul(i + 1, dp[i + 1])));
            for (int i = 0; i <= cnt; ++i) if (cn - i * 2 > 1) add_self(new_dp[i], mul(dp[i], mul(mul(cn - i * 2, cn - i * 2 - 1), (MOD + 1) / 2)));
        } else {
            for (int i = 0; i < cnt; ++i) add_self(new_dp[i], mul(i + 1, dp[i + 1]));
            for (int i = 0; i <= cnt; ++i) if (cn - i * 2 > 0) add_self(new_dp[i], mul(cn - i * 2, dp[i]));
        }
        std::swap(new_dp, dp);
    }
    std::cout << (used == sum ? dp[0] : 0) << '\n';
    return 0;
}
