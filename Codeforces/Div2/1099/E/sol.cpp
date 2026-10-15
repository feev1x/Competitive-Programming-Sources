#include <bits/stdc++.h>

inline void solve() {
    int n, d; std::cin >> n >> d;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<std::vector<int64_t>> down(n + 1), up(n + 1);
    std::vector<int> dep(n + 1);
    {
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            down[v].resize(1);
            down[v][0] = 1;
            dep[v] = dep[p] + 1;
            for (auto to: g[v]) if (to != p) {
                self(self, to, v);
                if (down[v].size() < down[to].size() + 1) down[v].resize(down[to].size() + 1);
                for (int i = 0; i < down[to].size(); ++i) down[v][i + 1] += down[to][i];
            }
        }; Dfs(Dfs, 1, 1);
    }
    {
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            up[v] = up[p];
            up[v].emplace(up[v].begin(), 1);
            if (p != v && up[v].size() < down[p].size() + 1) up[v].resize(down[p].size() + 1);
            if (p != v) for (int i = 1; i < down[p].size(); ++i) up[v][i + 1] += down[p][i] - (down[v].size() <= i - 1 ? (int64_t)0 : down[v][i - 1]);
            for (auto to: g[v]) if (to != p) self(self, to, v);
        }; Dfs(Dfs, 1, 1);
    }
    int64_t res = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        if (down[v].size() > d - 1) res += down[v][d - 1] * (d - 2);
        auto dwn = down[v];
        down[v].clear();
        for (auto to: g[v]) if (to != p) {
            self(self, to, v);
            for (int i = 0; i < down[to].size(); ++i) dwn[i + 1] -= down[to][i];
            if (down[v].size() < down[to].size()) std::swap(down[v], down[to]);
            for (int i = 0; i < down[to].size(); ++i) {
                if (d - i - 3 >= 0 && d - i - 3 < down[v].size()) res += down[to][i] * down[v][d - i - 3] * (d - 2);
                for (int j = 0; j < down[v].size(); ++j) {
                    if (d - i - j - 3 > 0 && d - i - j - 3 < dwn.size())
                        res += down[to][i] * down[v][j] * dwn[d - i - j - 3];
                    if (d - i - j - 3 > 0 && d - i - j - 3 < up[v].size())
                        res += down[to][i] * down[v][j] * up[v][d - i - j - 3];
                }
            }
            for (int i = 0; i < down[to].size(); ++i) down[v][i] += down[to][i];
        }
        down[v].emplace(down[v].begin(), 1);
    }; Dfs(Dfs, 1, 1);
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
