#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> sz, p;
    int n;
    Dsu(int n) : n(n) {
        sz.assign(n, 1);
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
    }
    inline int get(int v) { return v == p[v] ? v : p[v] = get(p[v]); }
    inline bool unite(int u, int v) {
        u = get(u), v = get(v);
        if (u != v) {
            if (sz[u] > sz[v]) std::swap(u, v);
            return sz[v] += sz[u], p[u] = v, true;
        }
        return false;
    }
};

inline void solve() {
    int n, m, q; std::cin >> n >> m >> q;
    std::vector<std::tuple<int, int, int>> e;
    Dsu d(q + 1);
    int res = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;
        e.emplace_back(u, v, w);
    }
    std::vector<int> c(q + 1), val(n + 1);
    for (int i = 1; i <= q; ++i) std::cin >> c[i], val[c[i]] = i;
    for (auto [u, v, w]: e) if (w) cnt += d.unite(val[u], val[v]);
    for (auto [u, v, w]: e) if (w == 0) res += d.unite(val[u], val[v]);
    if (res + cnt < q - 1) std::cout << "-1\n";
    else std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
