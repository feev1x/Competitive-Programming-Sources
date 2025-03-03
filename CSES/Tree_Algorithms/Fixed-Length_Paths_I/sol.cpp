/**
 *    author:  feev1x
 *    created: 27.02.2025 11:12:50
**/
#include <bits/stdc++.h>

#pragma GCC target("avx,avx2")
#pragma GCC optimize("O3,unroll-loops")

using graph = std::vector<std::vector<int>>;

struct Centroid {
    std::vector<int> sz, cnt;
    std::vector<bool> del;
    graph g;
    int n, k;

    Centroid(graph _g, int _k) : g(_g), k(_k) {
        sz.resize(g.size());
        del.resize(g.size());
        cnt.resize(g.size());
    }

    inline void dfs(int v, int p) {
        sz[v] = 1;

        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
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

    inline int64_t calc_ans(int v, int p, int d) {
        int64_t res = 0;

        if (k - d < n) {
            res += cnt[k - d];
        }

        if (d == k) {
            return res;
        }

        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            res += calc_ans(to, v, d + 1);
        }

        return res;
    }

    inline void add_cnt(int v, int p, int d) {
        cnt[d]++;

        if (d == k) {
            return;
        }

        for (auto to: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            add_cnt(to, v, d + 1);
        }
    }

    inline int64_t calc(int v) {
        dfs(v, v);

        n = sz[v], v = get(v, v);

        std::fill(cnt.begin(), cnt.begin() + n, 0);

        cnt[0] = 1;

        int64_t res = 0;
        for (auto to: g[v]) {
            if (del[to]) {
                continue;
            }

            res += calc_ans(to, v, 1);

            add_cnt(to, v, 1);
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
    
    int n, k; std::cin >> n >> k;

    graph g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    Centroid cen(g, k);

    std::cout << cen.calc(1) << '\n';
    return 0;
}
