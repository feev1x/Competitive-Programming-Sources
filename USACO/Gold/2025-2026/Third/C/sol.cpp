#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, N = 2e5 + 5;
int fac[N], inv[N];

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }
inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a), n >>= 1;
    }
    return res;
}

inline void solve() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int res = 0;
    std::vector<int> dp(n + 1), sz(n + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        int ml = 1;
        sz[v] = 1;
        dp[v] = 1;
        for (auto to: g[v]) {
            if (to == p) continue;
            self(self, to, v);
            sz[v] += sz[to];
            dp[v] = mul(dp[v], dp[to]);
            ml = mul(ml, inv[sz[to]]);
        }
        ml = mul(ml, fac[sz[v] - 1]);
        dp[v] = mul(dp[v], ml);
    };
    Dfs(Dfs, 1, 1);
    auto Dfs2 = [&](auto &&self, int wp, int v, int p) -> void {
        int ml = inv[n - sz[v]], fml = inv[sz[v] - 1];
        for (auto to: g[v]) if (to != p) fml = mul(fml, fac[sz[to]]);
        for (auto to: g[v]) {
            if (to == p) continue;
            int nw = mul(dp[v], binpow(dp[to], MOD - 2));
            nw = mul(nw, inv[sz[v] - 1]);
            nw = mul(nw, fac[sz[to]]);
            nw = mul(nw, fac[n - sz[to] - 1]);
            nw = mul(nw, wp);
            nw = mul(nw, inv[n - sz[v]]);
            self(self, nw, to, v);
            ml = mul(ml, inv[sz[to]]);
        }
        ml = mul(ml, fac[n - 1]);
        add_self(res, mul(mul(dp[v], fml), mul(ml, wp)));
    };
    Dfs2(Dfs2, 1, 1, 1);
    std::cout << mul(mul(res, inv[n]), inv[n - 1]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    fac[0] = inv[1] = inv[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = mul(fac[i - 1], i);
    inv[N - 1] = binpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i > 1; --i) inv[i] = mul(inv[i + 1], i + 1);
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
