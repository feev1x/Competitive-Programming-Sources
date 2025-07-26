/**
 *    author:  feev1x
 *    created: 04.07.2025 09:50:44
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    std::vector<bool> can;
    int n;

    Dsu(int _n) : n(_n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        can.resize(n + 1);

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
    
    inline void set(int v) {
        can[get(v)] = true;
    }

    inline bool val(int v) {
        return can[get(v)];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto Dis = [](int64_t x, int64_t y, int64_t x1, int64_t y1) {
        return (x - x1) * (x - x1) + (y - y1) * (y - y1);
    };
    
    int64_t n, r; std::cin >> n >> r;

    r *= r;

    std::map<std::pair<int, int>, int> mp;

    bool sm = true;
    Dsu d(n);
    std::vector<int64_t> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i] >> y[i];

        if (r <= 100) {
            mp[{x[i], y[i]}] = i;
        }

        if (y[i])
            sm = false;
    }

    if (sm) {
        std::vector<int> idx(n + 1);

        std::iota(idx.begin(), idx.end(), 0);

        std::sort(idx.begin() + 1, idx.end(), [&](int i, int j) {
            return x[i] < x[j];
        });

        for (int i = 2; i <= n; ++i)
            if (Dis(x[idx[i]], y[idx[i]], x[idx[i - 1]], y[idx[i - 1]]) <= r)
                d.unite(idx[i], idx[i - 1]);

        for (int i = 3; i <= n; ++i)
            if (Dis(x[idx[i]], y[idx[i]], x[idx[i - 2]], y[idx[i - 2]]) <= r)
                d.set(idx[i]);

        for (int i = 1; i <= n; ++i)
            std::cout << d.val(i);

        std::cout << '\n';
        exit(0);
    }

    if (r <= 100) {
        std::vector<std::vector<int>> g(n + 1);

        for (int i = 1; i <= n; ++i)
            for (int cx = 0; g[i].size() <= 6 && cx * cx <= r && cx <= 100; ++cx) {
                for (int cy = cx == 0 ? -1 : 0, j = mp[{x[i] + cx, y[i] + cy}]; cx * cx + cy * cy <= r && cy >= -10; --cy, j = mp[{x[i] + cx, y[i] + cy}]) {
                    if (j > 0) {
                        if (g[i].size() <= 6)
                            g[i].emplace_back(j);

                        if (g[j].size() <= 6)
                            g[j].emplace_back(i);
                        d.unite(j, i);
                    }
                }
                for (int cy = cx == 0 ? 1 : 0, j = mp[{x[i] + cx, y[i] + cy}]; cx * cx + cy * cy <= r && cy <= 10; ++cy, j = mp[{x[i] + cx, y[i] + cy}]) {
                    if (j > 0) {
                        if (g[i].size() <= 6)
                            g[i].emplace_back(j);

                        if (g[j].size() <= 6)
                            g[j].emplace_back(i);

                        d.unite(j, i);
                    }
                }
            }

        int _t = 0;
        std::vector<bool> used(n + 1), col(n + 1);
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            if (g[v].size() > 6) {
                d.set(v);

                return;
            }
     
            for (auto to: g[v]) {
                if (used[to]) {
                    if (col[to] == col[v])
                        d.set(v);
                } else {
                    col[to] = !col[v];
                    self(self, to);
                }
            }
        };
     
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) 
                Dfs(Dfs, i);
     
            std::cout << d.val(i);
        }
     
        std::cout << '\n';
        exit(0);
    }

    int _t = 0;
    std::vector<bool> used(n + 1), col(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        for (int to = 1; to <= n; ++to) {
            if (to == v || Dis(x[v], y[v], x[to], y[to]) > r) {
                continue;
            }

            d.unite(v, to);

            if (used[to]) {
                if (col[to] == col[v])
                    d.set(v);
            } else {
                col[to] = !col[v];
                self(self, to);
            }
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) 
            Dfs(Dfs, i);

        std::cout << d.val(i);
    }

    std::cout << '\n';
    return 0;
}

