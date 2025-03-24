/**
 *    author:  feev1x
 *    created: 20.03.2025 11:10:04
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<bool> col(n + 1);
    std::vector<std::vector<std::pair<int, bool>>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        w &= 1;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    auto Dfs = [&](auto &&self, int v, int p, bool flag) -> void {
        col[v] = flag;

        for (auto [to, w]: g[v]) {
            if (to == p) {
                continue;
            }
            
            self(self, to, v, flag ^ w);
        }
    };

    Dfs(Dfs, 1, 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cout << col[i] << '\n';
    }
    return 0;
}
