/**
 *    author:  feev1x
 *    created: 21.04.2025 10:19:51
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto Dfs = [&](auto &&self, int v, int p) -> int {
        int nw = k - 1;

        if (v != 1) {
            nw--;
        }

        int res = 1;
        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            res = mul(res, mul(self(self, to, v), nw--));
        }

        return res;
    };

    std::cout << mul(k, Dfs(Dfs, 1, 1)) << '\n';
    return 0;
}
