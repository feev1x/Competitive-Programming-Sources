/**
 *    author:  feev1x
 *    created: 04.03.2025 02:06:26
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    int n;

    Dsu(int _n) : n(_n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline bool unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            p[u] = v;
            sz[v] += sz[u];

            return true;
        }

        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::array<int, 3>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        edges.push_back({w, u, v});
    }

    std::sort(edges.begin(), edges.end());

    Dsu d(n);
    int64_t res = 0;
    for (auto [w, u, v]: edges) {
        res += w * d.unite(u, v);
    }

    if (d.sz[d.get(1)] != n) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        std::cout << res << '\n';
    }
    return 0;
}
