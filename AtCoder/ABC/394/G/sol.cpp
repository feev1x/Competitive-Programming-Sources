/**
 *    author:  feev1x
 *    created: 20.03.2025 09:28:26
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9, LOG = 30;

struct Dsu {
    std::vector<int> sz, p;
    int n;

    Dsu(int _n) : n(_n) {
        sz.assign(n + 1, 1);
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
    
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
        }
    }

    auto Idx = [&](int i, int j) {
        return (i - 1) * m + j;
    };

    Dsu d(n * m);
    std::vector<std::vector<std::pair<int, int>>> g(n * m + 1);
    std::vector<std::array<int, 3>> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i != n) {
                edges.push_back({std::min(a[i][j], a[i + 1][j]), Idx(i, j), Idx(i + 1, j)});
            }

            if (j != m) {
                edges.push_back({std::min(a[i][j], a[i][j + 1]), Idx(i, j), Idx(i, j + 1)});
            }
        }
    }

    std::sort(edges.begin(), edges.end(), std::greater<>());

    for (auto [w, u, v]: edges) {
        if (d.unite(u, v)) {
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
    }

    int _t = 1;
    std::vector<int> dep(n * m + 1), tin(n * m + 1), tout(n * m + 1);
    std::vector<std::array<int, LOG>> anc(n * m + 1), mn(n * m + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        dep[v] = dep[p] + 1;
        tin[v] = _t++;

        for (int i = 1; i < LOG; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
            mn[v][i] = std::min(mn[v][i - 1], mn[anc[v][i - 1]][i - 1]);
        }

        for (auto [to, w]: g[v]) {
            if (to == p) {
                continue;
            }

            anc[to][0] = v;
            mn[to][0] = w;

            self(self, to, v);
        }

        tout[v] = _t++;
    };

    for (int i = 0; i <= n * m; ++i) {
        anc[i].fill(1);
        mn[i].fill(INF);
    }

    Dfs(Dfs, 1, 1);
    tout[0] = _t;

    auto IsPar = [&](int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    };

    auto Lca = [&](int u, int v) {
        if (IsPar(u, v)) {
            return u;
        }
        
        for (int i = LOG - 1; i >= 0; --i) {
            int nx = anc[u][i];

            if (!IsPar(nx, v)) {
                u = nx;
            }
        }

        return anc[u][0];
    };

    auto LiftMin = [&](int v, int k) {
        int res = INF;

        for (int i = 0; i < LOG; ++i) {
            if (k >> i & 1) {
                res = std::min(res, mn[v][i]);
                v = anc[v][i];
            }
        }

        return res;
    };

    int q; std::cin >> q;
    while (q--) {
        int a, b, y, c, d, z; std::cin >> a >> b >> y >> c >> d >> z;

        if (a == c && b == d) {
            std::cout << std::abs(y - z) << '\n';

            continue;
        }

        int u = Idx(a, b), v = Idx(c, d), lca = Lca(u, v);

        int mn_e = std::min(LiftMin(u, dep[u] - dep[lca]), LiftMin(v, dep[v] - dep[lca])), res = 0;

        if (mn_e < y) {
            res += y - mn_e;
            y = mn_e;
        }

        res += std::abs(y - z);

        std::cout << res << '\n';
    }
    return 0;
}
