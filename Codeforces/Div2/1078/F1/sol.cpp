#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }

inline void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<int> a(n + 1), b(k), val(1 << k), xr(n + 1);
    std::map<int, int> mp;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 0; i < k; ++i) std::cin >> b[i], mp[b[i]] = 1 << i;
    for (int mask = 0; mask < 1 << k; ++mask) for (int i = 0; i < k; ++i) val[mask] ^= b[i] * (mask >> i & 1);
    {
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            xr[v] = a[v];
            for (auto to: g[v]) if (to != p) {
                self(self, to, v);
                xr[v] ^= xr[to];
            }
        }; Dfs(Dfs, 1, 1);
    }
    auto Dfs = [&](auto &&self, int v, int p) -> std::vector<int> {
        std::vector<int> ans(1 << k);
        ans[0] = 1;
        for (auto to: g[v]) if (to != p) {
            auto got = self(self, to, v);
            std::vector<int> new_ans(1 << k);
            for (int i = 0; i < 1 << k; ++i)
                for (int j = 0; j < 1 << k; ++j)
                    add_self(new_ans[i ^ j], mul(ans[j], got[i]));
            std::swap(ans, new_ans);
        }
//        if (v == 3) std::cout << ans[0] << '\n';
        auto new_ans = ans;
        if (v != 1) for (int i = 0; i < 1 << k; ++i) if (mp.count(xr[v] ^ val[i])) add_self(new_ans[i ^ mp[xr[v] ^ val[i]]], ans[i]);
        return new_ans;
    }; auto ans = Dfs(Dfs, 1, 1);
    int res = 0;
    for (int i = 0; i < ans.size(); ++i) if (mp.count(xr[1] ^ val[i])) add_self(res, ans[i]);
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
