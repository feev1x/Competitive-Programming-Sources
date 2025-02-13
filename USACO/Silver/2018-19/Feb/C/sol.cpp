/**
 *    author:  feev1x
 *    created: 12.02.2025 13:17:38
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    int n, cnt;

    Dsu(int _n) : n(_n), cnt(_n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline void unite(int u, int v) {
        u = get(u);
        v = get(v);

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
    std::freopen("revegetate.in", "r", stdin);
    std::freopen("revegetate.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<int> val(n + 1);
    std::vector<bool> used(n + 1), col(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::pair<int, int>> ss, dd;
    for (int i = 0; i < m; ++i) {
        char ch; std::cin >> ch;

        int u, v; std::cin >> u >> v;

        if (ch == 'S') {
            ss.emplace_back(u, v);
        } else {
            dd.emplace_back(u, v);
        }
    }

    Dsu d(n), d1(n);
    for (auto [u, v]: ss) {
        d.unite(u, v);
        d1.unite(u, v);
    }

    for (auto [u, v]: dd) {
        if (d.get(u) == d.get(v)) {
            std::cout << "0\n";

            exit(0);
        }

        g[d.get(u)].emplace_back(d.get(v));
        g[d.get(v)].emplace_back(d.get(u));
    }

    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (auto to: g[v]) {
            if (used[to] && col[to] == col[v]) {
                std::cout << "0\n";

                exit(0);
            } else if (used[to]) {
                continue;
            }

            col[to] = !col[v];

            self(self, to);
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        Dfs(Dfs, i);
    }

    for (auto [u, v]: dd) {
        d.unite(u, v);
    } 

    std::cout << 1;
    
    for (int i = 0; i < d.cnt; ++i) {
        std::cout << 0;
    }

    std::cout << '\n';
    return 0;
}
