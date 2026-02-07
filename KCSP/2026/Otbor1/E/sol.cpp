#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> sz, p;
    int n, cnt;

    Dsu(int n) : n(n) {
        sz.assign(n, 1);
        p.resize(n);

        cnt = n;
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

            sz[v] += sz[u];
            p[u] = v;
            cnt--;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<std::tuple<int, int, int>> e;
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        e.emplace_back(w, u, v);

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    std::sort(e.begin(), e.end(), std::greater<>());

    Dsu d(n + 1);
    int64_t res1 = 0, res2 = 0, res = 0;

    std::vector<std::pair<int, int>> ans1;
    for (auto [w, u, v]: e) {
        if (d.get(u) == d.get(1) && d.get(v) == d.get(n) || d.get(u) == d.get(n) && d.get(v) == d.get(1)) {
            ans1.emplace_back(u, v);
            res1 += w;
            continue;
        }

        d.unite(u, v);
    }
    
    std::sort(e.begin(), e.end());

    std::vector<std::pair<int, int>> ans2, ans;
    for (auto [w, u, v]: e) {
        if (d.get(u) == d.get(1) && d.get(v) == d.get(n) || d.get(u) == d.get(n) && d.get(v) == d.get(1)) {
            ans2.emplace_back(u, v);
            res2 += w;
            continue;
        }

        d.unite(u, v);
    }

    if (res1 > res2) {
        res = res1, ans = ans1;
    } else {
        res = res2, ans = ans2;
    }

    std::cout << res << '\n' << ans.size() << '\n';
    for (auto [u, v]: ans) {
        std::cout << v << ' ' << u << '\n';
    }
    return 0;
}
