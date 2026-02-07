#include <bits/stdc++.h>

constexpr int N = 1e5 + 5;

struct Dsu {
    std::vector<int> p, sz;
    int n;

    Dsu(int n) : n(n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

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

    int n, m, q; std::cin >> n >> m >> q;

    std::set<int> st;
    std::vector<int> h(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> h[i];

        if (i < n) {
            st.emplace(i);
        }
    }

    Dsu d(n);
    std::vector<std::array<int, 4>> e(m);
    std::vector<std::tuple<int, int, int>> edges;
    int nw = 0;
    for (auto &[l, r, w, t]: e) {
        std::cin >> l >> r >> w >> t;
    }

    std::sort(e.begin(), e.end(), [&](const std::array<int, 4> &a, const std::array<int, 4> &b) {
        return a[2] < b[2];
    });

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    if (*std::max_element(h.begin(), h.end()) == 1) {
        for (auto [l, r, w, t]: e) {
            std::vector<int> del;

            for (auto it = st.lower_bound(l); it != st.end() && *it < r; ++it) {
                int u = *it, v = u + 1;

                if (d.unite(u, v)) {
                    g[u].emplace_back(v, w);
                    g[v].emplace_back(u, w);
                }
                del.emplace_back(*it);
            }

            for (auto u: del) {
                st.erase(u);
            }
        }
    } else {
        for (auto [l, r, w, t]: e) {
            std::vector<int> val;

            for (int i = l; i <= r; ++i) {
                if (h[i] <= t) {
                    val.emplace_back(i);
                }
            }

            for (int i = 0; i + 1 < val.size(); ++i) {
                int u = val[i], v = val[i + 1];

                if (d.unite(u, v)) {
                    g[u].emplace_back(v, w);
                    g[v].emplace_back(u, w);
                }
            }
        }
    }

    std::vector<int> tin(n + 1), tout(n + 1);
    std::vector<std::array<int, 20>> anc(n + 1), mx(n + 1);
    for (auto &u: anc) {
        for (auto &v: u) {
            v = 0;
        }
    }

    for (auto &u: mx) {
        for (auto &v: u) {
            v = 0;
        }
    }

    int t = 0;
    auto Dfs = [&](auto &&self, int v) -> void {
        tin[v] = ++t;

        for (int i = 1; i < 20; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
            mx[v][i] = std::max(mx[v][i - 1], mx[anc[v][i - 1]][i - 1]);
        }

        for (auto [to, w]: g[v]) {
            if (to == anc[v][0]) {
                continue;
            }

            anc[to][0] = v;
            mx[to][0] = w;
            self(self, to);
        }

        tout[v] = ++t;
    };

    for (int i = 1; i <= n; ++i) {
        if (tin[i] == 0) {
            Dfs(Dfs, i);
        }
    }

    tout[0] = ++t;

    auto Lca = [&](int u, int v) {
        if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
            return u;
        }

        for (int i = 19; i >= 0; --i) {
            int nx = anc[u][i];
            
            if (tin[nx] > tin[v] || tout[v] > tout[nx]) {
                u = nx;
            }
        }

        return anc[u][0];
    };

    while (q--) {
        int a, b; std::cin >> a >> b;

        if (d.get(a) != d.get(b)) {
            std::cout << "-1\n";
            continue;
        }

        int lca = Lca(a, b);

        int max = 0;
        for (int i = 19; i >= 0; --i) {
            int nx = anc[a][i];

            if (tin[nx] <= tin[lca] && tout[lca] <= tout[nx]) {
                continue;
            }

            max = std::max(max, mx[a][i]);
            a = nx;
        }

        if (a != lca) {
            max = std::max(max, mx[a][0]);
        }

        for (int i = 19; i >= 0; --i) {
            int nx = anc[b][i];

            if (tin[nx] <= tin[lca] && tout[lca] <= tout[nx]) {
                continue;
            }

            max = std::max(max, mx[b][i]);
            b = nx;
        }

        if (b != lca) {
            max = std::max(max, mx[b][0]);
        }

        std::cout << max << '\n';
    }

    return 0;
}
