/**
 *    author:  feev1x
 *    created: 25.02.2025 16:40:56
**/
#include <bits/stdc++.h>

using wgraph = std::vector<std::vector<std::pair<int, int>>>;

inline int phi(int n) {
    int res = n;

    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }

            res -= res / p;
        }
    }

    if (n > 1) {
        res -= res / n;
    }

    return res;
}

struct Centroid {
    std::map<int, int> cnt;
    std::vector<int> sz;
    std::vector<bool> del;
    wgraph g;
    int n, MOD, phi_MOD;

    Centroid(wgraph _g, int _MOD) : g(_g), MOD(_MOD), n(0) {
        phi_MOD = phi(MOD);

        sz.resize(g.size());
        del.resize(g.size());
    }

    inline int mul(int a, int b) {
        return (int64_t)a * b % MOD;
    }

    inline int binpow(int a, int64_t n) {
        int res = 1;

        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }

            a = mul(a, a);
            n >>= 1;
        }

        return res;
    }

    inline void dfs(int v, int p) {
        sz[v] = 1;

        for (auto [to, w]: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            dfs(to, v);

            sz[v] += sz[to];
        }
    }

    inline int get(int v, int p) {
        for (auto [to, w]: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            if (sz[to] * 2 > n) {
                return get(to, v);
            }
        }

        return v;
    }

    inline int64_t calc_ans(int v, int p, int num, int d) {
        int64_t res = cnt[mul(((-num % MOD) + MOD) % MOD, binpow(10, (int64_t)d * (phi_MOD - 1)))];

        for (auto [to, w]: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            res += calc_ans(to, v, (mul(num, 10) + w) % MOD, d + 1);
        }

        return res;
    }

    inline void add_cnt(int v, int p, int num, int d) {
        cnt[num]++;


        for (auto [to, w]: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            add_cnt(to, v, (num + mul(w, binpow(10, d))) % MOD, d + 1);
        }
    }

    inline void del_cnt(int v, int p, int num, int d) {
        cnt[num]--;

        for (auto [to, w]: g[v]) {
            if (to == p || del[to]) {
                continue;
            }

            del_cnt(to, v, (num + mul(w, binpow(10, d))) % MOD, d + 1);
        }
    }

    inline int64_t calc(int v) {
        dfs(v, v);

        n = sz[v], v = get(v, v);

        int64_t res = 0;

        cnt.clear();

        cnt[0] = 1;
        for (auto [to, w]: g[v]) {
            if (del[to]) {
                continue;
            }

            add_cnt(to, v, w, 1);
        }

        res += cnt[0] - 1;

        for (auto [to, w]: g[v]) {
            if (del[to]) {
                continue;
            }

            del_cnt(to, v, w, 1);
            
            res += calc_ans(to, v, w, 1);

            add_cnt(to, v, w, 1);
        }

        del[v] = true;
        for (auto [to, w]: g[v]) {
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
    
    int n, MOD; std::cin >> n >> MOD;

    wgraph g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v, w; std::cin >> u >> v >> w; u++, v++, w %= MOD;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    Centroid cen(g, MOD);

    std::cout << cen.calc(1) << '\n';
    return 0;
}
