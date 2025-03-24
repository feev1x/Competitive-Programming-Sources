/**
 *    author:  feev1x
 *    created: 20.03.2025 11:17:13
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> sz, p;
    int n, cnt;

    Dsu(int _n) : n(_n), cnt(_n) {
        sz.assign(n + 1, 1);
        p.resize(n + 1);

        std::iota(p.begin(), p.end(), 0);
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

            p[u] = v;
            sz[v] += sz[u];
            cnt--;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    Dsu d(n);
    std::vector<int> x(m), y(m), z(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> x[i] >> y[i] >> z[i];

        d.unite(x[i], y[i]);
    }

    std::cout << d.cnt << '\n';
    return 0;
}
