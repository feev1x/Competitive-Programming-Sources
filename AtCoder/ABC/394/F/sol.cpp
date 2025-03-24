/**
 *    author:  feev1x
 *    created: 06.03.2025 17:10:43
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> ans(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int res = -1;
    std::vector<bool> used(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() < 4) {
            used[i] = true;
        }
    }

    auto Dfs = [&](auto &&self, int v) -> int {
        int cnt = 4, ans = 4;
        used[v] = true;

        std::vector<int> mx;
        for (auto to: g[v]) {
            if (used[to]) {
                continue;
            }

            mx.emplace_back(self(self, to));
        }

        std::sort(mx.begin(), mx.end(), std::greater<>());

        for (int i = 0; i < std::min(4, (int)mx.size()); ++i) {
            cnt += mx[i] - 1;

            if (i < 3) {
                ans += mx[i] - 1;
            }
        }

        res = std::max(res, cnt + 1);
        return ans;
    };

    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        res = std::max(res, Dfs(Dfs, i) + 1);
    }

    std::cout << res << '\n';
    return 0;
}
