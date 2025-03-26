/**
 *    author:  feev1x
 *    created: 24.03.2025 16:47:06
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k; std::cin >> n >> m >> k;
    
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < k; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
    }

    auto Kuhn = [&]() {
        std::vector<int> pair(m + 1);
        std::vector<bool> used(n + 1), matched(n + 1);

        auto AugPath = [&](auto &&self, int v) -> bool {
            used[v] = true;

            for (auto to: g[v]) {
                if (!pair[to] || !used[pair[to]] && self(self, pair[to])) {
                    matched[v] = true;
                    pair[to] = v;

                    return true;
                }
            }

            return false;
        };

        bool found = true;
        while (found) {
            std::fill(used.begin(), used.end(), false);
            found = false;

            for (int i = 1; i <= n; ++i) {
                if (!matched[i] && !used[i] && AugPath(AugPath, i)) {
                    found = true;

                    break;
                }
            }
        }

        std::vector<std::pair<int, int>> res;
        for (int i = 1; i <= m; ++i) {
            if (pair[i]) {
                res.emplace_back(pair[i], i);
            }
        }

        return res;
    };

    auto res = Kuhn();

    std::cout << res.size() << '\n';
    for (auto [u, v]: res) {
        std::cout << u << ' ' << v << '\n';
    }
    return 0;
}
