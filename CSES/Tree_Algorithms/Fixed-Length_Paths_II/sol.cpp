/**
 *    author:  feev1x
 *    created: 27.02.2025 11:34:03
**/
#include <bits/stdc++.h>

#pragma GCC optmize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
 
using graph = std::vector<std::vector<int>>;
 
inline int min(int a, int b) {
    if (a < b) {
        return a;
    }
 
    return b;
}
 
inline int max(int a, int b) {
    if (a > b) {
        return a;
    }
 
    return b;
}
 
//struct Bit {
    std::vector<int> pref;
 
    inline void add(int r, int x) {
        r++;
 
        for (; r < pref.size(); r += r & -r) {
            pref[r] += x;
        }
    }
 
    inline int64_t get(int r) {
        r++;
 
        int64_t res = 0;
        
        for (; r > 0; r -= r & -r) {
            res += pref[r];
        }
 
        return res;
    }
//};
 
//struct Centroid {
    std::vector<int> sz;
    std::vector<bool> del;
    graph g;
    int n, k1, k2;
 
//    Centroid(graph _g, int _k1, int _k2) : g(_g), k1(_k1), k2(_k2) {
//        sz.resize(g.size());
//        del.resize(g.size());
//    }
 
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
 
        if (k1 - d < n) {
            res += get(min(k2 - d, n - 1)) - get(max(k1 - d, 0) - 1);
        }
 
        if (d == k2) {
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
        add(d, 1);
 
        if (d == k2) {
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
 
        pref.clear();
        pref.resize(n + 1);
        add(0, 1);
 
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
//};
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> k1 >> k2;
 
    g.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
 
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
 
    sz.resize(g.size());
    del.resize(g.size());
 
    std::cout << calc(1) << '\n';
    return 0;
}
