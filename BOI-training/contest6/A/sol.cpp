#include "boardgames.h"
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    int n;

    Dsu(int _n) : n(_n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        std::iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline void unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v])
                std::swap(u, v);

            p[u] = v;
            sz[v] += sz[u];
        }
    }
};

std::vector<int> partition_players(int n, int m, std::vector<int> x, std::vector<int> y) {
    std::vector<std::vector<int>> g(n + 1);

    for (int i = 0; i < m; ++i) {
        x[i]++, y[i]++;

        if (x[i] > y[i])
            std::swap(x[i], y[i]);

        g[y[i]].emplace_back(x[i]);
    }

    std::vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        int r = i, pref = i;

        Dsu d(n);
        for (int j = i; j <= n; ++j) {
            for (auto to: g[j])
                if (to >= i)
                    d.unite(to, j);

            while (pref + 1 <= n && d.get(i) == d.get(pref + 1))
                pref++;

            if (pref == j)
                r = j;
        }

        ans.emplace_back(r - i + 1);
        i = r;
    }

    return ans;
}
