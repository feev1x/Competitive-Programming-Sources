/**
 *    author:  feev1x
 *    created: 04.03.2025 03:36:00
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> inv(2 * m + 1), comp(2 * m + 1), ord;
    for (int i = 1; i <= m; ++i) {
        inv[i] = i + m;
    }

    for (int i = m + 1; i <= 2 * m; ++i) {
        inv[i] = i - m;
    }

    std::vector<std::vector<int>> g(2 * m + 1), r_g(2 * m + 1);
    for (int i = 0; i < n; ++i) {
        char ch; int u; std::cin >> ch >> u;

        if (ch == '-') {
            u += m; 
        }

        int v; std::cin >> ch >> v;

        if (ch == '-') {
            v += m;
        }

        g[inv[u]].emplace_back(v);
        g[inv[v]].emplace_back(u);
        r_g[v].emplace_back(inv[u]);
        r_g[u].emplace_back(inv[v]);
    }

    {
        std::vector<bool> used(2 * m + 1);

        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            for (auto to: g[v]) {
                if (used[to]) {
                    continue;
                }

                self(self, to);
            }

            ord.emplace_back(v);
        };

        for (int i = 1; i <= 2 * m; ++i) {
            if (used[i]) {
                continue;
            }

            Dfs(Dfs, i);
        }

        std::reverse(ord.begin(), ord.end());
    }
    
    int cnt = 0;
    std::vector<bool> used(2 * m + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;
        comp[v] = cnt;

        if (comp[inv[v]] == cnt) {
            std::cout << "IMPOSSIBLE\n";

            exit(0);
        }

        for (auto to: r_g[v]) {
            if (used[to]) {
                continue;
            }

            self(self, to);
        }
    };

    for (auto v: ord) {
        if (used[v]) {
            continue;
        }

        cnt++;
        Dfs(Dfs, v);
    }

    std::string res(m + 1, '-');
    for (int v = 1; v <= m; ++v) {
        if (comp[v] > comp[inv[v]]) {
            res[v] = '+';
        } else {
            res[v] = '-';
        }
    }

    for (int i = 1; i <= m; ++i) {
        std::cout << res[i] << " \n"[i == m];
    }
    return 0;
}
