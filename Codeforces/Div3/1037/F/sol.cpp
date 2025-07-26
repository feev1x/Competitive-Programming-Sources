/**
 *    author:  feev1x
 *    created: 22.07.2025 17:07:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;    
    while (tt--) {
        int n, q; std::cin >> n >> q;

        std::vector<int> p(n + 1), pe(n + 1), a(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        std::vector<std::vector<std::pair<int, int>>> g(n + 1);
        std::vector<std::map<int, int64_t>> mp(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v, w; std::cin >> u >> v >> w;

            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        int64_t res = 0;
        auto Dfs = [&](auto &&self, int v) -> void {
            for (auto [to, w]: g[v]) {
                if (to == p[v])
                    continue;

                mp[v][a[to]] += w;
                res += w;

                p[to] = v;
                pe[to] = w;
                self(self, to);
            }

            res -= mp[v][a[v]];
        };

        Dfs(Dfs, 1);

        while (q--) {
            int v, x; std::cin >> v >> x;

            res += mp[v][a[v]];
            if (a[v] != a[p[v]])
                res -= pe[v];

            mp[p[v]][a[v]] -= pe[v]; 

            a[v] = x;

            res -= mp[v][a[v]];
            if (a[v] != a[p[v]])
                res += pe[v];

            mp[p[v]][a[v]] += pe[v];

            std::cout << res << '\n';
        }
    }
    return 0;
}
