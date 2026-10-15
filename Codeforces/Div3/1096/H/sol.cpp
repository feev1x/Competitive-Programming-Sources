#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int root = -1;
    for (int i = 1; i <= n; ++i) if (g[i].size() > 1) { root = i; break; }
    std::vector<bool> odd(n + 1);
    std::vector<int> path(n + 1);
    int res = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        for (auto to: g[v]) if (to != p) {
            self(self, to, v);
            odd[v] = odd[v] ^ odd[to];
            path[v] = std::max(path[v], path[to]);
        }
        if (g[v].size() == 1) odd[v] = true;
        if (odd[v]) res++, path[v]++;
        else path[v]--;
    }; Dfs(Dfs, root, root);
    std::cout << res - (odd[root] ? path[root] : 0) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
