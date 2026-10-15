#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    int n, cnt;
    Dsu(int _n) : n(_n) {
        p.resize(n + 1), cnt = n;
        sz.assign(n + 1, 1);
        std::iota(p.begin(), p.end(), 0);
    }
    inline int get(int v) {
        return p[v] == v ? v : p[v] = get(p[v]);
    }
    inline void unite(int u, int v) {
        u = get(u), v = get(v);
        if (u != v) {
            if (sz[u] > sz[v]) std::swap(u, v);
            p[u] = v, cnt--;
            sz[v] += sz[u];
        }
    }
};

inline void solve() {
    int n, m, res = 0; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1);
    Dsu d(n);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        d.unite(u, v);
    }
    std::vector<bool> good(n + 1, 1);
    std::vector<int> col(n + 1, -1), c0(n + 1), c1(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        if (col[v] == 0) c0[d.get(v)]++;
        else c1[d.get(v)]++;
        for (auto to: g[v]) {
            if (col[to] != -1) {
                if (col[to] == col[v] && good[d.get(v)]) good[d.get(v)] = false;
                continue;
            }
            col[to] = !col[v];
            self(self, to);
        }
    };
    for (int i = 1; i <= n; ++i) if (col[i] == -1) col[i] = 0, Dfs(Dfs, i);
    for (int i = 1; i <= n; ++i) if (good[i]) res += std::max(c0[i], c1[i]);
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
