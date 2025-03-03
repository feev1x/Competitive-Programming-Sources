/**
 *    author:  feev1x
 *    created: 25.02.2025 14:47:03
**/
#include <bits/stdc++.h>

using graph = std::vector<std::vector<int>>;

struct Centroid {
    std::vector<int> sz, a;
    std::array<std::array<int, 2>, 20> cnt;
    std::vector<bool> del;
    graph g;
    int n;

    Centroid(graph _g, std::vector<int> _a) : g(_g), a(_a), n(0) {
        sz.resize(g.size());
        del.resize(g.size());
    }

    inline void dfs(int v, int p) {
        sz[v] = 1;

        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            if (v == 2) {
                
            }

            dfs(to, v);

            sz[v] += sz[to];
        }
    }

    inline int get(int v, int p) {
        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            if (sz[to] * 2 > n) {
                return get(to, v);
            }
        }

        return v;
    }

    inline int64_t calc_ans(int v, int p, int xr) {
        xr ^= a[v];

        int64_t res = 0;

        for (int i = 0; i < 20; ++i) {
            res += cnt[i][(xr >> i & 1) ^ 1] * (1ll << i);
        }

        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            res += calc_ans(to, v, xr);
        }

        return res;
    }

    inline void add_cnt(int v, int p, int xr) {
        xr ^= a[v];

        for (int i = 0; i < 20; ++i) {
            cnt[i][xr >> i & 1]++;
        }

        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            add_cnt(to, v, xr);
        }
    }

    inline int64_t calc(int v) {
        dfs(v, v);

        n = sz[v], v = get(v, v);

        int64_t res = a[v];

        for (int i = 0; i < 20; ++i) {
            cnt[i][1] = 0;
            cnt[i][0] = 1;
        }

        for (auto to: g[v]) {
            if (del[to]) {
                continue;
            }

            res += calc_ans(to, v, a[v]);

            add_cnt(to, v, 0);
        }

        del[v] = true;
        for (auto to: g[v]) {
            if (del[to]) {
                continue;
            }

            res += calc(to);
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

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

    Centroid cen(g, a);

    std::cout << cen.calc(1) << '\n';
    return 0;
}
