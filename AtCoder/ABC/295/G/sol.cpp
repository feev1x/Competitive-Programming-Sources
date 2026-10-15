#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz, sm;
    int n;
    Dsu(int _n) : n(_n) {
        p.resize(n + 1), sz.assign(n + 1, 1);
        iota(p.begin(), p.end(), 0);
        sm = p;
    }
    inline int get(int v) {
        return p[v] == v ? v : p[v] = get(p[v]);
    }
    inline void unite(int u, int v) {
        u = get(u), v = get(v);
        if (u != v) {
            if (sz[u] > sz[v]) std::swap(u, v);
            sz[v] += sz[u], p[u] = v, sm[v] = std::min(sm[v], sm[u]);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; std::cin >> n;
    Dsu d(n);
    std::vector<int> p(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) std::cin >> p[i], g[p[i]].emplace_back(i);
    auto Dfs = [&](auto &&self, int v) -> void {
        for (auto to: g[v]) self(self, to), d.sm[v] = std::min(d.sm[v], d.sm[to]);
    };
    Dfs(Dfs, 1);
    std::cin >> q;
    while (q--) {
        int type; std::cin >> type;
        if (type == 1) {
            int u, v; std::cin >> u >> v;
            d.unite(u, v);
        } else {
            int x; std::cin >> x;
            std::cout << d.sm[d.get(x)] << '\n';
        }
    }
    return 0;
}
