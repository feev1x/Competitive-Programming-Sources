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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::vector<std::string> s(m);
    std::vector<int> val(n), fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    inv[n] = binpow(fac[n], MOD - 2);
    for (int i = n - 1; i > 1; --i) inv[i] = mul(inv[i + 1], i + 1);
    for (auto &u: s) std::cin >> u;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[j][i] == 'H') val[i] |= 1 << j;
    std::vector<int> cnt(1 << m), ans(1 << m);
    for (auto u: val) cnt[u]++;
    auto P = [&](int n, int k) { return mul(fac[n], inv[n - k]); };
	std::vector<int> df;
    for (int i = 0; i < n; ++i) {
		if (cnt[val[i]]) df.emplace_back(val[i]);
        for (int j = 1; j <= cnt[val[i]]; ++j) add_self(ans[val[i]], P(cnt[val[i]], j));
        cnt[val[i]] = 0;
    }
	std::sort(df.begin(), df.end());
    std::vector<int> dp(1 << m);
    dp[0] = (ans[0] + 1) % MOD;
//    for (int i = 0; i < m; ++i)
//        for (int mask = 1; mask < 1 << m; ++mask) if (mask >> i & 1) add_self(dp[mask], mul(ans[mask], dp[mask ^ (1 << i)]));
	for (auto mask: df)
        for (int smask = mask; smask; smask = (smask - 1) & mask)
            add_self(dp[mask], mul(ans[mask], dp[smask ^ mask]));
    int res = MOD - 1;
    for (auto u: dp) add_self(res, u);
    std::cout << res << '\n';
    return 0;
}
