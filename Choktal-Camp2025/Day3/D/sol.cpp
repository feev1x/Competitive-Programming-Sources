/**
 *    author:  feev1x
 *    created: 03.07.2025 12:46:49
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, D; std::cin >> n >> D;

    if (D % 2 == 0)
        D--;

    std::vector<int> d(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector dv(n + 1, std::vector<std::vector<int>>(D + 1));
    std::vector<std::pair<int, int>> res;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        d[v] = d[p] + 1;
        dv[v][0].emplace_back(v);

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            for (int i = 0; i < D; ++i) {
                if (dv[to][i].size() > dv[v][i + 1].size())
                    std::swap(dv[to][i], dv[v][i + 1]);

                for (auto u: dv[to][i])
                    dv[v][i + 1].emplace_back(u);
            }
        }

        if (v != 1) {
            for (int i = 0; i * 2 < D; ++i) {
                int j = D - i;

                while (dv[v][i].size() && dv[v][j].size()) {
                    res.emplace_back(dv[v][i].back(), dv[v][j].back());
                    dv[v][i].pop_back();
                    dv[v][j].pop_back();
                }
            }
        } else {
            for (int i = D; i >= 0; --i) {
                for (int j = D - i; dv[v][i].size() && j >= 0; j -= 2) {
                    while (dv[v][i].size() && dv[v][j].size()) {
                        res.emplace_back(dv[v][i].back(), dv[v][j].back());
                        dv[v][i].pop_back();
                        dv[v][j].pop_back();
                    }
                }
            }
        }
    };

    Dfs(Dfs, 1, 1);

    std::cout << res.size() << '\n';
    for (auto [u, v]: res) {
        std::cout << u << ' ' << v << '\n';
    }
    return 0;
}


