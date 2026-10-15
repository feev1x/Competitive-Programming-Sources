#include <bits/stdc++.h>

struct Segtree {
    std::vector<int64_t> t;
    int n;
    Segtree(int n) : n(n) { t.resize(4 * n); }
    inline int64_t get(int v, int tl, int tr, int i) {
        if (tl == tr) return t[v];
        int tm = tl + tr >> 1;
        if (i <= tm) return t[v] + get(v << 1, tl, tm, i);
        return t[v] + get(v << 1 | 1, tm + 1, tr, i);
    }
    inline void update(int v, int tl, int tr, int l, int r, int64_t x) {
        if (tl > r || l > tr) return;
        if (l <= tl && tr <= r) return t[v] += x, void();
        int tm = tl + tr >> 1;
        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);
    }
    inline int64_t get(int i) { return get(1, 1, n, i); }
    inline void update(int l, int r, int64_t x) { update(1, 1, n, l, r, x); }
};

struct Fliptree {
    std::
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; std::cin >> n >> q;
    std::vector<int> w(n + 1), c(n + 1), par(n + 1);
    std::vector s(2, std::vector<int64_t>(n + 1));
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> w[i];
    for (int i = 1; i <= n; ++i) std::cin >> c[i];
    g[0].emplace_back(1);
    c[0] = 2;
    for (int i = 1; i < n; ++i) {
        int a, b; std::cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        s[0][v] = s[1][v] = w[v];
        par[v] = p;
        for (auto to: g[v]) if (to != p) {
            self(self, to, v);
            if (c[to] == c[v]) s[c[v]][v] += s[c[to]][to];
            else s[1 - c[v]][v] += s[c[to]][to];
        }
    }; Dfs(Dfs, 1, 0);
    Hld hld(g, s, c);
    while (q--) {
        int type; std::cin >> type;
        if (type == 1) {
            int v; std::cin >> v;
            int p = par[hld.getpar(v)];
            hld.update(par[v], p, -hld.get(v, c[v]), c[v]);
            hld.flip(v);
            c[v] = 1 - c[v];
            p = par[hld.getpar(v)];
            hld.update(par[v], p, hld.get(v, c[v]), c[v]);
        } else if (type == 2) {
            int v, x; std::cin >> v >> x;
            int p = par[hld.getpar(v)];
            hld.update(v, p, x, c[v]);
            hld.update(v, v, x, 1 - c[v]);
        } else {
            int v; std::cin >> v;
            std::cout << hld.get(hld.getpar(v), c[v]) << '\n';
        }
    }
    return 0;
}
