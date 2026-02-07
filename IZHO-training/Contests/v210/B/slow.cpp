#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1), g2(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g2[u].emplace_back(v);
        g2[v].emplace_back(u);
    }


    std::vector<int> sub(n + 1), sub2(n + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        sub[v] = 1;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            sub[v] += sub[to];
        }
    };

    auto Dfs2 = [&](auto &&self, int v, int p) -> void {
        sub2[v] = 1;

        for (auto to: g2[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            sub2[v] += sub2[to];
        }
    };

    for (int i = 1; i <= n; ++i) {
        Dfs(Dfs, i, i);
        Dfs2(Dfs2, i, i);

        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (sub[j] > sub2[j]) {
                cnt++;
            }
        }

        std::cout << cnt << " \n"[i == n];
    }
    return 0;
}
