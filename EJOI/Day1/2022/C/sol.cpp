/**
 *    author:  feev1x
 *    created: 03.05.2025 14:30:07
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> sz, p;
    int n;

    Dsu(int _n) : n(_n) {
        sz.assign(n + 1,  1);
        p.resize(n + 1);

        std::iota(p.begin(), p.end(), 0);
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

            sz[v] += sz[u];
            p[u] = v;

            return true;
        }

        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<int> p;
        std::vector<std::array<int, 4>> e, ee1, ee;
        for (int i = 0; i < m; ++i) {
            int u, v, l, r; std::cin >> u >> v >> l >> r;

            p.emplace_back(l);
            e.push_back({l, r, u, v});
        }

        std::sort(p.begin(), p.end());
        p.erase(std::unique(p.begin(), p.end()), p.end());

        Dsu d1(n), d(n);
        auto e1 = e;
        
        std::sort(e1.begin(), e1.end());
        for (auto [l, r, u, v]: e1) {
            if (d1.unite(u, v)) {
                ee1.push_back({l, r, u, v});
            }
        }

        int idx = 1;
        for (auto [l, r, u, v]: e) {
            if (d.unite(u, v)) {
                ee.push_back({l, r, u, v});
            }

            if (idx == n - 1) {
                break;
            }

            idx++;
        }

        std::sort(ee.begin(), ee.end());
        std::sort(ee1.begin(), ee1.end());

        if (ee == ee1 && p.size() == m) {
            std::cout << "YES\n";

            for (auto [l, r, u, v]: e) {
                std::cout << l << ' ';
            }

            std::cout << '\n';
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
