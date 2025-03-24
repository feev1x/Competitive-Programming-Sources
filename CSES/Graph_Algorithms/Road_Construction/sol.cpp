/**
 *    author:  feev1x
 *    created: 04.03.2025 02:11:45
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    int n, cnt, mx;

    Dsu(int _n) : n(_n), cnt(n), mx(1) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline void unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            cnt--;
            p[u] = v;
            sz[v] += sz[u];

            mx = std::max(mx, sz[v]);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    Dsu d(n);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        d.unite(u, v);

        std::cout << d.cnt << ' ' << d.mx << '\n';
    }
    return 0;
}
