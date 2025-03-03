/**
 *    author:  feev1x
 *    created: 26.02.2025 14:18:01
**/
#include <bits/stdc++.h>

using graph = std::vector<std::vector<int>>;

struct Segtree {
    std::vector<int> t;
    int n;

    Segtree() : n(0) {}

    Segtree(int _n) : n(_n) {
        t.resize(n * 2 + 2);
    }
    
    inline void set(int i, int x) {
        for (t[i += n] = x; i > 1; i >>= 1) {
            t[i >> 1] = std::max(t[i], t[i ^ 1]);
        }
    }

    inline int get(int l, int r) {
        r++;

        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res = std::max(res, t[l++]);
            }

            if (r & 1) {
                res = std::max(res, t[--r]);
            }
        }

        return res;
    }
};

struct Hld {
    std::vector<int> heavy, idx, p, a, sz, head, dep;
    graph g;
    Segtree t;
    int n, _t;

    inline void dfs(int v) {
        sz[v] = 1;
        dep[v] = dep[p[v]] + 1;

        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }

            p[to] = v;
            dfs(to);

            sz[v] += sz[to];

            if (sz[to] > sz[heavy[v]]) {
                heavy[v] = to;
            }
        }
    }

    inline void hld(int v) {
        idx[v] = _t++;

        t.set(idx[v], a[v]);

        if (heavy[v]) {
            head[heavy[v]] = head[v];
            hld(heavy[v]);
        }

        for (auto to: g[v]) {
            if (to == p[v] || to == heavy[v]) {
                continue;
            }

            hld(to);
        }
    }

    Hld(graph _g, std::vector<int> _a) : g(_g), a(_a), n(a.size() - 1), _t(1) {
        heavy.resize(n + 1);
        head.resize(n + 1);
        idx.resize(n + 1);
        p.resize(n + 1);
        sz.resize(n + 1);
        dep.resize(n + 1);

        t = Segtree(n);

        iota(head.begin(), head.end(), 0);

        dfs(1);
        hld(1);
    }

    inline void set(int v, int x) {
        a[v] = x;

        t.set(idx[v], a[v]);
    }

    inline int get(int u, int v) {
        int res = 0;

        while (head[u] != head[v]) {
            if (dep[head[u]] > dep[head[v]]) {
                std::swap(u, v);
            }

            res = std::max(res, t.get(idx[head[v]], idx[v]));
            v = p[head[v]];
        }

        if (idx[u] > idx[v]) {
            std::swap(u, v);
        }

        res = std::max(res, t.get(idx[u], idx[v]));

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    graph g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    Hld hld(g, a);

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int v, x; std::cin >> v >> x;

            hld.set(v, x);
        } else {
            int u, v; std::cin >> u >> v;

            std::cout << hld.get(u, v) << ' ';
        }
    }

    std::cout << '\n';
    return 0;
}
