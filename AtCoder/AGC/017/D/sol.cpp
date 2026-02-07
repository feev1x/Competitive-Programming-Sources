#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<int> nim(n + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        int xr = 0;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            xr ^= nim[to];
        }

        nim[v] = xr + 1;
    };

    Dfs(Dfs, 1, 1);

    std::cout << (!(nim[1] - 1) ? "Bob" : "Alice") << '\n';
    return 0;
}
